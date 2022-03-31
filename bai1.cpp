#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct Node{
    double stt;
    double x, y;
};

double KC_2diem(Node nodeX, Node nodeY){
    return sqrt((nodeX.x - nodeY.x) * (nodeX.x - nodeY.x) + (nodeX.y - nodeY.y) * (nodeX.y - nodeY.y));
}

int main(int argc, char *argv[]){
    string path = argv[1];
    int id = stoi(argv[2]);

    Node node;

    vector<Node> danhsach;
    Node max;
    Node min;
    Node nodeID;

    ifstream myFile(path);
    if(! myFile){
        cout << "File Error!";
        exit(0);
    }



    string line;
    getline(myFile, line);
    while (getline(myFile,line)){
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        node.stt = stod(token);

        getline(ss, token, ',');
        node.x = stod(token);

        getline(ss, token, ',');
        node.y = stod(token);

        if (id == node.stt){
            nodeID = node;
        }
        danhsach.push_back(node);
    }

    max = danhsach[0];
    min = danhsach[0];

    for (int i = 0; i < danhsach.size(); ++i){
        if (danhsach[i].stt == id) continue;

        if (KC_2diem(nodeID, danhsach[i]) > (KC_2diem(nodeID, max))){
            max = danhsach[i];
        }

        if (KC_2diem(nodeID, danhsach[i]) > (KC_2diem(nodeID, min))){
            min = danhsach[i];
        }

        ofstream ofs("./output1.txt");

        if (!ofs)
        {
            return 1;
        }

        ofs << "Diem gan nhat voi diem co id: " << id << endl;
        ofs << "ID = " << min.stt << endl;
        ofs << "x = " << min.x << endl;
        ofs << "y = " << min.y << endl;

        ofs << "Diem xa nhat voi diem co id: " << id << endl;
        ofs << "ID = " << max.stt << endl;
        ofs << "x = " << max.x << endl;
        ofs << "y = " << max.y << endl;

        myFile.close();
        ofs.close();

    }

    return 0;
}