/* 
 * File:   aplication.h
 * Author: MOUSTAFA
 *
 * Created on June 14, 2023, 8:46 PM
 */

#ifndef APLICATION_H
#define	APLICATION_H

/* Section Includes*/
#include "MCAL_Layer/GPIO/hal_gpio.h"
#include "MCAL_Layer/TIMER1/hal_timer1.h"
#include "MCAL_Layer/Delay/M_Delay.h"
#include "ECU_Layer/7_seg/ecu_segment.h"
#include "ECU_Layer/led/ecu_led.h"

/* Section : Macros Declarations  */
#define ZERO_INIT 0
#define TIME_GREEN_LED   9
#define TIME_YELLOW_LED  14
#define TIME_RED_LED     21
/* Section : macros Function Declarations */
void Timer1InterruptHandler(void);//Decleration Of Timer1 Interrupt Function 
/* Data types Declarations */
/*Structure For The Green Led */
led_t LedGreen={.port=PORTD_INDEX,.pin=GPIO_PIN0,.status=LED_OFF};
/*Structure For The Green Led */
led_t LedYellow={.port=PORTD_INDEX,.pin=GPIO_PIN1,.status=LED_OFF};
/*Structure For The Green Led */
led_t LedRed={.port=PORTD_INDEX,.pin=GPIO_PIN2,.status=LED_OFF};

/*Definition Structure Of Timer1 Module */
timer1_config_t Timer1Obj={.TIMER1_HandlerInterrupt=Timer1InterruptHandler,.preloaded_value=45536,
                           .timer1_mode_timer_or_counter=TIMER1_TIMER_MODE_CFG,
                           .timer1_mode_wr_reg=TIMER1_16BIT_MODE_CFG,
                           .timer1_pre_scaler_val=TIMER1_INPUT_CLK_PRESCALER_DIV_1,
                           .timer1_oscillator_enable=TIMER1_OSCILLATOR_DISABLE_CFG};
/* Definition Of The Seven Segment Structure */
segment_t SegObj={.segment_pin[0].port=PORTB_INDEX,.segment_pin[0].pin=GPIO_PIN0,.segment_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                  .segment_pin[1].port=PORTB_INDEX,.segment_pin[1].pin=GPIO_PIN1,.segment_pin[1].direction=GPIO_DIRECTION_OUTPUT,
                  .segment_pin[2].port=PORTB_INDEX,.segment_pin[2].pin=GPIO_PIN2,.segment_pin[2].direction=GPIO_DIRECTION_OUTPUT,
                  .segment_pin[3].port=PORTB_INDEX,.segment_pin[3].pin=GPIO_PIN3,.segment_pin[3].direction=GPIO_DIRECTION_OUTPUT,
                  .segment_status=SEGMENT_COMMON_CATHODE};
/* Function Declarations*/

#endif	/* APLICATION_H */

