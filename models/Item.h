class model::Item : public model::Schema {
public:
    enum ItemType {GD, TP, TC};

    std::string name;
    ItemType type;
    int price;
    int weight;
    model::ddmmyyy productday;
    std::string expireday;
    std::string producer;

    void verify() {
        if (price > 10e9)
            throw "Gia san pham khong qua 10e9 VND";
        if (weight > 10e9)
            throw "Can nang san pham khong qua 10e9 VND";
        if ()
    }
};