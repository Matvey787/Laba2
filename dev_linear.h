#ifndef DEVS_H
#define DEVS_H

double dev_exp(double *radioactivity, double *time, int M, double interval_left, double interval_right, double decay_time);
double dev_linear(double *radioactivity, double *time, int M, double decay_rate);

#endif
