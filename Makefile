CXXFLAGS += --std=c++17
//GTKFLAGS +=`/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: rental_site.o main.o  main_window.o controller.o dialogs.o vehicle.o view.o
		${CXX} ${CXXFLAGS} -o main rental_site.o main.o  main_window.o controller.o dialogs.o vehicle.o view.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
rental_site.o: rental_site.cpp *.h
		${CXX} ${CXXFLAGS} -c rental_site.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp *.h
		${CXX} ${CXXFLAGS} -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp *.h
		${CXX} ${CXXFLAGS} -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
controller.o: controller.cpp *.h
		${CXX} ${CXXFLAGS} -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
dialogs.o:dialogs.cpp *.h
		${CXX} ${CXXFLAGS} -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
vehicle.o: vehicle.cpp *.h
		${CXX} ${CXXFLAGS} -c vehicle.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

view.o: view.cpp *.h
		${CXX} ${CXXFLAGS} -c view.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
Clean:
		-rm -f *.o a.out main
