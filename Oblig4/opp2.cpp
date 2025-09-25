//
// Created by Sebastian E Burmo on 25/09/2025
// Oppgave 2 - Kombinerte navn program
// Source code: https://gitlab.com/ntnu-iini4003/gtkmm-example

#include <gtkmm.h>

// Create a class with all widgets as members
class NameWindow : public Gtk::Window {
public:
    Gtk::Box main_box;
    Gtk::Box name_box;
    Gtk::Label first_name_label;
    Gtk::Entry first_name_entry;
    Gtk::Label last_name_label;
    Gtk::Entry last_name_entry;
    Gtk::Button combine_button;
    Gtk::Label result_label;

    NameWindow() : main_box(Gtk::ORIENTATION_VERTICAL, 10),
                   name_box(Gtk::ORIENTATION_HORIZONTAL, 10) {

        // Set window properties with size and width
        set_title("ØVING 4");
        set_default_size(400, 200);
        set_border_width(10);

        // Application Labels
        first_name_label.set_text("First name:");
        last_name_label.set_text("Last name:");

        // Button properties
        combine_button.set_label("Combine names");
        combine_button.set_sensitive(false); // Initially disabled

        // Set up result label, empty string which fills with content when button pressed
        result_label.set_text("");

        // First name
        Gtk::Box* first_name_box = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_HORIZONTAL, 5);
        first_name_box->pack_start(first_name_label, false, false);
        first_name_box->pack_start(first_name_entry, true, true);

        // Last name
        Gtk::Box* last_name_box = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_HORIZONTAL, 5);
        last_name_box->pack_start(last_name_label, false, false);
        last_name_box->pack_start(last_name_entry, true, true);

        // Add everything to main box
        main_box.pack_start(*first_name_box, false, false);
        main_box.pack_start(*last_name_box, false, false);
        main_box.pack_start(combine_button, false, false);
        main_box.pack_start(result_label, false, false);

        add(main_box);
        show_all();

        // Connect signals
        first_name_entry.signal_changed().connect(
            sigc::mem_fun(*this, &NameWindow::on_entry_changed));
        last_name_entry.signal_changed().connect(
            sigc::mem_fun(*this, &NameWindow::on_entry_changed));
        combine_button.signal_clicked().connect(
            sigc::mem_fun(*this, &NameWindow::on_combine_clicked));
    }

private:
    void on_entry_changed() {
        // Enable button only if both entries have text
        bool both_filled = !first_name_entry.get_text().empty() &&
                          !last_name_entry.get_text().empty();
        combine_button.set_sensitive(both_filled);

        // Clear result if entries change
        result_label.set_text("");
    }

    void on_combine_clicked() {
        std::string first_name = first_name_entry.get_text();
        std::string last_name = last_name_entry.get_text();
        std::string full_name = first_name + " " + last_name;
        result_label.set_text("Names Combined: " + full_name); // Show combined names as result in the empty string in resultlabel
    }
};

// The same main as the gtkmm example repo
int main() {
    auto app = Gtk::Application::create();
    NameWindow window;
    return app->run(window);
}