//
// Created by firas on 12/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_MOVIE_H
#define T0466146_453_COURSEWORK_REAL_MOVIE_H



#include <iostream>
using namespace std;

class Movie {
private:
    string title_;
    string genre_;
    string date_;
    string time_;

public:
    Movie();
    Movie(string title, string genre, string date, string time);

    string GetTitle();
    string GetGenre();
    string GetDate();
    string GetTime();

    void SetTitle(string title);
    void SetGenre(string genre);
    void SetDate(string date);
    void SetTime(string time);

    void DisplayMovie();
};



#endif //T0466146_453_COURSEWORK_REAL_MOVIE_H
