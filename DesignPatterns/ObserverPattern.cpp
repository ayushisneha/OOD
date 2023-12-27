#include<iostream>
#include<list>
#include<vector>
using namespace std;

class IObserver{
public:
    virtual void update(string message) = 0;
};

class WeatherStation{
    private:
    vector<IObserver*> observers;
    string message;

    public:
    void addObserver(IObserver* observer){
        observers.push_back(observer);
    } 
    void removeObserver(IObserver* observer){
        //
    }
    void notifyAllObserver(){
        for(auto observer:observers){
            observer->update(message);
        }
    }
    void setMessage(string msg){
        message = msg;
        notifyAllObserver();
    }

};

class Display1:public IObserver{
    void update(string msg){
        cout<<"Display1 received message: "<<msg<<endl;
    }

};
class Display2:public IObserver{
    void update(string msg){
        cout<<"Display2 received message: "<<msg<<endl;
    }

};


int main(){

    WeatherStation* weatherStation = new WeatherStation();
    Display1* display1 = new Display1();
    Display2* display2 = new Display2();

    weatherStation->addObserver(display1);
    weatherStation->addObserver(display2);

    weatherStation->setMessage("Hello");
    string msg="a";
    int i=0;

    while(i<10){

        weatherStation->setMessage(msg);
        msg=msg+"a";
        i++;
    }
    return 0;
}
