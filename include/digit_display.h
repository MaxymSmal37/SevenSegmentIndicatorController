#ifndef DIGIT_DISPLAY_H
#define DIGIT_DISPLAY_H

#include <msp430.h>

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

extern const unsigned int symbolForDigit[10];
extern const unsigned int section[4];

void initDisplay();
void clearDisplay();
void printDigit(unsigned int digit, unsigned int numberOfDisplay);
void printLine(unsigned int numberOfDisplay);

#endif /* DIGIT_DISPLAY_H */
