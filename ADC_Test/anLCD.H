#ifndef		__SPG_LCD_H__
#define		__SPG_LCD_H__

void  Clear_LCD(void);
void  Return_Home(void);
void  DecCUR_LCD(void);
void  IncCUR_LCD(void);
void  ShiftDISP_Right(void);
void  ShiftDISP__Left(void);
void  DisOFF_CurOFF(void);
void  DisOFF_CurON(void);
void  DisON_CurOFF(void);
void  DisON_CurON(void);
void  DisON_CurBLINK(void);
void  ShiftENTIREDISP_Right(void);
void  ShiftENTIREDISP_Left(void);
void  ShitCUR_Right(void);
void  ShitCUR_Left(void);
void  ShowSTRING_LCD( char *str, unsigned int dispcharess );
void  ShowNINT_LCD( unsigned long int value1, unsigned char ress, 
					unsigned char num );
void  ShowNINT0_LCD( unsigned long int value1, unsigned char ress, 
					unsigned char num );
void  ShowCHAR_LCD( char string, unsigned int adress );
void  Delay111_LCD( int x );

#endif
