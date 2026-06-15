//
// Created by firas on 15/06/2026.
//

#include "booking_manager.h"

using namespace std;

BookingManager::BookingManager() {
}

void BookingManager::AddBooking(Booking booking) {
    bookings_.push_back(booking);
}

void BookingManager::DisplayAllBookings() {
    if (bookings_.empty()) {
        cout << "No bookings found." << endl;
        return;
    }

    for (int i = 0; i < bookings_.size(); i++) {
        cout << "Booking " << i + 1 << ":" << endl;
        bookings_[i].DisplayBooking();
        cout << endl;
    }
}

vector<Booking> BookingManager::SearchByCustomerName(string customer_name) {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetCustomerName() == customer_name) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

vector<Booking> BookingManager::SearchByMovieTitle(string movie_title) {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetMovie().GetTitle() == movie_title) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

vector<Booking> BookingManager::SearchByDate(string booking_date) {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetBookingDate() == booking_date) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

bool BookingManager::IsCapacityAvailable(Screen screen, Booking booking) {
    if (booking.GetTotalTickets() <= screen.GetAvailableSeats()) {
        return true;
    }

    return false;
}

bool BookingManager::IsValidBookingDay(string booking_day) {
    if (booking_day == "Thursday" || booking_day == "Friday" ||
        booking_day == "Saturday" || booking_day == "Sunday" ||
        booking_day == "Monday" || booking_day == "Tuesday" ||
        booking_day == "Wednesday") {
        return true;
    }

    return false;
}

bool BookingManager::CanAddBooking(Screen screen, Booking booking) {
    if (!IsValidBookingDay(booking.GetBookingDate())) {
        return false;
    }

    if (!IsCapacityAvailable(screen, booking)) {
        return false;
    }

    return true;
}

double BookingManager::CalculateTotalRevenue() {
    double total_revenue = 0.0;

    for (int i = 0; i < bookings_.size(); i++) {
        total_revenue = total_revenue + bookings_[i].GetTotalCost();
    }

    return total_revenue;
}

void BookingManager::SaveBookingsToFile(string file_name) {
    ofstream out_file(file_name);

    if (!out_file.is_open()) {
        cout << "Error opening booking file for writing." << endl;
        return;
    }

    for (int i = 0; i < bookings_.size(); i++) {
        out_file
            << bookings_[i].GetCustomerName() << ","
            << bookings_[i].GetMovie().GetTitle() << ","
            << bookings_[i].GetBookingDate() << ","
            << bookings_[i].GetBookingTime() << ","
            << bookings_[i].GetAdultTickets() << ","
            << bookings_[i].GetChildTickets() << ","
            << bookings_[i].GetStudentTickets() << ","
            << bookings_[i].GetSeniorTickets() << ","
            << bookings_[i].GetTotalCost() << ","
            << bookings_[i].GetPaymentDetails().GetPaymentMethod()
            << endl;
    }

    out_file.close();
}

void BookingManager::LoadBookingsFromFile(string file_name) {
    ifstream in_file(file_name);

    if (!in_file.is_open()) {
        cout << "Error opening booking file for reading." << endl;
        return;
    }

    bookings_.clear();

    string line;
    while (getline(in_file, line)) {
        stringstream ss(line);
        string customer_name;
        string movie_title;
        string booking_date;
        string booking_time;
        string adult_tickets_text;
        string child_tickets_text;
        string student_tickets_text;
        string senior_tickets_text;
        string total_cost_text;
        string payment_method;

        getline(ss, customer_name, ',');
        getline(ss, movie_title, ',');
        getline(ss, booking_date, ',');
        getline(ss, booking_time, ',');
        getline(ss, adult_tickets_text, ',');
        getline(ss, child_tickets_text, ',');
        getline(ss, student_tickets_text, ',');
        getline(ss, senior_tickets_text, ',');
        getline(ss, total_cost_text, ',');
        getline(ss, payment_method, ',');

        Movie movie;
        movie.SetTitle(movie_title);

        PaymentDetails payment_details;
        payment_details.SetPaymentMethod(payment_method);

        Booking booking(
            customer_name,
            movie,
            booking_date,
            booking_time,
            stoi(adult_tickets_text),
            stoi(child_tickets_text),
            stoi(student_tickets_text),
            stoi(senior_tickets_text),
            stod(total_cost_text),
            payment_details
        );

        bookings_.push_back(booking);
    }

    in_file.close();
}

vector<Booking> BookingManager::GetBookings() {
    return bookings_;
}