//
// Created by firas on 14/06/2026.
//

#include <iostream>
#include "screen.h"

using namespace std;

Screen::Screen() {
    screen_id_ = "";
    current_movie_ = "";
    max_capacity_ = 0;
    available_seats_ = 0;
    facilities_ = "";
}

Screen::Screen(string screen_id, string current_movie, int max_capacity, int available_seats, string facilities) {
    screen_id_ = screen_id;
    current_movie_ = current_movie;
    max_capacity_ = max_capacity;
    available_seats_ = available_seats;
    facilities_ = facilities;
}

string Screen::GetScreenId() {
    return screen_id_;
}

string Screen::GetCurrentMovie() {
    return current_movie_;
}

int Screen::GetMaxCapacity() {
    return max_capacity_;
}

int Screen::GetAvailableSeats() {
    return available_seats_;
}

string Screen::GetFacilities() {
    return facilities_;
}

void Screen::SetScreenId(string screen_id) {
    screen_id_ = screen_id;
}

void Screen::SetCurrentMovie(string current_movie) {
    current_movie_ = current_movie;
}

void Screen::SetMaxCapacity(int max_capacity) {
    max_capacity_ = max_capacity;
}

void Screen::SetAvailableSeats(int available_seats) {
    available_seats_ = available_seats;
}

void Screen::SetFacilities(string facilities) {
    facilities_ = facilities;
}

void Screen::DisplayScreen() {
    cout << "Screen ID: " << screen_id_ << endl;
    cout << "Current Movie: " << current_movie_ << endl;
    cout << "Maximum Capacity: " << max_capacity_ << endl;
    cout << "Available Seats: " << available_seats_ << endl;
    cout << "Facilities: " << facilities_ << endl;
}
