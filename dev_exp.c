#include <stdio.h>
#include <math.h>

#include "dev_exp.h"

double dev_exp(double *radioactivity, double *time, int M, double interval_left, double interval_right, double decay_time)
{
    int i;
    double sum_residuals1 = 0;
    for (i = 0; i < M; i++)
    {
        sum_residuals1 += (radioactivity[i] - exp(-time[i] / decay_time));
    }
    double deviation1 = sqrt(sum_residuals1) / M;
    return deviation1;
}
