#include "Sat2d.hpp"

// class Vector
Sat2d::Vector& Sat2d::Vector::copy(Sat2d::Vector vector) {
    this->x = vector.x;
    this->y = vector.y;
    return *this;
}
Sat2d::Vector& Sat2d::Vector::add(Sat2d::Vector vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}
Sat2d::Vector& Sat2d::Vector::sub(Sat2d::Vector vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    return *this;
}
Sat2d::Vector& Sat2d::Vector::scale(int x, int y) {
    this->x *= x;
    this->y *= y;
    return *this;
}
float Sat2d::Vector::len(Sat2d::Vector vector) {
    return (float)sqrt(vector.x*vector.x + vector.y*vector.y);
}
Sat2d::Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}
Sat2d::Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

bool Sat2d::pointInBox(Vector point, Box box) {
    int r = abs(box.pos.x + box.width - point.x);
    int l = abs(box.pos.x - point.x);
    int u = abs(box.pos.y - point.y);
    int d = abs(box.pos.y + box.height - point.y);
    bool collide = r + l == box.width && u + d == box.height;
    if (collide) {
        // debug
        // line(box.pos.x, box.pos.y, box.pos.x + box.width, box.pos.y + box.height);
        // line(box.pos.x + box.width, box.pos.y, box.pos.x, box.pos.y + box.height);
    }
    return collide;
}