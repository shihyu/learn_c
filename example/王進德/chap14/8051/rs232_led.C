#include "reg51.h"
#include "intrins.h"

void delay10ms(int);
void KeyScan(void);

unsigned char current_value=0;
unsigned char next_value=0;
unsigned char LED_state=0x00;
unsigned char a;

main()
{
  TMOD=0x20;
  TH1=0xFD;
  TR1=1;
  PCON&=0x7F;
  SCON=0x50;
  IE=0x90;

  while(1) {
  	KeyScan();
    P1=~LED_state;
	delay10ms(50);
	if (next_value != current_value) {
	  SBUF=next_value+0x40;
	  current_value=next_value;
	}
	switch(next_value) {
      case 1:
        if (LED_state == 0x00 | LED_state == 0xFF)
			LED_state=0x80;
		LED_state=_crol_(LED_state,1);
		break;
 	  case 2:
		if (LED_state == 0x00 | LED_state == 0xFF)
			LED_state=0x01;
		LED_state=_cror_(LED_state,1);
		break;
	  case 3:
		LED_state=0xFF;
		break;
	  case 4:
		LED_state=0x00;
		break;
	} /* switch */
  } /* while */
}

void SCON_int(void) interrupt 4
{
  if (TI == 1) {
	TI=0;
  }
  else {
	RI=0;
	a=SBUF;
	if ((a>=0x40 && a<=0x44)||(a>=0x61 && a<=0x64))	{
		a &= 0x0F;
		next_value=a;
	} /* if */
  } /* if_else */
}
	
void KeyScan(void)
{
  unsigned char row;
  unsigned char coll;
  unsigned char key_value;
  unsigned char scan_value;
  unsigned char read_row;
  key_value=0x01;
  scan_value=0x01;
  for (coll=1;coll<=4;coll++) {
    P0=~scan_value;
	read_row=~P0;
	read_row &= 0xF0;
	for (row=1;row<=4;row++) {
	  if (read_row == 0x10) {
	    if (key_value<5)
		  next_value=key_value;
	  } /* if */
	  read_row >>= 1;
	  ++key_value;
	} /* for */
    scan_value <<= 1;
  } /* for */
}


void delay10ms(int count)
{
  int i,j;
  for (i=0;i<count;i++)
    for (j=0;j<1200;j++)
	  ;
}

