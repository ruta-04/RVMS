#include "view.h"
#include "controller.h"
#include "rental_site.h"
#include "dialogs.h"
View::View()
{
}
View::View(Rental_site rental_site):_rental_site{rental_site}
{
}
int View::main_menu()
{
  //std::string menu=R"(
  //<span font='18' weight='bold'underline='double'underline_color='#7D3C98' background='#D6EAF8'>
  //C1325 Rental Vehicle Management System </span><sup><small><b>TM</b></small></sup>

  //<span weight='bold'underline='single' underline_color='red'>
  //Vehicles</span>

  //(1) Add vehicle
  ///(2) List all Vehicles	
  //(3) Rent vehicle
  //(4) Return vehicle

  //<span weight='bold'underline='single' underline_color='red'>
  //Utility</span>

  //(9)<span foreground='green'> Help </span>
  //(0) Exit 
  //)";
  // std::string result= Dialogs::input("ruta","Input");
  //	try{
  //	  return 1;
  //	}
  //	catch(...)
  //	  {
  //	    return 0;
  //	  }
        
}

std::string View::help()
{
  Dialogs::message("This program manages a fleet of rental vehicles. Adding a vehicle (option 1) requires a year, make, model, body_style. This year may be any integer and make and make are strings. The body_style is selected from a list. Adding a body_style requires a program change.Listing all vehicles (option 2) displays all information known about vehicles, including the identity of their respective renters. Renting a vehicle(option 3) requires a renter's name, license, and phone number. Returing a vehicle(option 4) requires no additional information");

	return " ";
}

void View::list_of_vehicles()
{
  //  std::cout<<"in view clas";
  _rental_site.vehicles();
 
}
