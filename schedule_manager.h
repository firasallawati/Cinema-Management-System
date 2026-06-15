//
// Created by firas on 15/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_SCHEDULE_MANAGER_H
#define T0466146_453_COURSEWORK_REAL_SCHEDULE_MANAGER_H



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "movie_schedule.h"
#include "movie.h"
#include "screen.h"

using namespace std;

class ScheduleManager {
private:
    vector<MovieSchedule> schedules_;

public:
    ScheduleManager();

    void AddSchedule(MovieSchedule schedule);
    void DisplayAllSchedules();

    vector<MovieSchedule> SearchByMovieTitle(string movie_title);
    vector<MovieSchedule> SearchByScreenId(string screen_id);
    vector<MovieSchedule> SearchByDate(string date);

    bool IsValidScheduleDay(string day);
    bool IsTimeOrderValid(string start_time, string end_time);
    bool HasTwentyFiveMinuteGap(string previous_end_time, string next_start_time);
    bool CanAddSchedule(MovieSchedule schedule);

    void SaveSchedulesToFile(string file_name);
    void LoadSchedulesFromFile(string file_name);

    vector<MovieSchedule> GetSchedules();
};


#endif //T0466146_453_COURSEWORK_REAL_SCHEDULE_MANAGER_H
