#ifndef MODEL
#define MODEL
#include <iostream>
#include "../Util/Util.hpp"

namespace Model {
    class Schema {
    public:
        int id;
        Util::ddmmyyyy create_at;

        Schema(int id, Util::ddmmyyyy create_at);
        Schema();
    };

    class Bill : public Schema {
    public:
        std::vector<int> items;
        int overall;
        int input;
        int output;
        int employ_id;

        void verify();
        Bill(std::vector<int> items, int overall, int input, int output, int employ_id);
        Bill();
    };

    class Employee : public Schema {
    public:
        std::string name;
        std::string birthday;
        int citizen_id;
        std::string address;
        std::string mail;
        int phone;
        int working_yr;

        void verify();
        Employee(std::string name, std::string birthday, int citizen_id, std::string address, std::string mail, int phone, int working_yr);
        Employee();
    };

    class Item : public Schema {
    public:
        enum ItemType {GD, TP, TC};

        std::string name;
        ItemType type;
        int price;
        int weight;
        Util::ddmmyyyy productday;
        int expireday;
        std::string producer;

        void verify();
        Item(std::string name, ItemType type, int price, int weight, Util::ddmmyyyy productday, int expireday, std::string producer);
        Item();
    };
};

#endif