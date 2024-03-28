#include "animation_display.h"


#define DELAY_TIME 80000

int switchDisplay = 1;


void cycle_digit_animation()
{
    const unsigned int delay = 1200000;
    int dispNum = 1;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        printDigit(i, 1);
        __delay_cycles(delay);

        if (dispNum == 4)
        {
            dispNum = 0;
        }
        dispNum++;
    }
}

void displayCarusel()
{
    P1OUT |= A;
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (A | B);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (C | B);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (C | D);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (D | E);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (E | F);
    __delay_cycles(DELAY_TIME);
    P1OUT &= ~F;
}

void reversedDisplayCarusel()
{
    P1OUT |= A;
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (F | A);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (F | E);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (D | E);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (C | D);
    __delay_cycles(DELAY_TIME);
    P1OUT ^= (B | C);
    __delay_cycles(DELAY_TIME);
    P1OUT &= ~B;
}

void circle_animation()
{
    if (switchDisplay > 0)
    {
        P1OUT &= ~DT;
        P2OUT |= D2 | D3;
        P2OUT &= ~(D1 | D4);
        displayCarusel();
        P1OUT |= DT;
        switchDisplay *= -1;
    }
    else
    {
        P1OUT &= ~DT;
        P2OUT

 |= D1 | D4;
        P2OUT &= ~(D3 | D2);
        reversedDisplayCarusel();
        P1OUT |= DT;
        switchDisplay *= -1;
    }
}
