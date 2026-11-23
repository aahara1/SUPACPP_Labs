#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include "CustomFunctions.h"


int main() {
std::string inputfile= "input2D_float.txt";
std::ifstream data_file;
data_file.open(inputfile);

std::vector<float> xVals;
std::vector<float> yVals;
std::vector<float> mag;

if (!data_file.is_open()) { // message for if the file doesnt open
    std::cout << "ERROR opening file: " << inputfile << std::endl;
    return -1;
}
else{ //message for file opening
std::cout << "File: " << inputfile << " opened successfully" << std::endl;
}

std::string line;
std::getline(data_file,line); // skipping the header
std::string x_str, y_str;
std::string printYN, magYN;

std::cout << "would you like to print out N lines of data y/n";
std::cin >> printYN;
std::cout << "would you like to print and store the magnitudes of the data points y/n";
std::cin >> magYN;

readInFile(data_file,xVals,yVals);

if (printYN == "y"){
    printOut(xVals,yVals);
}

if (magYN =="y"){
    magnitude(xVals,yVals,mag);
}

bestFit(xVals,yVals, "bestFit.txt" );
data_file.close();

}