#include <graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include <cstddef>


struct element::Column {
    std::string header;
    int size;
};

class element::Table : public element::Element {
    public:
        static const int COL_SIZE = 25;

        int width;
        int height;
        std::vector<element::Column> colData; // array of collumn size
        std::vector<std::vector<element::Element*> > rowData; // 2d array table data

        bool isMouseHovering(int mouseX, int mouseY) {
            return sat2d::pointInBox((sat2d::Vector){mouseX, mouseY}, (sat2d::Box){pos, width, height});
        }

        void onClick(int mouseX, int mouseY) {
            element::Element::onClick(mouseX, mouseY);
        }

        void update() {
            element::Element::update();
        }

        bool draw() {
            element::Element::draw();

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

        addRow(std::vector<element::Element*> data) {
            this->rowData.push_back(data);
            for (int i = 0; i != data.size(); ++i) {
                this->elements.push_back(data[i]);
            }
        }

        Table(sat2d::Vector pos, int height, std::vector<element::Column> cData) : Element(pos) {
            this->height = height;
            this->width = 0;
            std::vector<element::Element*> headers;
            int curX = 10;
            for (int i = 0; i != cData.size(); ++i) {
                this->width += cData[i].size;
                headers.push_back(new element::EditableLabel((sat2d::Vector){curX, 10}, cData[i].header, cData[i].size, COL_SIZE));
                curX += cData[i].size;
            }
            this->addRow(headers);
            this->colData = cData;
        }
};
