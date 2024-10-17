//cust.h
//shah, tirth
//tshah

#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <string>
using namespace std;

class Cust
{
 public:
  // public member functions go here
  void print(ostream &os);
  Cust(string name, bool is_robber, int arrival_time, int item_count);
  string getName();
    bool getIsRobber();
    int getArrivalTime();
    int getItemCount();
    void outputEnteredStore(ostream &os, int clock);
    void outputDoneShopping(ostream &os, int clock);
    void outputStartedCheckout(ostream &os, int clock, int checkerIndex);
    void outputPaid(ostream &os, int clock, int payment, int itemCount, int checkerIndex);
    void outputStole(ostream &os, int clock, int stolenCash, int itemCount, int checkerIndex);


    
 private:
  // member variables go here
  string setName;
    bool setIsRobber;
    int setArrivalTime;
    int setItemCount;

}; 

#endif