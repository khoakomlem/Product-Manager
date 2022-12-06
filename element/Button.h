#include <iostream>
#include <graphics.h>


class element::Button : public element::Element {

    public:
        int width;
        int height;

        bool draw() {
            rectangle(100,100,200,200);
            return false;
        }
        void onClick() {
            std::cout<<"test";
        }

        Button(element::Pos pos, int width, int height) : Element(pos) {
            this->width = width;
            this->height = height;
        }
};
