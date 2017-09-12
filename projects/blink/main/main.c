/**
 * @file main.c
 * @brief Toggles an output pin at a regular interval.
 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_INTERVAL    400

void app_main(void)
{
	bool pinLevel = true;
	gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    while (true)
    {
        gpio_set_level(GPIO_NUM_4, pinLevel);
        pinLevel = !pinLevel;
        vTaskDelay(BLINK_INTERVAL / portTICK_PERIOD_MS);
    }
}
