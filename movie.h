#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string description;
    string genre;
    int running_time;
    string main_star;
    string film_distributor;
    string release_date;

public:
    Movie();

    Movie(const string& title,
          const string& description,
          const string& genre,
          int running_time,
          const string& main_star,
          const string& film_distributor,
          const string& release_date);

    string GetTitle() const;
    string GetDescription() const;
    string GetGenre() const;
    int GetRunningTime() const;
    string GetMainStar() const;
    string GetFilmDistributor() const;
    string GetReleaseDate() const;

    void SetTitle(const string& title);
    void SetDescription(const string& description);
    void SetGenre(const string& genre);
    void SetRunningTime(int running_time);
    void SetMainStar(const string& main_star);
    void SetFilmDistributor(const string& film_distributor);
    void SetReleaseDate(const string& release_date);

    void DisplayMovie() const;
};

#endif