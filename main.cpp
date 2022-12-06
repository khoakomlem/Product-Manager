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
    std::vector<element::Element*> elements;
    initwindow(1366, 768);

    elements.push_back(new element::EditableLabel("Tesst", (element::Pos){10, 10}, 100, 100));
    elements.push_back(new element::Table((element::Pos){10, 10}, 300, 300, (element::Collumn[]){{"1", 10}, {"2", 20}, {"3", 30}}));
    elements[1]->visible = 0;

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
            elements[i]->update(&elements);
            requestClearDevice = elements[i]->draw();
        }
        std::cout << elements[1]->visible;
    }
    closegraph();
}
