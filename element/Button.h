class element::Button : public element::EditableLabel {
    public:
        int bounce = 3;
        bool draw() {
            element::EditableLabel::draw();
            rectangle(boundary.x - bounce, boundary.y - bounce, boundary.x + boundary.width + bounce, boundary.y + boundary.height + bounce);
            return false;
        }
        virtual void onClick(int mouseX, int mouseY) {
            element::EditableLabel::onClick(mouseX, mouseY);
            this->bounce = 0;
            this->draw();
            delay(200);
            this->bounce = 3;
        }

        Button(sat2d::Vector pos, std::string body, int width, int height) : EditableLabel(pos, body, width, height) {
        }
        Button() {
        }
};
