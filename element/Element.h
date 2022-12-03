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
    public:
        void onClick():
        void onKeyDown(keyCode):
        bool visible = true;
        bool markAsRemove = false;
}

#include "Button.h"
#include "EditableLabel.h"
#include "Table.h"
