#include "WareHouse.h"
#include <iostream>
#include <fstream>

using std:: string;
#include <sstream>

using namespace std;

WareHouse* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        std::cout << "usage: warehouse <config_path>" << std::endl;
        return 0;
    }
    string configurationFile = argv[1];
    cout << configurationFile<< endl;
    cout << "Line 19"<< endl;
    WareHouse wareHouse(configurationFile);
    cout << "Line 21"<< endl;
    wareHouse.start();
    // if(backup!=nullptr){
    // 	delete backup;
    // 	backup = nullptr;
    // }
    return 0;
}

