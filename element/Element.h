#ifndef NAMESPACES
#define NAMESPACES
//Element: button, table, ...
namespace element {
    class Element;
    class Button;
    class EditableLabel;
    class Table;
    struct Column;
}
#endif

class element::Element {

    public:
        vector<Element*> elements;
        sat2d::Vector pos;
        bool visible;
        bool markAsRemove;

        virtual void update() {};
        virtual bool draw() { return false; };
        virtual void onClick(int mouseX, int mouseY) {};
        virtual void onKeyDown(int keyCode) {};
        virtual bool isMouseHovering(int mouseX, int mouseY) { return false; };

        Element(sat2d::Vector pos) {
            this->element
            this->pos = pos;
            this->visible = true;
            this->markAsRemove = false;
        }
};

#include "EditableLabel.h"
#include "Button.h"
#include "Table.h"
