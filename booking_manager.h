//
// Created by firas on 15/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H
#define T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "booking.h"
#include "screen.h"

using namespace std;

class BookingManager {
private:
    vector<Booking> bookings_;

public:
    BookingManager();

    void AddBooking(Booking booking);
    void DisplayAllBookings();

    vector<Booking> SearchByCustomerName(string customer_name);
    vector<Booking> SearchByMovieTitle(string movie_title);
    vector<Booking> SearchByDate(string booking_date);

    bool IsCapacityAvailable(Screen screen, Booking booking);
    bool IsValidBookingDay(string booking_day);
    bool CanAddBooking(Screen screen, Booking booking);

    double CalculateTotalRevenue();

    void SaveBookingsToFile(string file_name);
    void LoadBookingsFromFile(string file_name);

    vector<Booking> GetBookings();
};



#endif //T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H
