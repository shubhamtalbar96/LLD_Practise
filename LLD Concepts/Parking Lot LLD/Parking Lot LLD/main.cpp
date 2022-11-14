//
//  main.cpp
//  Parking Lot LLD
//
//  Created by Shubham Talbar on 11/9/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Gate {
private:
    int gateId;
    ParkingAttendant* parkingAttendant;
};

class Entrance : public Gate {
public:
    ParkingTicket* getParkingTicket(Vehicle* vehicle);
};

class Exit : public Gate {
public:
    ParkingTicket* payForParking(ParkingTicket* parkingTicket, PaymentType paymentType);
};

class ParkingDisplayBoard {
private:
    unordered_map<ParkingSpaceType, int> freeSpotsAvailable;

public:
    void updateFreeSpots(ParkingSpaceType parkingSpaceType, int spaces);
};

class ParkingSpace {
private:
    int parkingSpaceId;
    bool isFree;
    double costPerHour;
    Vehicle* vehicle;
    ParkingSpaceType parkingSpaceType;
    
};

class ParkingFloor {
private:
    int levelId;
    bool isFull;
    vector<ParkingSpace> parkingSpaces;
    ParkingDisplayBoard* parkingDisplayBoard;
    
public:
    ParkingFloor(ParkingDisplayBoard* parkingDisplayBoard) {
        this->parkingDisplayBoard = parkingDisplayBoard;
    }
    
};

class Address {
private:
    string country;
    string state;
    string city;
    string street;
    string pincode;
};

class ParkingLot {
private:
    vector<ParkingFloor> parkingFloors;
    vector<Entrance> entrances;
    vector<Exit> exits;
    
    Address* parkingLotaddress;
    string parkingLotName;

public:
    bool isParkingAvailable(Vehicle *vehicle);
    bool updateParkingAttendant(ParkingAttendant* parkingAttendant, int gateId);
    
    ParkingLot(string name, Address *address) {
        this->parkingLotName = name;
        this->parkingLotaddress = address;
    }
};




int main() {
    return 0;
}
