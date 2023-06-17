/* 
 * File:   application.c
 * Author: MOUSTAFA
 *
 * Created on June 14, 2023, 8:46 PM
 */

#include "aplication.h"

/*
 * 
 */
volatile uint8 u8ValueOfSeg=TIME_GREEN_LED;
volatile uint16 u16Counter=0;
volatile uint8 ValueOfSecond=0;
/*volatile uint8 u8LedGreenSeconds=TIME_GREEN_LED;//Initialize The Seconds Of The Green Led
volatile uint8 u8LedYellowSeconds=TIME_YELLOW_LED;//Initialize The Seconds Of The Yellow Led
volatile uint8 u8LedRedSeconds=TIME_RED_LED;//Initialize The Seconds Of The Red Led
*/
int main(void) {
    /************Initialization of The Modules Of The System*/
    led_initialize(&LedGreen);//Initialize Of The Led Green
    led_initialize(&LedYellow);//Initialize Of The Led Yellow
    led_initialize(&LedRed);//Initialize Of The Led Red
    Timer1_Init(&Timer1Obj);//Initialize Of The Timer1 Module
    seven_segment_initialize(&SegObj);//Initialize Of The Seven Segment
    led_turn_on(&LedGreen);//Put The Led On In The First Of the System
    led_turn_off(&LedYellow);//Put The Led Of The Yellow Off First 
    led_turn_off(&LedRed);//Put The Led Of The Red Off First 
    ADCON1bits.PCFG=0x0F;//Make The Pin Of The ADC Is All Digital
    while(1){//While Loop Will Work Forever 
        //To DisPlay The Value Every 20 Milli Seconds For Devision of Eye
        seven_segment_write_number(&SegObj,u8ValueOfSeg);//Show The Segment Value of The Seconds
      if(ValueOfSecond==TIME_GREEN_LED){//if Counter Is Equal To The Time Of Green Led 10 
        led_turn_off(&LedGreen);//Put The Green Led Off
        led_turn_off(&LedRed);//Put The Red Led Off          
        led_turn_on(&LedYellow);//Put The Yellow Led ON         
        u8ValueOfSeg=TIME_YELLOW_LED-TIME_GREEN_LED;        
        }
    if(ValueOfSecond==TIME_YELLOW_LED){//if Counter Is Equal To The Time Of Green Led (17 - 10) 
        led_turn_off(&LedGreen);//Put The Green Led Off
        led_turn_on(&LedRed);//Put The Red Led on          
        led_turn_off(&LedYellow);//Put The Yellow Led ON        
        u8ValueOfSeg=TIME_RED_LED-TIME_YELLOW_LED;        
    }
    if(ValueOfSecond==TIME_RED_LED){//if Counter Is Equal To The Time Of Green Led 10 
        led_turn_on(&LedGreen);//Put The Green Led on
        led_turn_off(&LedRed);//Put The Red Led Off          
        led_turn_off(&LedYellow);//Put The Yellow Led ON          
        u8ValueOfSeg=TIME_GREEN_LED;
        ValueOfSecond=0;//Reset The Value Of the SEconds 
    }
    }
    return (EXIT_SUCCESS);
}


/*Function That Call if The Interrupt Of Timer1 Is Generated*/
void Timer1InterruptHandler(void){//It Will Call Every 10 Milli Seconds
    u16Counter++;//Increment Counter Every 10 Milli Seconds
    if (u16Counter==100){//To Decrement The Value Of The Segment Every 1 second
        u8ValueOfSeg--;//Decrement The Value Of The Segment Every 1 Second
        ValueOfSecond++;//Increment Every 1 Second
        u16Counter=0;//Reset The Counter Value
    }
}