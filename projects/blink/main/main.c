#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_INTERVAL    400

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true)
    {
        gpio_set_level(GPIO_NUM_4, level);
        level = !level;
        vTaskDelay(BLINK_INTERVAL / portTICK_PERIOD_MS);
    }
}
