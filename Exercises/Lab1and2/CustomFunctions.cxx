#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include "CustomFunctions.h"

// function to read in the data into two vectors for x and y
void readInFile(std::ifstream &data_file, std::vector<float> &xVals, std::vector<float> &yVals){
    std::string x_str, y_str;
    while ((std::getline(data_file,x_str,',')) && std::getline(data_file,y_str)){

        xVals.push_back(std::stof(x_str));
        yVals.push_back(std::stof(y_str));
    }


}

// function to print out N values of the data
void printOut(std::vector<float> &xVals, std::vector<float> &yVals){
    int N;
    std::cout << "Enter Number of Lines to print";
    std::cin >> N;
    if (N > xVals.size()){
        std::cout << "Error, there are only " << xVals.size() << " values in this file, printing out just the first 5" << std::endl;
        for (int i=0; i<5; i++){
            std::cout<<xVals[i] << "," << yVals[i] << std::endl;
        }
    }
    else{
        for(int i=0; i<N;i++){
        std::cout<<xVals[i] << "," << yVals[i] << std::endl;
        }
    }
}

// function for finding the magnitude of each data point
void magnitude(std::vector<float> &xVals,std::vector<float> &yVals,std::vector<float> &mag){
    for (int i=0;i<xVals.size();i++){
        mag.push_back(sqrt(xVals[i]*xVals[i]+yVals[i]*yVals[i]));
        std::cout << mag[i] << std::endl;
    }



}

void bestFit(std::vector<float> &xVals, std::vector<float> &yVals, std::string outputName){
    std::vector<float> xi_yi;
    std::vector<float> xi_xi;
    float m;
    float c;
    for (int i=0;i<xVals.size();i++){
        xi_xi.push_back(xVals[i]*xVals[i]);
        xi_yi.push_back(xVals[i]*yVals[i]);
    }
    float xi_sum = std::accumulate(xVals.begin(),xVals.end(),0.0f);
    float yi_sum = std::accumulate(yVals.begin(),yVals.end(),0.0f);
    float xiyi_sum = std::accumulate(xi_yi.begin(),xi_yi.end(),0.0f);
    float xixi_sum = std::accumulate(xi_xi.begin(),xi_xi.end(),0.0f);
    m= (xVals.size()*xiyi_sum - xi_sum*yi_sum)/(xVals.size()*xixi_sum - xi_sum*xi_sum);
    c = (xixi_sum*yi_sum-xiyi_sum*xi_sum)/(xVals.size()*xixi_sum-xi_sum*xi_sum);
    std::cout << "y=" <<m <<"x+" << c << std::endl;

    std::ofstream outStream;
    outStream.open(outputName);
    outStream << "y=" <<m <<"x+" << c << std::endl;
    outStream.close();

}