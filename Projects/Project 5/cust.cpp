//cust.cpp
//shah, tirth
//tshah

#include <iostream>
#include <string>
#include <assert.h>
#include "cust.h"
using namespace std; 

// Add class contructor here...
Cust::Cust(string name, bool isRobber, int arrivalTime, int itemCount) {
    this->setName=name;
    this->setIsRobber=isRobber;
    this->setArrivalTime=arrivalTime;
    this->setItemCount=itemCount;
    
}

void Cust::print(ostream &os)
{
    if (getIsRobber())
    {
        os<<getName()<<" robber "<<getArrivalTime()<<" "<<getItemCount()<<endl;
    }
    else
    {
         os<<getName()<<" shopper "<<getArrivalTime()<<" "<<getItemCount()<<endl;
    }
}
string Cust::getName() {
    return setName;
}
bool Cust::getIsRobber() {
    return setIsRobber;
}
int Cust::getArrivalTime() {
    return setArrivalTime;
}
int Cust::getItemCount() {
    return setItemCount;
}
// New methods for outputting messages
void Cust::outputEnteredStore(ostream &os, int clock) {
    assert(clock == setArrivalTime); 
    os << clock << ": " << setName << " entered store" << endl;
}

void Cust::outputDoneShopping(ostream &os, int clock) {
    assert(clock >= setArrivalTime); 
    os << clock << ": " << setName << " done shopping" << endl;
}

void Cust::outputStartedCheckout(ostream &os, int clock, int checkerIndex) {
    assert(clock > setArrivalTime); 
    os << clock << ": " << setName << " started checkout with checker " << checkerIndex << endl;
}

void Cust::outputPaid(ostream &os, int clock, int payment, int itemCount, int checkerIndex) {
    os << clock << ": " << setName << " paid $" << payment
       << " for " << itemCount << (itemCount == 1 ? " item" : " items")
       << " to checker " << checkerIndex << endl;
}

void Cust::outputStole(ostream &os, int clock, int stolenCash, int itemCount, int checkerIndex) {
    os << clock << ": " << setName << " stole $" 
       << stolenCash << " and "
       << itemCount << (itemCount == 1 ? " item" : " items")
       << " from checker " << checkerIndex << endl;
}