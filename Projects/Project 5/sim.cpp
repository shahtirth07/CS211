//sim.cpp
//shah, tirth
//tshah

#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "cust.h"
#include "pqueue.h"

const int ITEM_COST = 3;
const int SHOP_TIME_PER_ITEM = 2;
const int CHECKOUT_TIME_PER_ITEM = 1;
const int ROBBERY_TIME = 7;
const int INITIAL_CHECKER_CASH = 250;

bool is_valid_integer(char* str) {
    int start = 0;

    if (str[0] == '-') {
        start = 1;
    }

    if (str[start] == '\0') {
        return false;
    }

    for (int i = start; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

void read_input(ifstream &inputFile, PQueue &arrivalQueue) {
    string customerName;
    int arrivalTime;
    string role;
    int itemCount;

    while (inputFile >> customerName >> role >> arrivalTime >> itemCount) {
        assert(arrivalTime >= 0); // Assert that arrival time is non-negative
        bool isRobber = (role == "robber");

        Cust* newCustomer = new Cust(customerName, isRobber, arrivalTime, itemCount);
        arrivalQueue.enqueue(newCustomer, arrivalTime);
    }
}

void run_simulation(int numCheckers, PQueue &arrivalQueue, int breakDuration, ostream &outputStream) {
    struct Checkout {
        int cash;
        int doneTime;
        Cust* currentCustomer;
    };

    Checkout* checkers = new Checkout[numCheckers];
    for (int i = 0; i < numCheckers; i++) {
        checkers[i].doneTime = 0;
        checkers[i].cash = INITIAL_CHECKER_CASH;
        checkers[i].currentCustomer = nullptr;
    }

    PQueue shoppingQueue;
    PQueue checkerQueue;

    int remainingCustomers = arrivalQueue.getSize();
    int clock;

    for (clock = 1; remainingCustomers > 0; clock++) {
        // Check customers arriving at the store
        while (true) {
            Cust* arrivingCustomer = nullptr;
            int priority;

            if (arrivalQueue.getFirstPriority(priority) && priority == clock) {
                arrivalQueue.dequeue(arrivingCustomer);
                arrivingCustomer->outputEnteredStore(outputStream, clock);
                assert(clock == arrivingCustomer->getArrivalTime()); // Assert arrival time matches

                int shoppingDuration = arrivingCustomer->getItemCount() * SHOP_TIME_PER_ITEM;
                int doneShoppingTime = clock + shoppingDuration;

                shoppingQueue.enqueue(arrivingCustomer, doneShoppingTime);
            } else {
                break;
            }
        }

        // Check customers done shopping
        while (true) {
            Cust* finishedShoppingCustomer = nullptr;
            int shoppingPriority;

            if (shoppingQueue.getFirstPriority(shoppingPriority) && shoppingPriority == clock) {
                shoppingQueue.dequeue(finishedShoppingCustomer);
                finishedShoppingCustomer->outputDoneShopping(outputStream, clock);
                checkerQueue.enqueue(finishedShoppingCustomer, 0);  // Priority for the checker queue is always 0
            } else {
                break;
            }
        }

        // Handle checkers who are done with a customer
        for (int i = 0; i < numCheckers; ++i) {
            Checkout& checker = checkers[i];

            if (checker.currentCustomer != nullptr && checker.doneTime == clock) {
                Cust* customer = checker.currentCustomer;

                if (!customer->getIsRobber()) {
                    // Shopper paid
                    int payment = customer->getItemCount() * ITEM_COST;
                    assert(checker.cash >= 0); // Cash shouldn't be negative
                    assert(payment > 0); // Payment should be positive

                    checker.cash += payment;
                    customer->outputPaid(outputStream, clock, payment, customer->getItemCount(), i);
                } else {
                    // Robber stole
                    customer->outputStole(outputStream, clock, checker.cash, customer->getItemCount(), i);
                    checker.doneTime = clock + breakDuration; 
                    checker.cash = 0; // Set break time for robbers
                }

                remainingCustomers--;
                delete customer;
                checker.currentCustomer = nullptr;
            }
        }

        // Assign new customers to available checkers
        for (int i = 0; i < numCheckers; ++i) {
            Checkout& checker = checkers[i];

            if (checker.doneTime <= clock && checker.currentCustomer == nullptr) {
                if (!checkerQueue.isEmpty()) {
                    Cust* customer;
                    checkerQueue.dequeue(customer);
                    checker.currentCustomer = customer;

                    if (!customer->getIsRobber()) {
                        checker.doneTime = clock + customer->getItemCount() * CHECKOUT_TIME_PER_ITEM;
                    } else {
                        checker.doneTime = clock + ROBBERY_TIME;
                    }

                    customer->outputStartedCheckout(outputStream, clock, i);
                    assert(clock == checker.doneTime - (customer->getIsRobber() ? ROBBERY_TIME : customer->getItemCount() * CHECKOUT_TIME_PER_ITEM)); // Assert timing is correct
                }
            }
        }
    }

    // After the simulation loop, output final cash in each register and the final clock time
    for (int i = 0; i < numCheckers; ++i) {
        outputStream << "registers[" << i << "] = $" << checkers[i].cash << endl;
        assert(checkers[i].cash >= 0); // Final cash should not be negative
    }

    outputStream << "time = " << clock << endl;

    delete[] checkers;
}


int main(int argc, char *argv[]) {
    PQueue arrivalQueue;
    if (argc < 5) {
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    if (argc > 5) {
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    int numCheckers;
    if (is_valid_integer(argv[1])) {
        numCheckers = atoi(argv[1]);
        assert(numCheckers >= 1); // Assert valid checker count
    } else {
        cerr << "Error: invalid number of checkers specified." << endl;
        exit(1);
    }

    int breakLength;
    if (is_valid_integer(argv[2])) {
        breakLength = atoi(argv[2]);
        assert(breakLength >= 0); // Assert valid break length
    } else {
        cerr << "Error: invalid checker break duration specified." << endl;
        exit(1);
    }

    ifstream inputFile(argv[3]);
    if (!inputFile) {   
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        exit(1);
    }

    ofstream outputFile(argv[4]);
    if (!outputFile) {
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        exit(1);
    }

    read_input(inputFile, arrivalQueue);
    run_simulation(numCheckers, arrivalQueue, breakLength, outputFile);
    return 0;
}
