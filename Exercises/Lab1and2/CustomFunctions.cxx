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

// printing for the magnitude function
void printOut(std::vector<float> &mag){
    for (int i=0;i<mag.size();i++){
        std::cout << mag[i] << std::endl;
    }

}
// printing out for best fit equaiton
void printOut(float &m, float &c){
    std::cout << "the line of best fit has equation: y=" << m <<"x+"<< c << std::endl;
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
    }



}

void bestFit(std::vector<float> &xVals, std::vector<float> &yVals, std::string outputName, float &m, float &c, std::vector<float> yValsE,float &chi2DOF){
    std::vector<float> xi_yi;
    std::vector<float> xi_xi;
    std::vector<float> howGoodFit;
    float chi2;
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

    for (int i=0;i<xVals.size();i++){
        howGoodFit.push_back((yVals[i] - (m*xVals[i]+c))*(yVals[i] - (m*xVals[i]+c))/(yValsE[i]*yValsE[i]));
    }
    chi2 = std::accumulate(howGoodFit.begin(),howGoodFit.end(),0.0f);
    chi2DOF = chi2/(xVals.size()-2);

}

float power(float x, int y){

if (y==0){
        return 1;
    }
    return x*power(x,y-1);
}

void xPOWERy(std::vector<float> &xVals, std::vector<float> &yVals, std::vector<float> &xTOy){
    for (int i = 0; i < xVals.size(); i++){
        int n = std::round(yVals[i]);
        xTOy.push_back(power(xVals[i],n));
    }

}

// saving for the magnitude and x^y
void saveFile(std::vector<float> var, std::string outputName){
    std::ofstream outStream;
    outStream.open(outputName);
    for (int i=0; i<var.size();i++){
        outStream << var[i] << std::endl;
    }
    outStream.close();

}
// saving for fitting a straight line
void saveFile(float m, float c, float chi2DOF,std::string outputName){
    std::ofstream outStream;
    outStream.open(outputName);
    outStream << "y=" <<m <<"x+" << c << std::endl;
    outStream << "Chi squared test divided by DoF is: " << chi2DOF << std::endl;
    outStream.close();

}

