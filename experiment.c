#include <stdio.h>
#include <math.h>

static int is_equal (double, double);


int experiment (double *radioactivity, double *time, double start_time, double end_time, double step)
{
    int N = 1;
    int R = 1;
    int i = 0;
    const double betta = 3.5;
    time[0] = start_time;
    for(i = 1; is_equal(time[i - 1], end_time) != 1; i++, N++)
    {
        time[i] = time[i - 1] + step;
        if (time[i] > end_time)
        {
            time[i] = end_time;
            break;
        }
    }
    for(i = 0; i < N; i++)
    {
        radioactivity[i] = R * exp(-time[i]/betta);
    }
    return N;
}

static int is_equal(double a, double b)
{
    if (fabs(a - b) < 0.01)
    {
        return 1;
    }
    return 0;

}
