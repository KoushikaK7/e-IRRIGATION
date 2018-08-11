#include	"P30F4011.H"

/*	Used to Initialise Single ADC Channel
	Arg	:	ch	-	Channel to be sampled..	*/

void	Init_ADC(unsigned char ch);		

/*	Used to Read Single ADC Channel
	Return : 12 Bit ADC Data	*/

unsigned int	Read_ADC(void);

/*	Used to Initialise Multible ADC Channels with PWM as Trigger Source
	Arg	:	Ch	-	Channels to be sampled..
			No	-	No Of Channels to be sampled..  */

void	Init_ADC_PWM(unsigned int Ch,unsigned char No);

/*	Used to Initialise Multible ADC Channels with Continous sampling using Interrupt
	Arg	:	Ch	-	Channels to be sampled..
			No	-	No Of Channels to be sampled..  */

void	Init_ADC_INTR(unsigned int Ch,unsigned char No);

//Use the Following Function for ADC ISR when using Interrupt

/*void __attribute__((__interrupt__)) _ADCInterrupt(void)
{

    IFS0bits.ADIF = 0;
}*/

