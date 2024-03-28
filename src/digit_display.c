#include "digit_display.h"


void initDisplay()
{
    P1DIR |= A | B | C | D | E | F | G | DT; // initialize segment
    P2DIR |= D1 | D2 | D3 | D4;              // initialize sector

    clearDisplay();
}

void clearDisplay()
{
    P1OUT &= ~(A | B | C | D | E | F | G | DT); // OFF all segment
    P2OUT |= D1 | D2 | D3 | D4;                 // OFF all sector
}

void printDigit(unsigned int digit, unsigned int numberOfDisplay)
{
    switch (numberOfDisplay)
    {
    case 1:
        P2OUT = ~(section[0]);
        break;
    case 2:
        P2OUT = ~(section[1]);
        break;
    case 3:
        P2OUT = ~(section[2]);
        break;
    case 4:
        P2OUT = ~(section[3]);
        break;
    }

    switch (digit)
    {
    case 0:
        P1OUT = symbolForDigit[0];
        break;
    case 1:
        P1OUT = symbolForDigit[1];
        break;
    case 2:
        P1OUT = symbolForDigit[2];
        break;
    case 3:
        P1OUT = symbolForDigit[3];
        break;
    case 4:
        P1OUT = symbolForDigit[4];
        break;
    case 5:
        P1OUT = symbolForDigit[5];
        break;
    case 6:
        P1OUT = symbolForDigit[6];
        break;
    case 7:
        P1OUT = symbolForDigit[7];
        break;
    case 8:
        P1OUT = symbolForDigit[8];
        break;
    case 9:
        P1OUT = symbolForDigit[9];
        break;
    }
}

void printLine(unsigned int numberOfDisplay)
{
    clearDisplay();

    switch (numberOfDisplay)
    {
    case 1:
        P2OUT &= ~D1;
        break;
    case 2:
        P2OUT &= ~D2;
        break;
    case 3:
        P2OUT &= ~D3;
        break;
    case 4:
        P2OUT &= ~D4;
        break;
    default:
        P2OUT &= ~(D1 | D2 | D3 | D4);
        break;
    }

    P1OUT |= G;
}

void printNumber(int number)
{
    int primaryNumber = number;
    int displayCounter = 4;
    int counter = 0;

    if (number < 0)
    {
        number *= -1;
    }
    if ((number > -1000) && (number < 10000))
    {
        while (number > 0)
        {
            int res = number % 10;
            number /= 10;
            clearDisplay();
            printDigit(res, displayCounter);
            displayCounter--;
            __delay_cycles(1000);
        }
        if (primaryNumber < 0)
        {
            printLine(displayCounter);
        }
    }
    else
    {
        printLine(4);
    }
}
