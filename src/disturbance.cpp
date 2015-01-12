#include <tree2/disturbance.h>

#include <Rcpp.h>

namespace tree2 {

Disturbance::Disturbance(double mean_interval_)
  : shape(2.0),
    mean_interval(mean_interval_) {
  scale = pow(R::gammafn(1.0/shape)/shape/mean_interval, shape);
  p0 = shape*pow(scale, 1.0 / shape) / R::gammafn(1.0 / shape);
}

double Disturbance::density(double time) const {
  return p0 * pr_survival(time);
}

double Disturbance::r_mean_interval() const {
  return mean_interval;
}

// This is the probability that a patch survives from time 0 to time
// 'time'.
double Disturbance::pr_survival(double time) const {
  return exp(-scale * pow(time, shape));
}

// This is the conditional probability of surviving to 'time', given
// that we were alive at 'time_start'.  It was used in the original
// EBT implementation.
double Disturbance::pr_survival_conditional(double time,
                                            double time_start) const {
  return pr_survival(time) / pr_survival(time_start);
}

// Cumulative density function: this is the inverse of pr_survival
double Disturbance::cdf(double p) const {
  return pow(log(p) / -scale, 1/shape);
}

}
