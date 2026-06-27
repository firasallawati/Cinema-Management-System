#ifndef T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H
#define T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H

#include <vector>
#include <string>
#include "booking.h"
#include "screen.h"

class BookingManager {
private:
    std::vector<Booking> bookings_;
    std::vector<Screen> screens_;

    Screen* FindScreenById(const std::string& screen_id);

public:
    BookingManager() = default;
    BookingManager(const std::vector<Screen>& screens);

    bool CanAddBooking(const Booking& booking);
    void AddBooking(const Booking& booking);

    void DisplayAllBookings() const;

    std::vector<Booking> SearchByCustomerName(const std::string& name) const;
    std::vector<Booking> SearchByMovieTitle(const std::string& title) const;
    std::vector<Booking> SearchByDate(const std::string& date) const;

    void LoadBookingsFromFile(const std::string& filename);
    void SaveBookingsToFile(const std::string& filename) const;
};
#endif //T0466146_453_COURSEWORK_REAL_BOOKING_MANAGER_H