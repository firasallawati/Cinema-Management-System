#ifndef T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H
#define T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H

#include <string>

class MovieSchedule {
private:
    std::string screen_id_;
    std::string movie_title_;
    std::string day_;
    std::string date_;
    std::string start_time_;
    std::string end_time_;

public:
    MovieSchedule();
    MovieSchedule(const std::string& screen_id,
                  const std::string& movie_title,
                  const std::string& day,
                  const std::string& date,
                  const std::string& start_time,
                  const std::string& end_time);

    std::string GetScreenId() const;
    std::string GetMovieTitle() const;
    std::string GetDay() const;
    std::string GetDate() const;
    std::string GetStartTime() const;
    std::string GetEndTime() const;

    void SetScreenId(const std::string& screen_id);
    void SetMovieTitle(const std::string& movie_title);
    void SetDay(const std::string& day);
    void SetDate(const std::string& date);
    void SetStartTime(const std::string& start_time);
    void SetEndTime(const std::string& end_time);

    void DisplayMovieSchedule() const;
};

#endif //T0466146_453_COURSEWORK_REAL_MOVIE_SCHEDULE_H