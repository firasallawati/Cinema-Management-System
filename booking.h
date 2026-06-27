//
// booking.h
//

#ifndef T0466146_453_COURSEWORK_REAL_BOOKING_H
#define T0466146_453_COURSEWORK_REAL_BOOKING_H

#include <iostream>
#include <string>
#include "movie.h"
#include "payment_details.h"

class Booking {
private:
    std::string customer_name_;
    Movie movie_;
    std::string screen_id_;      // NEW: link booking to a specific screen
    std::string booking_date_;   // e.g. "Thursday"
    std::string booking_time_;   // e.g. "19:30"
    int adult_tickets_;
    int child_tickets_;
    int student_tickets_;
    int senior_tickets_;
    double total_cost_;
    PaymentDetails payment_details_;

public:
    Booking();
    Booking(const std::string& customer_name,
            const Movie& movie,
            const std::string& screen_id,
            const std::string& booking_date,
            const std::string& booking_time,
            int adult_tickets,
            int child_tickets,
            int student_tickets,
            int senior_tickets,
            double total_cost,
            const PaymentDetails& payment_details);

    std::string GetCustomerName() const;
    Movie GetMovie() const;
    std::string GetScreenId() const;
    std::string GetBookingDate() const;
    std::string GetBookingTime() const;
    int GetAdultTickets() const;
    int GetChildTickets() const;
    int GetStudentTickets() const;
    int GetSeniorTickets() const;
    double GetTotalCost() const;
    PaymentDetails GetPaymentDetails() const;

    void SetCustomerName(const std::string& customer_name);
    void SetMovie(const Movie& movie);
    void SetScreenId(const std::string& screen_id);
    void SetBookingDate(const std::string& booking_date);
    void SetBookingTime(const std::string& booking_time);
    void SetAdultTickets(int adult_tickets);
    void SetChildTickets(int child_tickets);
    void SetStudentTickets(int student_tickets);
    void SetSeniorTickets(int senior_tickets);
    void SetTotalCost(double total_cost);
    void SetPaymentDetails(const PaymentDetails& payment_details);

    int GetTotalTickets() const;
    void DisplayBooking() const;
};

#endif //T0466146_453_COURSEWORK_REAL_BOOKING_H