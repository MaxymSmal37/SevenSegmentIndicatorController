#include <msp430.h>

#undef C

#define A BIT3
#define B BIT5
#define C BIT7
#define D BIT1
#define E BIT0
#define F BIT4
#define G BIT6
#define DT BIT2

#define D1 BIT0
#define D2 BIT1
#define D3 BIT2
#define D4 BIT5

#define DELAY_TIME 80000

void clearDisplay();
void initDisplay();
void displayCarusel();
void reversedDisplayCarusel();
void circle_animation();
void printLine(unsigned int numberOfDisplay);
void printDigit(unsigned int digit, unsigned int numberOfDisplay);
void cycle_digit_animation();
void printNumber(int number);
int getTemperature();


const unsigned int symbolForDigit[10] = {
    A | B | C | D | E | F,     // 0
    B | C,                     // 1
    A | B | G | D | E,         // 2
    A | B | G | C | D,         // 3
    B | C | F | G,             // 4
    A | C | D | F | G,         // 5
    A | C | D | E | F | G,     // 6
    A | B | C,                 // 7
    A | B | C | D | E | F | G, // 8
    A | B | C | D | F | G      // 9
};

const unsigned int section[4] = {D1, D2, D3, D4};

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    CCTL0 = CCIE;
    TACTL = TASSEL_2 + MC_1 + ID_3;
    CCR0 = 10000;

    initDisplay();
    printLine(0);

    while (1)
    {
        printNumber(7698);
    }

    return 0;
}
