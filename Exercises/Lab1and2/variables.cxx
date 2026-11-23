#include <iostream>
#include <cmath>
float x = 7.5;
float y = 3.4;

float magnitude;

int main(){
magnitude = sqrt(x*x+y*y);

std::cout << "magnitude=" << magnitude << std::endl;

}