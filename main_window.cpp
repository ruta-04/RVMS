#include "main_window.h"
#include "controller.h"
#include "rental_site.h"
//#include "view.h"
Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //   F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
   Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //Vehicle
    //Create a vehicle menu and add to the menu bar
    Gtk::MenuItem *menuitem_vehicle=Gtk::manage(new Gtk::MenuItem("Vehicle",true));
    menubar->append(*menuitem_vehicle);
    Gtk::Menu *vehiclemenu=Gtk::manage(new Gtk::Menu());
    menuitem_vehicle->set_submenu(*vehiclemenu);

    //add vehcile
    Gtk::MenuItem *menuitem_addVehicle=Gtk::manage(new Gtk::MenuItem("New",true));
    menuitem_addVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_addVehicle_click));
    vehiclemenu->append(*menuitem_addVehicle);

    //list vehicle
    Gtk::MenuItem *menuitem_listVehicle=Gtk::manage(new Gtk::MenuItem("List",true));
    menuitem_listVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_listVehicle_click));
    vehiclemenu->append(*menuitem_listVehicle);

    //rent vehicle
    Gtk::MenuItem *menuitem_rentVehicle=Gtk::manage(new Gtk::MenuItem("Rent",true));
    menuitem_rentVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_rentVehicle_click));
    vehiclemenu->append(*menuitem_rentVehicle);

    //retrun vehicle
    Gtk::MenuItem *menuitem_returnVehicle=Gtk::manage(new Gtk::MenuItem("Return",true));
    menuitem_returnVehicle->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_returnVehicle_click));
    vehiclemenu->append(*menuitem_returnVehicle);

    //magic
    Gtk::MenuItem *menuitem_magic=Gtk::manage(new Gtk::MenuItem("Magic",true));
    menuitem_magic->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_magic_click));
    vehiclemenu->append(*menuitem_magic);

    
    //         N E W   G A M E
    // Append New to the File menu
    //Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Game", true));
    //menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_game_click));
    //filemenu->append(*menuitem_new);

    
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   G A M E
    // Add a new game icon
    //Gtk::ToolButton *new_game_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    //new_game_button->set_tooltip_markup("Create a new name, discarding any in progress");
    //new_game_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_game_click));
    //toolbar->append(*new_game_button);

    //     O N E   S T I C K
    // Add a icon for taking one stick
    //button1_on_image = Gtk::manage(new Gtk::Image{"button1_on.png"});
    //button1_off_image = Gtk::manage(new Gtk::Image{"button1_off.png"});
    //button1 = Gtk::manage(new Gtk::ToolButton(*button1_on_image));
    //button1->set_tooltip_markup("Select one stick");
    //button1->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button1_click));
    //toolbar->append(*button1);

    //     T W O   S T I C K S
    // Add a icon for taking two sticks
    //button2_on_image = Gtk::manage(new Gtk::Image{"button2_on.png"});
    //button2_off_image = Gtk::manage(new Gtk::Image{"button2_off.png"});
    //button2 = Gtk::manage(new Gtk::ToolButton(*button2_on_image));
    //button2->set_tooltip_markup("Select two sticks");
    //button2->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button2_click));
    //toolbar->append(*button2);

    //     T H R E E   S T I C K S
    // Add a icon for taking three sticks
//    button3_on_image = Gtk::manage(new Gtk::Image{"button3_on.png"});
//    button3_off_image = Gtk::manage(new Gtk::Image{"button3_off.png"});
//    button3 = Gtk::manage(new Gtk::ToolButton(*button3_on_image));
//    button3->set_tooltip_markup("Select three sticks");
//    button3->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button3_click));
//    toolbar->append(*button3);
//
//    //     C O M P U T E R   P L A Y E R
//    // Add a toggle button to enable computer to play as Player 2
//    Gtk::Image *robot_image = Gtk::manage(new Gtk::Image{"freepik_robot.png"});
//    computer_player = Gtk::manage(new Gtk::ToggleToolButton(*robot_image));
//    computer_player->set_tooltip_markup("Enable for computer to be Player 2");
//    computer_player->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_computer_player_click));
//    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
//    toolbar->append(*sep1);
//    toolbar->append(*computer_player);
//
//    //     Q U I T
//    // Add a icon for quitting
   Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
   quit_button->set_tooltip_markup("Exiting");
   quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
   Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
   sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);
//
//    // S T I C K S   D I S P L A Y
//    // Provide a text entry box to show the remaining sticks
//    sticks = Gtk::manage(new Gtk::Label());
//    // sticks->set_has_frame(false);
//    sticks->set_hexpand(true);
//    sticks->set_vexpand(true);
//    vbox->add(*sticks);
    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
//    msg = Gtk::manage(new Gtk::Label());
//    msg->set_hexpand(true);
//    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    //on_new_game_click();
}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

//void Main_window::on_button1_click() {
//    nim->take_sticks(1);
//    set_sticks();
//}
//
//void Main_window::on_button2_click() {
//    nim->take_sticks(2);
//    set_sticks();
//}
//
//void Main_window::on_button3_click() {
//    nim->take_sticks(3);
//    set_sticks();
//}
//
//void Main_window::on_computer_player_click() {
//    set_sticks();
//}
//
//void Main_window::on_new_game_click() {
//    nim = new Nim();
//    set_sticks();
//}

void Main_window::on_addVehicle_click(){
  c.execute_cmd(1) ;
}
void Main_window::on_listVehicle_click(){
  c.execute_cmd(2) ;
}
void Main_window::on_rentVehicle_click(){
  c.execute_cmd(3) ;
}
void Main_window::on_returnVehicle_click(){
  c.execute_cmd(4) ;
}
void Main_window::on_magic_click(){
  c.execute_cmd(42) ;
}


void Main_window::on_quit_click() {
    hide();
}

void Main_window::on_about_click() {
  
  v.help();
  // Glib::ustring s = "<span size='24000' weight='bold'>Nim</span>\n<span size='large'>Copyright 2017 by George F. Rice</span>\n<span size='small'>Licensed under Creative Commons Attribution 4.0 International\nRobot icon created by Freepik, used under free attribution license</span>";
  // Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
  //dlg.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

//void Main_window::set_sticks() {
//    // s collects the status message
//    Glib::ustring s = "";
//
//    // If the robot is enabled and it's their turn, move the robot
//    if (nim->sticks_left() > 0) {
//        if (computer_player->get_active() && nim->current_player() == 2) {
//           s += "Robot plays " + std::to_string(nim->optimal_move()) + ", ";
//           nim->take_sticks(nim->optimal_move());
//        }
//    }
//
//    // Report who's turn it is, or (if all sticks gone) who won
//    if (nim->sticks_left() > 0) {
//        s += "Player " + std::to_string(nim->current_player()) + "'s turn";
//    } else {
//        s += "<span size='16000' weight='bold'>Player "
//              +  std::to_string(3-nim->current_player())
//              +  " wins!</span>";
//    }
//
//    // Display the collected status on the status bar
//    msg->set_markup(s);
//
//    // Update the visual display of sticks
//    s = "<span size='24000' weight='bold'>";
//    for(int i=0; i<nim->sticks_left(); ++i) s.append("| ");
//    s.append("</span>  (" + std::to_string(nim->sticks_left()) + " sticks)");
//    sticks->set_markup(s);
//
//    // Set sensitivity of the human stick selectors so user can't make an illegal move
//    button1->set_sensitive(nim->sticks_left() > 0);
//    button2->set_sensitive(nim->sticks_left() > 1);
//    button3->set_sensitive(nim->sticks_left() > 2);
//}

