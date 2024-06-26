﻿#include <iostream>

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
    void someMethod() {
        printf("someMethod()\n");
    }
    virtual ~Base() {
        printf("~Base()\n");
    }
};

void pass_object(unique_ptr<Base> obj)
{
    obj->someMethod();
} // obj и объект Base (96 строчка) удаляются здесь

shared_ptr<Base> pass_return_object(shared_ptr<Base> obj)
{
    obj->someMethod();
    return obj;
}

int main()
{
    shared_ptr<Base> obj1 = make_shared<Base>();
    obj1 = pass_return_object(obj1);
    shared_ptr<Base> obj2 = obj1;
    obj2->someMethod();
}