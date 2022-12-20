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
    int framerate = 30;
    bool requestClearDevice = false;
    element::Element* document = new element::Element((sat2d::Vector){0, 0});
    std::vector<element::Column> colData;
    element::Column arr[3] = {{"1", 10}, {"2", 20}, {"3", 30}};

    // list item table
    colData.push_back((element::Column){"id", 100});
    colData.push_back((element::Column){"name", 200});
    colData.push_back((element::Column){"description", 700});
    colData.push_back((element::Column){"modify", 100});
    colData.push_back((element::Column){"remove", 100});
    document->elements.push_back(new element::Table((sat2d::Vector){10, 10}, 300, colData));
    document->elements.push_back(new element::Prompt((sat2d::Vector){100, 100}, "do you want to", 200, 100));

    initwindow(1366, 768);
    // settextstyle(3, HORIZ_DIR, 3);

    while (1) {
        requestClearDevice = false;

        // hook click event
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            cleardevice();
            document->update();
            document->draw();
            delay(1000/framerate * 1.0);
            std::cout<<"test";
        }
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        document->onClick(mouseX, mouseY);
    }

    closegraph();
    getch();
}
