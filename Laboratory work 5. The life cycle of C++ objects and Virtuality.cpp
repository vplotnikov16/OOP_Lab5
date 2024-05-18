#include <iostream>

using namespace std;


class Shape {
public:
    virtual bool isA(const string& s) {
        return s == "Shape";
    }
    virtual void area() = 0;
    void show() {
        printf("I am shape or its heir \n");
    }
};

class Triangle : public Shape {
public:
    bool isA(const string& s) {
        return (s == "Triangle") || Shape::isA(s);
    }
    void area() {
        printf("S=0.5*a*h \n");
    }
    void triangleMethod() {
        printf("triangleMethod \n");
    }
};

class RightTriangle : public Triangle {
public:
    bool isA(const string& s) {
        return (s == "RightTriangle") || Triangle::isA(s);
    }
};

class Rectangle : public Shape {
public:
    bool isA(const string& s) {
        return (s == "Rectangle") || Shape::isA(s);
    }
    void area() {
        printf("S=a*b \n");
    }
    void show() {
        printf("I am rectangle \n");
    }
    void rectangleMethod() {
        printf("rectangleMethod \n");
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const int size = 10;
    Shape* shapes[size];
    for (int i = 0; i < size; i++) {
        int choice = rand();
        if (choice % 3 == 0) {
            shapes[i] = new Triangle();
        }
        else if (choice % 3 == 1) {
            shapes[i] = new RightTriangle();
        }
        else if (choice % 3 == 2) {
            shapes[i] = new Rectangle();
        }
    }

    // Безопасное приведение типов вручную
    for (int i = 0; i < size; i++) {
        if (shapes[i]->isA("Triangle")) {
            static_cast<Triangle*>(shapes[i])->triangleMethod();
        }
    }
    printf("\n");
    // Безопасное приведение типов с использованием dynamic_cast
    for (int i = 0; i < size; i++) {
        Triangle* t = dynamic_cast<Triangle*>(shapes[i]);
        if (t != nullptr) t->triangleMethod();
    }
}