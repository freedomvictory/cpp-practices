//
// Created by dingguoliang on 2021/2/27.
//

/*
 * Composite pattern example
 * Reference : <agile software development> p258
 * */
#include "shapes.h"

using namespace std;

void Circle::draw()
{
    cout << "Circle::draw()" << endl;
}
void Square::draw()
{
    cout << "Square::draw()" << endl;
}

void CompositeShape::addElement(Shape *s)
{
    _shapes.push_back(s);
}
void CompositeShape::draw()
{
    if(!_shapes.empty())
    {
        for(Shape* shape : _shapes)
            shape->draw();
    }
}
CompositeShape::~CompositeShape()
{
    if(!_shapes.empty())
    {
        for(Shape* shape : _shapes)
            delete shape;
    }
}

int main(int argc, char **argv)
{
    Circle* c = new Circle;
    Square* s = new Square;

    CompositeShape composite;
    composite.addElement(c);
    composite.addElement(s);
    //also `composite` could add itself, if it was, `composite` construct a tree structure

    //CompositeShape composite_b;
    //composite_b.addElement(new Circle);
    //composite.addElement(composite_b);
    composite.draw();


}