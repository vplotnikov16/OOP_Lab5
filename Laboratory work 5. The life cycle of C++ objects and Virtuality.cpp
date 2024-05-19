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
    Base(const Base& obj) {
        printf("Base(Base& obj)\n");
    }
    virtual ~Base() {
        printf("~Base()\n");
    }
};

Base func1() {
    Base obj1;
    return obj1;
}
Base* func2() {
    Base obj2;
    return &obj2;
}
Base& func3() {
    Base obj;
    return obj;
}
Base func4() {
    Base* obj4 = new Base();
    return *obj4;
}
Base* func5() {
    Base* obj = new Base();
    return obj;
}
Base& func6() {
    Base* obj = new Base();
    return *obj;
}


int main()
{
    Base obj1 = func1();
    printf("\n");
    Base* obj2 = func2();
    printf("\n");
    Base& obj3 = func3();
    printf("\n\n");
    Base obj4 = func4();
    printf("\n");
    Base* obj5 = func5();
    printf("\n");
    Base& obj6 = func6();


}