#include "vehicle.h"
#include <iostream>
#include "dialogs.h"
Vehicle::Vehicle()
{
}

Vehicle::Vehicle(int year,std::string make,std::string model,Body_style body_style):_year{year},_make{make},_model{model},_body_style{body_style},_renter{" "},_renter_dl{" "},_renter_phone{" "}
	{
		
	}
void Vehicle::rent_vehicle(std::string renter_name,std::string renter_drivers_license,std::string renter_phone)
	{
	  if(is_rented==false)
	    {
		_renter=renter_name;
		_renter_dl=renter_drivers_license;
		_renter_phone=renter_phone;
		is_rented=true;
	    }
	  else
	    {
	      // std::cout<<"The vehicle is already rented"<<std::endl;
	      Dialogs::message("The vehicle is already rented");
	    }
	}
void Vehicle::return_vehicle()
{
  if(is_rented)
    {
  is_rented=false;
    }
  else
    {
      Dialogs::message("The vehicle was not rented");
    }
}
std::string Vehicle::to_string()
{
  switch(_body_style)
    {
    case 0: return "SEDAN" ; break;
    case 1: return "HATCHBACK"; break;
    case 2: return "MINIVAN"; break;
    case 3: return "TRUCK"; break;
    case 4: return "SUV"; break;
    case 5: return "CROSSOVER"; break;
    case 6: return "SEDAN"; break;
    }
}
//std::ostream &operator<< (std::ostream &ost,Vehicle &vehicle)
//	{
//  std::string r;
// if(vehicle.is_rented)
//	    { 
//	      r="(Rented to "+vehicle._renter+" "+vehicle._renter_dl+" "+vehicle._renter_phone+")";
//	    }
//	  else
//	    {
//	      r= "  ";
//	    }
//
//	  ost<<vehicle._year<<" "<< vehicle._make<<" "<< vehicle._model<<" "<< vehicle.to_string()<<"       "<<r<<std::endl;
//        return ost;
// }

std::string Vehicle::get_list()
{
   std::string r;
 if(is_rented)
	    { 
	      r="(Rented to "+_renter+" "+_renter_dl+" "+_renter_phone+")";
	    }
	  else
	    {
	      r= "  ";
	    }
  std::string details=(std::to_string)(_year)+" "+_make+" "+_model+" "+to_string()+"  "+r;
  return details;
}
	   
