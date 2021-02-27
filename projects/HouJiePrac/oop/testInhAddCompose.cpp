//
// Created by dingguoliang on 2021/2/25.
//

/*
 * By this example ,we got :
 * Inheritance + Composition constructor init  order :base class -> component -> own class
 * */

#include <iostream>
using namespace std;

//base class
class Shape
{
public:
    Shape()
    {
        cout << "Shape::Shape()" << endl;
    }
    virtual void draw() = 0;
};

//component
class MyType
{
public:
    MyType()
    {
        cout << "MyType::MyType()" << endl;
    }
};
//own class
class Rectangle : public Shape
{
public:
    Rectangle()
    {
        cout << "Rectangle::Rectangle()" << endl;
    }
    void draw() override
    {
        cout << "Rectangle draw" << endl;
    }
private:
    MyType _m;
};

int main(int argc, char **argv)
{
    Rectangle r;
    r.draw();
}