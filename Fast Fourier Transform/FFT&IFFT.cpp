#include "cmath"
#include "complex"
#include "vector"
#include "iostream"
#define lf long double
#define ulld unsigned long long int
#define lld long long int
#define clf std::complex<long double>
#include "../vector_matrix_cals/vector_matrix_cals.cpp"
#define MATRIX_LF std::vector<std::vector<long double>>
#define VECTOR_LF std::vector<long double>
#define MATRIX_CLF std::vector<std::vector<std::complex<long double>>>
#define VECTOR_CLF std::vector<std::complex<long double>>


using namespace std;


VECTOR_CLF FFT(VECTOR_CLF x, ulld N) {
    clf for_result(0,0);
    VECTOR_CLF result;
    for (ulld k = 0;k<=N-1;k++) {
        for (ulld m = 0; m <= N - 1; m++) {
            for_result += x[m] * exp(clf(0, -2 * M_PI * m * k / N));
        }
        result.push_back((lf) (1/N) * for_result);
    }
    return result;
}

VECTOR_CLF IFFT(VECTOR_CLF X, ulld N) {
    clf for_result(0,0);
    VECTOR_CLF result;
    for (ulld k = 0;k<=N-1;k++) {
        for (ulld m = 0; m <= N - 1; m++) {
            for_result += X[m] * exp(clf(0, 2 * M_PI * m * k / N));
        }
        result.push_back((lf) (1/N) * for_result);
    }
    return result;
}