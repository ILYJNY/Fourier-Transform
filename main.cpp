#include "Discrete Fourier Transform/Discrete Fourier Transform/main.cpp"







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
            break;

        }

        else {
            if (todo_list == "DFT") {
                DFT_main();
            }
        }
    }
}