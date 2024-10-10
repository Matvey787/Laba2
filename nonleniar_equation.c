#include <stdio.h>
#include <math.h>

#include "nonleniar_equation.h"
#include "model.h"

double nonlinear_equation (double *radioactivity, double *time, int N, double precision)
{
    const double EPS = 0.e-12;

    double interval1 = 0, interval2 = 0;
    scanf("%lg %lg", &interval1, &interval2);

    double sr = 0;

    for (int i = 0; i < N; i++)
    {
        while(interval2 - interval1 > precision)
        {
            sr = (interval1 + interval2) / 2;

            double ans = model(radioactivity, time, N, sr);

            if (ans > EPS)
            {
                interval2 = sr;
            }

            if (ans < -EPS)
            {
                interval1 = sr;
            }
        }
    }

}




