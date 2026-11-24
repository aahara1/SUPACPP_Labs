#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H

#include <string>
#include <fstream>
#include <vector>

#pragma once

void readInFile(std::ifstream &data_file, std::vector<float> &xVals, std::vector<float> &yVals);
void printOut(std::vector<float> &xVals, std::vector<float> &yVals); // for the values in the dataset
void printOut(float &m, float &c); // for line of best fit
void printOut(std::vector<float> &mag); // for vector magnitude
void magnitude(std::vector<float> &xVals, std::vector<float> &yVals, std::vector<float> &mag);
void bestFit(std::vector<float> &xVals, std::vector<float> &yVals, std::string outputName, float &m, float &c, std::vector<float> yValsE, float &chi2DOF);
void xPOWERy(std::vector<float> &xVals, std::vector<float> &yVals, std::vector<float> &xTOy);
float power(std::vector<float> x, std::vector<int> y);
void saveFile(std::vector<float> var, std::string outputName);
void saveFile(float m, float c, float chi2DOF,std::string outputName);

#endif