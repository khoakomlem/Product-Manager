class element::Prompt : public element::Element {
    public:
        int width;
        int height;
        element::OneTimeButton confirmBtn;
        element::OneTimeButton cancelBtn;
        element::OneTimeButton closeBtn;

        bool draw() {
            element::Element::draw();
            rectangle(pos.x, pos.y, pos.x + width, pos.y + height);
            return false;
        }

        bool isMouseHovering(int mouseX, int mouseY) {
            return sat2d::pointInBox((sat2d::Vector){mouseX, mouseY}, (sat2d::Box){(sat2d::Vector){pos.x, pos.y}, width, height});
        }

        Prompt(sat2d::Vector pos, std::string body, int width, int height) : Element(pos) {
            this->width = width;
            this->height = height;
            int btnWidth = (3.5/12)*width;
            int btnHeight = (1.5/8)*height;
            this->confirmBtn = *(new element::OneTimeButton((sat2d::Vector){(int)(pos.x + (0.5/12.0) * width), (int)(pos.y + (6/8.0) * height)}, "confirm", btnWidth, btnHeight));
            this->cancelBtn = *(new element::OneTimeButton((sat2d::Vector){(int)(pos.x + (8/12.0) * width), (int)(pos.y + (6/8.0) * height)}, "cancel", btnWidth, btnHeight));
            this->closeBtn = *(new element::OneTimeButton((sat2d::Vector){(int)(pos.x + (10.5/12.0) * width), pos.y}, "x", (int)((1.5/12.0)*width), (int)((1.5/12.0)*width)));
            this->elements.push_back(&this->confirmBtn);
            this->elements.push_back(&this->cancelBtn);
            this->elements.push_back(&this->closeBtn);
        }
};
