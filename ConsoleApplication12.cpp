#include <iostream>
#include <string>
using namespace std;

__interface IDrivable {
    void start() const;
    void stop() const;
    void upSpeed(int addsp);
    void downSpeed(int decsp);
};

class Car : public IDrivable {
public:
    Car(const string& brand, int maxSpeed)
        : brand(brand), maxSpeed(maxSpeed), Speed(0) {}

    virtual void start() const{
        cout << "Car " << brand << " start" << endl;
    }

    virtual void stop() const{
        cout << "Car " << brand << " stop" << endl;
    }

    virtual void upSpeed(int addsp){
        Speed += addsp;
        if (Speed > maxSpeed) Speed = maxSpeed;
        cout << "Car " << brand << " speed increased to " << Speed << endl;
    }

    virtual void downSpeed(int decsp){
        Speed -= decsp;
        if (Speed < 0) Speed = 0;
        cout << "Car " << brand << " speed decreased to " << Speed  << endl;
    }

private:
    string brand;
    const int maxSpeed;
    int Speed;
};

class Horse : public IDrivable {
public:
    Horse(const string& name, const string& breed)
        : name(name), breed(breed), speed(0) {}

    virtual void start() const{
        cout << "Horse " << name << " start" << endl;
    }

    virtual void stop() const{
        cout << "Horse " << name << " stop" << endl;
    }

    virtual void upSpeed(int addsp){
        speed += addsp;
        cout << "Horse " << name << " speed increased to " << speed << endl;
    }

    virtual void downSpeed(int decsp){
        speed -= decsp;
        if (speed < 0) speed = 0;
        cout << "Horse " << name << " speed decreased to " << speed  << endl;
    }

private:
    string name;
    string breed;
    int speed;
};

class Driver {
public:
    Driver(const string& name) : name(name), vehicle(nullptr) {}

    void setVehicle(IDrivable* vehicle) {
        this->vehicle = vehicle;
    }

    void testDrive() {
        if (!vehicle) {
            cout << name << "no vehicle" << endl;
            return;
        }

        vehicle->start();
        vehicle->upSpeed(20);
        vehicle->upSpeed(30);
        vehicle->downSpeed(15);
        vehicle->stop();
    }

private:
    string name;
    IDrivable* vehicle;
};

int main() {
    Car car("Toyota", 180);
    Horse horse("Nighthawk", "konyaka");

    Driver driver("Maksim");

    cout << "==============car==============" << endl;
    driver.setVehicle(&car);
    driver.testDrive();

    cout << "==============horse==============" << endl;
    driver.setVehicle(&horse);
    driver.testDrive();

    return 0;
}
