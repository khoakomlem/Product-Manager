#include <graphics.h>

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

        bool draw() {
            element::Pos pos = computePos();
            outtextxy(pos.x, pos.y, (char*)body.c_str());
            return false;
        }
        void onClick() {
            // chuyen sang editable
        }
        Pos computePos() {
            int outX = boundary.x;
            int outY = boundary.y;

            switch (align.horizontal) {
                case LEFT:
                    outX += margin.left;
                    break;
                case CENTER:
                    outX += std::max(margin.left, boundary.width / 2 - (int)body.length() * 4);
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
                    outY += std::max(margin.top, boundary.height / 2);
                    break;
                case BOTTOM:
                    outY += boundary.height - margin.bottom;
                    break;
            }

            return (element::Pos){outX, outY};
        }

        EditableLabel(std::string body, element::Pos pos, int width, int height) : Element(pos) {
            this->body = body;
            this->align = {MIDDLE, TOP};
            // 0: left; 1: center; 2: right;
            // 0: top; 1: middle; 2: bottom;
            this->margin = {5, 5, 5, 5}; // pixels
            this->boundary = {pos.x, pos.y, width, height};
        }
};
