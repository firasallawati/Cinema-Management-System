//
// Created by firas on 14/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_SCREEN_H
#define T0466146_453_COURSEWORK_REAL_SCREEN_H


#include <string>
using namespace std;

class Screen {
private:
    string screen_id_;
    int capacity_;
    string facilities_;   // e.g. "Standard", "IMAX, Seat service"

public:
    Screen();
    Screen(string screen_id, int capacity, string facilities);

    string GetScreenId();
    int GetCapacity();
    string GetFacilities();

    void SetScreenId(string screen_id);
    void SetCapacity(int capacity);
    void SetFacilities(string facilities);

    void DisplayScreen();
};

#endif //T0466146_453_COURSEWORK_REAL_SCREEN_H
