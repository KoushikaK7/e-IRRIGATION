/*--------------------------------------------------------------
-------------------E-Irrigation System----------------------
Input: RB0 - 0-5V -> 0-100% Moisture
Output: RE2 - RelayON(1)/RelayOFF(0)
Written By: SuSe
Board No:
Change Log:
14_1121_01 - First Version
15_0112_01 - Modified to accodomate 4 Sensors

-------------------------------------------------------------*/

#include "p30f4011.h"
#include "anLCD.h"
#include "PLDC01_LCD.h"
#include "dsADC.h"

#define Motor_Relay LATE
#define Mositure_Sensor _RB1

unsigned int Analog;
float Moisture;
unsigned int Sensor1_Raw,Sensor2_Raw,Sensor3_Raw,Sensor4_Raw;
float Sensor1_PC,Sensor2_PC,Sensor3_PC,Sensor4_PC;

unsigned char welcome[26] = "e-IRRIGATION WELCOMES YOU";//25
unsigned int dx,di;

unsigned int Status,pStatus,display_cnt;

void main()
{

Int_IO_LCD( ); 
DisON_CurOFF();
//Init_ADC( 0);
Init_ADC_INTR(0,3);
ADPCFGbits.PCFG1 = 1;
TRISBbits.TRISB0 = 1;
TRISE = 0x00;

//ShowSTRING_LCD("    E-IRRIGATION    ",0x80);
//ShowSTRING_LCD("       SYSTEM       ",0xC0);
//ShowSTRING_LCD(" Moisture Level:000%",0x94);//0x94+16,3
//ShowSTRING_LCD(" Pump Status:OFF    ",0xD4);//0xD4+13


ShowSTRING_LCD("STATUS:             ",0xC0);//7
ShowSTRING_LCD("SEN1 SEN2  SEN3 SEN4",0x94);//0x94+16,3
ShowSTRING_LCD("   %    %     %    % ",0xD4);//0,5,11,16

Delay111_LCD(1000);

do{

	if(di == 0)
		ShowSTRING_LCD("e-IRRIGATION        ",0x80);		
	else if(di == 1)
		ShowSTRING_LCD("        WELCOMES YOU",0x80);

	display_cnt++;
   if(display_cnt >= 50)
   {
		if(di == 1) di = 0; else di = 1;
		display_cnt = 0;
   }


	Sensor1_PC = 100.0- ((float)Sensor1_Raw/1023.0 * 100.0);
	Sensor2_PC = 100.0- ((float)Sensor3_Raw/1023.0 * 100.0);//100.0- ((float)Sensor2_Raw/1023.0 * 100.0);
	Sensor3_PC = 100.0- ((float)Sensor3_Raw/1023.0 * 100.0);
	Sensor4_PC = 100.0- ((float)Sensor4_Raw/1023.0 * 100.0);
	

	if((Sensor1_PC >= 50.0) && (Sensor2_PC >= 50.0) && (Sensor3_PC >= 50.0) && (Sensor4_PC >= 50.0))
	{
       Status = 2; // Fully irrigated
	}
	else //if((Sensor1_PC < 50.0) || (Sensor2_PC < 50.0) || (Sensor3_PC < 50.0) || (Sensor4_PC < 50.0))
	{
      Status = 1; // Underirrigation
	}


	ShowNINT_LCD(Sensor1_PC,0xD4+0,3);
	ShowNINT_LCD(Sensor2_PC,0xD4+5,3);
	ShowNINT_LCD(Sensor3_PC,0xD4+11,3);
	ShowNINT_LCD(Sensor4_PC,0xD4+16,3);

    if(pStatus != Status)
	{
	pStatus = Status;
/*	if(Status == 0)
	{
	//	Motor_Relay =0xFF;
		ShowSTRING_LCD("Not Irrigated",0xc0+7);
		Delay111_LCD( 1000 );		
	}*/
	if(Status == 1)
	{
		Motor_Relay =0xFF;
		ShowSTRING_LCD("In Progress",0xc0+7);
		Delay111_LCD( 1000 );		
	}
	else
	{
		Motor_Relay =0x00;
		ShowSTRING_LCD("Completed  ",0xc0+7);
		Delay111_LCD( 1000 );		
	}
	}
/*	if(Moisture > 50.0)
	{
		ShowSTRING_LCD(" Pump Status:OFF    ",0xD4);//0xD4+13
		Motor_Relay =0x00;
		Delay111_LCD( 1000 );		
	}
	else
	{
		Motor_Relay =0xFF;
		ShowSTRING_LCD(" Pump Status:ON    ",0xD4);//0xD4+13
		Delay111_LCD( 1000 );
	}*/
	Delay111_LCD( 100 );
}while(1);
}

void __attribute__((__interrupt__)) _ADCInterrupt(void)
{
 IFS0bits.ADIF		=		 0;
 
 Sensor1_Raw = ADCBUF1;
 Sensor2_Raw = ADCBUF2;
 Sensor3_Raw = ADCBUF3;
 Sensor4_Raw = ADCBUF0;
}