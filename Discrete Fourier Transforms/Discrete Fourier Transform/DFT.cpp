#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#define lf long double
#define ulld unsigned long long int


using namespace std;

complex<lf> polar(lf r, lf seta) {
    return {r * cos(seta),r * sin(seta)};
}



vector<complex<lf>> DFT(vector<complex<lf>> input) {
    ulld n = input.size();
    vector<complex<lf>> result(n);
    for (ulld k = 0; k < n; k++) {
        complex<lf> sum(0, 0);
        for (ulld t = 0; t < n; t++) {
            lf angle = 2 * M_PI * t * k / n;
            sum += input[t] * polar(1.0, -angle);
        }
        result[k] = sum;
    }
    return result;
}
