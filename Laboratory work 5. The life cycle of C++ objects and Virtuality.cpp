#include <iostream>

using namespace std;


class Shape {
public:
    virtual string classname() {
        return "Shape";
    }
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
    string classname() {
        return "Triangle";
    }
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
    string classname() {
        return "RightTriangle";
    }
    bool isA(const string& s) {
        return (s == "RightTriangle") || Triangle::isA(s);
    }
};

class Rectangle : public Shape {
public:
    string classname() {
        return "Rectangle";
    }
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

class Base {
public:
    Base() {
        printf("Base()\n");
    }
    Base(Base* obj) {
        printf("Base(Base* obj)\n");
    }
    Base(Base& obj) {
        printf("Base(Base& obj)\n");
    }
    virtual ~Base() {
        printf("~Base()\n");
    }
};

class Desc : Base {
public:
    Desc() {
        printf("Desc()\n");
    }
    Desc(Desc* obj) {
        printf("Desc(Desc* obj)\n");
    }
    Desc(Desc& obj) {
        printf("Desc(Desc& obj)\n");
    }
    ~Desc() {
        printf("~Desc()\n");
    }
};

void func1(Base obj) {
    printf("func1(Base obj)\n");
}

void func2(Base* obj) {
    printf("func2(Base* obj)\n");
}

void func3(Base& obj) {
    printf("func3(Base& obj)\n");
}

int main()
{
    Base b;
    Base* pb = new Base();
    func1(b);
    func2(&b);
    func3(b);
    func1(*pb);
    func2(pb);
    func3(*pb);

    printf("\n");

    Desc d;
    Desc* pd = new Desc();
    func1(b);
    func2(&b);
    func3(b);
    func1(*pb);
    func2(pb);
    func3(*pb);
}