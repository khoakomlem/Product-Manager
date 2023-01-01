#ifndef UTIL
#define UTIL
#include <vector>

namespace Util {
    struct ddmmyyyy {
        int dd;
        int mm;
        int yyyy;
    };

    template <typename Schema> class Manager {
    public:
        int ai = 0;
        std::vector<Schema> items;

        int auto_increase() {
            return this->ai++;
        }

        bool remove(int id) {
            int index = this->findIndexById(id);
            if (index != -1) {
                this->items.erase(this->items.begin() + 1);
                return true;
            }
            return false;
        }    

        int findIndexById(int id) {
            for (int i = 0; i != items.size(); ++i) {
                if (items[i].id == id) {
                    return i;
                }
            }
            return -1;
        }

        bool add(Schema document) {
            document->id = this->auto_increase();
            document->create_at = Util::ddmmyyyy{1, 1, 1};
            this->items.push_back(document);
            return true;
        }
    };
}

#endif