#include "radio_control.h"

controller_t controller_g;
extern SPI_HandleTypeDef hspi1;

void Radio_Control_Init()
{
    // Initialize controller
    controller_g.x = 0;
    controller_g.y = 0;
}

void Radio_Control_Task(void *pvParameters)
{

    (void)pvParameters;

    while (1)
    {
        // Update controller_g with new data

        // vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 second
    }
}

void CSN_Select()
{
    HAL_GPIO_WritePin(GPIO_PORT, CSN_PIN, GPIO_PIN_RESET);
}

void CSN_Deselect()
{
    HAL_GPIO_WritePin(GPIO_PORT, CSN_PIN, GPIO_PIN_SET);
}

void CE_Enable()
{
    HAL_GPIO_WritePin(GPIO_PORT, CE_PIN, GPIO_PIN_SET);
}

void CE_Disable()
{
    HAL_GPIO_WritePin(GPIO_PORT, CE_PIN, GPIO_PIN_RESET);
}

// uint8_t RF_Read_Registers(uint8_t reg, uint8_t *data, uint8_t size)
// {
//     CSN_Select();
//     HAL_SPI_Transmit(&hspi1, &reg, 1, 100);
//     HAL_SPI_Receive(&hspi1, data, size, 1000);
//     CSN_Deselect();
// }

// uint8_t RF_Write_Registers(uint8_t reg, uint8_t *data, uint8_t size)
// {
//     CSN_Select();
//     HAL_SPI_Transmit(&hspi1, &reg, 1, 100);
//     HAL_SPI_Transmit(&hspi1, data, size, 1000);
//     CSN_Deselect();
// }
