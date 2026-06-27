#include "booking_manager.h"
#include <fstream>
#include <sstream>

using namespace std;

void BookingManager::AddBooking(const Booking& booking) {
    bookings_.push_back(booking);
}

bool BookingManager::CanAddBooking(const Booking& booking) {
    if (booking.GetTotalTickets() <= 0) {
        return false;
    }

    return true;
}

vector<Booking> BookingManager::SearchByCustomerName(const string& customer_name) const {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetCustomerName() == customer_name) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

vector<Booking> BookingManager::SearchByMovieTitle(const string& movie_title) const {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetMovie().GetTitle() == movie_title) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

vector<Booking> BookingManager::SearchByDate(const string& booking_date) const {
    vector<Booking> results;

    for (int i = 0; i < bookings_.size(); i++) {
        if (bookings_[i].GetBookingDate() == booking_date) {
            results.push_back(bookings_[i]);
        }
    }

    return results;
}

void BookingManager::DisplayAllBookings() const {
    if (bookings_.empty()) {
        cout << "No bookings available." << endl;
        return;
    }

    for (int i = 0; i < bookings_.size(); i++) {
        cout << "Booking " << i + 1 << ":" << endl;
        bookings_[i].DisplayBooking();
        cout << endl;
    }
}

void BookingManager::LoadBookingsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Booking file not found. Starting with empty bookings." << endl;
        return;
    }

    bookings_.clear();

    string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string customer_name;
        string movie_title;
        string movie_description;
        string movie_genre;
        string running_time_str;
        string main_star;
        string film_distributor;
        string release_date;
        string screen_id;
        string booking_date;
        string booking_time;
        string adult_tickets_str;
        string child_tickets_str;
        string student_tickets_str;
        string senior_tickets_str;
        string total_cost_str;
        string payment_method;
        string card_number;
        string cvc_number;
        string expiry_date;
        string cash_paid_str;

        getline(ss, customer_name, ',');
        getline(ss, movie_title, ',');
        getline(ss, movie_description, ',');
        getline(ss, movie_genre, ',');
        getline(ss, running_time_str, ',');
        getline(ss, main_star, ',');
        getline(ss, film_distributor, ',');
        getline(ss, release_date, ',');
        getline(ss, screen_id, ',');
        getline(ss, booking_date, ',');
        getline(ss, booking_time, ',');
        getline(ss, adult_tickets_str, ',');
        getline(ss, child_tickets_str, ',');
        getline(ss, student_tickets_str, ',');
        getline(ss, senior_tickets_str, ',');
        getline(ss, total_cost_str, ',');
        getline(ss, payment_method, ',');
        getline(ss, card_number, ',');
        getline(ss, cvc_number, ',');
        getline(ss, expiry_date, ',');
        getline(ss, cash_paid_str, ',');

        int running_time = stoi(running_time_str);
        int adult_tickets = stoi(adult_tickets_str);
        int child_tickets = stoi(child_tickets_str);
        int student_tickets = stoi(student_tickets_str);
        int senior_tickets = stoi(senior_tickets_str);
        double total_cost = stod(total_cost_str);
        double cash_paid = 0.0;

        if (!cash_paid_str.empty()) {
            cash_paid = stod(cash_paid_str);
        }

        Movie movie(
            movie_title,
            movie_description,
            movie_genre,
            running_time,
            main_star,
            film_distributor,
            release_date
        );

        PaymentDetails payment_details;
        payment_details.SetPaymentMethod(payment_method);
        payment_details.SetCardNumber(card_number);
        payment_details.SetCvcNumber(cvc_number);
        payment_details.SetExpiryDate(expiry_date);
        payment_details.SetCashPaid(cash_paid);

        Booking booking(
            customer_name,
            movie,
            screen_id,
            booking_date,
            booking_time,
            adult_tickets,
            child_tickets,
            student_tickets,
            senior_tickets,
            total_cost,
            payment_details
        );

        bookings_.push_back(booking);
    }

    file.close();
}

void BookingManager::SaveBookingsToFile(const string& filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening booking file for saving." << endl;
        return;
    }

    file << "CustomerName,MovieTitle,MovieDescription,MovieGenre,RunningTime,MainStar,FilmDistributor,ReleaseDate,ScreenID,BookingDate,BookingTime,AdultTickets,ChildTickets,StudentTickets,SeniorTickets,TotalCost,PaymentMethod,CardNumber,CvcNumber,ExpiryDate,CashPaid" << endl;

    for (int i = 0; i < bookings_.size(); i++) {
        Movie movie = bookings_[i].GetMovie();
        PaymentDetails payment = bookings_[i].GetPaymentDetails();

        file << bookings_[i].GetCustomerName() << ","
             << movie.GetTitle() << ","
             << movie.GetDescription() << ","
             << movie.GetGenre() << ","
             << movie.GetRunningTime() << ","
             << movie.GetMainStar() << ","
             << movie.GetFilmDistributor() << ","
             << movie.GetReleaseDate() << ","
             << bookings_[i].GetScreenId() << ","
             << bookings_[i].GetBookingDate() << ","
             << bookings_[i].GetBookingTime() << ","
             << bookings_[i].GetAdultTickets() << ","
             << bookings_[i].GetChildTickets() << ","
             << bookings_[i].GetStudentTickets() << ","
             << bookings_[i].GetSeniorTickets() << ","
             << bookings_[i].GetTotalCost() << ","
             << payment.GetPaymentMethod() << ","
             << payment.GetCardNumber() << ","
             << payment.GetCvcNumber() << ","
             << payment.GetExpiryDate() << ","
             << payment.GetCashPaid()
             << endl;
    }

    file.close();
}