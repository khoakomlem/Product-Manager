class element::EditableLabel : public element::Element {
    public:
        static const int LEFT = 0;
        static const int CENTER = 1;
        static const int RIGHT = 2;
        static const int TOP = 0;
        static const int BOTTOM = 2;
        static const int MIDDLE = 1;

        struct Boundary {
            int x;
            int y;
            int width;
            int height;
        };
        struct Align {
            int horizontal;
            int vertical;
        };
        struct Margin {
            int left;
            int top;
            int right;
            int bottom;
        };

        Align align;
        Margin margin;
        Boundary boundary;
        std::string body;

        virtual bool draw() {
            element::Element::draw();
            sat2d::Vector pos = computePos();
            outtextxy(pos.x, pos.y, (char*)body.c_str());
            return false;
        }

        bool isMouseHovering(int mouseX, int mouseY) {
            // std::cout<<pos.x<<" "<<pos.y<<" "<<boundary.width<<" "<<boundary.height<<" "<<mouseX<<" "<<mouseY<<std::endl;
            return sat2d::pointInBox((sat2d::Vector){mouseX, mouseY}, (sat2d::Box){pos, boundary.width, boundary.height});
        }

        sat2d::Vector computePos() {
            int outX = boundary.x;
            int outY = boundary.y;

            switch (align.horizontal) {
                case LEFT:
                    outX += margin.left;
                    break;
                case CENTER:
                    outX += std::max(margin.left, (int)(boundary.width  / 2 - body.length() * 4));
                    break;
                case RIGHT:
                    outX += boundary.width - margin.right;
                    break;
            }

            switch (align.vertical) {
                case TOP:
                    outY += margin.top;
                    break;
                case MIDDLE:
                    outY += std::max(margin.top, boundary.height / 2 - 3);
                    break;
                case BOTTOM:
                    outY += boundary.height - margin.bottom;
                    break;
            }

            return (sat2d::Vector){outX, outY};
        }

        EditableLabel(sat2d::Vector pos, std::string body, int width, int height) : Element(pos) {
            this->body = body;
            this->align = {CENTER, MIDDLE};
            this->margin = {5, 5, 5, 5}; // pixels
            this->boundary = {pos.x, pos.y, width, height};
        }
        EditableLabel() {
        }
};
