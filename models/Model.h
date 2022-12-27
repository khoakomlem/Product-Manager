namespace model {
    struct ddmmyyy {
        int dd;
        int mm;
        int yyyy;
    };
    template <typename T> class Model;
    class Bill;
    class Employee;
    class Item;
};

template <typename Schema> class model::Model {
    public:
        int ai = 0;
        std::vector<Schema> list;

        int auto_increase() {
            return this->ai++;
        }

        bool remove(int id) {
            int index = this->findIndexById(id);
            if (index != -1) {
                this->list.erase(list.begin() + 1);
                return true;
            }
            return false;
        }

        int findIndexById(int id) {
            for (int i = 0; i != list.size(); ++i) {
                if (list[i].id == id) {
                    return i;
                }
            }
            return -1;
        }

        bool add(Schema document) {
            document.id = this->auto_increase();
            document.create_at = model::ddmmyyy{1, 1, 1};
            this->list.push_back(document);
            return true;
        }
};

class model::Schema {
    int id;
    int create_at;
}

#include "Bill.h"
#include "Employee.h"
#include "Item.h"
