// Código desenvolvido por Marcelo Tucci Maia
// Para o trabalho final das disciplinas ECOP04 e ECOP14 da Unifei
// data 01/08/2021


#include "pic18f4520.h"
#include "config.h"
#include "atraso.h"
#include "lcd.h"
#include "adc.h"
#include "i2c.h"
#include "pwm.h"
#include "teclado.h"
#include "ssd.h"
#include "secadora.h"

#define L_L3    0x90
#define L_L4    0xD0


void sec_contr(long int seg);

void main() {
    unsigned char i, j;
    unsigned char tcl, tcl1;
    int tmp;
    char str[6];
    //long int cont = 1000;

    s_start();
    //ssdInit();

    BitClr(INTCON2, 7); //liga pull up 
    //TRISA = 0x00; //config da porta A 
    //ADCON1 = 0x0E; //config AD

    //BitSet(PORTA, 5); //liga o 1o display
    //TRISD = 0x00; //config. a porta D]
    //PORTD = 0x3F;

    //atraso_ms(5000);

    for (;;) {


        lcd_cmd(L_CLR);
        lcd_cmd(L_L1 + 4);
        lcd_str("PROJETO");
        lcd_cmd(L_L2 + 3);
        lcd_str("SECADORA");
        lcd_cmd(L_L3);
        lcd_str("Marcelo T. Maia");
        lcd_cmd(L_L4 + 3);
        lcd_str("2020032328");

        atraso_ms(1000);
        lcd_cmd(L_CLR);
        lcd_str("Modo Operacao:");
        lcd_cmd(L_L2);
        lcd_str("1: Passa Facil");
        lcd_cmd(L_L3);
        lcd_str("2: Economia");
        lcd_cmd(L_L4);
        lcd_str("3: Para Guardar");
        //while (PORTBbits.RB1);

        TRISB = 0xF8;

        while (1) {
            TRISD = 0x0F;
            tcl = tc_tecla(0) + 0x30;
            TRISD = 0x00;
            //ler_teclado();
            //lcd_dat(tcl);

            if (tcl == '1') {
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                lcd_str("Escolha Carga");
                lcd_cmd(L_L2);
                lcd_str("1: Minima");
                lcd_cmd(L_L3);
                lcd_str("2: Media");
                lcd_cmd(L_L4);
                lcd_str("3: Maxima");

                TRISD = 0x0F;
                tcl = tc_tecla(0) + 0x30;
                TRISD = 0x00;

                if (tcl == '1') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(10);
                } else if (tcl == '2') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(15);
                } else if (tcl == '3') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(20);
                } else {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2);
                    lcd_str("Comando invalido");
                    atraso_ms(2000);
                }
            } else if (tcl == '2') {
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                lcd_str("Escolha Carga");
                lcd_cmd(L_L2);
                lcd_str("1: Minima");
                lcd_cmd(L_L3);
                lcd_str("2: Media");
                lcd_cmd(L_L4);
                lcd_str("3: Maxima");

                //ler_teclado();

                TRISD = 0x0F;
                tcl = tc_tecla(0) + 0x30;
                TRISD = 0x00;

                if (tcl == '1') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(25);
                } else if (tcl == '2') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(30);
                } else if (tcl == '3') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();

                    sec_contr(35);
                } else {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2);
                    lcd_str("COMANDO INVALIDO");
                    atraso_ms(2000);
                }

            } else if (tcl == '3') {
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                lcd_str("Escolha Carga");
                lcd_cmd(L_L2);
                lcd_str("1: Minima");
                lcd_cmd(L_L3);
                lcd_str("2: Media");
                lcd_cmd(L_L4);
                lcd_str("3: Maxima");

                //ler_teclado();

                TRISD = 0x0F;
                tcl = tc_tecla(0) + 0x30;
                TRISD = 0x00;

                if (tcl == '1') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(40);
                } else if (tcl == '2') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();
                    sec_contr(45);
                } else if (tcl == '3') {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 3);
                    lcd_str("INICIANDO");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("SECAGEM");

                    leds();

                    sec_contr(50);
                } else {
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2);
                    lcd_str("COMANDO INVALIDO");
                    atraso_ms(2000);
                }

            } else {
                lcd_cmd(L_CLR);
                lcd_cmd(L_L2);
                lcd_str("Comando invalido");
                atraso_ms(2000);
            }
            break;

        }

    }
}

void sec_contr(long int seg) {
    unsigned char tmp, tcl1;
    char str[6];
    long int cont = seg * 100;
    unsigned char i, j;

    lcd_cmd(L_CLR);
    lcd_cmd(L_L2 + 4);
    lcd_str("SECAGEM");
    lcd_cmd(L_L3 + 2);
    lcd_str("EM ANDAMENTO");

    while (1) {
        ssdInit();
        ssdDigit(((cont / 100) % 10), 3);
        ssdDigit(((cont / 1000) % 10), 2);
        ssdDigit(((cont / 10000) % 10), 1);
        ssdUpdate();
        atraso_ms(10);
        cont--;

        PORTCbits.RC5 = 1;
        pwmSet1(25);



        if (cont == 0) {
            PORTCbits.RC5 = 0;
            pwmSet1(90);
            BitClr(PORTA, 5);

            lcd_cmd(L_CLR);
            lcd_cmd(L_L2 + 4);
            lcd_str("SECAGEM");
            lcd_cmd(L_L3 + 3);
            lcd_str("TERMINADA");
            atraso_ms(2000);
            lcd_cmd(L_CLR);


            lcd_cmd(L_L2 + 5);
            lcd_str("AGUARDE");
            lcd_cmd(L_L3 + 2);
            lcd_str("RESFRIAMENTO");
            atraso_ms(2000);
            lcd_cmd(L_CLR);

            for (j = 0; j < 600; j++) {
                TRISA = 0x07;

                lcd_cmd(L_L1 + 3);
                tmp = (adc_amostra(1)*10) / 20;
                itoa(tmp, str);
                lcd_cmd(L_L2 + 3);
                lcd_dat('T');
                lcd_dat('E');
                lcd_dat('M');
                lcd_dat('P');
                lcd_dat('E');
                lcd_dat('R');
                lcd_dat('A');
                lcd_dat('T');
                lcd_dat('U');
                lcd_dat('R');
                lcd_dat('A');
                lcd_cmd(L_L3 + 7);
                lcd_dat(str[3]);
                lcd_dat(str[4]);
                lcd_dat('C');
                atraso_ms(10);

                if (str[3] == '2' && str[4] == '8') {

                    pwmSet1(0);
                    lcd_cmd(L_CLR);
                    lcd_cmd(L_L2 + 5);
                    lcd_str("ATE A");
                    lcd_cmd(L_L3 + 4);
                    lcd_str("PROXIMA");
                    atraso_ms(3000);



                    break;
                }

            }

            break;

        }

    }
}