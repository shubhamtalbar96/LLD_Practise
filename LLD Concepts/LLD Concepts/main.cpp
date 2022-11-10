//
//  main.cpp
//  LLD Concepts
//
//  Created by Shubham Talbar on 11/9/22.
//

#include <iostream>

using namespace std;

// ++++++++++++++++++++++++++++++++++++++++++++
// Demonstrating Virtual methods in CPP

class Base {
public:
    virtual void show() {
        cout << "In Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "In Derived class" << endl;
    }
};

// ++++++++++++++++++++++++++++++++++++++++++++
// Demonstrating Abstract Classes in CPP
class Interface {
public:
    virtual void show() = 0;
};

class InterfaceImpl : public Interface {
public:
    void show() {
        cout << "Inside InterfaceImpl" << endl;
    }
};

// ---------------------------------------------
// Demonstrating Factory Design Pattern
enum class ObjectType {PLANE, BOAT};

class IGameObject {
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject {
public:
    Plane() {}
    void Update() {}
    void Render() {}
};

class Boat : public IGameObject {
public:
    Boat() {}
    void Update() {}
    void Render() {}
};

IGameObject* MakeGameObjectFactory(ObjectType type) {
    if (type == ObjectType::PLANE) {
        return new Plane;
    }
    else if (type == ObjectType::BOAT) {
        return new Boat;
    }
    
    return nullptr;
}

int main() {
    // Virtual method
//    Base* ptr = new Derived();
//    ptr->show();
    
    // Interface implementation
//    Interface* ptr = new InterfaceImpl();
//    ptr->show();
    
    // Factory Design Pattern Demo
    IGameObject* myObject = MakeGameObjectFactory(ObjectType::PLANE);
    delete myObject;
    
    return 0;
}
