//
// Created by dingguoliang on 2021/2/27.
//

#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <vector>


class Shape
{
public:
    virtual void draw() = 0;
};
class CompositeShape : public Shape
{
public:
    void draw() override;
    void addElement(Shape*);
    ~CompositeShape();
private:
    std::vector<Shape*> _shapes;
};

class Circle : public Shape
{
public:
    void draw() override;
};
class Square : public Shape
{
public:
    void draw() override;
};













#endif //HOUJIEPRAC_SHAPES_H
