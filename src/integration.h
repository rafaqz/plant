// -*-c++-*-
#ifndef TREE_INTEGRATION_H_
#define TREE_INTEGRATION_H_

#include <Rcpp.h>
#include <list>

#include "functor.h"
#include "quadrature.h"
#include "integration_workspace.h"

namespace integration {

// This is the "QAG" algorithm from QUADPACK -- quadrature, adaptive,
// Gaussian.  Does not handle infinite intervals or singularities.
//
// The second constructor (size_t) will make a non-adaptive integrator
// that uses the given rule.  This may broaden soon to allow evenly
// spaced points via the trapezium rule, etc.
class QAG {
public:
  QAG(size_t rule, size_t max_iterations, double atol, double rtol);
  QAG(size_t rule);
  double integrate(util::DFunctor *f, double a, double b);
  double integrate_with_intervals(util::DFunctor *f,
				  intervals_type intervals);

  double get_last_area()       const {return area;}
  double get_last_error()      const {return error;}
  size_t get_last_iterations() const {return iteration;}
  intervals_type get_last_intervals() const;

  bool is_adaptive() const {return adaptive;}

  // * R interface
  double r_integrate(util::RFunctionWrapper fun, double a, double b);
  double r_integrate_with_intervals(util::RFunctionWrapper fun,
				    Rcpp::List intervals);
  Rcpp::List r_get_last_intervals() const;

private:
  double integrate_adaptive(util::DFunctor *f, double a, double b);
  double integrate_fixed(util::DFunctor *f, double a, double b);
  internal::workspace::point do_integrate(util::DFunctor *f,
					  double a, double b);
  bool initialise(util::DFunctor *f, double a, double b);
  bool refine(util::DFunctor *f);
  static bool subinterval_too_small(double a1, double mid, double b2);

  bool adaptive;

  QK q;
  internal::workspace w;

  // Control parameters
  size_t limit;
  double epsabs;
  double epsrel;

  // Intermediates
  double area, error;
  size_t iteration;
  size_t roundoff_type1, roundoff_type2;
};

}

#endif
