class Bill {
    int id;
    string create_at;
    std::vector<int> items;
    int overall;
    int input;
    int output;
    int employ_id;

    Bill(int id, string create_at, std::vector<int> items, int overall, int output, int employ_id) {
        this->id = id;
        this->create_at = create_at;
        this->overall = overall;
        this->input = input;
        this->output = output;
        this->employ_id = employ_id;
    }
}