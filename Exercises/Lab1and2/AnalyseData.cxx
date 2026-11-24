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
data_file.open(inputfile); // reading in the data file

std::string inputfile2 = "error2D_float.txt";
std::ifstream error_file;
error_file.open(inputfile2); // reading in the error on the data file

std::vector<float> xVals; // x vals themselves
std::vector<float> yVals; // y vals themselves
std::vector<float> xValsE; // error in the x vals
std::vector<float> yValsE; // error in the y vals
std::vector<float> mag;
std::vector<float> xTOy; // for x^y function

if (!data_file.is_open()) { // message for if the file doesnt open
    std::cout << "ERROR opening file: " << inputfile << std::endl;
    return -1;
}
else{ //message for file opening
std::cout << "File: " << inputfile << " opened successfully" << std::endl;
}

std::string line; // a variable that each line of the file can sit in temporarily
std::getline(data_file,line); // skipping the header of data file
std::getline(error_file,line); // skipping the header of error file

std::string x_str, y_str; // the strings to be added to each x and y list
std::string printYN, magYN, fitYN,powerYN; // variables to use when the user decides what to print out
float m,c, chi2DOF; // variables for the best fit later


readInFile(data_file,xVals,yVals);

readInFile(error_file,xValsE,yValsE);


std::cout << "would you like to print out N lines of data y/n";
std::cin >> printYN;

if (printYN == "y"){
    printOut(xVals,yVals);
}


std::cout << "would you like to calculate the magnitude of the data points and save it to a file y/n";
std::cin >> magYN;

if (magYN =="y"){
    magnitude(xVals,yVals,mag);
    printOut(mag);
    saveFile(mag,"magnitudeData.txt");
}




std::cout << "would you like to calculate the line of best fit and save it to a file y/n";
std::cin >> fitYN;

if (fitYN =="y"){
    bestFit(xVals,yVals, "bestFit.txt",m,c,yValsE, chi2DOF);
    printOut(m,c);
    saveFile(m,c,chi2DOF,"LineFitData.txt");
}

std::cout << "would you like to calculate the x^y and save it to a file y/n";
std::cin >> powerYN;

if (powerYN =="y"){
    xPOWERy(xVals,yVals,xTOy);
    printOut(xTOy);
    saveFile(xTOy,"powerData.txt");
}


data_file.close();

}