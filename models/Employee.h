class model::Employee : public class model::Schema {
public:
    std::string name;
    std::string birthday;
    int citizen_id;
    std::string address;
    std::string mail;
    int phone;
    int working_yr;

    void verify() {
        if (name.length() > 256)
            throw "Tên không quá 256 kí tự";
        if (citizen_id / 1e11 == 0 || citizen_id / 1e11 > 9)
            throw "So cccd phai dung 12 chu so";
        if (address.length() > 256)
            throw "Dia chi thuong tru khong qua 256 ki tu";
        if (mail.length() > 256)
            throw "Dia chi mail khong qua 256 ki tu";
        if (phone / 1e9 == 0 || phone / 1e9 > 9)
            throw "So dien thoai lien lac phai dung 10 chu so";
    };
};
