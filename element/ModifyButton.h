class element::ModifyButton : public element::ModifyButton {
    public:
        bool draw() {
            element::Button::draw();
            return false;
        }
        void onClick() {
            
        }
}