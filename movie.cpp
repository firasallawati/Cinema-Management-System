//
// Created by firas on 12/06/2026.
//

#include "movie.h"

using namespace std;

Movie::Movie() {
    title_ = "";
    description_ = "";
    genre_ = "";
    certificate_ = "";
    runningTime_ = 0;
    mainStar_ = "";
    distributor_ = "";
    releaseDate_ = "";
}

Movie::Movie(string title, string description, string genre, string certificate,
             int runningTime, string mainStar, string distributor, string releaseDate) {
    title_ = title;
    description_ = description;
    genre_ = genre;
    certificate_ = certificate;
    runningTime_ = runningTime;
    mainStar_ = mainStar;
    distributor_ = distributor;
    releaseDate_ = releaseDate;
}

string Movie::GetTitle() {
    return title_;
}

string Movie::GetDescription() {
    return description_;
}

string Movie::GetGenre() {
    return genre_;
}

string Movie::GetCertificate() {
    return certificate_;
}

int Movie::GetRunningTime() {
    return runningTime_;
}

string Movie::GetMainStar() {
    return mainStar_;
}

string Movie::GetDistributor() {
    return distributor_;
}

string Movie::GetReleaseDate() {
    return releaseDate_;
}

void Movie::SetTitle(string title) {
    title_ = title;
}

void Movie::SetDescription(string description) {
    description_ = description;
}

void Movie::SetGenre(string genre) {
    genre_ = genre;
}

void Movie::SetCertificate(string certificate) {
    certificate_ = certificate;
}

void Movie::SetRunningTime(int runningTime) {
    runningTime_ = runningTime;
}

void Movie::SetMainStar(string mainStar) {
    mainStar_ = mainStar;
}

void Movie::SetDistributor(string distributor) {
    distributor_ = distributor;
}

void Movie::SetReleaseDate(string releaseDate) {
    releaseDate_ = releaseDate;
}

void Movie::DisplayMovie() {
    cout << "Title: " << title_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Genre: " << genre_ << endl;
    cout << "Certificate: " << certificate_ << endl;
    cout << "Running Time: " << runningTime_ << " minutes" << endl;
    cout << "Main Star: " << mainStar_ << endl;
    cout << "Distributor: " << distributor_ << endl;
    cout << "Release Date: " << releaseDate_ << endl;
}