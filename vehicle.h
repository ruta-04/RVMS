#ifndef __VEHICLE_H
#define __VEHICLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

enum Body_style
{
	SEDAN,
	HATCHBACK,
	MINIVAN,
	TRUCK,
	SUV,
	CROSSOVER,
};


class Vehicle
{
	public:
		Vehicle();
		Vehicle(int year,std::string make,std::string model,Body_style body_style);
		void rent_vehicle(std::string renter_name,std::string renter_drivers_license,std::string renter_phone);
		void return_vehicle();
		//friend std::ostream &operator<< (std::ostream &ost, Vehicle &vehicle);
std::string get_list();
		std::string to_string();
		
	
	protected:
		std::string _make;
		std::string _model;
		int _year;
		Body_style _body_style;
		bool is_rented=false;
		std::string _renter;
		std::string _renter_dl;
		std::string _renter_phone;
};

#endif		
