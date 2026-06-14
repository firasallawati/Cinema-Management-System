//
// Created by firas on 15/06/2026.
//

#include "movie_schedule.h"
#include <iostream>

using namespace std;

MovieSchedule::MovieSchedule() {
    screen_id_ = "";
    movie_title_ = "";
    day_ = "";
    date_ = "";
    start_time_ = "";
    end_time_ = "";
}

MovieSchedule::MovieSchedule(string screen_id, string movie_title, string day, string date, string start_time, string end_time) {
    screen_id_ = screen_id;
    movie_title_ = movie_title;
    day_ = day;
    date_ = date;
    start_time_ = start_time;
    end_time_ = end_time;
}

string MovieSchedule::GetScreenId() {
    return screen_id_;
}

string MovieSchedule::GetMovieTitle() {
    return movie_title_;
}

string MovieSchedule::GetDay() {
    return day_;
}

string MovieSchedule::GetDate() {
    return date_;
}

string MovieSchedule::GetStartTime() {
    return start_time_;
}

string MovieSchedule::GetEndTime() {
    return end_time_;
}

void MovieSchedule::SetScreenId(string screen_id) {
    screen_id_ = screen_id;
}

void MovieSchedule::SetMovieTitle(string movie_title) {
    movie_title_ = movie_title;
}

void MovieSchedule::SetDay(string day) {
    day_ = day;
}

void MovieSchedule::SetDate(string date) {
    date_ = date;
}

void MovieSchedule::SetStartTime(string start_time) {
    start_time_ = start_time;
}

void MovieSchedule::SetEndTime(string end_time) {
    end_time_ = end_time;
}

void MovieSchedule::DisplayMovieSchedule() {
    cout << "Screen ID: " << screen_id_ << endl;
    cout << "Movie Title: " << movie_title_ << endl;
    cout << "Day: " << day_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Start Time: " << start_time_ << endl;
    cout << "End Time: " << end_time_ << endl;
}
