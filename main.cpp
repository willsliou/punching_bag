#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using std::cin;
using std::cout;
using std::endl; // flush


/*
Because javascript can't read from files well -__-
*/

int main() {
    // Create object file
    std::fstream myFile;
    // Open object file
    myFile.open("Accer_0.1_Left_Side_X_Away_2.txt");
    // Declare variables
    std::string inputLime;
    int x, y, z;
    // Skip first line
    std::string dummyLine;
    std::getline(myFile, dummyLine);

    int timeHour, timeMin, timeSec, xx, yy, zz;
    int myMaxX = -1, myMaxY= -1, myMaxZ = -1;
    // Begin reading stream
    myFile >> timeHour >> timeMin >> timeSec >> xx >> yy >> zz;
    cout << timeHour << ":" << timeMin << ":"<< timeSec << endl;
    cout << xx << endl;
    cout << yy << endl;
    cout << zz << endl;
    // while (myFile >> time >> x >> y >> z) {

    //     if (myMaxX < x) { myMaxX = x;}
    //     if (myMaxY < y) { myMaxY = y;}
    //     if (myMaxZ < z) { myMaxZ = z;}
    // }

    cout << myMaxZ;
    cout << "Program is ending.";
}