//
// Created by firas on 15/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_INPUT_HANDLER_H
#define T0466146_453_COURSEWORK_REAL_INPUT_HANDLER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InputHandler {
public:
    static string GetNonEmptyString(const string& prompt);
    static int GetNonNegativeInt(const string& prompt);
    static int GetIntInRange(const string& prompt, int min, int max);
    static double GetDoubleAtLeast(const string& prompt, double minimum_value);

    static string NormalizeDay(string day);
    static bool IsValidDay(const string& day);
    static string GetValidDay(const string& prompt);

    static bool IsValidTimeFormat(const string& time_text);
    static int TimeToMinutes(const string& time_text);
    static string GetValidTime(const string& prompt);
    static string GetValidEndTimeAfterStart(const string& prompt, const string& start_time);

    static string GetValidPaymentMethod(const string& prompt);
};

#endif //T0466146_453_COURSEWORK_REAL_INPUT_HANDLER_H
