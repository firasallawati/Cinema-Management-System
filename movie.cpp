//
// Created by firas on 12/06/2026.
//

#include <iostream>
#include "movie.h"

using namespace std;

Movie::Movie() {
    title_ = "";
    description_ = "";
    genre_ = "";
    certificate_ = "";
    running_time_ = 0;
    main_star_ = "";
    distributor_ = "";
    release_date_ = "";
}

Movie::Movie(string title, string description, string genre, string certificate,
             int running_time, string main_star, string distributor, string release_date) {
    title_ = title;
    description_ = description;
    genre_ = genre;
    certificate_ = certificate;
    running_time_ = running_time;
    main_star_ = main_star;
    distributor_ = distributor;
    release_date_ = release_date;
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
    return running_time_;
}

string Movie::GetMainStar() {
    return main_star_;
}

string Movie::GetDistributor() {
    return distributor_;
}

string Movie::GetReleaseDate() {
    return release_date_;
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

void Movie::SetRunningTime(int running_time) {
    running_time_ = running_time;
}

void Movie::SetMainStar(string main_star) {
    main_star_ = main_star;
}

void Movie::SetDistributor(string distributor) {
    distributor_ = distributor;
}

void Movie::SetReleaseDate(string release_date) {
    release_date_ = release_date;
}

void Movie::DisplayMovie() {
    cout << "Title: " << title_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Genre: " << genre_ << endl;
    cout << "Certificate: " << certificate_ << endl;
    cout << "Running Time: " << running_time_ << " minutes" << endl;
    cout << "Main Star: " << main_star_ << endl;
    cout << "Distributor: " << distributor_ << endl;
    cout << "Release Date: " << release_date_ << endl;
}