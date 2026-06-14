//
// Created by firas on 14/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_SCREEN_H
#define T0466146_453_COURSEWORK_REAL_SCREEN_H


#include <iostream>
#include <string>
using namespace std;

class Screen {
private:
    string screen_id_;
    string current_movie_;
    int max_capacity_;
    int available_seats_;
    string facilities_; // e.g. "Standard", "IMAX, Seat service"

public:
    Screen();
    Screen(string screen_id, string current_movie, int max_capacity, int available_seats, string facilities);

    string GetScreenId();
    string GetCurrentMovie();
    int GetMaxCapacity();
    int GetAvailableSeats();
    string GetFacilities();

    void SetScreenId(string screen_id);
    void SetCurrentMovie(string current_movie);
    void SetMaxCapacity(int max_capacity);
    void SetAvailableSeats(int available_seats);
    void SetFacilities(string facilities);

    void DisplayScreen();
};

#endif //T0466146_453_COURSEWORK_REAL_SCREEN_H
