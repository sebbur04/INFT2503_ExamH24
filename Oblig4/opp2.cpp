//
// Created by Sebastian E Burmo on 25/09/2025
// Oppgave 2 - Kombinerte navn program
// Source code: https://gitlab.com/ntnu-iini4003/gtkmm-example , used as a kind of template

#include <gtkmm.h>

// Create a class with all widgets as members
class Window : public Gtk::Window {
public:
    Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL, 5};
    Gtk::Label first_name_label, last_name_label, label;
    Gtk::Entry first_name_entry, last_name_entry;
    Gtk::Button button{"Combine names"};

    // Set window properties with size and width
    Window() {
        set_title("Øving 4");
        set_default_size(400, 200);
        // Application Labels
        first_name_label.set_text("First name");
        last_name_label.set_text("Last name");
        button.set_sensitive(false);

        // Add widgets to the vertical box, using PACK_SHRINK to keep natural size
        // Found it on the box.h docks
        vbox.pack_start(first_name_label, Gtk::PACK_SHRINK);
        vbox.pack_start(first_name_entry, Gtk::PACK_SHRINK);
        vbox.pack_start(last_name_label, Gtk::PACK_SHRINK);
        vbox.pack_start(last_name_entry, Gtk::PACK_SHRINK);
        vbox.pack_start(button, Gtk::PACK_SHRINK);
        vbox.pack_start(label, Gtk::PACK_SHRINK);

        // Show All make all widgets visible, while vbox is beeing part of window
        add(vbox);
        show_all();

        //First name and last name entry must be filled to enable button
        first_name_entry.signal_changed().connect([this]() {
            button.set_sensitive(
                !first_name_entry.get_text().empty() &&
                !last_name_entry.get_text().empty()
            );
        });

        last_name_entry.signal_changed().connect([this]() {
            button.set_sensitive(
                !first_name_entry.get_text().empty() &&
                !last_name_entry.get_text().empty()
            );
        });

        //When the button is clicked, comine name and show it in the label with set_text
        button.signal_clicked().connect([this]() {
            label.set_text("Names combined: " +
                first_name_entry.get_text() + " " +
                last_name_entry.get_text());
        });
    }
};

// Same as the example code from the repo
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    Window window;
    return app->run(window);
}
