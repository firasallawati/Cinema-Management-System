#include <iostream>
#include <vector>
#include <string>
#include "movie.h"
#include "screen.h"
#include "payment_details.h"
#include "booking.h"
#include "booking_manager.h"
#include "movie_schedule.h"
#include "schedule_manager.h"

using namespace std;

double CalculateBookingCost(int adult_tickets, int child_tickets, int student_tickets, int senior_tickets) {
    double adult_price = 9.50;
    double child_price = 5.50;
    double student_price = 7.00;
    double senior_price = 6.50;

    return (adult_tickets * adult_price) +
           (child_tickets * child_price) +
           (student_tickets * student_price) +
           (senior_tickets * senior_price);
}

void DisplayBookingSearchResults(vector<Booking> results) {
    if (results.empty()) {
        cout << "No matching bookings found." << endl;
        return;
    }

    for (int i = 0; i < results.size(); i++) {
        cout << "Result " << i + 1 << ":" << endl;
        results[i].DisplayBooking();
        cout << endl;
    }
}

int main() {
    BookingManager booking_manager;
    ScheduleManager schedule_manager;

    vector<Screen> screens;
    screens.push_back(Screen("Screen 1", "No Movie", 250, 250, "IMAX"));
    screens.push_back(Screen("Screen 2", "No Movie", 200, 200, "Standard"));
    screens.push_back(Screen("Screen 3", "No Movie", 180, 180, "Couple Seats"));
    screens.push_back(Screen("Screen 4", "No Movie", 150, 150, "Seat Service"));
    screens.push_back(Screen("Screen 5", "No Movie", 100, 100, "Standard"));

    int choice = 0;

    while (choice != 8) {
        cout << endl;
        cout << "    Cinema Booking System     " << endl;
        cout << "1. Add Booking" << endl;
        cout << "2. View All Bookings" << endl;
        cout << "3. Search Bookings" << endl;
        cout << "4. Add Schedule" << endl;
        cout << "5. View All Schedules" << endl;
        cout << "6. Save Data" << endl;
        cout << "7. Load Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string customer_name;
            string movie_title;
            string booking_day;
            string booking_time;
            int adult_tickets;
            int child_tickets;
            int student_tickets;
            int senior_tickets;
            string payment_method;

            cout << "Enter customer name: ";
            getline(cin, customer_name);

            cout << "Enter movie title: ";
            getline(cin, movie_title);

            cout << "Enter booking day (Thursday to Wednesday): ";
            getline(cin, booking_day);

            cout << "Enter booking time (HH:MM): ";
            getline(cin, booking_time);

            cout << "Enter number of adult tickets: ";
            cin >> adult_tickets;

            cout << "Enter number of child tickets: ";
            cin >> child_tickets;

            cout << "Enter number of student tickets: ";
            cin >> student_tickets;

            cout << "Enter number of senior tickets: ";
            cin >> senior_tickets;
            cin.ignore();

            cout << "Choose a screen:" << endl;
            for (int i = 0; i < screens.size(); i++) {
                cout << i + 1 << ". " << screens[i].GetScreenId()
                     << " | Capacity: " << screens[i].GetAvailableSeats()
                     << " | Facilities: " << screens[i].GetFacilities() << endl;
            }

            int screen_choice;
            cout << "Enter screen number: ";
            cin >> screen_choice;
            cin.ignore();

            if (screen_choice < 1 || screen_choice > screens.size()) {
                cout << "Invalid screen choice." << endl;
                continue;
            }

            Movie movie;
            movie.SetTitle(movie_title);

            double total_cost = CalculateBookingCost(adult_tickets, child_tickets, student_tickets, senior_tickets);

            PaymentDetails payment_details;
            cout << "Enter payment method (Cash/Card): ";
            getline(cin, payment_method);
            payment_details.SetPaymentMethod(payment_method);

            if (payment_method == "Card" || payment_method == "card") {
                string card_number;
                string cvc_number;
                string expiry_date;

                cout << "Enter card number: ";
                getline(cin, card_number);
                cout << "Enter CVC number: ";
                getline(cin, cvc_number);
                cout << "Enter expiry date: ";
                getline(cin, expiry_date);

                payment_details.SetCardNumber(card_number);
                payment_details.SetCvcNumber(cvc_number);
                payment_details.SetExpiryDate(expiry_date);
            } else if (payment_method == "Cash" || payment_method == "cash") {
                double cash_paid;
                cout << "Enter cash paid: ";
                cin >> cash_paid;
                cin.ignore();
                payment_details.SetCashPaid(cash_paid);
            }

            Booking booking(
                customer_name,
                movie,
                booking_day,
                booking_time,
                adult_tickets,
                child_tickets,
                student_tickets,
                senior_tickets,
                total_cost,
                payment_details
            );

            if (booking_manager.CanAddBooking(screens[screen_choice - 1], booking)) {
                booking_manager.AddBooking(booking);

                int remaining_seats = screens[screen_choice - 1].GetAvailableSeats() - booking.GetTotalTickets();
                screens[screen_choice - 1].SetAvailableSeats(remaining_seats);
                screens[screen_choice - 1].SetCurrentMovie(movie_title);

                cout << "Booking added successfully." << endl;
                cout << "Total cost: " << total_cost << endl;
            } else {
                cout << "Booking could not be added. Check day or seating capacity." << endl;
            }
        }

        else if (choice == 2) {
            booking_manager.DisplayAllBookings();
        }

        else if (choice == 3) {
            int search_choice;
            cout << "Search bookings by:" << endl;
            cout << "1. Customer name" << endl;
            cout << "2. Movie title" << endl;
            cout << "3. Date/Day" << endl;
            cout << "Enter choice: ";
            cin >> search_choice;
            cin.ignore();

            if (search_choice == 1) {
                string customer_name;
                cout << "Enter customer name: ";
                getline(cin, customer_name);
                DisplayBookingSearchResults(booking_manager.SearchByCustomerName(customer_name));
            } else if (search_choice == 2) {
                string movie_title;
                cout << "Enter movie title: ";
                getline(cin, movie_title);
                DisplayBookingSearchResults(booking_manager.SearchByMovieTitle(movie_title));
            } else if (search_choice == 3) {
                string booking_date;
                cout << "Enter date/day: ";
                getline(cin, booking_date);
                DisplayBookingSearchResults(booking_manager.SearchByDate(booking_date));
            } else {
                cout << "Invalid search choice." << endl;
            }
        }

        else if (choice == 4) {
            string screen_id;
            string movie_title;
            string day;
            string date;
            string start_time;
            string end_time;

            cout << "Enter screen ID: ";
            getline(cin, screen_id);

            cout << "Enter movie title: ";
            getline(cin, movie_title);

            cout << "Enter day: ";
            getline(cin, day);

            cout << "Enter date: ";
            getline(cin, date);

            cout << "Enter start time (HH:MM): ";
            getline(cin, start_time);

            cout << "Enter end time (HH:MM): ";
            getline(cin, end_time);

            MovieSchedule schedule(screen_id, movie_title, day, date, start_time, end_time);

            if (schedule_manager.CanAddSchedule(schedule)) {
                schedule_manager.AddSchedule(schedule);
                cout << "Schedule added successfully." << endl;
            } else {
                cout << "Schedule could not be added. Check day, time order, or 25-minute gap." << endl;
            }
        }

        else if (choice == 5) {
            schedule_manager.DisplayAllSchedules();
        }

        else if (choice == 6) {
            booking_manager.SaveBookingsToFile("bookings.csv");
            schedule_manager.SaveSchedulesToFile("schedules.csv");
            cout << "Data saved successfully." << endl;
        }

        else if (choice == 7) {
            booking_manager.LoadBookingsFromFile("bookings.csv");
            schedule_manager.LoadSchedulesFromFile("schedules.csv");
            cout << "Data loaded successfully." << endl;
        }

        else if (choice == 8) {
            cout << "Exiting program." << endl;
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}