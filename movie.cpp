#include "movie.h"

using namespace std;

Movie::Movie()
    : title(""),
      description(""),
      genre(""),
      running_time(0),
      main_star(""),
      film_distributor(""),
      release_date("") {
}

Movie::Movie(const string& title,
             const string& description,
             const string& genre,
             int running_time,
             const string& main_star,
             const string& film_distributor,
             const string& release_date)
    : title(title),
      description(description),
      genre(genre),
      running_time(running_time),
      main_star(main_star),
      film_distributor(film_distributor),
      release_date(release_date) {
}

string Movie::GetTitle() const {
    return title;
}

string Movie::GetDescription() const {
    return description;
}

string Movie::GetGenre() const {
    return genre;
}

int Movie::GetRunningTime() const {
    return running_time;
}

string Movie::GetMainStar() const {
    return main_star;
}

string Movie::GetFilmDistributor() const {
    return film_distributor;
}

string Movie::GetReleaseDate() const {
    return release_date;
}

void Movie::SetTitle(const string& title) {
    this->title = title;
}

void Movie::SetDescription(const string& description) {
    this->description = description;
}

void Movie::SetGenre(const string& genre) {
    this->genre = genre;
}

void Movie::SetRunningTime(int running_time) {
    this->running_time = running_time;
}

void Movie::SetMainStar(const string& main_star) {
    this->main_star = main_star;
}

void Movie::SetFilmDistributor(const string& film_distributor) {
    this->film_distributor = film_distributor;
}

void Movie::SetReleaseDate(const string& release_date) {
    this->release_date = release_date;
}

void Movie::DisplayMovie() const {
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Genre: " << genre << endl;
    cout << "Running Time: " << running_time << " minutes" << endl;
    cout << "Main Star: " << main_star << endl;
    cout << "Film Distributor: " << film_distributor << endl;
    cout << "Release Date: " << release_date << endl;
}