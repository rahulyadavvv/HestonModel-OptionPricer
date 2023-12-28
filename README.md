# Heston model pricer

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

The pricer is run as follows:
```bash
./Pricer \
-t 0 \
-T 1 \
-N 1000 \
-M 1000 \
-Xt 100 \
-Vt 0.04 \
-K 100 \
-r 0.05 \
--kappa 1.2 \
--theta 0.04 \
--sigma 0.3 \
--rho -0.5
```
- t - start time 
- T - end time
- N - number of steps per simulation
- M - number of simulations
- Xt - initial price
- Vt - initial vol
- K - strike price
- r - rate
- kappa - mean reversion rate
- theta - long-run variance
- sigma - vol of vol
- rho - correlation of processes
