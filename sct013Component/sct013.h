#ifndef SCT013_SENSOR_H
#define SCT013_SENSOR_H
#define ADC_BITS    12
#define ADC_COUNTS  (1<<ADC_BITS)

void convert_Read_Value_To_Ampere(double *reading, double value);
le_result_t calculaMedia(int valores[], double *reading);
double map(double x, double in_min, double in_max, double out_min, double out_max);
le_result_t mangOH_ReadGps(
    double *latitude,     ///< WGS84 Latitude in degrees, positive North [resolution 1e-6].
    double *longitude,    ///< WGS84 Longitude in degrees, positive East [resolution 1e-6].
    double *hAccuracy,    ///< Horizontal position's accuracy in meters.
    double *altitude,     ///< Altitude in meters, above Mean Sea Level.
    double *vAccuracy     ///< Vertical position's accuracy in meters.
);

#endif //SCT013_SENSOR_H
