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
#include "movie_manager.h"

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
    MovieManager movie_manager;

    vector<Screen> screens;
    screens.push_back(Screen("Screen 1", "No Movie", 250, 250, "IMAX"));
    screens.push_back(Screen("Screen 2", "No Movie", 200, 200, "Standard"));
    screens.push_back(Screen("Screen 3", "No Movie", 180, 180, "Couple Seats"));
    screens.push_back(Screen("Screen 4", "No Movie", 150, 150, "Seat Service"));
    screens.push_back(Screen("Screen 5", "No Movie", 100, 100, "Standard"));

    int choice = 0;

    while (choice != 11) {
        cout << endl;
        cout << "     Cinema Booking System   " << endl;
        cout << "1. Add Booking" << endl;
        cout << "2. View All Bookings" << endl;
        cout << "3. Add Movies" << endl;
        cout << "4. List Movies" << endl;
        cout << "5. Add Schedule" << endl;
        cout << "6. View All Schedules" << endl;
        cout << "7. Search Bookings" << endl;
        cout << "8. Save Data" << endl;
        cout << "9. Load Data" << endl;
        cout << "10. Reset Data" << endl;
        cout << "11. Exit" << endl;

        choice = InputHandler::GetIntInRange("Enter choice: ", 1, 11);

        if (choice == 1) {
            if (movie_manager.GetMovieCount() == 0) {
                cout << "No movies available. Please add movies or load data first." << endl;
                continue;
            }

            string customer_name = InputHandler::GetNonEmptyString("Enter customer name: ");

            cout << "Available movies:" << endl;
            movie_manager.ListMovies();
            int movie_choice = InputHandler::GetIntInRange("Enter movie number: ", 1, movie_manager.GetMovieCount());
            const Movie* selected_movie = movie_manager.GetMovieByIndex(movie_choice - 1);

            if (selected_movie == nullptr) {
                cout << "Invalid movie choice." << endl;
                continue;
            }

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
            string screen_id = screens[screen_choice - 1].GetScreenId();

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

            Booking booking(
                customer_name,
                *selected_movie,
                screen_id,
                booking_day,
                booking_time,
                adult_tickets,
                child_tickets,
                student_tickets,
                senior_tickets,
                total_cost,
                payment_details
            );

            if (booking_manager.CanAddBooking(booking)) {
                booking_manager.AddBooking(booking);

                int updated_seats = screens[screen_choice - 1].GetAvailableSeats() - booking.GetTotalTickets();
                screens[screen_choice - 1].SetAvailableSeats(updated_seats);
                screens[screen_choice - 1].SetCurrentMovie(selected_movie->GetTitle());

                cout << "Booking added successfully." << endl;
            } else {
                cout << "Booking could not be added. Check booking rules or screen capacity." << endl;
            }
        }

        else if (choice == 2) {
            booking_manager.DisplayAllBookings();
        }

        else if (choice == 3) {
            cout << "Add new movie" << endl;

            string title = InputHandler::GetNonEmptyString("Enter movie title: ");
            string description = InputHandler::GetNonEmptyString("Enter description: ");
            string genre = InputHandler::GetNonEmptyString("Enter genre: ");
            int running_time = InputHandler::GetNonNegativeInt("Enter running time (minutes): ");
            string main_star = InputHandler::GetNonEmptyString("Enter main star: ");
            string film_distributor = InputHandler::GetNonEmptyString("Enter film distributor: ");
            string release_date = InputHandler::GetNonEmptyString("Enter release date: ");

            Movie movie(
                title,
                description,
                genre,
                running_time,
                main_star,
                film_distributor,
                release_date
            );

            movie_manager.AddMovie(movie);
            cout << "Movie added successfully." << endl;
        }

        else if (choice == 4) {
            movie_manager.ListMovies();
        }

        else if (choice == 5) {
            if (movie_manager.GetMovieCount() == 0) {
                cout << "No movies available. Please add movies or load data first." << endl;
                continue;
            }

            string screen_id = InputHandler::GetNonEmptyString("Enter screen ID: ");

            cout << "Available movies:" << endl;
            movie_manager.ListMovies();
            int movie_choice = InputHandler::GetIntInRange("Enter movie number: ", 1, movie_manager.GetMovieCount());
            const Movie* selected_movie = movie_manager.GetMovieByIndex(movie_choice - 1);

            if (selected_movie == nullptr) {
                cout << "Invalid movie choice." << endl;
                continue;
            }

            string day = InputHandler::GetValidDay("Enter day: ");
            string date = InputHandler::GetNonEmptyString("Enter date: ");
            string start_time = InputHandler::GetValidTime("Enter start time (HH:MM): ");
            string end_time = InputHandler::GetValidEndTimeAfterStart("Enter end time (HH:MM): ", start_time);

            MovieSchedule schedule(screen_id, selected_movie->GetTitle(), day, date, start_time, end_time);

            if (schedule_manager.CanAddSchedule(schedule)) {
                schedule_manager.AddSchedule(schedule);
                cout << "Schedule added successfully." << endl;
            } else {
                cout << "Schedule could not be added. Check schedule overlap or 25-minute gap." << endl;
            }
        }

        else if (choice == 6) {
            schedule_manager.DisplayAllSchedules();
        }

        else if (choice == 7) {
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

        else if (choice == 8) {
            booking_manager.SaveBookingsToFile("bookings.csv");
            schedule_manager.SaveSchedulesToFile("schedules.csv");
            movie_manager.SaveMoviesToFile("movies.csv");
            cout << "Data saved successfully." << endl;
        }

        else if (choice == 9) {
            booking_manager.LoadBookingsFromFile("bookings.csv");
            schedule_manager.LoadSchedulesFromFile("schedules.csv");
            movie_manager.LoadMoviesFromFile("movies.csv");
            cout << "Data loaded successfully." << endl;
        }

        else if (choice == 10) {
            string confirm;

            do {
                confirm = InputHandler::GetNonEmptyString("Are you sure you want to reset all data (Bookings, Schedules & Movies)? This action cannot be undone. (Y/N): ");

                if (confirm == "Y" || confirm == "y") {
                    booking_manager = BookingManager();
                    schedule_manager = ScheduleManager();
                    movie_manager = MovieManager();

                    screens.clear();
                    screens.push_back(Screen("Screen 1", "No Movie", 250, 250, "IMAX"));
                    screens.push_back(Screen("Screen 2", "No Movie", 200, 200, "Standard"));
                    screens.push_back(Screen("Screen 3", "No Movie", 180, 180, "Couple Seats"));
                    screens.push_back(Screen("Screen 4", "No Movie", 150, 150, "Seat Service"));
                    screens.push_back(Screen("Screen 5", "No Movie", 100, 100, "Standard"));

                    cout << "All data reset successfully." << endl;
                    break;
                }
                else if (confirm == "N" || confirm == "n") {
                    cout << "Reset cancelled." << endl;
                    break;
                }
                else {
                    cout << "Invalid input. Please enter Y or N." << endl;
                }

            } while (true);
        }

        else if (choice == 11) {
            cout << "Exiting program." << endl;
        }
    }

    return 0;
}
