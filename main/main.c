/* SPI Slave example, sender (uses SPI master driver)

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_timer.h"

#include "nfc4.h"

nfc4_t nfc4;

char *TAG = "LOGGER";

void application_init(void)
{
    /**< Click config object. */
    nfc4_cfg_t nfc4_cfg; 

    ESP_LOGI(TAG, " Application Init ");

    // Click initialization.
    nfc4_cfg_setup(&nfc4_cfg);

    esp_err_t init_flag = nfc4_init(&nfc4, &nfc4_cfg);
    ESP_LOGI(TAG, " Application Init Status: %d", init_flag);

    // NFC4_SET_DATA_SAMPLE_EDGE;

    if (NFC4_ERROR == nfc4_default_cfg(&nfc4))
    {
        ESP_LOGI(TAG, " Default Config Error. ");
        ESP_LOGI(TAG, " Please, run program again... ");
    }

    ESP_LOGI(TAG, " Application Task ");
}

// Main application
void app_main(void)
{
    application_init();
    while (1)
    {
    }
}
