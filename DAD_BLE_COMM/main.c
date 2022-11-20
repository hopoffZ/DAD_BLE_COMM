#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Two options: device can be a sender, or a receiver.  This is determined by the existence of certain
	//external connections to the MSP432, I.E. HMI, removable storage, SPE, etc.
}
