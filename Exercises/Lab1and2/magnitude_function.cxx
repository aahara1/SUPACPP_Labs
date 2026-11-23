#include <iostream>
#include <cmath>


float magnitude(float x, float y){
    return sqrt(x*x+y*y);

}




int main(){

    float mag;
    float x;
    float y;
    std::cout << "enter x";
    std::cin >> x;
    std::cout << "enter y";
    std::cin >> y;
    mag = magnitude(x,y);

    std::cout << "magnitude=" << mag << std::endl;

}