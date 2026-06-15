//
// Created by firas on 12/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_MOVIE_H
#define T0466146_453_COURSEWORK_REAL_MOVIE_H


#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title_;
    string description_;
    string genre_;
    string certificate_;
    int running_time_;
    string main_star_;
    string distributor_;
    string release_date_;

public:
    Movie();
    Movie(string title, string description, string genre, string certificate,
          int running_time, string main_star, string distributor, string release_date);

    string GetTitle() const;
    string GetDescription() const;
    string GetGenre() const;
    string GetCertificate() const;
    int GetRunningTime() const;
    string GetMainStar() const;
    string GetDistributor() const;
    string GetReleaseDate() const;

    void SetTitle(string title);
    void SetDescription(string description);
    void SetGenre(string genre);
    void SetCertificate(string certificate);
    void SetRunningTime(int running_time);
    void SetMainStar(string main_star);
    void SetDistributor(string distributor);
    void SetReleaseDate(string release_date);

    void DisplayMovie() const;
};



#endif //T0466146_453_COURSEWORK_REAL_MOVIE_H
