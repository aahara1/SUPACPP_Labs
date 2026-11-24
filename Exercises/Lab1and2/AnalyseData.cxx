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


int choice;
bool Running;

Running = true;
while (Running){
    std::cout << "select an option on what to do." << std::endl;
    std::cout << "1. Print out N lines of data." << std::endl;
    std::cout << "2. Calculate the magnitude of each data point." << std::endl;
    std::cout << "3. Find the line of best fit and the chi squared/NDoF of the data." << std::endl;
    std::cout << "4. Find x^y for each data point." << std::endl;
    std::cout <<"5. Exit" <<std::endl;
    std::cin >> choice;

    if (choice == 1){
        printOut(xVals,yVals);
    }

    if (choice == 2){
        magnitude(xVals,yVals,mag);
        printOut(mag);
        saveFile(mag,"magnitudeData.txt");
    }

    if (choice == 3){
        bestFit(xVals,yVals, "bestFit.txt",m,c,yValsE, chi2DOF);
        printOut(m,c);
        saveFile(m,c,chi2DOF,"LineFitData.txt");
    }

    if (choice == 4){
        xPOWERy(xVals,yVals,xTOy);
        printOut(xTOy);
        saveFile(xTOy,"powerData.txt");
    }

    if (choice == 5){
        Running = false;
    }
}





data_file.close();

}