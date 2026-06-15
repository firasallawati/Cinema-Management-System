#include <iostream>
#include <vector>
#include "movie.h"
#include "screen.h"
#include "payment_details.h"
#include "booking.h"
#include "booking_manager.h"
#include "movie_schedule.h"
#include "schedule_manager.h"
#include "input_handler.h"

using namespace std;

double CalculateBookingCost(int adult_tickets, int child_tickets, int student_tickets, int senior_tickets) {
    return (adult_tickets * 9.50) +
           (child_tickets * 5.50) +
           (student_tickets * 7.00) +
           (senior_tickets * 6.50);
}

void DisplayBookingResults(const vector<Booking>& bookings) {
    if (bookings.empty()) {
        cout << "No matching bookings found." << endl;
        return;
    }

    for (int i = 0; i < bookings.size(); i++) {
        cout << "Result " << i + 1 << ":" << endl;
        bookings[i].DisplayBooking();
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
        cout << "    Cinema Booking System    " << endl;
        cout << "1. Add Booking" << endl;
        cout << "2. View All Bookings" << endl;
        cout << "3. Search Bookings" << endl;
        cout << "4. Add Schedule" << endl;
        cout << "5. View All Schedules" << endl;
        cout << "6. Save Data" << endl;
        cout << "7. Load Data" << endl;
        cout << "8. Exit" << endl;

        choice = InputHandler::GetIntInRange("Enter choice: ", 1, 8);

        if (choice == 1) {
            string customer_name = InputHandler::GetNonEmptyString("Enter customer name: ");
            string movie_title = InputHandler::GetNonEmptyString("Enter movie title: ");
            string booking_day = InputHandler::GetValidDay("Enter booking day (Thursday to Wednesday): ");
            string booking_time = InputHandler::GetValidTime("Enter booking time (HH:MM): ");

            int adult_tickets = InputHandler::GetNonNegativeInt("Enter number of adult tickets: ");
            int child_tickets = InputHandler::GetNonNegativeInt("Enter number of child tickets: ");
            int student_tickets = InputHandler::GetNonNegativeInt("Enter number of student tickets: ");
            int senior_tickets = InputHandler::GetNonNegativeInt("Enter number of senior tickets: ");

            while (adult_tickets + child_tickets + student_tickets + senior_tickets == 0) {
                cout << "At least one ticket must be booked." << endl;
                adult_tickets = InputHandler::GetNonNegativeInt("Enter number of adult tickets: ");
                child_tickets = InputHandler::GetNonNegativeInt("Enter number of child tickets: ");
                student_tickets = InputHandler::GetNonNegativeInt("Enter number of student tickets: ");
                senior_tickets = InputHandler::GetNonNegativeInt("Enter number of senior tickets: ");
            }

            cout << "Choose a screen:" << endl;
            for (int i = 0; i < screens.size(); i++) {
                cout << i + 1 << ". "
                     << screens[i].GetScreenId()
                     << " | Available Seats: " << screens[i].GetAvailableSeats()
                     << " | Facilities: " << screens[i].GetFacilities()
                     << endl;
            }

            int screen_choice = InputHandler::GetIntInRange("Enter screen number: ", 1, screens.size());

            int total_tickets = adult_tickets + child_tickets + student_tickets + senior_tickets;
            while (total_tickets > screens[screen_choice - 1].GetAvailableSeats()) {
                cout << "Not enough seats available on this screen." << endl;
                cout << "Available seats: " << screens[screen_choice - 1].GetAvailableSeats() << endl;

                adult_tickets = InputHandler::GetNonNegativeInt("Re-enter number of adult tickets: ");
                child_tickets = InputHandler::GetNonNegativeInt("Re-enter number of child tickets: ");
                student_tickets = InputHandler::GetNonNegativeInt("Re-enter number of student tickets: ");
                senior_tickets = InputHandler::GetNonNegativeInt("Re-enter number of senior tickets: ");

                total_tickets = adult_tickets + child_tickets + student_tickets + senior_tickets;
            }

            double total_cost = CalculateBookingCost(adult_tickets, child_tickets, student_tickets, senior_tickets);
            cout << "Total booking cost: " << total_cost << endl;

            string payment_method = InputHandler::GetValidPaymentMethod("Enter payment method (Cash/Card): ");

            PaymentDetails payment_details;
            payment_details.SetPaymentMethod(payment_method);

            if (payment_method == "Card") {
                string card_number = InputHandler::GetNonEmptyString("Enter card number: ");
                string cvc_number = InputHandler::GetNonEmptyString("Enter CVC number: ");
                string expiry_date = InputHandler::GetNonEmptyString("Enter expiry date: ");

                payment_details.SetCardNumber(card_number);
                payment_details.SetCvcNumber(cvc_number);
                payment_details.SetExpiryDate(expiry_date);
            } else {
                double cash_paid = InputHandler::GetDoubleAtLeast("Enter cash paid: ", total_cost);
                payment_details.SetCashPaid(cash_paid);
            }

            Movie movie;
            movie.SetTitle(movie_title);

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

                int updated_seats = screens[screen_choice - 1].GetAvailableSeats() - booking.GetTotalTickets();
                screens[screen_choice - 1].SetAvailableSeats(updated_seats);
                screens[screen_choice - 1].SetCurrentMovie(movie_title);

                cout << "Booking added successfully." << endl;
            } else {
                cout << "Booking could not be added. Check booking rules or screen capacity." << endl;
            }
        }

        else if (choice == 2) {
            booking_manager.DisplayAllBookings();
        }

        else if (choice == 3) {
            cout << "Search bookings by:" << endl;
            cout << "1. Customer name" << endl;
            cout << "2. Movie title" << endl;
            cout << "3. Date/Day" << endl;

            int search_choice = InputHandler::GetIntInRange("Enter choice: ", 1, 3);

            if (search_choice == 1) {
                string customer_name = InputHandler::GetNonEmptyString("Enter customer name: ");
                DisplayBookingResults(booking_manager.SearchByCustomerName(customer_name));
            } else if (search_choice == 2) {
                string movie_title = InputHandler::GetNonEmptyString("Enter movie title: ");
                DisplayBookingResults(booking_manager.SearchByMovieTitle(movie_title));
            } else {
                string booking_date = InputHandler::GetNonEmptyString("Enter date/day: ");
                DisplayBookingResults(booking_manager.SearchByDate(booking_date));
            }
        }

        else if (choice == 4) {
            string screen_id = InputHandler::GetNonEmptyString("Enter screen ID: ");
            string movie_title = InputHandler::GetNonEmptyString("Enter movie title: ");
            string day = InputHandler::GetValidDay("Enter day: ");
            string date = InputHandler::GetNonEmptyString("Enter date: ");
            string start_time = InputHandler::GetValidTime("Enter start time (HH:MM): ");
            string end_time = InputHandler::GetValidEndTimeAfterStart("Enter end time (HH:MM): ", start_time);

            MovieSchedule schedule(screen_id, movie_title, day, date, start_time, end_time);

            if (schedule_manager.CanAddSchedule(schedule)) {
                schedule_manager.AddSchedule(schedule);
                cout << "Schedule added successfully." << endl;
            } else {
                cout << "Schedule could not be added. Check schedule overlap or 25-minute gap." << endl;
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
    }

    return 0;
}