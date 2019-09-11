#include "rental_site.h"
#include "dialogs.h"
Rental_site::Rental_site(){}
void Rental_site::add_vehicle(Vehicle vehicle)
{
  _vehicles.push_back(vehicle);
  //std::cout<<_vehicles[0];

}
void Rental_site::rent_vehicle(int vehicle,std::string renter_name,std::string renter_drivers_license,std::string renter_phone)
{
   _vehicles[vehicle].rent_vehicle(renter_name,renter_drivers_license,renter_phone);
 
}

void Rental_site:: return_vehicle(int vehicle)
{
  _vehicles[vehicle].return_vehicle();
}

std::string Rental_site::vehicles()
{
  //std::cout<<"in renter class";
  int i=0;
  //std::cout<<" "<<std::endl;
  //for(auto e:_vehicles)
  //  {
      //std::cout<<"inside the loop";
      //std::cout<<"("<< i<<") ";
      //std::cout<<e;
  //  std::string vehicle_details="("+std::to_string(i)+")"+std::cout<<e;
  //   i++;
  // }
  //std::cout<<"out of the loop";
  std::string temp=" ";
  for(i=0;i<_vehicles.size();i++)
    {
      temp=temp+"("+(std::to_string(i))+")  "+_vehicles[i].get_list()+"\n";
    
    }
  return temp;
 
}

void Rental_site::easter_egg()
{
  add_vehicle(Vehicle(2014,"Tesla","Model_S_85",(Body_style)0));
  add_vehicle(Vehicle(2014,"Telsa","Model_3_lr",(Body_style)3));
  add_vehicle(Vehicle(2014,"Honda","Model_S_100",(Body_style)4));
  add_vehicle(Vehicle(2014,"Audi","Model_S_85",(Body_style)1));
  
}
