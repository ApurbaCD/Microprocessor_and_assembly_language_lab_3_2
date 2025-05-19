#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000

#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)

#define GPIOC_CRH *(volatile unsigned int *) (GPIOC_BASE + 0x04)
#define GPIOC_BSRR *(volatile unsigned int *) (GPIOC_BASE + 0x10)

#define DELAY 500000

int main(){
	RCC_APB2ENR |=(1u << 4);

	GPIOC_CRH &= ~(0xF <<20);

	GPIOC_CRH |= (1u <<21);
	GPIOC_CRH &=~(1u <<20);
	GPIOC_CRH &=~(1u <<22);
	GPIOC_CRH &=~(1u <<23);


	while(1){
		GPIOC_BSRR|=(1u << 13);
		for(int i=0;i<DELAY;i++){}
		GPIOC_BSRR|=(1u << 29);
		for(int i=0;i<DELAY;i++){}
	}

}
