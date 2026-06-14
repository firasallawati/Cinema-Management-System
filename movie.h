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
    int runningTime_;
    string mainStar_;
    string distributor_;
    string releaseDate_;

public:
    Movie();
    Movie(string title, string description, string genre, string certificate,
          int runningTime, string mainStar, string distributor, string releaseDate);

    string GetTitle();
    string GetDescription();
    string GetGenre();
    string GetCertificate();
    int GetRunningTime();
    string GetMainStar();
    string GetDistributor();
    string GetReleaseDate();

    void SetTitle(string title);
    void SetDescription(string description);
    void SetGenre(string genre);
    void SetCertificate(string certificate);
    void SetRunningTime(int runningTime);
    void SetMainStar(string mainStar);
    void SetDistributor(string distributor);
    void SetReleaseDate(string releaseDate);

    void DisplayMovie();
};

#endif //T0466146_453_COURSEWORK_REAL_MOVIE_H
