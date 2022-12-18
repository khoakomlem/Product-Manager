namespace sat2d {
    class Vector;
    class Box;
    bool pointInBox(Vector point, Box box);
}

#include "Vector.h"
#include "Box.h"
#include "Point.h"

bool sat2d::pointInBox(Vector point, Box box) {
    int r = abs(box.pos.x + box.width - point.x);
    int l = abs(box.pos.x - point.x);
    int u = abs(box.pos.y - point.y);
    int d = abs(box.pos.y + box.height - point.y);
    bool collide = r + l == box.width && u + d == box.height;
    if (collide) {
        // debug
        line(box.pos.x, box.pos.y, box.pos.x + box.width, box.pos.y + box.height);
        // line(box.pos.x + box.width, box.pos.y, box.pos.x, box.pos.y + box.height);
    }
    return collide;
}