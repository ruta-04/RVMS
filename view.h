#ifndef __VIEW_H
#define __VIEW_H
#include "controller.h"
#include "rental_site.h"
#include "vehicle.h"
#include <vector>
#include <iostream>


class View
{
 	private:
		Rental_site _rental_site;
		
	public: 
		View(Rental_site rental_site);
		View();
		int main_menu();
		void  list_of_vehicles();
		std::string help();
		
};

#endif
		
