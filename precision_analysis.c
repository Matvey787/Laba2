#include <stdio.h>
#include "precision_analysis.h"
#include "linear_equation.h"

double precision_analysis (double *radioactivity, double *time, int N)
{
    size_t i = 10;
    double decay_rate = linear_equation(radioactivity, time, i);
    double decay_time = nonlinear_equation(radioactivity, time, i, precision);
    double Dev_exp = dev_exp(radioactivity, time, i, decay_time);
    double Dev_linear = dev_linear(radioactivity, time, i, decay_rate);
    for (i = 10; i < N && Dev_linear / Dev_exp > 2; i++)
    {
        decay_rate = linear_equation(radioactivity, time, i + 1);
        decay_time = nonlinear_equation(radioactivity, time, i + 1, precision);

        Dev_exp = dev_exp(radioactivity, time, i, decay_time);
        Dev_linear = dev_linear(radioactivity, time, i, decay_rate);
    }
    return i;
}
