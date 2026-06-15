//
// Created by firas on 14/06/2026.
//

#include "booking.h"

using namespace std;

Booking::Booking() {
    customer_name_ = "";
    movie_ = Movie();
    booking_date_ = "";
    booking_time_ = "";
    adult_tickets_ = 0;
    child_tickets_ = 0;
    student_tickets_ = 0;
    senior_tickets_ = 0;
    total_cost_ = 0.0;
    payment_details_ = PaymentDetails();
}

Booking::Booking(string customer_name, Movie movie, string booking_date, string booking_time,
                 int adult_tickets, int child_tickets, int student_tickets, int senior_tickets,
                 double total_cost, PaymentDetails payment_details) {
    customer_name_ = customer_name;
    movie_ = movie;
    booking_date_ = booking_date;
    booking_time_ = booking_time;
    adult_tickets_ = adult_tickets;
    child_tickets_ = child_tickets;
    student_tickets_ = student_tickets;
    senior_tickets_ = senior_tickets;
    total_cost_ = total_cost;
    payment_details_ = payment_details;
}

string Booking::GetCustomerName() const {
    return customer_name_;
}

Movie Booking::GetMovie() const {
    return movie_;
}

string Booking::GetBookingDate() const {
    return booking_date_;
}

string Booking::GetBookingTime() const {
    return booking_time_;
}

int Booking::GetAdultTickets() const {
    return adult_tickets_;
}

int Booking::GetChildTickets() const {
    return child_tickets_;
}

int Booking::GetStudentTickets() const {
    return student_tickets_;
}

int Booking::GetSeniorTickets() const {
    return senior_tickets_;
}

double Booking::GetTotalCost() const {
    return total_cost_;
}

PaymentDetails Booking::GetPaymentDetails() const {
    return payment_details_;
}

void Booking::SetCustomerName(string customer_name) {
    customer_name_ = customer_name;
}

void Booking::SetMovie(Movie movie) {
    movie_ = movie;
}

void Booking::SetBookingDate(string booking_date) {
    booking_date_ = booking_date;
}

void Booking::SetBookingTime(string booking_time) {
    booking_time_ = booking_time;
}

void Booking::SetAdultTickets(int adult_tickets) {
    adult_tickets_ = adult_tickets;
}

void Booking::SetChildTickets(int child_tickets) {
    child_tickets_ = child_tickets;
}

void Booking::SetStudentTickets(int student_tickets) {
    student_tickets_ = student_tickets;
}

void Booking::SetSeniorTickets(int senior_tickets) {
    senior_tickets_ = senior_tickets;
}

void Booking::SetTotalCost(double total_cost) {
    total_cost_ = total_cost;
}

void Booking::SetPaymentDetails(PaymentDetails payment_details) {
    payment_details_ = payment_details;
}

int Booking::GetTotalTickets() const {
    return adult_tickets_ + child_tickets_ + student_tickets_ + senior_tickets_;
}

void Booking::DisplayBooking() const {
    cout << "Customer Name: " << customer_name_ << endl;
    cout << "Movie: " << movie_.GetTitle() << endl;
    cout << "Date: " << booking_date_ << endl;
    cout << "Time: " << booking_time_ << endl;
    cout << "Adult Tickets: " << adult_tickets_ << endl;
    cout << "Child Tickets: " << child_tickets_ << endl;
    cout << "Student Tickets: " << student_tickets_ << endl;
    cout << "Senior Tickets: " << senior_tickets_ << endl;
    cout << "Total Tickets: " << GetTotalTickets() << endl;
    cout << "Total Cost: " << total_cost_ << endl;
    cout << "Payment Method: " << payment_details_.GetPaymentMethod() << endl;
}
