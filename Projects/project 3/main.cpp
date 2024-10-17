#include <iostream>
#include "vlist.h"
#include "video.h"

using namespace std;

void read_input(Vlist &vlist) {
    string command;
    while (getline(cin, command)) {
        cout<<command<<endl;
        if (command == "insert") {
            string title, url, comment;
            int length, rating;

            getline(cin, title);   // Read title
            getline(cin, url);     // Read URL
            getline(cin, comment); // Read comment
            cin >> length; 
            cin >> rating;
             // Ignore the remaining newline

            Video* video = new Video(title, url, comment, length, rating);
            vlist.insert(video);
            cin.ignore();
        }
        else if (command == "print") {
            cout<<"hiii"<<endl;
            vlist.print();
        }
        else if (command == "length") {
            cout << vlist.length() << endl;
        }
        else if (command == "lookup") {
            string title;
            getline(cin, title);
            vlist.lookup(title);
        }
        else if (command == "remove") {
            string title;
            getline(cin, title);
            vlist.remove(title);
        }
        else {
            cerr << "<" << command << "> is not a legal command, giving up." << endl;
            exit(1);
        }
    }

}


int main() {
    Vlist vlist = Vlist();
    read_input(vlist);
return 0;
}