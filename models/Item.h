enum ItemType {GD, TP, TC}

struct Item {
    int id;
    std::string name;
    ItemType type;
    int price;
    int weight;
    string datetime;
    string expire;
    string producer;
}