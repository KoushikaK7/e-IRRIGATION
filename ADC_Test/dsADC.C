#include	"dsADC.H"

void	Init_ADC(unsigned char ch)
{
	ADCON1				=	0x0000; 
	ADCON2				=	0x0000;
	ADCON3				=	0x0002;
    ADCHS               =   0x0000;
	ADCHSbits.CH0SA 	=	ch;	
	ADCSSL 				=	0x0000; 
	ADPCFG				=	0x0000; 
	ADCON1bits.ADON		=	1;
}

unsigned int	Read_ADC(void)
{
	unsigned int adcvalue=0;

	ADCON1bits.SAMP =1;
	Delay111_LCD(20);
	ADCON1bits.SAMP =0;
	while (!ADCON1bits.DONE);
	adcvalue = ADCBUF0;
	ADCON1bits.DONE =0;	

	return adcvalue;
}

void	Init_ADC_PWM(unsigned int Ch,unsigned char No)
{
 	ADCON1bits.FORM	=	0;
    ADCON1bits.SSRC	=	3;
    ADCON1bits.ASAM	=	1;
    ADCON1bits.SIMSAM	=1;

	ADCON2bits.SMPI	=	1;
	ADCON2bits.CHPS	=	No;
     
	ADCON3bits.SAMC	=	0;
    ADCON3bits.ADCS	=	2;

    ADPCFG 			=	0x0000;
	ADCHS 			=	Ch;
    ADCSSL 			=	0x0000;
    
	ADCON1bits.ADON	=	1;
}

void	Init_ADC_INTR(unsigned int Ch,unsigned char No)
{
 	 ADCON1bits.FORM	=	0;
     ADCON1bits.SSRC	=	7;
     ADCON1bits.ASAM	=	1;
     ADCON1bits.SIMSAM	=	1;
     
	 ADCON2bits.SMPI	=	1;
     ADCON2bits.CHPS	=	No;
     
	 ADCON3bits.SAMC	=	0;
     ADCON3bits.ADCS	=	4;

     ADPCFG 			=	0x0000;
     ADCHS 				=	Ch;
     ADCSSL 			=	0x0000;

	 IFS0bits.ADIF		=	0;
     IEC0bits.ADIE		=	1;
     
	 ADCON1bits.ADON	=	1;
}

