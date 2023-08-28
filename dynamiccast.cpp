// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Vehicle{
    // protected:
    // Vehicle(){}
    public:
    void start(){
        cout<<"key start" << endl;
    }
    void drive(){
        cout<<"key RWD" << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle{
    public:
    void enableRadar(){
        cout<<" Radar enable" << endl;
    }
};

class Truck : public Vehicle{
    public:
   void enableLoadGear(){
       cout<<" LoadGear enable" << endl;
   }
};

//DIP
                    //lvalue reference
void simulateDrive(Vehicle *obj){
    cout<<"obj typr name " << typeid(*obj).name() << endl;
    obj->start();
    obj->drive();
    // not allowed as inheritance is one way cant use parent class obj to call derived class method
    // obj-> enableRadar(); 
    // obj->enableLoadGear();
    //downcasting using dyn cast
    Car* carPointerRef = dynamic_cast<Car*>(obj);
    if(carPointerRef != NULL)
{
    carPointerRef->enableRadar();
}    
    Truck* truckPointerRef = dynamic_cast<Truck*>(obj);
    if(truckPointerRef != NULL)
{
    truckPointerRef->enableLoadGear();
}    
}


int main() {
    Vehicle vObj;
    Car cObj;
    Truck tObj;
    simulateDrive(&vObj);
    simulateDrive(&cObj);
    simulateDrive(&tObj);
    

    return 0;
}
