class model::Bill : model::Model {
    public:

        struct ddmmyyy {
            int dd;
            int mm;
            int yyyy;
        }

        int id;
        string create_at;
        std::vector<int> items;
        int overall;
        int input;
        int output;
        int employ_id;

        Bill(int create_at, std::vector<int> items, int overall, int output, int employ_id) : Model() {
            this->id = this->auto_increase();
            this->create_at = datetimeParse(create_at);
            this->items = items;
            if (overall > 10e9)
                throw "Tổng tiền (Số nguyên không quá 10^9)."
            this->overall = overall;
            if (input > 10e9)
                throw "Tiền thu từ khách (Số nguyên không quá 10^9)."
            this->input = input;
            if (output > 10e9)
                throw "Tiền trả khách (Số nguyên không quá 10^9)."
            this->output = output;
            this->employ_id = employ_id;
        }

        ddmmyyyy datetimeParse(int time) {
            int yyyy = time % 10000;
            int mm = (time % 1000000) / 10000;
            int dd = (time % 100000000) / 1000000;
            return (ddmmyyy){yyyy, mm, dd};
        }
}