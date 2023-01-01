// #include <graphics.h>
// #include <functional>
// #include <iostream>
// #include <memory>
// #include <cstddef>
#include<graphics.h>
#include "Element.hpp"


// class Element
void Element::Element::update() {
    for(int i = 0; i != elements.items.size(); i++) {
        if (elements.items[i]->markAsRemove) {
            elements.items.erase(elements.items.begin() + i);
            i--;
            continue;
        }
        elements.items[i]->update();
    }
};
bool Element::Element::draw() {
    for(int i = 0; i != elements.items.size(); i++) {
        if (!elements.items[i]->visible) continue;
        elements.items[i]->draw();
    }
    return false;
};
void Element::Element::onClick(int mouseX, int mouseY) {};
void Element::Element::onKeyDown(int keyCode) {};
bool Element::Element::isMouseHovering(int mouseX, int mouseY) { return false; };
Element::Element::Element(Global global, Sat2d::Vector pos) {
    this->global = global;
    this->pos = pos;
    this->visible = true;
    this->markAsRemove = false;
}
Element::Element::Element() {};


// class Label
bool Element::Label::isMouseHovering(int mouseX, int mouseY) {
    return Sat2d::pointInBox((Sat2d::Vector){mouseX, mouseY}, (Sat2d::Box){pos, boundary.width, boundary.height});
}
bool Element::Label::draw() {
    Element::draw();
    Sat2d::Vector pos = computePos();
    outtextxy(pos.x, pos.y, (char*)body.c_str());
    return false;
};
Sat2d::Vector Element::Label::computePos() {
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

    return (Sat2d::Vector){outX, outY};
};
Element::Label::Label(Global global, Sat2d::Vector pos, std::string body, int width, int height) : Element(global, pos) {
    this->body = body;
    this->align = {CENTER, MIDDLE};
    this->margin = {5, 5, 5, 5}; // pixels
    this->boundary = {pos.x, pos.y, width, height};
};
Element::Label::Label() {};


// class EditableLabel 
bool Element::EditableLabel::draw() {
    Label::draw();
    rectangle(boundary.x, boundary.y, boundary.x + boundary.width, boundary.y  + boundary.height);
}
bool Element::EditableLabel::isMouseHovering(int mouseX, int mouseY) {
    return Sat2d::pointInBox((Sat2d::Vector){mouseX, mouseY}, (Sat2d::Box){(Sat2d::Vector){boundary.x, boundary.y}, boundary.width, boundary.height});
}
void Element::EditableLabel::onClick(int mouseX, int mouseY) {
    Label::onClick(mouseX, mouseY);
    cleardevice();
    this->draw();
    this->awaitInput();
};
std::string Element::EditableLabel::awaitInput() {
    bool isExit = false;
    char c;
    while (kbhit()) {getch();}; // clear het ki tu trong memory, rat sussy :(
    do {
        if (kbhit()) {
            c = (char)getch( );

            if (c == KEY_ENTER){
                isExit = true;
            }

            if (c == KEY_ESCAPE) {
                isExit = true;
            }

            if (c == KEY_BACKSPACE) {
                if (this->body.length() <= 0) continue;
                this->body.pop_back();
                cleardevice();
                this->draw();
            }
            
            if (((int)c > 32 && (int)c < 127) || c == KEY_SPACE) {
                this->body.push_back(c);
                cleardevice();
                this->draw();
            }
        }
    } while (!isExit);
    return body;
};
Element::EditableLabel::EditableLabel(Global global, Sat2d::Vector pos, std::string body, int width, int height) : Label(global, pos, body, width, height) {};
Element::EditableLabel::EditableLabel() {};


// class Button
bool Element::Button::draw() {
    Label::draw();
    rectangle(boundary.x - bounce, boundary.y - bounce, boundary.x + boundary.width + bounce, boundary.y + boundary.height + bounce);
    return false;
};
void Element::Button::onClick(int mouseX, int mouseY) {
    Label::onClick(mouseX, mouseY);
    this->bounce = -3;
    this->draw();
    delay(200);
    this->bounce = 0;
};
Element::Button::Button(Global global, Sat2d::Vector pos, std::string body, int width, int height) : Label(global, pos, body, width, height) {}
Element::Button::Button() {};


// class OneTimeButton
void Element::OneTimeButton::reset() {
    this->clicked = false;
}
void Element::OneTimeButton::onClick(int mouseX, int mouseY) {
    Button::onClick(mouseX, mouseY);
    this->clicked = true;
}
bool Element::OneTimeButton::isMouseHovering(int mouseX, int mouseY) {
    return Sat2d::pointInBox((Sat2d::Vector){mouseX, mouseY}, (Sat2d::Box){(Sat2d::Vector){pos.x, pos.y}, boundary.width, boundary.height});
}
Element::OneTimeButton::OneTimeButton(Global global, Sat2d::Vector pos, std::string body, int width, int height) : Button(global, pos, body, width, height) {};
Element::OneTimeButton::OneTimeButton() {};


// class Prompt
bool Element::Prompt::draw() {
    Element::draw();
    rectangle(pos.x, pos.y, pos.x + width, pos.y + height);
    return false;
}
bool Element::Prompt::isMouseHovering(int mouseX, int mouseY) {
    return Sat2d::pointInBox((Sat2d::Vector){mouseX, mouseY}, (Sat2d::Box){(Sat2d::Vector){pos.x, pos.y}, width, height});
}
void Element::Prompt::onClick(int mouseX, int mouseY) {
    Element::onClick(mouseX, mouseY);
    if (this->closeBtn.clicked || this->cancelBtn.clicked || this->confirmBtn.clicked) {
        this->markAsRemove = true;
    }
    if (this->confirmBtn.clicked) {
        // do something
    }
}
Element::Prompt::Prompt(Global global, Sat2d::Vector pos, std::string body, int width, int height) : Element(global, pos) {
    this->width = width;
    this->height = height;
    int btnWidth = (3.5/12)*width;
    int btnHeight = (1.5/8)*height;
    this->confirmBtn = *(new OneTimeButton(
        this->global,
        (Sat2d::Vector){(int)(pos.x + (0.5/12.0) * width), (int)(pos.y + (6/8.0) * height)},
        "confirm",
        btnWidth,
        btnHeight
    ));
    this->cancelBtn = *(new OneTimeButton(
        this->global,
        (Sat2d::Vector){(int)(pos.x + (8/12.0) * width),
        (int)(pos.y + (6/8.0) * height)},
        "cancel",
        btnWidth,
        btnHeight
    ));
    this->closeBtn = *(new OneTimeButton(
        this->global,
        (Sat2d::Vector){(int)(pos.x + (11.5/12.0) * width), pos.y},
        "x",
        (int)((0.5/12.0)*width),
        (int)((0.5/12.0)*width)
    ));
    this->body = *(new Label(
        this->global,
        (Sat2d::Vector){(int)(pos.x + (0.5/12.0) * width), (int)(pos.y + (2/8.0) * height)},
        body,
        (int)( (11.5/12.0) * width ),
        (int)( (4/8.0) * height )
    ));
    this->elements.add(&this->confirmBtn);
    this->elements.add(&this->cancelBtn);
    this->elements.add(&this->closeBtn);
    this->elements.add(&this->body);
}


// class Table
bool Element::Table::isMouseHovering(int mouseX, int mouseY) {
    return Sat2d::pointInBox((Sat2d::Vector){mouseX, mouseY}, (Sat2d::Box){pos, width, height});
}
bool Element::Table::draw() {
    Element::draw();

    // draw frame
    rectangle(pos.x, pos.y, pos.x + width, pos.y + height);

    // draw columns
    int curX = pos.x;
    for(int i = 0; i != colData.size(); i++) {
        curX += colData[i].size;
        line(curX, pos.y, curX, pos.y + height);
    }

    // draw rows
    int size = 25;
    for(int curY = pos.y; curY < pos.y + height; curY+=size) {
        line(pos.x, curY, pos.x + width, curY);
    }
    return false;
}
void Element::Table::addRow(std::vector<Element*> data) {
    this->rowData.push_back(data);
    for (int i = 0; i != data.size(); ++i) {
        this->elements.add(data[i]);
    }
}
Element::Table::Table(Global global, Sat2d::Vector pos, int height, std::vector<Column> cData) : Element(global, pos) {
    this->height = height;
    this->width = 0;
    std::vector<Element*> headers;
    int curX = 10;
    for (int i = 0; i != cData.size(); ++i) {
        this->width += cData[i].size;
        headers.push_back(new Label(this->global, (Sat2d::Vector){curX, 10}, cData[i].header, cData[i].size, COL_SIZE));
        curX += cData[i].size;
    }
    this->addRow(headers);
    this->colData = cData;
}


// class AddButton
void Element::AddButton::update() {
    OneTimeButton::update();
    if (!this->itemAddWrap->visible && this->clicked) {
        this->reset();
    }
}
void Element::AddButton::onClick(int mouseX, int mouseY) {
    if (this->clicked) return;
    OneTimeButton::onClick(mouseX, mouseY);
    this->itemAddWrap->visible = true;
};
Element::AddButton::AddButton(Global global, Sat2d::Vector pos, std::string body, int width, int height) : OneTimeButton(global, pos, body, width, height) {
    this->itemAddWrap = new ItemAddWrap(
        this->global,
        Sat2d::Vector{100, 230}
    );
    this->itemAddWrap->visible = false;
    this->elements.add(this->itemAddWrap);
};


// class ItemAddWrap
Model::Item::ItemType convertItemType(std::string s) {
    if (s == "GD")
        return Model::Item::ItemType::GD;
    if (s == "TP")
        return Model::Item::ItemType::TP;
    if (s == "TC")
        return Model::Item::ItemType::TC;
}

void Element::ItemAddWrap::update() {
    Element::update();
    if (this->submitBtn->clicked) {
        try {
            Model::Item* item = new Model::Item(
                this->inputs[0]->body,
                convertItemType(this->inputs[1]->body),
                stoi(this->inputs[2]->body),
                stoi(this->inputs[3]->body),
                Util::ddmmyyyy{1,1,1},
                stoi(this->inputs[5]->body),
                this->inputs[6]->body
            );
            std::cout<<stoi(this->inputs[5]->body);
            item->verify();
            global.items.add(item);
            this->markAsRemove = true;
            return;
        }
        catch (std::string msg) {
            this->elements.add(new Prompt(global, (Sat2d::Vector){850, 330}, msg, 300, 200));
            this->submitBtn->reset();
        }
        catch(...) {
            this->elements.add(new Prompt(global, (Sat2d::Vector){850, 330}, "Loi stoi hoac khong xac dinh", 300, 200));
            this->submitBtn->reset();
        }
    }
};
Element::ItemAddWrap::ItemAddWrap(Global global, Sat2d::Vector pos) : Element(global, pos) {
    char arr[8][256] = {
        "Ma san pham",
        "Ten san pham",
        "Phan loai san pham",
        "Gia san pham",
        "Can nang san pham",
        "Ngay san xuat",
        "Han su dung",
        "Nha san xuat"
    };
    for (int i = 0; i < 8; ++i) {
        this->inputs.push_back(new EditableLabel(global, Sat2d::Vector{ pos.x + 250, pos.y + 100 + i*40 }, "1", 300, 30));
    }
    for (int i = 0; i < 8; ++i) {
        this->elements.add(new Label(global, Sat2d::Vector{ pos.x + 80, pos.y + 100 + i*40 }, (std::string)arr[i] + ": ", 100, 30));
        this->elements.add(inputs[i]);
    }
    this->submitBtn = new OneTimeButton(global, Sat2d::Vector{ pos.x + 600 , pos.y + 200}, "Submit", 100, 30);
    this->elements.add(this->submitBtn);
}