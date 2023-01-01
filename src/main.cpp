#include <iostream>
#include <vector>
#include<graphics.h>
// #include <algorithm>
#include<math.h>
// #include <functional>
// #include <memory>
#include "Util/Util.hpp"
#include "Sat2d/Sat2d.hpp"
#include "global.hpp"
#include "Model/Model.hpp"
#include "Element/Element.hpp"

bool checkOnClick(Element::Element* element, int mouseX, int mouseY) {
    for (int i = 0; i != element->elements.items.size(); ++i) {
        if (!element->visible) continue;
        checkOnClick(element->elements.items[i], mouseX, mouseY);
    }
    if (element->visible && element->isMouseHovering(mouseX, mouseY)) {
        element->onClick(mouseX, mouseY);
    }
}

int main()
{
    Global global;
    Element::Element* document = new Element::Element(global, (Sat2d::Vector){0, 0});
    Element::Element* billDatabase = new Element::Element(global, (Sat2d::Vector){0, 0});
    Element::Element* employeeDatabase = new Element::Element(global, (Sat2d::Vector){0, 0});
    Element::Element* itemDatabase = new Element::Element(global, (Sat2d::Vector){0, 0});

    Element::OneTimeButton* billBtn = new Element::OneTimeButton(global, (Sat2d::Vector){1220, 10}, "Bill Database", 150, 40);
    Element::OneTimeButton* employeeBtn = new Element::OneTimeButton(global, (Sat2d::Vector){1220, 60}, "Employee Database", 150, 40);
    Element::OneTimeButton* itemBtn = new Element::OneTimeButton(global, (Sat2d::Vector){1220, 110}, "Item Database", 150, 40);

    document->elements.add(billDatabase);
    document->elements.add(employeeDatabase);
    document->elements.add(itemDatabase);

    document->elements.add(billBtn);
    document->elements.add(employeeBtn);
    document->elements.add(itemBtn);

    billBtn->visible = false;
    billBtn->clicked = true;

    employeeDatabase->visible = false;
    itemDatabase->visible = false;

    // bill database
    std::vector<Element::Column> colData1;
    colData1.push_back((Element::Column){"Ma hoa don", 130});
    colData1.push_back((Element::Column){"Thoi gian mua hang", 230});
    // colData1.push_back((Element::Column){"Danh sach don hang", 700});
    colData1.push_back((Element::Column){"Tong tien", 160});
    colData1.push_back((Element::Column){"Tien thu tu khach", 160});
    colData1.push_back((Element::Column){"Tien tra khach", 160});
    colData1.push_back((Element::Column){"Ma nhan vien", 160});
    billDatabase->elements.add(new Element::AddButton(global, (Sat2d::Vector){10, 330}, "Add bill", 120, 40));
    billDatabase->elements.add(new Element::OneTimeButton(global, (Sat2d::Vector){10, 380}, "Charge", 120, 40));
    billDatabase->elements.add(new Element::Table(global, (Sat2d::Vector){10, 10}, 300, colData1));

    // employee database
    std::vector<Element::Column> colData2;
    colData2.push_back((Element::Column){"Ma nhan vien", 100});
    colData2.push_back((Element::Column){"Ho va ten", 300});
    colData2.push_back((Element::Column){"Ngay sinh", 100});
    colData2.push_back((Element::Column){"CCCD", 100});
    colData2.push_back((Element::Column){"Dia chi", 200});
    colData2.push_back((Element::Column){"Email", 200});
    colData2.push_back((Element::Column){"So dien thoai", 130});
    colData2.push_back((Element::Column){"Thoi gian lam viec", 70});
    employeeDatabase->elements.add(new Element::AddButton(global, (Sat2d::Vector){10, 330}, "Add employee", 120, 40));
    employeeDatabase->elements.add(new Element::OneTimeButton(global, (Sat2d::Vector){10, 380}, "Charge", 120, 40));
    employeeDatabase->elements.add(new Element::Table(global, (Sat2d::Vector){10, 10}, 300, colData2));

    // item database
    std::vector<Element::Column> colData3;
    colData3.push_back((Element::Column){"Ma san pham", 100});
    colData3.push_back((Element::Column){"Ten san pham", 250});
    colData3.push_back((Element::Column){"Loai", 80});
    colData3.push_back((Element::Column){"Gia san pham", 140});
    colData3.push_back((Element::Column){"Can nang san pham", 140});
    colData3.push_back((Element::Column){"Ngay san xuat", 140});
    colData3.push_back((Element::Column){"Han su dung", 140});
    colData3.push_back((Element::Column){"Nha san xuat", 140});
    itemDatabase->elements.add(new Element::AddButton(global, (Sat2d::Vector){10, 330}, "Add item", 120, 40));
    itemDatabase->elements.add(new Element::OneTimeButton(global, (Sat2d::Vector){10, 380}, "Charge", 120, 40));
    itemDatabase->elements.add(new Element::Table(global, (Sat2d::Vector){10, 10}, 300, colData3));

    initwindow(1366, 768);

    while (1) {
        global.requestClearDevice = false;

        while (!ismouseclick(WM_LBUTTONDOWN)) {
            cleardevice();
            document->update();
            document->draw();
            delay(1000.0/global.framerate);
        }
        
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        clearmouseclick(WM_LBUTTONDOWN);
        checkOnClick(document, mouseX, mouseY);

        if (billBtn->clicked && billBtn->visible) {
            std::cout<<"bill";
            billDatabase->visible = true;
            employeeDatabase->visible = false;
            itemDatabase->visible = false;

            billBtn->visible = false;
            employeeBtn->reset();
            employeeBtn->visible = true;
            itemBtn->reset();
            itemBtn->visible = true;
        }
        if (employeeBtn->clicked && employeeBtn->visible) {
            std::cout<<"employ";
            billDatabase->visible = false;
            employeeDatabase->visible = true;
            itemDatabase->visible = false;

            employeeBtn->visible = false;
            billBtn->reset();
            billBtn->visible = true;
            itemBtn->reset();
            itemBtn->visible = true;
        }
        if (itemBtn->clicked && itemBtn->visible) {
            std::cout<<"item";
            billDatabase->visible = false;
            employeeDatabase->visible = false;
            itemDatabase->visible = true;

            itemBtn->visible = false;
            employeeBtn->reset();
            employeeBtn->visible = true;
            billBtn->reset();
            billBtn->visible = true;
        }
        
        delay(100);
    }

    closegraph();
    getch();
}