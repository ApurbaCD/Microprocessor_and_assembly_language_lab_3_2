#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000
#define TIM2_BASE 0x40000000

#define RCC_APB2_ENR *(volatile unsigned int *)(RCC_BASE+0x18)
#define RCC_APB1_ENR *(volatile unsigned int *)(RCC_BASE+0x1C)


#define GPIOC_CRH *(volatile unsigned int *)(GPIOC_BASE+0x04)
#define GPIOC_ODR *(volatile unsigned int *)(GPIOC_BASE+0x0C)
#define GPIOC_BSRR *(volatile unsigned int *)(GPIOC_BASE+0x10)


#define TIM2_CR1 *(volatile unsigned int *)(TIM2_BASE+0x00)
#define TIM2_PSC *(volatile unsigned int *)(TIM2_BASE+0x28)
#define TIM2_ARR *(volatile unsigned int *)(TIM2_BASE+0x2C)
#define TIM2_SR *(volatile unsigned int *)(TIM2_BASE+0x10)



#define DELAY 10000

int main(){

	RCC_APB2_ENR |=(1u<<4);

	GPIOC_CRH &= ~(0xF<<20);
	GPIOC_CRH |= (1u <<21);
//	GPIOC_CRH &=~(1u <<20);
//	GPIOC_CRH &=~(1u <<22);
//	GPIOC_CRH &=~(1u <<23);

//	for TIM2 bus enable
	RCC_APB1_ENR |=(1u<<0);

//  for internal scaling in TIM2
//	t_time=f_input/(psc+1);
//	for t_time=1kHz,input is 8 MHz for HSI what will be the psc
//	psc is 7999

	TIM2_PSC=7999;
	TIM2_ARR=999;
	TIM2_CR1 |=(1u<<0);


	while(1){
		if(TIM2_SR &(1u<<0)){

			TIM2_SR &=~(1u<<0);

			GPIOC_ODR ^=(1u<<13);
		}
	}


}
