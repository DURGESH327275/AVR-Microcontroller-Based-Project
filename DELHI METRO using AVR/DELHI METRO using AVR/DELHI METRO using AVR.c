/*
 * DELHI_METRO_using_AVR.c
 *
 * Created: 06-01-2019 11:10:49
 *  Author: DURGESH
 */ 


#include <avr/io.h>
#include <util/delay.h>
lcd_cmd(unsigned char cmd)
{
	
	PORTD=cmd;      // select 8 bit mode lcd select
	PORTC &= ~((1<<0)|(1<<1)) ; //RS=0 & RW=0 for for select cmd register
	
	PORTC|=(1<<2) ;   // EN=1
	_delay_ms(5);
	PORTC&=~(1<<2);     //EN =0
	_delay_ms(5);

}
lcd_data(unsigned char data)
{
	PORTD=data;
	PORTC |= (1<<0) ; //RS=1 for select cmd register
	PORTC &= ~(1<<1);  //RW=0 for select write data
	PORTC |=(1<<2);   // EN=1
	_delay_ms(5);
	PORTC&=~(1<<2);     //EN =0
	_delay_ms(5);
}
lcd_string(unsigned char* str)
{int j;
	while(str[j]!='\0')
	{
		lcd_data(str[j]);
		j++;
	}
}

int main(void)
{  DDRD=0xff;
	DDRC=0xff;
	DDRA=0xff;
	DDRB=0xff;
	PORTB=0xff;
	PORTC|=((1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));

	
	int i;
	lcd_cmd(0x38);   // lcd ON
	lcd_cmd(0x0c);  //display on cursor off
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
lcd_string("Welcome To Delhi");	
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("      METRO     ");	
_delay_ms(3000);
lcd_cmd(0x01);    //lcd clear

	while(1)
	{
	
/************************************************************************/
/*                Rithala metro Station                                              */
/************************************************************************/
  

			 PORTB&=~(1<<0);
	 
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("      Rithala     ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station   ");
	_delay_ms(3000);
	
	
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
						
			lcd_cmd(0x80);  // characters start from position 0 & row 1st
			lcd_string("   Door is Open    ");
			lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
			lcd_string("                   ");
			_delay_ms(2000);
							
			PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
			PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
			_delay_ms(3000);
			
			
			PORTA=0x00; //door open
			_delay_ms(4000);   //door open for 3sec
			
									PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
									_delay_ms(1500);
									PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
									
			
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("  Door is Close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		

		PORTA|=	(1<<4);  //Port A pin 4 is high
		PORTA&=	~(1<<5);  //Port A pin 5 is low
		PORTA&=	~(1<<6);  //Port A pin 6 is low
		PORTA|=	(1<<7);  //Port A pin 7 is high
    _delay_ms(3000);
	
	PORTA=0x00;          //door close
	_delay_ms(2000);
	
	lcd_cmd(0x01);    //lcd clear
	
	/************************************************************************/
	/*                ROHINI West metro Station                             */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("   Rohini West   ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<1);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("   Rohini West     ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);
	
							PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
							_delay_ms(1500);
							PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
							
	
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
								PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
								_delay_ms(1500);
								PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
								
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;          // door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
   
	/************************************************************************/
	/*                ROHINI East metro Station                             */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("   Rohini East   ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<2);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("   Rohini East     ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);
	
							PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
							_delay_ms(1500);
							PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
							
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
								PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
								_delay_ms(1500);
								PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
								
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
   /************************************************************************/
	/*                Pitampura metro Station                             */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("    Pitampura    ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<3);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("    Pitampura      ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);
	
							PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
							_delay_ms(1500);
							PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
							
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
								PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
								_delay_ms(1500);
								PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
							
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
    /************************************************************************/
	/*                Kohat Enclave Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("  Kohat Enclave  ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<4);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("  Kohat Enclave    ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);
	
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear

    /************************************************************************/
	/*                NSP Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("      N.S.P      ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<5);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("      N.S.P        ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
   /************************************************************************/
	/*                Keshav Puram Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("  Keshav Puram   ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<6);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("   Keshav Puram    ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
					
										
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
      /************************************************************************/
	/*                Kanhaiya Nagar Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string(" Kanhaiya Nagar   ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTB&=~(1<<7);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("  Kanhaiya Nagar   ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						_delay_ms(1500);
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
   
      /************************************************************************/
	/*                Inder Lok Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("    Inder Lok    ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTC&=~(1<<4);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("    Inder Lok      ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);
	
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
						
	
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
   
         /************************************************************************/
	/*                Shastri Nagar Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("  Shastri Nagar  ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTC&=~(1<<5);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("  Shastri Nagar    ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 
		
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
							
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear

         /************************************************************************/
	/*                Partap Nagar Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("  Partap Nagar  ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTC&=~(1<<6);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("   Partap Nagar    ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
      /************************************************************************/
	/*                Pulbangash Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("   Pulbangash    ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);

PORTC&=~(1<<7);  // for led
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("    Pulbangash     ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
     /************************************************************************/
	/*                Tis Hazari Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("   Tis Hazari    ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("    Tis Hazari     ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
   
    /************************************************************************/
	/*                Kashmere Gate Station                                 */
	/************************************************************************/
	
PORTA|=	(1<<0);  //Port A pin 0 is high
PORTA&=	~(1<<1);  //Port A pin 1 is low
PORTA|=	(1<<2);  //Port A pin 2 is high
PORTA&=	~(1<<3);  //Port A pin 3 is low
_delay_ms(2000);
lcd_cmd(0x80);
lcd_string(" Next Station is ");
lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
lcd_string("  Kashmere Gate  ");
_delay_ms(8000);
lcd_cmd(0x01);    //lcd clear
PORTA=0x00;  //train stop
_delay_ms(2000);
	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("  Kashmere Gate    ");
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_string("  METRO Station    ");
	_delay_ms(3000);

	lcd_cmd(0x80);  // characters start from position 0 & row 1st
	lcd_string("  Kashmere Gate    ");
	
	lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
	lcd_cmd(0x1c);      // right shift 
	lcd_string("Train is Terminated Here");
	_delay_ms(6000);	
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
							
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is Open    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		_delay_ms(2000);
		PORTA|=	(1<<5)|(1<<6);  //Port A pin 4 & 7 is high
		PORTA&=	~(1<<4)|(1<<7);  //Port A pin 5 & 6 is low
		_delay_ms(3000);
		PORTA=0x00; //door open
		_delay_ms(4000);   //door open for 3sec
		
						PORTC&=~(1<<3);  //Port C pin 3 is low  & buzzer on
						_delay_ms(1500);
						PORTC|=(1<<3);     //Port C pin 3 is high & buzzer off
						
								
		lcd_cmd(0x80);  // characters start from position 0 & row 1st
		lcd_string("   Door is close    ");
		lcd_cmd(0xc0);      //  characters start from position 0 & row 2nd
		lcd_string("                   ");
		
	/*	PORTC|=(1<<3);     //Port C pin 3 is high
		_delay_ms(1000);
		PORTC&=~(1<<3);  //Port C pin 3 is low
		_delay_ms(500); */
	
		PORTA|=	(1<<4)|(1<<7);  //Port A pin 4 & 7 is high
		PORTA&=	~((1<<5)|(1<<6));  //Port A pin 5 & 6 is low
    _delay_ms(3000);
	
	PORTA=0x00;                //door close
	_delay_ms(1000);
   lcd_cmd(0x01);    //lcd clear
}
}