class element::Prompt : public element::Element {
    public:
        int width;
        int height;
        element::OneTimeButton confirmBtn;
        element::OneTimeButton cancelBtn;
        element::OneTimeButton closeBtn;
        element::EditableLabel body;

        bool draw() {
            element::Element::draw();
            rectangle(pos.x, pos.y, pos.x + width, pos.y + height);
            return false;
        }

        bool isMouseHovering(int mouseX, int mouseY) {
            return sat2d::pointInBox((sat2d::Vector){mouseX, mouseY}, (sat2d::Box){(sat2d::Vector){pos.x, pos.y}, width, height});
        }

        void onClick(int mouseX, int mouseY) {
            element::Element::onClick(mouseX, mouseY);
            if (this->closeBtn.clicked || this->cancelBtn.clicked) {
                this->markAsRemove = true;
            }
            if (this->confirmBtn.clicked) {
                // do something
            }
        }

        Prompt(sat2d::Vector pos, std::string body, int width, int height) : Element(pos) {
            this->width = width;
            this->height = height;
            int btnWidth = (3.5/12)*width;
            int btnHeight = (1.5/8)*height;
            this->confirmBtn = *(new element::OneTimeButton(
                (sat2d::Vector){(int)(pos.x + (0.5/12.0) * width), (int)(pos.y + (6/8.0) * height)},
                "confirm",
                btnWidth,
                btnHeight
            ));
            this->cancelBtn = *(new element::OneTimeButton(
                (sat2d::Vector){(int)(pos.x + (8/12.0) * width),
                (int)(pos.y + (6/8.0) * height)},
                "cancel",
                btnWidth,
                btnHeight
            ));
            this->closeBtn = *(new element::OneTimeButton(
                (sat2d::Vector){(int)(pos.x + (11.5/12.0) * width), pos.y},
                "x",
                (int)((0.5/12.0)*width),
                (int)((0.5/12.0)*width)
            ));
            this->body = *(new element::EditableLabel(
                (sat2d::Vector){(int)(pos.x + (0.5/12.0) * width), (int)(pos.y + (2/8.0) * height)},
                body,
                (int)( (11.5/12.0) * width ),
                (int)( (4/8.0) * height )
            ));
            this->elements.push_back(&this->confirmBtn);
            this->elements.push_back(&this->cancelBtn);
            this->elements.push_back(&this->closeBtn);
            this->elements.push_back(&this->body);
        }
};
