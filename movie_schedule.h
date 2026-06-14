//
// Created by firas on 15/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H
#define T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H



#include <iostream>
#include <string>
using namespace std;

class MovieSchedule {
private:
    string screen_id_;
    string movie_title_;
    string day_;
    string date_;
    string start_time_;
    string end_time_;

public:
    MovieSchedule();
    MovieSchedule(string screen_id, string movie_title, string day, string date, string start_time, string end_time);

    string GetScreenId();
    string GetMovieTitle();
    string GetDay();
    string GetDate();
    string GetStartTime();
    string GetEndTime();

    void SetScreenId(string screen_id);
    void SetMovieTitle(string movie_title);
    void SetDay(string day);
    void SetDate(string date);
    void SetStartTime(string start_time);
    void SetEndTime(string end_time);

    void DisplayMovieSchedule();
};

#endif //T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H
