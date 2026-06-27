//
// booking.cpp
//

#include "booking.h"
#include <iostream>

Booking::Booking() {
    customer_name_ = "";
    movie_ = Movie();
    screen_id_ = "";
    booking_date_ = "";
    booking_time_ = "";
    adult_tickets_ = 0;
    child_tickets_ = 0;
    student_tickets_ = 0;
    senior_tickets_ = 0;
    total_cost_ = 0.0;
    payment_details_ = PaymentDetails();
}

Booking::Booking(const std::string& customer_name,
                 const Movie& movie,
                 const std::string& screen_id,
                 const std::string& booking_date,
                 const std::string& booking_time,
                 int adult_tickets,
                 int child_tickets,
                 int student_tickets,
                 int senior_tickets,
                 double total_cost,
                 const PaymentDetails& payment_details) {
    customer_name_ = customer_name;
    movie_ = movie;
    screen_id_ = screen_id;
    booking_date_ = booking_date;
    booking_time_ = booking_time;
    adult_tickets_ = adult_tickets;
    child_tickets_ = child_tickets;
    student_tickets_ = student_tickets;
    senior_tickets_ = senior_tickets;
    total_cost_ = total_cost;
    payment_details_ = payment_details;
}

std::string Booking::GetCustomerName() const {
    return customer_name_;
}

Movie Booking::GetMovie() const {
    return movie_;
}

std::string Booking::GetScreenId() const {
    return screen_id_;
}

std::string Booking::GetBookingDate() const {
    return booking_date_;
}

std::string Booking::GetBookingTime() const {
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

void Booking::SetCustomerName(const std::string& customer_name) {
    customer_name_ = customer_name;
}

void Booking::SetMovie(const Movie& movie) {
    movie_ = movie;
}

void Booking::SetScreenId(const std::string& screen_id) {
    screen_id_ = screen_id;
}

void Booking::SetBookingDate(const std::string& booking_date) {
    booking_date_ = booking_date;
}

void Booking::SetBookingTime(const std::string& booking_time) {
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

void Booking::SetPaymentDetails(const PaymentDetails& payment_details) {
    payment_details_ = payment_details;
}

int Booking::GetTotalTickets() const {
    return adult_tickets_ + child_tickets_ + student_tickets_ + senior_tickets_;
}

void Booking::DisplayBooking() const {
    std::cout << "Customer Name: " << customer_name_ << std::endl;
    std::cout << "Movie: " << movie_.GetTitle() << std::endl;
    std::cout << "Screen ID: " << screen_id_ << std::endl;
    std::cout << "Date: " << booking_date_ << std::endl;
    std::cout << "Time: " << booking_time_ << std::endl;
    std::cout << "Adult Tickets: " << adult_tickets_ << std::endl;
    std::cout << "Child Tickets: " << child_tickets_ << std::endl;
    std::cout << "Student Tickets: " << student_tickets_ << std::endl;
    std::cout << "Senior Tickets: " << senior_tickets_ << std::endl;
    std::cout << "Total Tickets: " << GetTotalTickets() << std::endl;
    std::cout << "Total Cost: " << total_cost_ << std::endl;
    std::cout << "Payment Method: " << payment_details_.GetPaymentMethod() << std::endl;
}