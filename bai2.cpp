#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]){
    string path = argv[1];
    int id = argc;

    double w,trongso;
    int diemi, diemj;

    ifstream myFile(path);
    if(! myFile){
        cout << "File Error!";
        exit(0);
    }

    string line;
    getline(myFile, line);
    while (getline(myFile,line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        diemi = stoi(token);

        getline(ss, token, ',');
        diemj = stoi(token);

        getline(ss, token, ',');
        trongso = stod(token);
    }
    if (trongso > w && diemi == id){
        cout << diemi << "->" << diemj << endl;
    }else{
        cout << "k co diem thoa man!" << endl;
    }

    return 0;
}