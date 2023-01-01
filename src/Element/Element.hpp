#ifndef ELEMENT
#define ELEMENT
#include <iostream>
#include "../global.hpp"
#include "../Util/Util.hpp"
#include "../Sat2d/Sat2d.hpp"

namespace Element {
    struct Column {
        std::string header;
        int size;
    };
    class Element {
    public:
        int id;
        Util::ddmmyyyy create_at;
        Global global;
        Util::Manager<Element*> elements;
        Sat2d::Vector pos;
        bool visible = true;
        bool markAsRemove;

        virtual void update();
        virtual bool draw();
        virtual void onClick(int mouseX, int mouseY);
        virtual void onKeyDown(int keyCode);
        virtual bool isMouseHovering(int mouseX, int mouseY);
        Element(Global global, Sat2d::Vector pos);
        Element();
    };
    class Label : public Element {
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

        bool draw();
        bool isMouseHovering(int mouseX, int mouseY);
        Sat2d::Vector computePos();
        Label(Global global, Sat2d::Vector pos, std::string body, int width, int height);
        Label();
    };
    class EditableLabel : public Label {
    public:
        static const int KEY_ENTER = 13;
        static const int KEY_BACKSPACE = 8;
        static const int KEY_ESCAPE = 27;
        static const int KEY_SPACE = 32;

        bool draw();
        bool isMouseHovering(int mouseX, int mouseY);
        void onClick(int mouseX, int mouseY);
        std::string awaitInput();
        EditableLabel(Global global, Sat2d::Vector pos, std::string body, int width, int height);
        EditableLabel();
    };
    class Button : public Label {
    public:
        int bounce = 0;

        virtual bool draw();
        virtual void onClick(int mouseX, int mouseY);
        Button(Global global, Sat2d::Vector pos, std::string body, int width, int height);
        Button();
    };
    class OneTimeButton : public Button {
    public:
        bool clicked = false;

        void reset();
        void onClick(int mouseX, int mouseY);
        bool isMouseHovering(int mouseX, int mouseY);
        OneTimeButton(Global global, Sat2d::Vector pos, std::string body, int width, int height);
        OneTimeButton();
    };
    class Prompt : public Element {
    public:
        int width;
        int height;
        OneTimeButton confirmBtn;
        OneTimeButton cancelBtn;
        OneTimeButton closeBtn;
        Label body;

        bool draw();
        bool isMouseHovering(int mouseX, int mouseY);
        void onClick(int mouseX, int mouseY);
        Prompt(Global global, Sat2d::Vector pos, std::string body, int width, int height);
    };
    class Table : public Element {
    public:
        static const int COL_SIZE = 25;
        int width;
        int height;
        std::vector<Column> colData; // array of collumn size
        std::vector<std::vector<Element*> > rowData; // 2d array table data

        bool isMouseHovering(int mouseX, int mouseY);
        bool draw();
        void addRow(std::vector<Element*> data);
        Table(Global global, Sat2d::Vector pos, int height, std::vector<Column> cData);
    };
    class ItemAddWrap : public Element::Element {
    public:
        OneTimeButton* submitBtn;
        std::vector<EditableLabel*> inputs;

        void update();
        ItemAddWrap(Global global, Sat2d::Vector pos);
    };
    class AddButton : public OneTimeButton {
    public:
        ItemAddWrap* itemAddWrap;

        void update();
        void onClick(int mouseX, int mouseY);
        AddButton(Global global, Sat2d::Vector pos, std::string body, int width, int height);
    };
}

#endif