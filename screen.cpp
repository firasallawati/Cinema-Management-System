//
// Created by firas on 14/06/2026.
//

#include <iostream>
#include "screen.h"

using namespace std;

Screen::Screen() {
    screen_id_ = "";
    capacity_ = 0;
    facilities_ = "";
}

Screen::Screen(string screen_id, int capacity, string facilities) {
    screen_id_ = screen_id;
    capacity_ = capacity;
    facilities_ = facilities;
}

string Screen::GetScreenId() {
    return screen_id_;
}

int Screen::GetCapacity() {
    return capacity_;
}

string Screen::GetFacilities() {
    return facilities_;
}

void Screen::SetScreenId(string screen_id) {
    screen_id_ = screen_id;
}

void Screen::SetCapacity(int capacity) {
    capacity_ = capacity;
}

void Screen::SetFacilities(string facilities) {
    facilities_ = facilities;
}

void Screen::DisplayScreen() {
    cout << "Screen ID: " << screen_id_ << endl;
    cout << "Capacity: " << capacity_ << endl;
    cout << "Facilities: " << facilities_ << endl;
}
