#include <iostream>

using namespace std;


class Shape {
public:
    virtual void area() = 0;
    void show() {
        printf("I am shape or its heir \n");
    }
};

class Triangle : public Shape {
public:
    void area() {
        printf("S=0.5*a*h \n");
    }
};

class Rectangle : public Shape {
public:
    void area() {
        printf("S=a*b \n");
    }
    void show() {
        printf("I am rectangle \n");
    }
};

int main()
{
    Shape* s_tr = new Triangle();
    Shape* s_rect = new Rectangle();
    Triangle* tr = new Triangle();
    Rectangle* rect = new Rectangle();
    s_tr->area();  // перекрываемый метод
    s_rect->area(); // перекрываемый метод
    tr->area(); // перекрываемый метод
    rect->area(); // перекрываемый метод
    s_tr->show(); // наследуемый метод
    s_rect->show(); // наследуемый метод
    tr->show(); // наследуемый метод
    rect->show(); // перекрываемый метод
}