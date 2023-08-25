#include<string>
#include<iostream>
using namespace std;

class IcommunicationManager {
    public:
    virtual void shareContent(string imageLink) =0;
};

class ImageGallery {
	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};
public:void share(int index, IcommunicationManager* comManager) {
    cout << "content is sharing" << endl;
    comManager->shareContent(images[index]);
}
};

class BluetoothManager : public IcommunicationManager{
public:
	void searchDevices() {}
    void pairdevice(){}
	void sendContent() {}
	void turnOn() {}
	void turnOff(){}

    void shareContent(string imageLink){}

};

class WhatsUpManager : public IcommunicationManager {
	void turnOn() {}
	void turnOff() {}
	void shareContent() {}
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}

void shareContent(string imageLink){}
};

class MailManager : public IcommunicationManager {

	void pullNewMails() {}
	void senMails(){}
	void composeEmail(){}
	void addAttachement() {}
void shareContent(string imageLink){}
};

int main() {

	MailManager* _mailManager = new  MailManager();
	BluetoothManager* _blueToothManager = new  BluetoothManager();
	WhatsUpManager* _wAManager = new  WhatsUpManager();
	
	ImageGallery* imageMgmt = new  ImageGallery();
	imageMgmt->share(0,_mailManager);
    imageMgmt->share(0,_blueToothManager);
    imageMgmt->share(0,_wAManager);
	
}