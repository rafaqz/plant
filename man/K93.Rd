% Generated by roxygen2: do not edit by hand
% Please edit documentation in r/k93.R
\name{K93_Individual}
\alias{K93_Individual}
\alias{lcp_whole_plant.Individual<K93>}
\alias{K93_Cohort}
\alias{K93_Species}
\alias{K93_Parameters}
\alias{K93_Patch}
\alias{K93_SCM}
\alias{K93_StochasticSpecies}
\alias{K93_StochasticPatch}
\alias{K93_StochasticPatchRunner}
\title{Create a K93 Individual or Cohort}
\usage{
K93_Individual(s = K93_Strategy())

\method{lcp_whole_plant}{`Individual<K93>`}(p, ...)

K93_Cohort(s = K93_Strategy())

K93_Species(s = K93_Strategy())

K93_Parameters()

K93_Patch(p)

K93_SCM(p)

K93_StochasticSpecies(s = K93_Strategy())

K93_StochasticPatch(p)

K93_StochasticPatchRunner(p)
}
\arguments{
\item{s}{A \code{\link{K93_Strategy}} object}

\item{p}{A \code{Parameters<K93,K93_Env>} object}

\item{...}{Arguments!}
}
\description{
Create a K93 Individual or Cohort
}
\examples{
pl <- K93_Individual()
pl$height
}
