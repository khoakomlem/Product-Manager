class sat2d::Vector {

    public:
        int x;
        int y;

        sat2d::Vector& copy(sat2d::Vector vector) {
            this->x = vector.x;
            this->y = vector.y;
            return *this;
        }

        sat2d::Vector& add(sat2d::Vector vector) {
            this->x += vector.x;
            this->y += vector.y;
            return *this;
        }

        sat2d::Vector& sub(sat2d::Vector vector) {
            this->x -= vector.x;
            this->y -= vector.y;
            return *this;
        }

        sat2d::Vector& scale(int x, int y) {
            this->x *= x;
            this->y *= y;
            return *this;
        }

        float len(sat2d::Vector vector) {
            return (float)sqrt(vector.x*vector.x + vector.y*vector.y);
        }

        Vector(int x, int y) {
            this->x = x;
            this->y = y;
        }

        Vector() {
            this->x = 0;
            this->y = 0;
        }
};