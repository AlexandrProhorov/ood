#pragma once
#include "include.h"

class Shape
{
public:
    std::string name;
    int X, Y;
};

class Circle : public Shape
{
public:
    int rad;
};

class Rectangle : public Shape
{
public:
    int X1, Y1;
};

class Triangle : public Rectangle
{
public:
    int X2, Y2;
};

