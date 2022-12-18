class sat2d::Box {
    public:
        sat2d::Vector pos;
        int width;
        int height;

        Box(sat2d::Vector pos, int width, int height) {
            this->pos = pos;
            this->width = width;
            this->height = height;
        }
};
