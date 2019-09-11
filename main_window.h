#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "view.h"
#include <gtkmm.h>
#include "rental_site.h"
#include "vehicle.h"
#include "controller.h"


class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
//        void on_new_game_click();        // Create a new game
//        void on_button1_click();         // Select one stick from pile
//        void on_button2_click();         // Select two sticks from pile
//        void on_button3_click();         // Select three sticks from pile
//        void on_computer_player_click(); // Enable / disable computer player
        void on_about_click();           // Display About dialog
      void on_quit_click();           // Exit the game
	void on_addVehicle_click();
	void on_listVehicle_click();
	void on_rentVehicle_click();
	void on_returnVehicle_click();
	void on_magic_click();

    private:
		View  v;
//        void set_sticks();                    // Update display, robot move
		Rental_site rental_site;
	Controller c;

//
//        Gtk::Label *sticks;                   // Display of sticks on game board
//        Gtk::Label *msg;                      // Status message display
//        Gtk::ToolButton *button1;             // Button to select 1 stick
//        Gtk::Image *button1_on_image;         //   Image when active
//        Gtk::Image *button1_off_image;        //   Image when inactive
//        Gtk::ToolButton *button2;             // Button to select 2 sticks
//        Gtk::Image *button2_on_image;
//        Gtk::Image *button2_off_image;
//        Gtk::ToolButton *button3;             // Button to select 3 sticks
//        Gtk::Image *button3_on_image;
//        Gtk::Image *button3_off_image;
//        Gtk::ToggleToolButton *computer_player;  // Button to enable robot
};
#endif 

