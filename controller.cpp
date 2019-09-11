#include "controller.h"
#include "dialogs.h"
#include "rental_site.h"

Controller::Controller()

{Rental_site r;
  rental_site=r;
}
//Controller::Controller():Controller((Rental_site)&rental_site){}
void Controller::execute_cmd(int command)
{
  View view;
  switch(command)
  {
  case 0: //std::cout<<"The program is existing"<<std::endl;
	      std::exit(0);break;
	      
  case 1: {int year, b_s;
	std::string make;
	std::string model;

	Dialogs::message("Enter the details for vehicle");
	std::string year_s=(Dialogs::input("Year?"," "));
	try
	  {
	    if(year_s=="CANCEL")
	      {
		break;
	      }
	    else
	      {
		year=(std::stoi)(year_s);
	      }
	  }
	catch(...)
	  {
	    exit(0);
	  }
	    
	//std::cout<<"year?  ";
	//std::cin>>year;

	std::string make_s=Dialogs::input("make?"," ");
	try
	  {
	    if(make_s=="CANCEL")
	      {
	        break;
	      }
	    else
	      {
		make=make_s;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
	//std::cout<<"make?  ";
	//std::cin>>make;

	std::string model_s=Dialogs::input("model?"," ");
	try
	  {
	    if(model_s=="CANCEL")
	      {
		break;
	      }
	    else
	      {
		model=model_s;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
	//std::cout<<"model?  ";
	//std::cin>>model;

	std::string body_s=(Dialogs::input("Body_style?"," "));
	 try
	  {
	    if(body_s=="CANCEL")
	      {
		break;
	      }
	    else
	      {
		int body=(std::stoi)(body_s);
		make=make_s; b_s=(Body_style)body;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
        
			 //std::cout<<"Sedan=0, Hatchback=1, Minivan=2, Truck=3, Suv=4, Crossover=5"<<std::endl;
			 //std::cout<<"Body_style?  ";
			 //std::cin>>b_s;
	rental_site.add_vehicle(Vehicle(year,make,model,(Body_style)b_s));}
	break;
	  
  case 2:{ //std::cout<<"List checking ";
   
    Dialogs::message(rental_site.vehicles(),"List of Vehicles"); } break;
	  
  case 3:	{int vehicle;
	std::string renters_name;
	std::string renters_d_l;
	std::string renters_phone;

	std::string vehicle_s=Dialogs::input("which vehicle?");
	try
	  {
	    if(vehicle_s=="CANCEL")
	      {
	        break;
	      }
	    else
	      {
		vehicle=(std::stoi)(vehicle_s);
	      }
	  }
	 catch(...)
	      {
		exit(0);
	      }
	//std::cout<<"which vehicle?  ";
	//	std::cin>>vehicle;

	
	Dialogs::message("Enter the renter's details");
	std::string r_n=Dialogs::input("Renter's name?");
	try
	  {
	    if(r_n=="CANCEL")
	      {
	        break;
	      }
	    else
	      {
		renters_name=r_n;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
	
	//std::cout<<"Renter's name?  ";
	//std::cin>>renters_name;

	
	std::string d_l_s=Dialogs::input("Renter's driving license?");
	try
	  {
	    if(d_l_s=="CANCEL")
	      {
		break;
	      }
	    else
	      {
		renters_d_l=d_l_s;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
	//	std::cout<<"Renter's driving license?  ";
	//std::cin>>renters_d_l;

	
	std::string r_p_s=Dialogs::input("Renter's phone?");
	try
	  {
	    if(r_p_s=="CANCEL")
	      {
		break;
	      }
	    else
	      {
		renters_phone=r_p_s;
	      }
	  }
	  catch(...)
	  {
		exit(0);
	  }
	//std::cout<<"Renter's phone?  ";
	//.std::cin>>renters_phone;

	rental_site.rent_vehicle(vehicle,renters_name,renters_d_l,renters_phone);}
	break;
	
  case 4:{ int i;

	  std::string return_i=Dialogs::input("Which vehicle?","Return Vehicle");
	  //std::cout<<"which vehicle?  ";
	  // std::cin>>i;
	  i=(std::stoi)(return_i);
	    rental_site.return_vehicle(i);}
	    break;
	    
  case 9: {view.help();break;}
  case 42: {rental_site.easter_egg();
	      Dialogs::message("four vehicles added","Magic");}
            break;
  default: view.help();
  }
}

//void Controller::show()
//{
//  View view;
//
// int option=-1;
//	while(option!=0)
//	  {
//	   
//	     int result=view.main_menu();
//	     //std::cout<<"Command?"<<std::endl;
//	     //std::cin>>option;
//	     if
//     	execute_cmd(option);
//	  }
//}

void Controller::cli()
{
  View view;
  int cmd=-1;
  while(cmd!=0)
    {
      cmd=view.main_menu();
      execute_cmd(cmd);
    }
}
	
