#include <iostream>
#include <string>
#include <vector>

#include "movie.h"
#include "screen.h"
#include "booking.h"
#include "payment_details.h"

using namespace std;

void DisplayMainMenu() {
    cout << endl;
    cout << "Cinema Management System" << endl;
    cout << "========================" << endl;
    cout << "1. Manage Movies" << endl;
    cout << "2. Manage Screens" << endl;
    cout << "3. Manage Weekly Schedule" << endl;
    cout << "4. Create Booking" << endl;
    cout << "5. View All Bookings" << endl;
    cout << "6. Search Bookings" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter option: ";
}

