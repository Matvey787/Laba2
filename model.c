#include <math.h>


double model(double *radioactivity, double *time, int N, double point)
{
    double summary = 0;
    int i = 0;

    while (i < N) summary += time[i]*expf(-1*time[i]/point)*(radioactivity[i] - expf(-1*time[i++]/point));

    return summary;
}
