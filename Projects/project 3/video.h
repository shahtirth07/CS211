//video.h
//Shah, Tirth
//tshah
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>

using namespace std;

//This is a Video header file it contains all the Attributes, Constructor and methods that this class will have as a blueprint.
class Video 
{
    public:
    void print();
    Video(string m_title, string m_url, string m_comment, float m_length, int m_rating);
    bool compareLengths(Video *otherVideo);
    bool compareRatings(Video *otherVideo);
    bool compareTitles(Video *otherVideo);
    bool compare(Video *otherVideo, string sort);

    string get_title() { 
        return m_title; 
    }


    private:
    string m_title;
    string m_url;
    string m_comment;
    float m_length;
    int m_rating;
};

#endif