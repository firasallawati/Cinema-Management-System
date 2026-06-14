#include <iostream>
#include <string>
using namespace std;

#include "movie.h"
#include "booking.h"
#include "payment_details.h"

int main() {
    const double ADULT_PRICE = 10.0;
    const double CHILD_PRICE = 7.0;
    const double STUDENT_PRICE = 8.0;
    const double SENIOR_PRICE = 6.0;

    Movie movie1("The Matrix", "Sci-Fi", "2000-02-15", "18:00");
    Movie movie2("Finding Nemo", "Animation", "2010-01-24", "16:00");
    Movie movie3("SpiderMan", "Action", "2026-08-04", "20:30");

    cout << "\n";
    cout << "       Cinema Booking\n";
    cout << "\n\n";

    string customer_name;
    cout << "Enter customer name (no spaces for now): ";
    cin >> customer_name;

    cout << "\nAvailable films:\n";
    cout << "1. " << movie1.GetTitle() << " (" << movie1.GetDate()
         << " " << movie1.GetTime() << ")\n";
    cout << "2. " << movie2.GetTitle() << " (" << movie2.GetDate()
         << " " << movie2.GetTime() << ")\n";
    cout << "3. " << movie3.GetTitle() << " (" << movie3.GetDate()
         << " " << movie3.GetTime() << ")\n";

    int film_choice;
    cout << "\nSelect a film (1-3): ";
    cin >> film_choice;

    while (film_choice < 1 || film_choice > 3) {
        cout << "Invalid choice. Please enter 1, 2 or 3: ";
        cin >> film_choice;
    }

    Movie selected_movie;
    if (film_choice == 1) {
        selected_movie = movie1;
    } else if (film_choice == 2) {
        selected_movie = movie2;
    } else {
        selected_movie = movie3;
    }

    int adult_tickets;
    int child_tickets;
    int student_tickets;
    int senior_tickets;

    cout << "\nEnter number of adult tickets: ";
    cin >> adult_tickets;
    while (adult_tickets < 0) {
        cout << "Tickets cannot be negative. Try again: ";
        cin >> adult_tickets;
    }

    cout << "Enter number of child tickets: ";
    cin >> child_tickets;
    while (child_tickets < 0) {
        cout << "Tickets cannot be negative. Try again: ";
        cin >> child_tickets;
    }

    cout << "Enter number of student tickets: ";
    cin >> student_tickets;
    while (student_tickets < 0) {
        cout << "Tickets cannot be negative. Try again: ";
        cin >> student_tickets;
    }

    cout << "Enter number of senior tickets: ";
    cin >> senior_tickets;
    while (senior_tickets < 0) {
        cout << "Tickets cannot be negative. Try again: ";
        cin >> senior_tickets;
    }

    double total_cost = adult_tickets * ADULT_PRICE
                      + child_tickets * CHILD_PRICE
                      + student_tickets * STUDENT_PRICE
                      + senior_tickets * SENIOR_PRICE;

    cout << "\nTotal cost of booking: " << total_cost << " GBP\n";

    string payment_method;
    cout << "\nEnter payment method (cash/card): ";
    cin >> payment_method;

    while (payment_method != "cash" && payment_method != "card") {
        cout << "Invalid. Please enter cash or card: ";
        cin >> payment_method;
    }

    PaymentDetails payment_details;

    if (payment_method == "card") {
        string card_number;
        string cvc_number;
        string expiry_date;

        cout << "Enter card number: ";
        cin >> card_number;

        cout << "Enter CVC number: ";
        cin >> cvc_number;

        cout << "Enter expiry date (mm/yy): ";
        cin >> expiry_date;

        payment_details.SetPaymentMethod("card");
        payment_details.SetCardNumber(card_number);
        payment_details.SetCvcNumber(cvc_number);
        payment_details.SetExpiryDate(expiry_date);
        payment_details.SetCashPaid(0.0);
    } else {
        double cash_paid;
        cout << "Enter amount of cash paid: ";
        cin >> cash_paid;

        while (cash_paid < total_cost) {
            cout << "Cash is less than total cost. Enter amount again: ";
            cin >> cash_paid;
        }

        double change = cash_paid - total_cost;
        cout << "Change to give customer: " << change << " GBP\n";

        payment_details.SetPaymentMethod("cash");
        payment_details.SetCashPaid(cash_paid);
        payment_details.SetCardNumber("");
        payment_details.SetCvcNumber("");
        payment_details.SetExpiryDate("");
    }

    Booking booking;
    booking.SetCustomerName(customer_name);
    booking.SetMovie(selected_movie);
    booking.SetBookingDate(selected_movie.GetDate());
    booking.SetBookingTime(selected_movie.GetTime());
    booking.SetAdultTickets(adult_tickets);
    booking.SetChildTickets(child_tickets);
    booking.SetStudentTickets(student_tickets);
    booking.SetSeniorTickets(senior_tickets);
    booking.SetTotalCost(total_cost);
    booking.SetPaymentDetails(payment_details);

    cout << "\nBooking Summary\n";
    booking.DisplayBooking();
    cout << "\nPayment details:\n";
    payment_details.DisplayPaymentDetails();

    return 0;
}