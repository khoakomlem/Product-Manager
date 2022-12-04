#include <graphics.h>
#include <iostream>

class element::Button {
    element::Pos pos;

    public:
        void update() {
        }
        void draw() {
            rectangle(100,100,200,200);
        }
        void onClick() {
            std::cout<<"test";
        }
}
