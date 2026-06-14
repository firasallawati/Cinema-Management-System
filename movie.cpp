//
// Created by firas on 12/06/2026.
//

#include "movie.h"

using namespace std;

Movie::Movie() {
    title_ = "";
    genre_ = "";
    date_ = "";
    time_ = "";
}

Movie::Movie(string title, string genre, string date, string time) {
    title_ = title;
    genre_ = genre;
    date_ = date;
    time_ = time;
}

string Movie::GetTitle() {
    return title_;
}

string Movie::GetGenre() {
    return genre_;
}

string Movie::GetDate() {
    return date_;
}

string Movie::GetTime() {
    return time_;
}

void Movie::SetTitle(string title) {
    title_ = title;
}

void Movie::SetGenre(string genre) {
    genre_ = genre;
}

void Movie::SetDate(string date) {
    date_ = date;
}

void Movie::SetTime(string time) {
    time_ = time;
}

void Movie::DisplayMovie() {
    cout << "Title: " << title_ << endl;
    cout << "Genre: " << genre_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Time: " << time_ << endl;
}