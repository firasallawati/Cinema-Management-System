#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

using namespace std;

class MovieManager {
private:
    vector<Movie> movies;

public:
    MovieManager();

    void AddMovie(const Movie& movie);
    void ListMovies() const;
    int GetMovieCount() const;
    const Movie* GetMovieByIndex(int index) const;

    void SaveMoviesToFile(const string& filename) const;
    void LoadMoviesFromFile(const string& filename);

    void ClearMovies();
};

#endif