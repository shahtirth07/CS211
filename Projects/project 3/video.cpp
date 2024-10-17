//video.cpp
//Shah, Tirth
//tshah
#include <iostream>
#include "video.h"

using namespace std;

//We have the implementation of the Video class in this file, this is the constructor.
Video::Video(string m_title, string m_url, string m_comment, float m_length, int m_rating) {
    this->m_title = m_title;
    this->m_url = m_url;
    this->m_comment = m_comment;
    this->m_length = m_length;
    this->m_rating = m_rating;
}

//prints the object of the video created.
void Video::print() {
    for (int i = 0; i<m_rating; i++) {

    }
    cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", " ;
        for (int i = 0; i < m_rating; i++) {
            cout << "*";
        }
        cout << endl;
    }

//compares the Video objects with respect to rating
//input: pointer to the video object.
//output: true or false
//Return: boolean type
bool Video::compareRatings(Video *otherVideo) {
    return this->m_rating < otherVideo->m_rating;
}


//Compares the video object with attribute length 
//input: pointer to the video object.
//output: true or false
//Return: boolean type
bool Video::compareLengths(Video *otherVideo) {
    return this->m_length > otherVideo->m_length;
}

//Compares the video object with attribute title 
//input: pointer to the video object.
//output: true or false
//Return: boolean type
bool Video::compareTitles(Video *otherVideo) {
    return this->m_title > otherVideo->m_title;
}

//Compares the video object with attribute title 
//input: pointer to the video object, and the string on which we need to perform the sort operation.
//output: true or false
//Return: boolean type
bool Video::compare(Video *otherVideo, string sort) {
    if (sort == "rating") return compareRatings(otherVideo);
    if (sort == "length") return compareLengths(otherVideo);
    return compareTitles(otherVideo);
}

