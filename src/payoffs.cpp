#include "payoffs.hpp"

//  payoff function for european put option.
double EuropeanPutPayoff(double strikePrice, double stockPrice) {
  double payoff = strikePrice - stockPrice;
  if (payoff > 0.0) {
    return payoff;
  } else {
    return 0.0;
  }
}

//  payoff function for european call option.
double EuropeanCallPayoff(double strikePrice, double stockPrice) {
  double payoff = stockPrice - strikePrice;
  if (payoff > 0.0) {
    return payoff;
  } else {
    return 0.0;
  }
}
