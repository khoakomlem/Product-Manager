enum ItemType {GD, TP, TC}

class model::Employee : model::Model {
    public:
        int id;
        std::string name;
        ItemType type;
        int price;
        int weight;
        string datetime;
        string expire;
        string producer;

        Employee(string create_at, std::vector<int> items, int overall, int output, int employ_id) {
            this->id = id;
            this->create_at = create_at;
            this->overall = overall;
            this->input = input;
            this->output = output;
            this->employ_id = employ_id;
            this->verify();
        }

        verify() {
            this->id 
        }
}