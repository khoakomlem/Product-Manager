class element::Button : public element::EditableLabel {
    public:
        bool draw() {
            element::EditableLabel::draw();
            // rectangle(100,100,200,200);
            return false;
        }
        void onClick(int mouseX, int mouseY) {
            std::cout<<"test";
        }

        Button(std::string body, sat2d::Vector pos, int width, int height) : EditableLabel(body, pos, width, height) {

        }
};
