#include "Model.hpp"

Model::Schema::Schema(int id, Util::ddmmyyyy create_at) {
    this->id = id;
    this->create_at = create_at;
}
Model::Schema::Schema() {}

void Model::Bill::verify() {
    if (overall > 10e9)
        throw (std::string)"Tổng tiền (Số nguyên không quá 10^9).";
    if (input > 10e9)
        throw (std::string)"Tiền thu từ khách (Số nguyên không quá 10^9).";
    if (output > 10e9)
        throw (std::string)"Tiền trả khách (Số nguyên không quá 10^9).";
}
Model::Bill::Bill(std::vector<int> items, int overall, int input, int output, int employ_id) {
    this->items = items;
    this->overall = overall;
    this->input = input;
    this->output = output;
    this->employ_id = employ_id;
};

void Model::Employee::verify() {
    if (name.length() > 256)
        throw (std::string)"Tên không quá 256 kí tự";
    if (citizen_id / 1e11 == 0 || citizen_id / 1e11 > 9)
        throw (std::string)"So cccd phai dung 12 chu so";
    if (address.length() > 256)
        throw (std::string)"Dia chi thuong tru khong qua 256 ki tu";
    if (mail.length() > 256)
        throw (std::string)"Dia chi mail khong qua 256 ki tu";
    if (phone / 1e9 == 0 || phone / 1e9 > 9)
        throw (std::string)"So dien thoai lien lac phai dung 10 chu so";
};
Model::Employee::Employee(std::string name, std::string birthday, int citizen_id, std::string address, std::string mail, int phone, int working_yr) {
    this->name = name;
    this->birthday = birthday;
    this->citizen_id = citizen_id;
    this->address = address;
    this->mail = mail;
    this->phone = phone;
    this->working_yr = working_yr;
};
Model::Employee::Employee() {};

void Model::Item::verify() {
    if (price > 10e9)
        throw (std::string)"Gia san pham khong qua 10e9 VND";
    if (weight > 10e9)
        throw (std::string)"Can nang san pham khong qua 10e9 VND";
    if (expireday > 12)
        throw (std::string)"Han su dung khong qua 12";
    if (producer.length() > 256)
        throw (std::string)"Nha san xuat khong qua 256 ki tu";
}
Model::Item::Item(std::string name, ItemType type, int price, int weight, Util::ddmmyyyy productday, int expireday, std::string producer) {
    this->name = name;
    this->type = type;
    this->price = price;
    this->weight = weight;
    this->productday = productday;
    this->expireday = expireday;
    std::cout<<expireday;
    this->producer = producer;
};
Model::Item::Item() {};