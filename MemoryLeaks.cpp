//  Created by Arjun krishna on 07/06/20.
//  Copyright © 2020 Arjun krishna. All rights reserved.

// ===========================================================================
// Common Memory Leaks in CPP
// ===========================================================================

#include <iostream>
// Memory leaks occur when new memory is allocated dynamically and never deallocated.

void NoDealloc(){
    char* Buff = new char [10];
    char* Buff2 = (char*)malloc(10);
//    delete[] Buff;
//    free(Buff2);
}

void WrongDealloc(){
    char* Buff = new char [10];
    delete Buff; //undefined behaviour
//    delete[] Buff;
}

void PointerReallocation(){
    char* Buff = new char [10];
//    delete[] Buff;
    Buff = new char [20];
}

void PointerReassignment(){
    char* Buff = new char [10];
//    delete [] Buff;
    Buff = nullptr; // No way to free memmory now
    // Often a function returns pointer to a dynamic memory and that
    // is not stored or deallocated by the caller, and therefore
    // the pointer to the dynamic memory gets lost.
}

// Common OOP (Object Oriented Programming) Memory Leaks

class Base {
public:
    Base(){
        std::cout<<"Constructor of Base called"<<std::endl;
    }
    ~Base(){ //should be virtual
        std::cout<<"Destructor of Base called"<<std::endl;
    }
};

class Derived : public Base {
public:
    Derived(){
        std::cout<<"Constructor of Derived called"<<std::endl;
    }
    
    ~Derived(){
           std::cout<<"Destructor of Derived called"<<std::endl;
    }
    
    Derived(const Derived &d){
        std::cout<<"Copy Constructor of Derived called"<<std::endl;
    }
    
};

class Container{
private:
    Derived* ptr;  //ptr C1 and ptr for C2 would be pointing to same location as ptr of C1 if shallow copy is done
public:
    Container(){
        ptr = new Derived();
    }
    
    ~Container(){
        delete ptr;
    }
    
//    Container(const Container &c) = default;
    
//    Container(const Container &c){
//        delete ptr;
//        ptr = new Derived(*c.ptr);
//    }
//
//    void operator=(const Container &c ) {
//        if(this == &c){
//            std::cout<<"Self assigment"<<std::endl;
//            return;
//        }
//        delete ptr;
//        ptr = new Derived(*c.ptr);
//    }
    
};

int main(int argc, const char * argv[]) {
    std::cout<<"Program started"<<std::endl;
    NoDealloc();
    WrongDealloc();
    PointerReallocation();
    PointerReassignment();
    
    Base* ptr = new Derived();
    delete ptr;

    Container C1;
    Container C2(C1);

    Container C3;
    Container C4;
    C3 = C4;

    //self assignment
    Container C5;
    C5 = C5;

    return 0;
}

