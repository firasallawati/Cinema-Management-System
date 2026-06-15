//
// Created by firas on 15/06/2026.
//

#include "input_handler.h"
#include <cctype>
string InputHandler::GetNonEmptyString(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (!value.empty()) {
            return value;
        }
        cout << "Input cannot be empty. Please try again." << endl;
    }
}
int InputHandler::GetNonNegativeInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid number. Please enter a whole number." << endl;
            continue;
        }
        cin.ignore(10000, '\n');
        if (value >= 0) {
            return value;
        }
        cout << "Number cannot be negative. Please try again." << endl;
    }
}
int InputHandler::GetIntInRange(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid number. Please enter a whole number." << endl;
            continue;
        }
        cin.ignore(10000, '\n');
        if (value >= min && value <= max) {
            return value;
        }
        cout << "Invalid choice. Enter a number between " << min << " and " << max << "." << endl;
    }
}
double InputHandler::GetDoubleAtLeast(const string& prompt, double minimum_value) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid amount. Please enter a valid number." << endl;
            continue;
        }
        cin.ignore(10000, '\n');
        if (value >= minimum_value) {
            return value;
        }
        cout << "Amount must be at least " << minimum_value << "." << endl;
    }
}
string InputHandler::NormalizeDay(string day) {
    for (int i = 0; i < day.length(); i++) {
        day[i] = tolower(day[i]);
    }
    if (!day.empty()) {
        day[0] = toupper(day[0]);
    }
    return day;
}
bool InputHandler::IsValidDay(const string& day) {
    return day == "Thursday" || day == "Friday" || day == "Saturday" ||
           day == "Sunday" || day == "Monday" || day == "Tuesday" ||
           day == "Wednesday";
}
string InputHandler::GetValidDay(const string& prompt) {
    string day;
    while (true) {
        cout << prompt;
        getline(cin, day);
        day = NormalizeDay(day);
        if (IsValidDay(day)) {
            return day;
        }
        cout << "Invalid day. Enter a day from Thursday to Wednesday." << endl;
    }
}
bool InputHandler::IsValidTimeFormat(const string& time_text) {
    if (time_text.length() != 5) {
        return false;
    }
    if (time_text[2] != ':') {
        return false;
    }
    if (!isdigit(time_text[0]) || !isdigit(time_text[1]) ||
        !isdigit(time_text[3]) || !isdigit(time_text[4])) {
        return false;
    }
    int hours = stoi(time_text.substr(0, 2));
    int minutes = stoi(time_text.substr(3, 2));
    return hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59;
}
int InputHandler::TimeToMinutes(const string& time_text) {
    int hours = stoi(time_text.substr(0, 2));
    int minutes = stoi(time_text.substr(3, 2));
    return (hours * 60) + minutes;
}
string InputHandler::GetValidTime(const string& prompt) {
    string time_text;
    while (true) {
        cout << prompt;
        getline(cin, time_text);
        if (IsValidTimeFormat(time_text)) {
            return time_text;
        }
        cout << "Invalid time format. Please use HH:MM." << endl;
    }
}
string InputHandler::GetValidEndTimeAfterStart(const string& prompt, const string& start_time) {
    string end_time;
    while (true) {
        end_time = GetValidTime(prompt);
        if (TimeToMinutes(end_time) > TimeToMinutes(start_time)) {
            return end_time;
        }
        cout << "End time must be later than start time. Please enter a valid end time." << endl;
    }
}
string InputHandler::GetValidPaymentMethod(const string& prompt) {
    string payment_method;
    while (true) {
        cout << prompt;
        getline(cin, payment_method);
        for (int i = 0; i < payment_method.length(); i++) {
            payment_method[i] = tolower(payment_method[i]);
        }
        if (payment_method == "cash") {
            return "Cash";
        }
        if (payment_method == "card") {
            return "Card";
        }
        cout << "Invalid payment method. Please enter Cash or Card." << endl;
    }
}
