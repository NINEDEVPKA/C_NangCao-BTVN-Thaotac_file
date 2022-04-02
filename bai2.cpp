#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string path = argv[1];
    int id = stoi(argv[2]);
    double w = stod(argv[3]);

    double trongso;
    int diemi, diemj;


    ifstream myFile(path);
    if (!myFile) {
        cout << "File Error!";
        exit(0);
    }

    ofstream ofs("./output2.txt");
    ofs << "Cac diem thoa man voi id = " << id << " va co trong so lon hon " << w << " gom cac diem: " << endl;

    string line;
    getline(myFile, line);
    while (getline(myFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        diemi = stoi(token);

        getline(ss, token, ',');
        diemj = stoi(token);

        getline(ss, token, ',');
        trongso = stod(token);

        if ((id == diemi) && (trongso > w)) {
            ofs << diemi << "->" << diemj << endl;
        }
    }
    myFile.close();
    ofs.close();

    return 0;

}
