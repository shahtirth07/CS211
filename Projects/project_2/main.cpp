//main.cpp
//Shah, Tirth
//tshah
#include <iostream>
#include "video.h"

using namespace std;

const int MAX = 100;

int main() {

    int video_count = 0;
    string title, url, comment;
    float length;
    int rating;
    string sort;
    Video* videos[MAX] = {NULL};

    getline(cin, sort);
    if(sort != "rating" && sort != "length" && sort != "title") {
        cerr << sort << "A is not a legal sorting method, giving up." << endl;
        return 1;
    }


    while(getline(cin, title)) { //getting user input.
        if(video_count >= MAX) { // checking for input only 100 objects.
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin.ignore();
        cin >> rating;
        cin.ignore();

        videos[video_count] = new Video(title, url, comment, length, rating); //creatinf Video object.
        video_count +=1; // maintaining the count of the objects.
    }

//used this to check the input befor sorting the Objects.
    /* for (int i = 0;  i < video_count; i++ ) {
        videos[i]->print();
    } */

// Used for bubble sorting.
    for (int last = video_count - 1; last > 0; last--) {
        for (int cur = 0; cur < last; cur ++) {
            if (videos[cur]->compare(videos[cur+1], sort)) {
                swap(videos[cur], videos[cur+1]);
            }
        }
    }

// Printing the sorted Objects.
    for (int i = 0; i < video_count; i++) {
        videos[i]->print();
    }

// freeing the memory of Video object.
    for (int i = 0; i < video_count; i++) {
        delete videos[i];
    }
    return 0;
}