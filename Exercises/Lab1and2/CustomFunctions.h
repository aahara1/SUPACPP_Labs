#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H

#include <string>
#include <fstream>
#include <vector>

#pragma once

void readInFile(std::ifstream &data_file, std::vector<float> &xVals, std::vector<float> &yVals);
void printOut(std::vector<float> &xVals, std::vector<float> &yVals);
void magnitude(std::vector<float> &xVals, std::vector<float> &yVals, std::vector<float> &mag);
void bestFit(std::vector<float> &xVals, std::vector<float> &yVals, std::string outputName);

#endif