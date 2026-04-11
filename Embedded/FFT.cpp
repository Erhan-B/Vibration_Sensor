#include "FFT.h"

FFT::FFT() {

}

/*
    Convert adcValue (output from esp32) to measured voltage then calculate gForce
*/
float FFT::calcGForce(int adcValue) {
    /*
        4095.0: esp32 adc upper limit
        Formula: voltage = (adcValue / adc upper limit) * esp32Voltage
    */
    float voltage = (adcValue/ 4095.0) * esp32Voltage;

    /*
        0.040: sensitivity of ADXL1002 (40V/g)
        esp32Voltage / 2.0: Theoretical zero-g bias
        Formula: gForce = (Measured voltage - ratiometric zero point)/sensitivity
    */
    float gForce = (voltage - esp32Voltage / 2.0) / 0.040;

    return gForce;
}


