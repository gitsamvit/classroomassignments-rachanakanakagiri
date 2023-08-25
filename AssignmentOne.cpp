#include <iostream>
#include <string>
using namespace std;

class ICommManager{
    public : 
    virtual void shareContent(string imageLink)=0;
};

class ImageGallery {
	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};

	
public:
void share(int index, ICommManager* configM) {
//SRP
//Reusability : im
//interface , DIP , interface segregation
configM->shareContent(images[index]); 
}
};


class BluetoothManager : public ICommManager {
public:
	void searchDevices() {}
    void pairdevice(){}
	void sendContent() {}
	void turnOn() {}
	void turnOff(){}
      
       public:
       
        void shareContent(string imageLink) {
            //delegation
              std::cout << "image shared via Bluetooth" << endl; 
        }
};

class WhatsUpManager : public ICommManager {
	void turnOn() {}
	void turnOff() {}
	void shareContent() {}
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}
    public:
        void shareContent(string imageLink) {
            std::cout << "image shared via WhatsUp" << endl; 
        }

};

class MailManager : public ICommManager {

	void pullNewMails() {}
	void senMails(){}
	void composeEmail(){}
	void addAttachement() {}
    public:
        void shareContent(string imageLink) {
              std::cout << "image shared via Mail" << endl; 
        }
};

int main() {

	MailManager* _mailManager = new  MailManager();
	BluetoothManager* _bluetoothManager = new  BluetoothManager();
	WhatsUpManager* _whatsUpManager = new  WhatsUpManager();
	
	ImageGallery* imageMgmt = new  ImageGallery();
	imageMgmt->share(0,_mailManager);
	imageMgmt->share(1,_whatsUpManager);
	imageMgmt->share(2,_bluetoothManager);
	imageMgmt->share(0,_mailManager);
	imageMgmt->share(0,_whatsUpManager);
	
	
}