#ifndef SAT2D
#define SAT2D
#include <math.h>

namespace Sat2d
{
    class Vector {
    public:
        int x;
        int y;

        Vector& copy(Vector vector);
        Vector& add(Vector vector);
        Vector& sub(Vector vector);
        Vector& scale(int x, int y);
        float len(Vector vector);
        Vector(int x, int y);
        Vector();
    };
    struct Box {
        Vector pos;
        int width;
        int height;
    };
    bool pointInBox(Vector point, Box box);
} // namespace Sat2d


#endif