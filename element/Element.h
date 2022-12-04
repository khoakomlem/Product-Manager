#ifndef NAMESPACES
#define NAMESPACES
//Element: button, table, ...
namespace element {
    class Element;
    class Button;
    class EditableLabel;
    class Table;
}
#endif

class element::Element {
    bool visible = true;
    bool markAsRemove = false;
    public:
        void update();
        void draw();
        void onClick();
        void onKeyDown(keyCode);    
}

class element::Pos {
    int x = 0;
    int y = 0;
    
    public:
        void set(int x, y) {
            this->x = x;
            this->y = y;
        }
}

#include "Button.h"
#include "EditableLabel.h"
#include "Table.h"
