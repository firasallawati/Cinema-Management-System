//
// Created by firas on 14/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_BOOKING_H
#define T0466146_453_COURSEWORK_REAL_BOOKING_H

#include <iostream>
#include <string>
#include "movie.h"
#include "payment_details.h"

using namespace std;

class Booking {
private:
    string customer_name_;
    Movie movie_;
    string booking_date_;   // ex: "2025-06-14" or "Thu"
    string booking_time_;   // ex: "19:30"
    int adult_tickets_;
    int child_tickets_;
    int student_tickets_;
    int senior_tickets_;
    double total_cost_;
    PaymentDetails payment_details_;

public:
    Booking();
    Booking(string customer_name, Movie movie, string booking_date, string booking_time,
            int adult_tickets, int child_tickets, int student_tickets, int senior_tickets,
            double total_cost, PaymentDetails payment_details);

    string GetCustomerName() const;
    Movie GetMovie() const;
    string GetBookingDate() const;
    string GetBookingTime() const;
    int GetAdultTickets() const;
    int GetChildTickets() const;
    int GetStudentTickets() const;
    int GetSeniorTickets() const;
    double GetTotalCost() const;
    PaymentDetails GetPaymentDetails() const;

    void SetCustomerName(string customer_name);
    void SetMovie(Movie movie);
    void SetBookingDate(string booking_date);
    void SetBookingTime(string booking_time);
    void SetAdultTickets(int adult_tickets);
    void SetChildTickets(int child_tickets);
    void SetStudentTickets(int student_tickets);
    void SetSeniorTickets(int senior_tickets);
    void SetTotalCost(double total_cost);
    void SetPaymentDetails(PaymentDetails payment_details);

    int GetTotalTickets() const;
    void DisplayBooking() const;
};

#endif //T0466146_453_COURSEWORK_REAL_BOOKING_H
