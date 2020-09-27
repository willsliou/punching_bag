#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl; // flush


/*
Because javascript can't read from files well -__-
*/

int main() {
    fstream myFile;
    myFile.open("AccelOutut.txt");
    string inputTime;
    int x, y, z;
    cin >> inputTime >> x >> y >> z;

}