#include "stm32f4xx.h"                  // Device header
int main(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef gpioA_init_input;
	gpioA_init_input.GPIO_Pin=GPIO_Pin_0;
	gpioA_init_input.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitTypeDef gpioinit;
	gpioinit.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	gpioinit.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Init(GPIOD,&gpioinit);
	GPIO_Init(GPIOA,&gpioA_init_input);
	while(1){
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
			GPIO_SetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			for(int i =0;i<=9000000;i++){}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			for(int i =0;i<=9000000;i++){}
		}
	}
}
