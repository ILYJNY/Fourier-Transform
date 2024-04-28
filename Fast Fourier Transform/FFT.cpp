#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#define lf long double
#define ulld unsigned long long int

using namespace std;

const lf PI = acos(-1);

void fft(vector<complex<lf>>& a, bool invert) {//true FFT, false IFFT
    ulld n = a.size();

    for (ulld i = 1, j = 0; i < n; ++i) {
        ulld bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (ulld len = 2; len <= n; len <<= 1) {
        lf ang = 2 * PI / len * (invert ? -1 : 1);
        complex<lf> wlen(cos(ang), sin(ang));
        for (ulld i = 0; i < n; i += len) {
            complex<lf> w(1);
            for (ulld j = 0; j < len / 2; ++j) {
                complex<lf> u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (complex<lf>& x : a)
            x /= n;
    }
}