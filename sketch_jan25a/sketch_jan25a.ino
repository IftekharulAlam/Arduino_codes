#include <avr/io.h>
#include "avr_adc.h"
#include "avr_usart.h"
#include <util/delay.h>


int main(void)
{
  /* ADC Configuration and Init */
  ADC_ConfigData ADC_Data;
  ADC_Data.Prescaler = ADC_PRESCALER_128;
  ADC_Data.VoltageReference = ADC_VOLTAGE_REFERENCE_AVCC;
  ADC_Init(ADC_Data);
  
  /* USART Configuration and Init */
  USART_ConfigData USART_Data;
  USART_Data.BaudRate = 9600;
  USART_Data.DataBit = USART_DATA_BIT_EIGHT;
  USART_Data.ParityBit = USART_PARITY_BIT_NO;
  USART_Data.StopBit = USART_STOP_BIT_ONE;
  USART_Data.UsartMode = USART_MODE_ASYNCHRONOUS;
  USART_Init(USART_Data);
    
  /* Local Variables */
  uint16_t ADC_RawData = 0x0000;
  float ADC_Voltage = 0.0f;
  
    while (1) 
    {
    /* Read ADC Value at Pin PC0 (A0/ADC0) */
    ADC_RawData = ADC_ReadPin(ADC0);
    
    /* Convert the raw ADC value to Voltage */
    ADC_Voltage = (float)( ADC_RawData * 5 ) / 1023;
    
    /* Print the data in terminal */
    USART_TransmitString("\nVoltage at ADC0 Pin = ");
    USART_WaitTillTransmitFree();
    USART_TransmitFloat(ADC_Voltage,3);
    
    /* Wait for 500ms */
    _delay_ms(500);
    }
}
