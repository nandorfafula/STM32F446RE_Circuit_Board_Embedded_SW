#include "ComplementaryFilter.h"

#define ACCELEROMETER_SENSITIVITY 8192.0
#define GYROSCOPE_SENSITIVITY 1000

//#define M_PI 3.14159265359

void ComplementaryFilter(float accData[3], float gyrData[3], float *pitch, float dt)
{
    float pitchAcc;

    // Integrate the gyroscope data -> int(angularSpeed) = angle
    if(gyrData[0] < 3000){
    	return;
    }
    *pitch += (gyrData[0] / GYROSCOPE_SENSITIVITY) * dt; // Angle around the X-axis

    // Compensate for drift with accelerometer data if !bullshit
    // Sensitivity = -2 to 2 G at 16Bit -> 2G = 32768 && 0.5G = 8192
    int forceMagnitudeApprox = abs(accData[0]) + abs(accData[1]) + abs(accData[2]);
    if (forceMagnitudeApprox > ACCELEROMETER_SENSITIVITY && forceMagnitudeApprox < 32768)
    {
	// Turning around the X axis results in a vector on the Y-axis
        pitchAcc = atan2f(accData[1], accData[2]) * 180 / M_PI;
        *pitch = *pitch * 0.98 + pitchAcc * 0.02;
    }
}
