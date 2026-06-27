//
// movie_schedule.cpp
//

#include "movie_schedule.h"
#include <iostream>

MovieSchedule::MovieSchedule() {
    screen_id_ = "";
    movie_title_ = "";
    day_ = "";
    date_ = "";
    start_time_ = "";
    end_time_ = "";
}

MovieSchedule::MovieSchedule(const std::string& screen_id,
                             const std::string& movie_title,
                             const std::string& day,
                             const std::string& date,
                             const std::string& start_time,
                             const std::string& end_time) {
    screen_id_ = screen_id;
    movie_title_ = movie_title;
    day_ = day;
    date_ = date;
    start_time_ = start_time;
    end_time_ = end_time;
}

std::string MovieSchedule::GetScreenId() const {
    return screen_id_;
}

std::string MovieSchedule::GetMovieTitle() const {
    return movie_title_;
}

std::string MovieSchedule::GetDay() const {
    return day_;
}

std::string MovieSchedule::GetDate() const {
    return date_;
}

std::string MovieSchedule::GetStartTime() const {
    return start_time_;
}

std::string MovieSchedule::GetEndTime() const {
    return end_time_;
}

void MovieSchedule::SetScreenId(const std::string& screen_id) {
    screen_id_ = screen_id;
}

void MovieSchedule::SetMovieTitle(const std::string& movie_title) {
    movie_title_ = movie_title;
}

void MovieSchedule::SetDay(const std::string& day) {
    day_ = day;
}

void MovieSchedule::SetDate(const std::string& date) {
    date_ = date;
}

void MovieSchedule::SetStartTime(const std::string& start_time) {
    start_time_ = start_time;
}

void MovieSchedule::SetEndTime(const std::string& end_time) {
    end_time_ = end_time;
}

void MovieSchedule::DisplayMovieSchedule() const {
    std::cout << "Screen ID: " << screen_id_ << std::endl;
    std::cout << "Movie Title: " << movie_title_ << std::endl;
    std::cout << "Day: " << day_ << std::endl;
    std::cout << "Date: " << date_ << std::endl;
    std::cout << "Start Time: " << start_time_ << std::endl;
    std::cout << "End Time: " << end_time_ << std::endl;
}