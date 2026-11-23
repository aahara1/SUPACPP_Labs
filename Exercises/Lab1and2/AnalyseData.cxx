#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>


int main() {
std::string inputfile= "input2D_float.txt";
std::ifstream data_file;
data_file.open(inputfile);
std::vector<float> xVals;
std::vector<float> yVals;

if (!data_file.is_open()) {
    std::cout << "ERROR opening file: " << inputfile << std::endl;
    return -1;
}
else{
std::cout << "File: " << inputfile << " opened successfully" << std::endl;
}

std::string line;
std::getline(data_file,line); // skipping the header
std::string x_str, y_str;

while ((std::getline(data_file,x_str,',')) && std::getline(data_file,y_str)){

        xVals.push_back(std::stof(x_str));
        yVals.push_back(std::stof(y_str));
}

for(int i=0; i<xVals.size();i++ ){
    std::cout << xVals[i] << "," << yVals[i] << std::endl;
}

data_file.close();

}