#include "movie_manager.h"
#include <fstream>
#include <sstream>

using namespace std;

MovieManager::MovieManager() {
}

void MovieManager::AddMovie(const Movie& movie) {
    movies.push_back(movie);
}

void MovieManager::ListMovies() const {
    if (movies.empty()) {
        cout << "No movies available." << endl;
        return;
    }

    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].GetTitle()
             << " | Genre: " << movies[i].GetGenre()
             << " | Running Time: " << movies[i].GetRunningTime() << " mins"
             << endl;
    }
}

int MovieManager::GetMovieCount() const {
    return movies.size();
}

const Movie* MovieManager::GetMovieByIndex(int index) const {
    if (index < 0 || index >= movies.size()) {
        return nullptr;
    }

    return &movies[index];
}

void MovieManager::SaveMoviesToFile(const string& filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening movie file for saving." << endl;
        return;
    }

    file << "Title,Description,Genre,RunningTime,MainStar,FilmDistributor,ReleaseDate" << endl;

    for (int i = 0; i < movies.size(); i++) {
        file << movies[i].GetTitle() << ","
             << movies[i].GetDescription() << ","
             << movies[i].GetGenre() << ","
             << movies[i].GetRunningTime() << ","
             << movies[i].GetMainStar() << ","
             << movies[i].GetFilmDistributor() << ","
             << movies[i].GetReleaseDate()
             << endl;
    }

    file.close();
}

void MovieManager::LoadMoviesFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Movie file not found. Starting with empty movie list." << endl;
        return;
    }

    movies.clear();

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string title;
        string description;
        string genre;
        string running_time_str;
        string main_star;
        string film_distributor;
        string release_date;

        getline(ss, title, ',');
        getline(ss, description, ',');
        getline(ss, genre, ',');
        getline(ss, running_time_str, ',');
        getline(ss, main_star, ',');
        getline(ss, film_distributor, ',');
        getline(ss, release_date, ',');

        int running_time = stoi(running_time_str);

        Movie movie(
            title,
            description,
            genre,
            running_time,
            main_star,
            film_distributor,
            release_date
        );

        movies.push_back(movie);
    }

    file.close();
}

void MovieManager::ClearMovies() {
    movies.clear();
}