#include <stdio.h>
#include <stdlib.h>

#include "experiment.h"
#include "add_noise.h"
#include "nonleniar_equation.h"
#include "linear_equation.h"
#include "precision_analysis.h"

int main()
{
    double start_time = 0;
    double end_time = 9.9;
    double step = 0.1;
    double precision = 0.0001;
    double radioactivity[100] = {0};
    double time[100] = {0};

    int n = experiment(radioactivity, time, start_time, end_time, step);

    add_noise(radioactivity, n);

    double decay_time = nonlinear_equation(radioactivity, time, n, precision);

    double decay_rate = linear_equation(radioactivity, time, n);

    double time_differences = precision_analysis(radioactivity, time, n, precision);

    printf("decay_time = %lf\n", decay_time);
    printf("decay_rate = %lf\n", decay_rate);
    printf("time_differences = %lf\n", time_differences);
    return 0;
}
