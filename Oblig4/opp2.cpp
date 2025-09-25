#include <gtkmm.h>

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

        // Set window properties
        set_title("Name Combiner");
        set_default_size(400, 200);
        set_border_width(10);

        // Set up labels
        first_name_label.set_text("First name:");
        last_name_label.set_text("Last name:");

        // Set up button
        combine_button.set_label("Combine names");
        combine_button.set_sensitive(false); // Initially disabled

        // Set up result label
        result_label.set_text("");

        // Pack first name widgets
        Gtk::Box* first_name_box = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_HORIZONTAL, 5);
        first_name_box->pack_start(first_name_label, false, false);
        first_name_box->pack_start(first_name_entry, true, true);

        // Pack last name widgets
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

        // Clear result when entries change
        result_label.set_text("");
    }

    void on_combine_clicked() {
        std::string first_name = first_name_entry.get_text();
        std::string last_name = last_name_entry.get_text();
        std::string full_name = first_name + " " + last_name;
        result_label.set_text("Full name: " + full_name);
    }
};

int main() {
    auto app = Gtk::Application::create("org.example.namecombiner");
    NameWindow window;
    return app->run(window);
}