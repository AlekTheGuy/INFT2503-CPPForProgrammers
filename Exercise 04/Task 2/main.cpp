#include <gtkmm.h>
#include <string>

using namespace std;

class Window : public Gtk::Window {
private:
    /// Toggles the button based on the validity of the first and last name.
    void toggle_button();
    /// Name needs to contain a character other than whitespace to be valid.
    bool is_valid_name(string name);

public:
    Gtk::VBox vbox;
    Gtk::Label label_first_name;
    Gtk::Entry entry_first_name;
    Gtk::Label label_last_name;
    Gtk::Entry entry_last_name;
    Gtk::Button button;
    Gtk::Label label;

    Window() {
        this->set_title("Task 4");
        this->set_default_size (400, 200);
        label_first_name.set_text("First name");
        entry_first_name.set_text("");
        label_last_name.set_text("Last name");
        entry_last_name.set_text("");
        button.set_label("Combine names");
        button.set_sensitive(false);
        vbox.pack_start(label_first_name);  //Add the widget entry to vbox
        vbox.pack_start(entry_first_name);  //Add the widget entry to vbox
        vbox.pack_start(label_last_name);  //Add the widget entry to vbox
        vbox.pack_start(entry_last_name);  //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

       entry_first_name.signal_changed().connect([this]() {
            toggle_button();
        });

        entry_last_name.signal_changed().connect([this]() {
            toggle_button();
        });

        button.signal_clicked().connect([this]() {
            label.set_text(entry_first_name.get_text() + " " + entry_last_name.get_text());
        });
    }
};

void Window::toggle_button(){
    button.set_sensitive(is_valid_name(entry_first_name.get_text()) && is_valid_name(entry_last_name.get_text()));
}

bool Window::is_valid_name(string name){
    if(name.empty()) return false;
    for(size_t i = 0; i < name.length(); ++i){
        if(name[i] != ' '){
            return true;
        }
    }
    return false;
}

int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
