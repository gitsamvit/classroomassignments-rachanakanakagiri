#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IDoorStateNotifier{
    public:
    virtual void notify(string status) = 0;
};
//composite class to broadcast the info to leaf class : has references of notification classes

class Door {
public:
//in a class if methods have polymorphic behavior is diff : mark it as virtual
	virtual void open(){}
	virtual void close(){}
public : void Security(string );
};

class SecurityDoor : public Door{
    IDoorStateNotifier* notifierRef;
    public :
    SecurityDoor(IDoorStateNotifier* notifyRefArg ) : 
    notifierRef{notifyRefArg} {}
    void open() override{
        this->notifierRef->notify("open");
    }
    void close() override{
         this->notifierRef->notify("close");
    }
};

class broadcastNotify : public IDoorStateNotifier {
    private:
    vector<IDoorStateNotifier*> notifiers;

public:
void addNotifier(IDoorStateNotifier* notifier){
    notifiers.push_back(notifier);
} 
            void notify(string status)  {
                //multicast
        for(auto notifier : notifiers){
            notifier->notify(status);
        }
    }   
};

class Buzzer : public IDoorStateNotifier{

public:
	void makeNoise(){}
	void notify(string status){
	std::cout << "Buzzer Door status is -> " << status <<endl;
	this->makeNoise();
	}
};

class  SMSManager : public IDoorStateNotifier{

	public :void sendNotificationMessage(){}
    void notify(string status){
    std::cout << "SMS notification ! Door status is -> " << status <<endl;
	this->sendNotificationMessage();
	 }
};

class VisualizationManager : public IDoorStateNotifier {
	public:void turnVideoOn() {}
	public:void turnVideoOff() {}
	void notify(string status){
	std::cout << "Visualization notification ! Door status is -> " << status << endl;
	}
};

//buzzer and sms notification w/o changing securedDoor

int main(){
    Door obj;
    Buzzer bObj;
    VisualizationManager vObj;
    SMSManager sObj;
    SecurityDoor sd2(&vObj);
    SecurityDoor sd3(&sObj);
    SecurityDoor sd1(&sObj);
    sd1.open();
    sd1.close();
    sd2.open();
    sd2.close();
    sd3.open();
    sd3.close(); 
    cout<<"************************" << endl;
    
    broadcastNotify bn;
    bn.addNotifier(&bObj);
    bn.addNotifier(&sObj);
    bn.addNotifier(&vObj);
    SecurityDoor newDoor{&bn};
    newDoor.open();
    newDoor.close();   
}