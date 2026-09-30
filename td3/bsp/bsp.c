#include "bsp.h"
#include "main.h"


static volatile bool sw1_pressed = false;
static volatile bool sw2_pressed = false;

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{

	if (pin == BTN_SW1_Pin)
	{
		sw1_pressed = true;
	}
	if (pin == BTN_SW2_Pin)
	{
		sw2_pressed = true;
	}
}

void bsp_led_set(uint8_t led, bool on)
{

	GPIO_PinState state = on ? GPIO_PIN_SET : GPIO_PIN_RESET;
	switch (led)
	{
	case 0: HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, state);
	case 1: HAL_GPIO_WritePin(LED1_GPIO_Port, LED2_Pin, state);
	case 2: HAL_GPIO_WritePin(LED1_GPIO_Port, LED3_Pin, state);
	break;

	}
}
bool bsp_sw1_pressed(void) {
	bool pressed = sw1_pressed;
	sw1_pressed = false;
	return pressed;
}
