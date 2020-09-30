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
    char eatColons; // Pacman
    int timeHour, timeMin, timeSec, xx, yy, zz;
    int myMaxX = -1, myMaxY= -1, myMaxZ = -1;
    
    // Skip first line in the file
    std::string dummyLine;
    std::getline(myFile, dummyLine);
    
    // Begin reading stream
    myFile >> timeHour >> eatColons >> timeMin >> eatColons >> timeSec;
    cout << timeHour << ":" << timeMin << ":"<< timeSec << endl;

    // Begin loop to find maximum
    while (myFile >> x >> y >> z) {
        // Change negatives to positives
        x = abs(x);
        y = abs(y);
        z = abs(z);
        // Take out first column
        myFile >> timeHour >> eatColons >> timeMin >> eatColons >> timeSec;
        // Change our max if max is greater.
        if (myMaxX < x) { myMaxX = x;}
        if (myMaxY < y) { myMaxY = y;}
        if (myMaxZ < z) { myMaxZ = z;}
    }

    // Display maximums
    cout << myMaxX << endl;
    cout << myMaxY << endl;
    cout << myMaxZ << endl;
    cout << "Program is ending.";
}
