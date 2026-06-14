

| Assessment Details | Please Complete All Details                                   |
| ------------------ | ------------------------------------------------------------- |
| Group              | A                                                             |
| Module Title       | IY453 Software Design and Implementation                      |
| Assessment Type    | IY453 Software Design and Implementation Coursework           |
| Module Tutor Name  | Jonathon Shore                                                |
| Student ID Number  | P466146                                                       |
| Date of Submission | 05/05/2026                                                    |
| Word Count         | 722                                                           |
| GitHub Link        | https://github.com/firasallawati/T0466146_453_Coursework_Real |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

---

### Purpose of the Program

---

The purpose of the program is to be designed for easy creation of ticket bookings by staff which can be used at the point of sale as well as making bookings of films for customers and managers can use to plan film showings one week in advance, the program will help in selecting a film, choosing a date and time, entering the required tickets, processing a payment (cash or card), as well as ensuring compliance with the rules of the cinema.

### **Core program functionality**

- **Create bookings**
  
  - Allow selecting a title from the list of movies offered and specifying the time when it is to be shown during the current week (Thursday to Wednesday).
  
  - Collecting customer details and the number of booked tickets for adults, children, students, and senior citizens.
  
  - Ensuring that the selected movie is to be shown according to its schedule and no more tickets can be sold than the seats available.
  
  - Computing the total booking cost using the set ticket prices.Collecting information about the chosen payment means and details of the payment process.
  
  - Capture the payment method (cash or card) and any required payment details.
  
  - Store the completed bookings in memory and save it to a bookings file so it can be viewed and searched later.
  
  **Manage movies**
  
  - Allow staff to add movie details such as title, description, genre, running time, main star, distributor, and release date.
  
  - Store movie details for later use in schedule creation and bookings.
  
  - Display the list of available movies so staff and managers can see which films can be scheduled and booked.
  
  **Manage screens**
  
  - Allow staff to enter details for each screen, including screen ID, maximum seating capacity, and facilities (Standard, IMAX, Couple seats, Seat service, etc.).
  
  - Store screen details so capacity checks and schedule creation can use this information to obey cinema rules.
  
  **Create weekly schedule**
  
  - Allow a manager to select the week to be scheduled (Thursday to Wednesday).
  
  - For each screen, allow the manager to select which film will be shown for that week.
  
  - Allow the manager to enter the start time of the first showing for each day, ensuring it does not start before 10:15.
  
  - For each showing, calculate the end time using the film’s running time and ensure the show does not end after the cinema closing time of 23:30.
  
  - Automatically enforce a 25‑minute gap between consecutive showings on the same screen for cleaning.
  
  - Store all schedule entries in memory and save them to a schedule file in text or CSV format.
  
  **View and search bookings**
  
  - Give an option for staff to view all stored bookings, showing customer name, film, date, time, ticket breakdown, and total cost.
  
  - Allow staff to search bookings by customer name, film title, or date, and show only the matching records.
  
  - Display clear confirmation messages when bookings are created successfully and informative error messages when input is invalid or a booking would overbook a screen.
  
  ---
  
  **System constraints (limitations / rules)**
  
  **Time and opening hours**
  
  - The cinema is open from 10:00 until 23:30 each day.
  
  - The earliest a film can be shown is 10:15, and no show may end after 23:30.
  
  - There must be a 25‑minute gap between the end of one showing and the start of the next showing in the same screen to allow for cleaning.
  
  **Weekly scope**
  
  - The system creates and manages schedules for one week at a time, from Thursday to Wednesday.
  
  - Staff can only make bookings for showings within the current Thursday–Wednesday week.
  
  **Capacity and tickets**
  
  - Each screen has a fixed maximum seating capacity that must not be exceeded when creating a booking.
  
  - Any booking that would exceed the screen’s capacity must be rejected.
  
  - Tickets are sold in four types only: adult, child, student, and senior citizen, each with a fixed ticket price.
  
  **Data storage and interface**
  
  - The program is a text‑based console application that uses menus and keyboard input.
  
  - Bookings and schedule data are stored in text or CSV files so that information is preserved between runs of the program.
  
  - Movie and screen information may initially be stored in memory, with file storage added as needed.
  
  **Scope exclusions**
  
  - The system does not manage staff accounts, user logins, or passwords.
  
  - It does not handle food, drink, or multiple cinema locations.
  
  - Card details are collected to process a transaction but are not stored permanently in any database.

---

### Input Process Output Table

---

![](IPOC.png)

---

### Algorithms

---

<img title="" src="CFlow.PNG" alt="" width="408">

<img src="CFlow1.PNG" title="" alt="" width="143">

<img src="CFlow2.PNG" title="" alt="" width="513">

<img src="CFlow3.PNG" title="" alt="" width="439">

<img src="CFlow4.PNG" title="" alt="" width="366">

<img src="CFlow5.PNG" title="" alt="" width="530">

<img src="CFlow6.PNG" title="" alt="" width="422">

<img src="CFlow7.PNG" title="" alt="" width="398">

---

### Appendix Code

---

**movie.h:**

#ifndef T0466146_453_COURSEWORK_REAL_MOVIE_H
#define T0466146_453_COURSEWORK_REAL_MOVIE_H

#include <string>
using namespace std;

class Movie {
private:
    string title_;
    string genre_;
    string date_;
    string time_;

public:
    Movie();
    Movie(string title, string genre, string date, string time);

string GetTitle();
string GetGenre();
string GetDate();
string GetTime();

void SetTitle(string title);
void SetGenre(string genre);
void SetDate(string date);
void SetTime(string time);

void DisplayMovie();

};

#endif //T0466146_453_COURSEWORK_REAL_MOVIE_H



**movie.cpp:**

#include <iostream>
#include "movie.h"

using namespace std;

Movie::Movie() {
    title_ = "";
    genre_ = "";
    date_ = "";
    time_ = "";
}

Movie::Movie(string title, string genre, string date, string time) {
    title_ = title;
    genre_ = genre;
    date_ = date;
    time_ = time;
}

string Movie::GetTitle() {
    return title_;
}

string Movie::GetGenre() {
    return genre_;
}

string Movie::GetDate() {
    return date_;
}

string Movie::GetTime() {
    return time_;
}

void Movie::SetTitle(string title) {
    title_ = title;
}

void Movie::SetGenre(string genre) {
    genre_ = genre;
}

void Movie::SetDate(string date) {
    date_ = date;
}

void Movie::SetTime(string time) {
    time_ = time;
}

void Movie::DisplayMovie() {
    cout << "Title: " << title_ << endl;
    cout << "Genre: " << genre_ << endl;
    cout << "Date: " << date_ << endl;
    cout << "Time: " << time_ << endl;
}



**payment_details.h:**

#ifndef T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H
#define T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H

#include <string>
using namespace std;

class PaymentDetails {
private:
    string payment_method_;
    string card_number_;
    string cvc_number_;
    string expiry_date_;
    double cash_paid_;

public:
    PaymentDetails();
    PaymentDetails(string payment_method, string card_number,
                   string cvc_number, string expiry_date, double cash_paid);

string GetPaymentMethod();
string GetCardNumber();
string GetCvcNumber();
string GetExpiryDate();
double GetCashPaid();

void SetPaymentMethod(string payment_method);
void SetCardNumber(string card_number);
void SetCvcNumber(string cvc_number);
void SetExpiryDate(string expiry_date);
void SetCashPaid(double cash_paid);

void DisplayPaymentDetails();

};

#endif //T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H



**payment_details.cpp:**

#include <iostream>
#include "payment_details.h"

using namespace std;

PaymentDetails::PaymentDetails() {
    payment_method_ = "";
    card_number_ = "";
    cvc_number_ = "";
    expiry_date_ = "";
    cash_paid_ = 0.0;
}

PaymentDetails::PaymentDetails(string payment_method, string card_number,
                               string cvc_number, string expiry_date, double cash_paid) {
    payment_method_ = payment_method;
    card_number_ = card_number;
    cvc_number_ = cvc_number;
    expiry_date_ = expiry_date;
    cash_paid_ = cash_paid;
}

string PaymentDetails::GetPaymentMethod() {
    return payment_method_;
}

string PaymentDetails::GetCardNumber() {
    return card_number_;
}

string PaymentDetails::GetCvcNumber() {
    return cvc_number_;
}

string PaymentDetails::GetExpiryDate() {
    return expiry_date_;
}

double PaymentDetails::GetCashPaid() {
    return cash_paid_;
}

void PaymentDetails::SetPaymentMethod(string payment_method) {
    payment_method_ = payment_method;
}

void PaymentDetails::SetCardNumber(string card_number) {
    card_number_ = card_number;
}

void PaymentDetails::SetCvcNumber(string cvc_number) {
    cvc_number_ = cvc_number;
}

void PaymentDetails::SetExpiryDate(string expiry_date) {
    expiry_date_ = expiry_date;
}

void PaymentDetails::SetCashPaid(double cash_paid) {
    cash_paid_ = cash_paid;
}

void PaymentDetails::DisplayPaymentDetails() {
    cout << "Payment method: " << payment_method_ << endl;
    if (payment_method_ == "card") {
        cout << "Card number: " << card_number_ << endl;
        cout << "CVC number: " << cvc_number_ << endl;
        cout << "Expiry date: " << expiry_date_ << endl;
    } else if (payment_method_ == "cash") {
        cout << "Cash paid: " << cash_paid_ << endl;
    }
}



**booking.h:**

#ifndef T0466146_453_COURSEWORK_REAL_BOOKING_H
#define T0466146_453_COURSEWORK_REAL_BOOKING_H

#include <string>
#include "movie.h"
#include "payment_details.h"

using namespace std;

class Booking {
private:
    string customer_name_;
    Movie movie_;
    string booking_date_;
    string booking_time_;
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

string GetCustomerName();
Movie GetMovie();
string GetBookingDate();
string GetBookingTime();
int GetAdultTickets();
int GetChildTickets();
int GetStudentTickets();
int GetSeniorTickets();
double GetTotalCost();
PaymentDetails GetPaymentDetails();

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

int GetTotalTickets();
void DisplayBooking();

};

#endif //T0466146_453_COURSEWORK_REAL_BOOKING_H



**booking.cpp:**

#include <iostream>
#include "booking.h"

using namespace std;

Booking::Booking() {
    customer_name_ = "";
    booking_date_ = "";
    booking_time_ = "";
    adult_tickets_ = 0;
    child_tickets_ = 0;
    student_tickets_ = 0;
    senior_tickets_ = 0;
    total_cost_ = 0.0;
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

string Booking::GetCustomerName() {
    return customer_name_;
}

Movie Booking::GetMovie() {
    return movie_;
}

string Booking::GetBookingDate() {
    return booking_date_;
}

string Booking::GetBookingTime() {
    return booking_time_;
}

int Booking::GetAdultTickets() {
    return adult_tickets_;
}

int Booking::GetChildTickets() {
    return child_tickets_;
}

int Booking::GetStudentTickets() {
    return student_tickets_;
}

int Booking::GetSeniorTickets() {
    return senior_tickets_;
}

double Booking::GetTotalCost() {
    return total_cost_;
}

PaymentDetails Booking::GetPaymentDetails() {
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

int Booking::GetTotalTickets() {
    return adult_tickets_ + child_tickets_ + student_tickets_ + senior_tickets_;
}

void Booking::DisplayBooking() {
    cout << "Customer name: " << customer_name_ << endl;
    cout << "Movie title: " << movie_.GetTitle() << endl;
    cout << "Booking date: " << booking_date_ << endl;
    cout << "Booking time: " << booking_time_ << endl;
    cout << "Adult tickets: " << adult_tickets_ << endl;
    cout << "Child tickets: " << child_tickets_ << endl;
    cout << "Student tickets: " << student_tickets_ << endl;
    cout << "Senior tickets: " << senior_tickets_ << endl;
    cout << "Total tickets: " << GetTotalTickets() << endl;
    cout << "Total cost: " << total_cost_ << " GBP" << endl;
}



**main.cpp:**

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
