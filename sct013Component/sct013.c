/**
 * @file
 *
 * This app reads the current adc reading every 1 seconds
 *
 * <HR>
 *
 */
#include <math.h>
#include "legato.h"
#include "interfaces.h"
#include "sct013.h"

//--------------------------------------------------------------------------------------------------
/**
 * The time between publishing ADC lectures
 *
 * @note Please change this timeout value as needed.
 */
//--------------------------------------------------------------------------------------------------
#define ADC_SAMPLE_INTERVAL_IN_MILLISECONDS (1000)

//--------------------------------------------------------------------------------------------------
/**
 * Timer handler  will publish the current ADC reading.
 */
//--------------------------------------------------------------------------------------------------
static void adcTimer
(
    le_timer_Ref_t adcTimerRef
)
{
    double value;

    int32_t valores[100]; 

	int i;

	for(i = 0; i < 100; i++){

		le_adc_ReadValue("EXT_ADC2", &valores[i]);

	}

	
	const le_result_t result = calculaMedia(valores,&value);

    if (result == LE_OK)
    {
        LE_INFO("Current value is: %lf", value);
    }
    else
    {
        LE_INFO("Couldn't get ADC value");
    }
}


le_result_t calculaMedia(int32_t valores[], double *reading){

	int i;

	double min = 1800;

	double max = 0;

	double valeMinimo;

	double picoMaximo;

	for(i = 0; i < 100; i++){

		if(valores[i] > max)
			max = valores[i];
		else if(valores[i] < min)
			min = valores[i];
	}

	LE_INFO("Minimo = %lf",min);
	LE_INFO("Maximo = %lf",max);

	valeMinimo = abs(911 - min);
	picoMaximo = abs(max - 911);

	LE_INFO("valeMinimo = %lf", valeMinimo);
	LE_INFO("picoMaximo = %lf", picoMaximo);

	if(valeMinimo > picoMaximo){

		convert_Read_Value_To_Ampere(reading, valeMinimo);

	}else if(picoMaximo > valeMinimo){

		convert_Read_Value_To_Ampere(reading, picoMaximo);

	}else{

		convert_Read_Value_To_Ampere(reading, picoMaximo);
	}

	return LE_OK;
	
}

void convert_Read_Value_To_Ampere(double *reading, double value){

	*reading = map(value, 0, 911, 0, 20);
	
}

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



//--------------------------------------------------------------------------------------------------
/**
 * Main program starts here
 */
//--------------------------------------------------------------------------------------------------
COMPONENT_INIT
{
    LE_INFO("---------------------- ADC Reading started");

    le_timer_Ref_t adcTimerRef = le_timer_Create("ADC Timer");
    le_timer_SetMsInterval(adcTimerRef, ADC_SAMPLE_INTERVAL_IN_MILLISECONDS);
    le_timer_SetRepeat(adcTimerRef, 0);

    le_timer_SetHandler(adcTimerRef, adcTimer);

    le_timer_Start(adcTimerRef);
}
