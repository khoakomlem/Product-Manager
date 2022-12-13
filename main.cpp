#include <algorithm>
#include <vector>
#include<math.h>
#include<graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include "element/Element.h"

int main()
{
    std::cout<<"noob";
    std::vector<element::Element*> elements;
    initwindow(1366, 768);
    elements.push_back(new element::EditableLabel("Tesst", (element::Pos){10, 10}, 100, 100));
    element::Column arr[3] = {{"1", 10}, {"2", 20}, {"3", 30}};

    // list item table
    std::vector<element::Column> cData;
    cData.push_back((element::Column){"id", 100});
    cData.push_back((element::Column){"name", 200});
    cData.push_back((element::Column){"description", 700});
    cData.push_back((element::Column){"modify", 50});
    cData.push_back((element::Column){"remove", 50});
    elements.push_back(new element::Table((element::Pos){10, 10}, 300, cData));

    bool requestClearDevice = false;

    while (1) {
        if (requestClearDevice) {
            cleardevice();
            requestClearDevice = false;
        }
        for(std::vector<element::Element*>::size_type i = 0; i != elements.size(); i++) {
            if (elements[i]->markAsRemove) {
                elements.erase(elements.begin() + i);
                i--;
                continue;
            }
            elements[i]->update();
            requestClearDevice = elements[i]->draw();
        }
    }

    closegraph();
    getch();
}
