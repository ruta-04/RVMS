#ifndef __RENTAL_SITE
#define __RENTAL_SITE
#include "vehicle.h"
#include <vector>
class Rental_site
{
	public:
		Rental_site();
		void add_vehicle(Vehicle vehicle);
		void rent_vehicle(int vehicle,std::string renter_name,std::string renter_drivers_license,std::string renter_phone);
		void return_vehicle(int vehicle);
		std::string vehicles();
		
		void easter_egg();

	private:
		std::vector<Vehicle> _vehicles;
};

#endif
