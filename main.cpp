#include "Discrete Fourier Transforms/Discrete Fourier Transform/main.cpp"
#include "main.h"
#include "sstream"
#include "Fast Fourier Transform/FFT.cpp"
#include "Discrete Fourier Transforms/Discrete Fourier Transform/DFT.cpp"
#define lf long double



    int main() {
    while (true) {
        string todo_list;
        cout << R"(What will You do?(type "/?" or "help" to see the lists of programs) : )";
        cin >> todo_list;
        vector<string> programs_list;
        if (todo_list == "/?" || todo_list == "help") {
            string line;
            ifstream file("../programs_list.txt"); // example.txt 파일을 연다. 없으면 생성.
            if(file.is_open()){
                cout << "-----------------------------\n";
                while(getline(file, line)) {
                    cout << line << endl;
                    programs_list.push_back(line);
                }
                cout << "-----------------------------\n";
                file.close(); // 열었떤 파일을 닫는다.
            } else {
                cout << "Unable to open \n";
            }
        }
        else if (todo_list == "STOP PROGRAM") {
            return 0;

        }

        else {
            vector<string> stringdatas;
            vector<complex<lf>> datas;
            string file_location;
            cout << "give the Location of File";
            cin >> file_location;
            string line;
            ifstream file(file_location); // example.txt 파일을 연다. 없으면 생성.
            if(file.is_open()){
                cout << "-----------------------------\n";
                while(getline(file, line)) {
                    stringdatas.push_back(line);
                }
                cout << "-----------------------------\n";
                file.close(); // 열었떤 파일을 닫는다.
            } else {
                cout << "Unable to open \n";
            }

            //string -> complex
            for (auto & stringdata : stringdatas) {
                stringdata;
                std::istringstream iss(stringdata);
                double real, imag;
                iss >> real >> imag;
                datas.emplace_back(real, imag);


            }


            if (todo_list == "DFT") {
                vector<complex<lf>> result_DFT = DFT(datas);
            }
            if (todo_list == "FFT") {
                string answer;
                cout << "invert or forward?" << endl;
                cin >> answer;
                if (answer == "invert")
                    fft(datas, true);

                else {
                    fft(datas, false);
                }
            }

        }
    }
}