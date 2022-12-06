#include <iostream>
#ifndef NAMESPACES
#define NAMESPACES
//Element: button, table, ...
namespace element {
    class Element;
    class Button;
    class EditableLabel;
    class Table;
    struct Pos;
    struct Column;
}
#endif

struct element::Pos {
    int x, y;
};

class element::Element {

    public:
        element::Pos pos;
        bool visible;
        bool markAsRemove;

        virtual void update(std::vector<element::Element*>* elements) {};
        virtual bool draw() {};
        virtual void onClick() {};
        virtual void onKeyDown(int keyCode) {};

        Element(element::Pos pos) {
            this->pos = pos;
            this->visible = true;
            this->markAsRemove = false;
        }
};
#include "Button.h"
#include "EditableLabel.h"
#include "Table.h"
