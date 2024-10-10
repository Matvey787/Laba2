#include <stdlib.h>

#include "add_noise.h"
void add_noise(double *radioctivity,int N)
{

double noise = 0;
for (int i=0;i<N;i++)
{
noise = (int)(((double)rand()*2/RAND_MAX -1)*100000);
radioctivity[i] += ((double)noise/100000)*0.05;
}
}
