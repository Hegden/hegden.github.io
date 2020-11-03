#include<iostream>
#include<string>

enum Color{
	RED,
	BLUE,
	BLACK,
	WHITE
};

std::string colornames[]={"RED","BLUE","BLACK","WHITE"};

class Vehicle {
	public:
	//Declare VehicleType within Vehicle. In the problem's context, VehicleType is closely related to Vehicle.	
	enum VehicleType{
		CAR,
		BUS,
		TRUCK
	};

	Color col;
       	Vehicle(){}	       
};

class Car:public Vehicle{
	public:
	Car(Color c) {col=c;std::cout<<"Creating "<<colornames[c]<<" Car"<<std::endl;}
};


class Bus:public Vehicle{
	public:
	Bus(Color c) {col=c;std::cout<<"Creating "<<colornames[c]<<" Bus"<<std::endl;}
};

//Templated method to invoke type-specific instances of the factory method. This approach is more cohesive for the following reason:
//Uninstantiated types e.g. when TRUCK is declared as a constant in the enum declaration but type Truck is not defined, we see a linker error.  
template <Vehicle::VehicleType v> Vehicle* VehicleFactory(Color c);

template <> Vehicle* VehicleFactory<Vehicle::CAR>(Color c){
        return new Car(c);
                                                  }
template <> Vehicle* VehicleFactory<Vehicle::BUS>(Color c){
        return new Bus(c);
                                                  }

//Problem:
//return new appears at multiple times (not related to cohesiveness). 
//if the method returns NULL, the caller does not know if it is because of a type not being defined, or we ran out of heap memory
//the caller has to handle NULL at runtime. 
/*
Vehicle* VehicleFactory(Vehicle::VehicleType type, Color c) {
	switch(type) {
	case Vehicle::BUS:
	{
		return new Bus(c);
	}
	case Vehicle::CAR:
	{
		return new Car(c);
	}
	default:
		return NULL;
	}
}*/

int main() {
	/*Vehicle* redCar = VehicleFactory(Vehicle::CAR,RED);
	Vehicle* blueBus = VehicleFactory(Vehicle::BUS,BLUE);
	//dynamic:
	//Vehicle* blueTruck = VehicleFactory(Vehicle::TRUCK,BLUE);*/
	Vehicle* redCar = VehicleFactory<Vehicle::CAR>(RED);
	Vehicle* blueBus = VehicleFactory<Vehicle::BUS>(BLUE);
	//the below line results in static error, which is easier to detect early compared to an error on line labelled 'dynamic' 
	Vehicle* blueTruck = VehicleFactory<Vehicle::TRUCK>(BLUE);
}
