//
// Created by firas on 15/06/2026.
//

#include "schedule_manager.h"

using namespace std;

ScheduleManager::ScheduleManager() {
}

void ScheduleManager::AddSchedule(MovieSchedule schedule) {
    schedules_.push_back(schedule);
}

void ScheduleManager::DisplayAllSchedules() {
    if (schedules_.empty()) {
        cout << "No schedules found." << endl;
        return;
    }

    for (int i = 0; i < schedules_.size(); i++) {
        cout << "Schedule " << i + 1 << ":" << endl;
        schedules_[i].DisplayMovieSchedule();
        cout << endl;
    }
}

vector<MovieSchedule> ScheduleManager::SearchByMovieTitle(string movie_title) {
    vector<MovieSchedule> results;

    for (int i = 0; i < schedules_.size(); i++) {
        if (schedules_[i].GetMovieTitle() == movie_title) {
            results.push_back(schedules_[i]);
        }
    }

    return results;
}

vector<MovieSchedule> ScheduleManager::SearchByScreenId(string screen_id) {
    vector<MovieSchedule> results;

    for (int i = 0; i < schedules_.size(); i++) {
        if (schedules_[i].GetScreenId() == screen_id) {
            results.push_back(schedules_[i]);
        }
    }

    return results;
}

vector<MovieSchedule> ScheduleManager::SearchByDate(string date) {
    vector<MovieSchedule> results;

    for (int i = 0; i < schedules_.size(); i++) {
        if (schedules_[i].GetDate() == date) {
            results.push_back(schedules_[i]);
        }
    }

    return results;
}

bool ScheduleManager::IsValidScheduleDay(string day) {
    if (day == "Thursday" || day == "Friday" ||
        day == "Saturday" || day == "Sunday" ||
        day == "Monday" || day == "Tuesday" ||
        day == "Wednesday") {
        return true;
    }

    return false;
}

bool ScheduleManager::IsTimeOrderValid(string start_time, string end_time) {
    if (start_time < end_time) {
        return true;
    }

    return false;
}

bool ScheduleManager::HasTwentyFiveMinuteGap(string previous_end_time, string next_start_time) {
    int previous_end_hour = stoi(previous_end_time.substr(0, 2));
    int previous_end_minute = stoi(previous_end_time.substr(3, 2));

    int next_start_hour = stoi(next_start_time.substr(0, 2));
    int next_start_minute = stoi(next_start_time.substr(3, 2));

    int previous_total_minutes = previous_end_hour * 60 + previous_end_minute;
    int next_total_minutes = next_start_hour * 60 + next_start_minute;

    if (next_total_minutes - previous_total_minutes >= 25) {
        return true;
    }

    return false;
}

bool ScheduleManager::CanAddSchedule(MovieSchedule schedule) {
    if (!IsValidScheduleDay(schedule.GetDay())) {
        return false;
    }

    if (!IsTimeOrderValid(schedule.GetStartTime(), schedule.GetEndTime())) {
        return false;
    }

    for (int i = 0; i < schedules_.size(); i++) {
        if (schedules_[i].GetScreenId() == schedule.GetScreenId() &&
            schedules_[i].GetDay() == schedule.GetDay() &&
            schedules_[i].GetDate() == schedule.GetDate()) {

            if (!HasTwentyFiveMinuteGap(schedules_[i].GetEndTime(), schedule.GetStartTime()) &&
                !HasTwentyFiveMinuteGap(schedule.GetEndTime(), schedules_[i].GetStartTime())) {
                return false;
            }
        }
    }

    return true;
}

void ScheduleManager::SaveSchedulesToFile(string file_name) {
    ofstream out_file(file_name);

    if (!out_file.is_open()) {
        cout << "Error opening schedule file for writing." << endl;
        return;
    }

    for (int i = 0; i < schedules_.size(); i++) {
        out_file
            << schedules_[i].GetScreenId() << ","
            << schedules_[i].GetMovieTitle() << ","
            << schedules_[i].GetDay() << ","
            << schedules_[i].GetDate() << ","
            << schedules_[i].GetStartTime() << ","
            << schedules_[i].GetEndTime()
            << endl;
    }

    out_file.close();
}

void ScheduleManager::LoadSchedulesFromFile(string file_name) {
    ifstream in_file(file_name);

    if (!in_file.is_open()) {
        cout << "Error opening schedule file for reading." << endl;
        return;
    }

    schedules_.clear();

    string line;
    while (getline(in_file, line)) {
        stringstream ss(line);
        string screen_id;
        string movie_title;
        string day;
        string date;
        string start_time;
        string end_time;

        getline(ss, screen_id, ',');
        getline(ss, movie_title, ',');
        getline(ss, day, ',');
        getline(ss, date, ',');
        getline(ss, start_time, ',');
        getline(ss, end_time, ',');

        MovieSchedule schedule(screen_id, movie_title, day, date, start_time, end_time);
        schedules_.push_back(schedule);
    }

    in_file.close();
}

vector<MovieSchedule> ScheduleManager::GetSchedules() {
    return schedules_;
}
