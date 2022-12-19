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

// Element hoat dong theo co che event bubbling 

class element::Element {

    public:
        std::vector<element::Element*> elements;
        sat2d::Vector pos;
        bool visible;
        bool markAsRemove;

        virtual void update() {
            for(int i = 0; i != elements.size(); i++) {
                if (elements[i]->markAsRemove) {
                    elements.erase(elements.begin() + i);
                    i--;
                    continue;
                }
                elements[i]->update();
            }
        };
        virtual bool draw() {
            for(int i = 0; i != elements.size(); i++) {
                elements[i]->draw();
            }
            return false;
        };
        virtual void onClick(int mouseX, int mouseY) {
            for(int i = 0; i != elements.size(); i++) {
                bool isHovering = elements[i]->isMouseHovering(mouseX, mouseY);
                if (isHovering) {
                    elements[i]->onClick(mouseX, mouseY);
                }
            }
        };
        virtual void onKeyDown(int keyCode) {};
        virtual bool isMouseHovering(int mouseX, int mouseY) { return false; };

        Element(sat2d::Vector pos) {
            this->pos = pos;
            this->visible = true;
            this->markAsRemove = false;
        }
};

#include "EditableLabel.h"
#include "Button.h"
#include "Table.h"
