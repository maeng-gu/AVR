#include <stdio.h>
#include <stm32f10x_lib.h>    // STM32F10x Library Definitions
#include "STM32_Init.h"       // STM32 Initialization


volatile unsigned long count=0;

int ledLight = 0;
int ledLight1 = 0;
int ledLight2 = 0;
int ledLight3 = 0;

 
 unsigned long c_micros;
 unsigned long p_micros;
 unsigned long p_micros1;
 
 int row_num = 0;
 
 int pwm_duty=10;
 int count_pwm;
 int i;
unsigned short reg_data = 0;
 int num[8] =   {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c};

void Delay(unsigned int nTime);
unsigned int TimingDealy;
   
   void Delay(unsigned int nTime) {
      TimingDealy = nTime;
      
      while(TimingDealy != 0);
   }
   
   void TimingDelay_Decrement(void) {
      if (TimingDealy != 0x00)
         TimingDealy --;
   }
	 
/*----------------------------------------------------------*\
 | HARDWARE DEFINE                                          |
\*----------------------------------------------------------*/
//#define LED             ( 1 << 5 )                // PB5: LED D2
#define LED             ( 1 << 6 )                // PB5: LED D2
#define LED1             ( 1 << 7 )                // PB5: LED D2
#define LED2             ( 1 << 8 )                // PB5: LED D2
/*----------------------------------------------------------*\
 | Timer1 Update Interrupt Handler                          |
\*----------------------------------------------------------*/
void TIM1_UP_IRQHandler (void) {

  if ((TIM1->SR & 0x0001) != 0) {                 // check interrupt source

	ledLight = ~ledLight;
	if( ledLight )
    	GPIOC->ODR &= ~(0x01 << 13);                           // switch on LED
	else
    	GPIOC->ODR |=  0x01 << 13;                           // switch off LED

//		
//		GPIOC->ODR |= 0x01 << 13; 
//		
    TIM1->SR &= ~(1<<0);                          // clear UIF flag
		

 }
} // end TIM1_UP_IRQHandler


void TIM1_CC_IRQHandler (void) {

  if ((TIM1->SR & 0x0002) != 0) {                 // check interrupt source

//	ledLight = ~ledLight;
//	if( ledLight )
    	GPIOC->ODR &= ~(0x01 << 13);                           // switch on LED
//	else
//    	GPIOB->ODR |=  LED;                           // switch off LED

    TIM1->SR &= ~(1<<1);                          // clear UIF flag
 }
} // end TIM1_UP_IRQHandler





/*----------------------------------------------------------*\
                        |
\*----------------------------------------------------------*/
void TIM2_IRQHandler (void) {
	

	
	
  if ((TIM2->SR & 0x0001) != 0) {                 // check interrupt source

//					count_pwm++;
//			
//			if(count_pwm == 100){
//				count_pwm = 0;
//				GPIOA->ODR = 0x20;
//			}
//			else if(count_pwm == pwm_duty){
//				GPIOA->ODR &= ~0x20;
//			}
//		
//	ledLight2 = ~ledLight2;
//	if( ledLight2 )
//    	GPIOA->ODR &= ~(0x01 << 5);                           // switch on LED
//	else
//    	GPIOA->ODR |=   (0x01 << 5);                          // switch off LED

    TIM2->SR &= ~(1<<0);                          // clear UIF flag
// }
	} // end TIM2_UP_IRQHandler
}

unsigned long micros_10us(){
	return count;
}

void delay_for()
{
	int i;
	for(i = 0 ; i < 12 ; i++) //1ms
	{}
	}
void SysTick_Handler(void)
 {

	 count++;
//		TimingDelay_Decrement();
// if(ledLight1 != ledLight1)
//	 
//	 //GPIOA 1밀리마다 토굴
//	 
//	 	ledLight1 = ~ledLight1;
//	if( ledLight1 )
//    	GPIOA->ODR &= ~0x20;                           // switch on LED
//	else
//    	GPIOA->ODR |=  0x20; 				
//	 
//	 #if 0
//	ledLight1 = ~ledLight1;
//	if( ledLight1 )
//    	GPIOB->ODR &= ~LED1;                           // switch on LED
//	else
//    	GPIOB->ODR |=  LED1; 				
//		
//	if(count++ == 1000){
//		count=0;
//		ledLight3 = ~ledLight3;
//		if( ledLight3 )
//	    	GPIOB->ODR &= ~(0x01 << 4);                           // switch on LED
//		else
//	    	GPIOB->ODR |=  (0x01 << 4); 
//	}
//			#endif
//		                          // switch off LED
 }

/*----------------------------------------------------------*\
 | MIAN ENTRY                                               |
\*----------------------------------------------------------*/

 unsigned long ii = 0;
 
int main (void) {
  stm32_Init ();                                // STM32 setup
	
		NVIC -> ICER[0] |= (0x01 << 25); // timer1 update interrupt clear
	RCC -> APB2ENR &= ~(0x01 << 11);

	
	RCC -> APB1ENR = 0x01;
	RCC -> APB2ENR |= 0x04; //PORTA clock enable
	
	GPIOA -> CRL &= ~(0xff << 5*4);	
	GPIOA -> CRL |= (0x03 << 5*4);	

//	
//	RCC -> APB2ENR |= 0x08; //PORTB clock enable
//	RCC-> APB2ENR |= 0x10; //PORtC clock enable
//	
//	GPIOB -> CRH = 0x33333333;	//colum : PB7 ~ PB15
//	GPIOC -> CRL = 0x33333333;	//ROW : PC0~PC7
	
//	GPIOC -> ODR = 0x00;
//	GPIOB -> ODR = 0xff00; 
	
	
//	GPIOA -> CRL = ~(0x0f << 20);
//	GPIOA -> CRL |= (0x03<<20);
//	
//	GPIOB -> ODR |= 0x20;

	//systick enable
//	SysTick -> LOAD = 720;//load값, 10 us interrupt
//	SysTick -> CTRL = 0x07;
	
	while(1)
	{
	//---------------------------------------------
	//SPI register setting
	TIM2 -> CR1 = 0x01;
	TIM2->DIER = 0x01;
	TIM2 -> PSC = 7200;
	TIM2 -> ARR = 10000;
	
	NVIC -> ISER[0] |= (0x01 << 28); //timer 2 update interrupt set

GPIOC -> CRL = 0xB4BB3333;
GPIOA -> CRL = 0xB0BB0B04;
RCC ->APB2ENR  = 0x501C;

SPI1 -> CR1 = 0x0B6C;
SPI1 -> CR2 = 0x00;

SPI1 -> DR = 0xaaaa;

//-------74595 latch enable-----------

GPIOC -> ODR = 0xff;
delay_for();
GPIOC -> ODR = 0x00;

for(ii = 0 ; ii < 300000 ; ii++)
{
	delay_for();
}

SPI1 -> DR = 0x5555;

//-------74595 latch enable-----------

GPIOC -> ODR = 0xff;
delay_for();
GPIOC -> ODR = 0x00;

for(ii = 0 ; ii < 300000 ; ii++)
{
	delay_for();
}
}

for(;;) {
		
//		c_micros = micros_10us();
//		if(c_micros - p_micros>10){
//			p_micros = c_micros;
//			//[1] all row off
//			GPIOB->ODR = 0x00;	//all row off
//			//[2]one colum value
//			for(i=0; i<8; i++){
//				if(!(num[row_num] & (0x80 >> i))){
//					reg_data |= 0x01 << i;
//				}
//			}
//			GPIOC -> ODR =  0x23;
//			//[3] one row off
//			GPIOB -> ODR = 0xff00 << row_num;
//			
//			//-----------------
//			//ROW NUMBER CHANGE
//			row_num++;
//			if(row_num == 100)
//			{
//				row_num=0;
//			}
			
//		}
		
                      
		
//		c_micros = micros_10us();
//		if(c_micros - p_micros>1000){
//			p_micros = c_micros;
//			
//			pwm_duty++;
//			
//			if(pwm_duty == 100){
//				pwm_duty = 1;
//			}
//		}
}
}
