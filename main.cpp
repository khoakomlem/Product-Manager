#include <algorithm>
#include <vector>
#include<math.h>
#include<graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include "sat2d/Sat2d.h"
#include "element/Element.h"

element::Element document;

int main()
{
    bool requestClearDevice = false;
    std::vector<element::Column> colData;
    element::Column arr[3] = {{"1", 10}, {"2", 20}, {"3", 30}};

    // list item table
    colData.push_back((element::Column){"id", 100});
    colData.push_back((element::Column){"name", 200});
    colData.push_back((element::Column){"description", 700});
    colData.push_back((element::Column){"modify", 100});
    colData.push_back((element::Column){"remove", 100});
    document->elements.push_back(new element::Table((sat2d::Vector){10, 10}, 300, colData));

    initwindow(1366, 768);
    // settextstyle(3, HORIZ_DIR, 3);

    while (1) {
        cleardevice();
        requestClearDevice = false;

        document->update();
        document->draw();

        // hook click event
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(100);
        }
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        document->onClick(mouseX, mouseY);
    }

    closegraph();
    getch();
}
