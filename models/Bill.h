class model::Bill : public model::Schema {
    // std::string create_at;
    std::vector<int> items;
    int overall;
    int input;
    int output;
    int employ_id;

    void verify() {
        if (overall > 10e9)
            throw "Tổng tiền (Số nguyên không quá 10^9).";
        if (input > 10e9)
            throw "Tiền thu từ khách (Số nguyên không quá 10^9).";
        if (output > 10e9)
            throw "Tiền trả khách (Số nguyên không quá 10^9).";
    }
};