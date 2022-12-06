#include <graphics.h>
#include <functional>
#include <iostream>
#include <memory>
#include <cstddef>


struct element::Column {
    std::string header;
    int size;
}

class element::Table : public element::Element {
    public:
        static const int COL_SIZE = 25;

        int width;
        int height;
        int cols;
        int rows;
        element::Column* colData;

        void update(std::vector<element::Element*>* elements) {
            for(std::vector<int>::size_type i = 0; i != (*elements).size(); i++) {
                //(*elements)[i]->visible = 1;
                //std::cout << i;
            }
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {

                }
            }
        }

        bool draw() {
            // draw frame
            rectangle(pos.x, pos.y, pos.x + width, pos.y + height);

            // draw columns
            int curX = pos.x;
            for(std::vector<element::Column*>::size_type i = 0; i != (*colData).size(); i++) {
                curX += colData[i];
                line(curX, pos.y, curX, pos.y + height);
            }

            // draw rows
            int size = 25;
            for(int curY = pos.y; curY < pos.y + height; curY+=size) {
                line(pos.x, curY, pos.x + width, curY);
            }
            return false;
        }

        Table(element::Pos pos, int width, int height, element::Column colData[]) : Element(pos) {
            this->width = width;
            this->height = height;
            this->colSizes = colSizes; // size - 1
            this->rows = (pos.y + height) % COL_SIZE + 1;

            std::vector<element::Column> sizes(colData, colData + sizeof(colData)/sizeof(element::Column));
            this->colData = colData;
        }
};
