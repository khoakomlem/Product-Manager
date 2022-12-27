#include <algorithm>
#include <vector>
#include<math.h>
#include<graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include "models/Model.h"
#include "sat2d/Sat2d.h"
#include "element/Element.h"
#include "global.h"

// utils
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int main()
{
    Global global;
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
    document->elements.push_back(new element::OneTimeButton((sat2d::Vector){10, 330}, "Add", 120, 40));
    document->elements.push_back(new element::OneTimeButton((sat2d::Vector){10, 380}, "Charge", 120, 40));
    document->elements.push_back(new element::Table((sat2d::Vector){10, 10}, 300, colData));
    document->elements.push_back(new element::Prompt((sat2d::Vector){300, 330}, "do you want to", 600, 200));

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
            delay(1000.0/framerate);
        }
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        document->onClick(mouseX, mouseY);
    }

    closegraph();
    getch();
}
