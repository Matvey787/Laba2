#include <stdio.h>
#include "linear_equation.h"

double linear_equation (double *radioactivity, double *time, int N)
{
    double square_time_sum = 0;

    size_t time_i = 0;
    for (time_i = 0; time_i < N; time_i++)
    {
        square_time_sum += time[time_i] * time[time_i];
    }

    double time_mul_rad_sum = 0;
    size_t time_rad_i = 0;
    for (time_rad_i = 0; time_rad_i < N; time_rad_i++)
    {
        time_mul_rad_sum += time[time_rad_i] * (1 - radioactivity[time_rad_i]);
    }

    double decay_rate = square_time_sum / time_mul_rad_sum;
    return decay_rate;
}
