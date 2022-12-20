class element::OneTimeButton : public element::Button {
    public:
        bool clicked = false;

        virtual void onClick(int mouseX, int mouseY) {
            element::Button::onClick(mouseX, mouseY);
            this->clicked = true;
        }

        bool isMouseHovering(int mouseX, int mouseY) {
            return sat2d::pointInBox((sat2d::Vector){mouseX, mouseY}, (sat2d::Box){(sat2d::Vector){pos.x, pos.y}, boundary.width, boundary.height});
        }

        OneTimeButton(sat2d::Vector pos, std::string body, int width, int height) : Button(pos, body, width, height) {

        }
        OneTimeButton() {
        }
};
