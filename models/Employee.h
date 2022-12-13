class model::Employee : model::Model {
    public:
        int id;
        string name;
        string datetime;
        int citizen_id;
        string address;
        string mail;
        int phone;
        int working_yr;

        Bill(string create_at, std::vector<int> items, int overall, int output, int employ_id) {
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