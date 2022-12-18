#include <algorithm>
#include <vector>
#include<math.h>
#include<graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include "sat2d/Sat2d.h"
#include "element/Element.h"

int main()
{
    std::vector<element::Element*> elements;
    element::Column arr[3] = {{"1", 10}, {"2", 20}, {"3", 30}};
    bool requestClearDevice = false;

    initwindow(1366, 768);
    // settextstyle(3, HORIZ_DIR, 3);

    // list item table
    std::vector<element::Column> cData;
    cData.push_back((element::Column){"id", 100});
    cData.push_back((element::Column){"name", 200});
    cData.push_back((element::Column){"description", 700});
    cData.push_back((element::Column){"modify", 100});
    cData.push_back((element::Column){"remove", 100});
    elements.push_back(new element::Table((sat2d::Vector){10, 10}, 300, cData));


    while (1) {
        cleardevice();
        requestClearDevice = false;

        // update view
        for(int i = 0; i != elements.size(); i++) {
            if (elements[i]->markAsRemove) {
                elements.erase(elements.begin() + i);
                i--;
                continue;
            }
            elements[i]->update();
            requestClearDevice = elements[i]->draw();
        }

        // hook click event
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            ellipse(10, 10, 10, 10, 10, 10);
            delay(500);
        }
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        std::cout<<mouseX<<" "<<mouseY<<std::endl;
        for(int i = 0; i != elements.size(); i++) {
            bool isHovering = elements[i]->isMouseHovering(mouseX, mouseY);
            if (isHovering) {
                elements[i]->onClick(mouseX, mouseY);
            }
        }

        // refresh rate
        delay(100);
    }

    closegraph();
    getch();
}
