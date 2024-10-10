#include <stdio.h>
#include <math.h>

#include "dev_linear.h"

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    int i;
    double sum_residuals2 = 0;
    for (i = 0; i < M; i++)
    {
        sum_residuals2 += (radioactivity[i] - pow((1 - (time[i] / decay_rate)), 2));
    }
    double deviation2 = sqrt(sum_residuals2) / M;
    return deviation2;
}

