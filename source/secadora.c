//#include <pic18f4520.h>
#include "pic18f4520.h"
#include "lcd.h"
#include "teclado.h"
#include "adc.h"
#include "pwm.h"
#include "ssd.h"
#include "atraso.h"

#define L_L3    0x90
#define L_L4    0xD0

void s_start(void) {

    ADCON1 = 0x06;
    //TRISA = 0xC3;
    TRISA = 0x07;
    TRISB = 0x03;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    lcd_init();
    adc_init();
    pwmInit();

    lcd_cmd(0x0C);
}

unsigned char ler_teclado() {
    unsigned* tcl;
    TRISD = 0x0F;
    tcl = tc_tecla(0) + 0x30;
    TRISD = 0x00;
    //return tcl;
}

void itoa(unsigned int val, char* str) {
    str[0] = (val / 10000) + 0x30;
    str[1] = ((val % 10000) / 1000) + 0x30;
    str[2] = ((val % 1000) / 100) + 0x30;
    str[3] = ((val % 100) / 10) + 0x30;
    str[4] = (val % 10) + 0x30;
    str[5] = 0;
}

void leds(void) {
    PORTD = 0b00000001;
    for (int k = 0; k < 8; k++) {
        atraso_ms(500);
        PORTD = PORTD * 2;
        //atraso_ms(500);
    }
    PORTD = 0xFF;
    atraso_ms(500);
    PORTD = 0x00;
    atraso_ms(500);
    PORTD = 0xFF;
    atraso_ms(500);
}

