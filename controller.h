#ifndef __CONTROLLER_H
#define __CONTROLLER_H
#include "rental_site.h"
#include "vehicle.h"
#include "view.h"

class Controller
{
	private:
		Rental_site rental_site;
                
	public:
	
		Controller();
	//Controller();
		//void show();
		void cli();
		void execute_cmd(int command);
		
	
};
#endif


