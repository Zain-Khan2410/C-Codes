#include<iostream>
using namespace std;
class SamsungSmartAppliance{
    protected:
    string modelname;
    bool powerOn;
    int currentmode;
    int numberofmodes;
    public:
    SamsungSmartAppliance(string mname, int mode, int noofmode){
        modelname = mname;
        powerOn = false;
        currentmode = mode;
        numberofmodes = noofmode;
    }
    void setPower(bool state){
        if(powerOn !=state){
            powerOn = state;
            cout<<" Model "<<modelname<<" is now "<<powerOn ? "ON" : "OFF";

        }}
        bool isPowerOn(){
           return powerOn;
        }
        virtual void displaystatus() const{
            cout <<"Model : "<<modelname<<endl<<"Power State: "<<(powerOn ? "ON" : "OFF");
            cout<<"Mode Index: "<<currentmode;

        }
        SamsungSmartAppliance operator++( ){
            if(powerOn){
                currentmode = (currentmode +1)%numberofmodes;
            }
            return *this;
        }

};
class SamsungSmartTV : public SamsungSmartAppliance
{
    private: 
    const string tvModes[3] = {"Movie", "Game", "News"};
public:
    SamsungSmartTV(string name) :SamsungSmartAppliance(name,0, 3) {}
    void displaystatus() const override{
        cout<<"Smart TV"<<endl;
        cout<<"Model NAME: "<<modelname<<endl;
        cout<<"Power State: "<<(powerOn ? "ON" : "OFF")<<endl;
        cout<<"TV Mode: "<<tvModes[currentmode]<<"Index ("<<currentmode<<")"<<endl;
    }

};
class SamsungSmartWashingMachine : public SamsungSmartAppliance
{
    private: 
    const string washModes[3] = {"Heavy", "Normal", "Light"};
public:
    SamsungSmartWashingMachine(string name) :SamsungSmartAppliance(name,0, 3) {}
    void displaystatus() const override{
        cout<<"Smart Washing Machine"<<endl;
        cout<<"Model NAME: "<<modelname<<endl;
        cout<<"Power State: "<<(powerOn ? "ON" : "OFF")<<endl;
        cout<<"TV Mode: "<<washModes[currentmode]<<"Index ("<<currentmode<<")"<<endl;
    }

};
int main(){
    SamsungSmartTV tv("SMART TV 404");
    SamsungSmartWashingMachine wash("ECOBUBBLE");

    tv.displaystatus();
    wash.displaystatus();
    cout<<endl;
    tv.setPower(true);
    cout<<endl;
    wash.setPower(true);

    ++tv;
    ++wash;
    
    cout<<endl;
    tv.displaystatus();
    wash.displaystatus();


}


 