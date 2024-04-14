//
// Created by Backup on 2024-04-14.
//

#include "main.h"
#define Lf long double
#define ulld unsigned long long int



using namespace std;


complex<Lf> expi_euler(complex<Lf> x) {
    complex<Lf> real_part(cos(x));
    complex<Lf> imag_part(sin(x));
    complex<Lf> result = real_part + imag_part;
    return result;
}


complex<Lf> sigma_in_DFT_1(ulld N, Lf k, vector<complex<Lf>> xlist) {
    complex<Lf> result_sum;
    for (ulld j=0;j<=N-1;j++) {
        result_sum += xlist[j] * expi_euler((2*M_PI*j*k)/N);
    }
    return result_sum;
}


int DFT_main() {
    vector<complex<Lf>> x_y_complex;
    bool able_to_open_file;
    string file_location;
    string textfile;
    cout << "Give the Location of File : ";
    cin >> file_location;
    ifstream info_file(file_location);
    vector<string> cuttedwithlinefile;
    vector<Lf> x_list;
    vector<Lf> y_list;
    if (info_file.is_open()) {
        string line;
        while (getline(info_file, line)) {
            cuttedwithlinefile.push_back(line);
        }
        able_to_open_file = true;
    }
    else {
        cout << "unable to open the file. Please try again";
        able_to_open_file = false;
    }

    if (able_to_open_file = true) {
        for (const auto & i : cuttedwithlinefile) {
            stringstream ss(i);
            Lf x_val, y_val;
            ss >> x_val >> y_val;
            x_list.push_back(x_val);
            y_list.push_back(y_val);
        }
    }
    else {
        cout << "unable to excess. try again";
        return 0;
    }
    //transform to complex
    for (int i=0;i<cuttedwithlinefile.size();i++) {
        complex<Lf> make_result_complex(x_list[i], y_list[i]);
        x_y_complex.push_back(make_result_complex);
    }
    //end
    vector<complex<Lf>> f_lists;
    Lf k = -1.8 * pow(10, 308);
    while (k<=1.8 * pow(10, 308)) {
        ulld N = x_y_complex.size();
        complex<Lf> trash_N_sqrt(1 / sqrt(N));
        complex<Lf> Y_K_result = trash_N_sqrt * sigma_in_DFT_1(N, k, x_y_complex);
        f_lists.push_back(Y_K_result);
        k+=0.00001;
    }
    //푸리에변환 리스트 변환까지됨------



};


