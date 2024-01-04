//estimation method
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#define CONFIDENCE_LEVEL 0.95  // Confidence level of 95%
#define DEGREE_OF_FREEDOM 10   // Sample size - 1

int main(void) {
  double sample_mean = 56.4;  // Sample mean
  double population_mean = 50;  // Population mean
  double population_stddev = 10;  // Population standard deviation

  // Calculate standard error of the mean
  double sem = population_stddev / sqrt(DEGREE_OF_FREEDOM + 1);

  // Calculate the critical value
  double t = tinv((CONFIDENCE_LEVEL + 1) / 2, DEGREE_OF_FREEDOM);

  // Calculate the margin of error
  double margin_of_error = t * sem;

  // Calculate the lower and upper bounds of the confidence interval
  double lower_bound = sample_mean - margin_of_error;
  double upper_bound = sample_mean + margin_of_error;

  printf("Confidence interval: (%.2f, %.2f)\n", lower_bound, upper_bound);

  return 0;
}
