#ifndef NAMESPACES
#define NAMESPACES
//Element: button, table, ...
namespace model {
    class Bill;
    class Employee;
    class Item;
}
#endif

class model::Model {
    public:
        int ai = 0;

        int auto_increase() {
            return this->ai++;
        }
}

#include<Bill.h>
#include<Employee.h>
#include<Item.h>