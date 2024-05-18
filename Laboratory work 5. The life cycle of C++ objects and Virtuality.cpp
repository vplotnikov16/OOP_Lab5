#include <iostream>

using namespace std;


class Shape {
public:
    virtual void area() = 0;
};

class Triangle : public Shape {
    void area() {
        printf("S=0.5*a*h \n");
    }
};

class Rectangle : public Shape {
    void area() {
        printf("S=a*b \n");
    }
};

int main()
{
    
}