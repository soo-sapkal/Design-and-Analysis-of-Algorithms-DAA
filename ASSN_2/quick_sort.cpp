/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

struct Movie {
    string name;
    string rating;
    string genre;
    int year;
    string released;
    float score;
    string director;
    string writer;
    float runtime;
};

Movie movies[10000];
int countMovie = 0;

void swapMovie(Movie &a, Movie &b) {
    Movie t = a;
    a = b;
    b = t;
}

// Lomuto partition scheme using the last element as pivot
int partition(Movie arr[], int low, int high) {
    float pivot = arr[high].score;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Place elements with smaller IMDb score before the pivot
        // But jar he asa kela tr soday lagtay,
        if (arr[j].score < pivot) {
            i++;
            swapMovie(arr[i], arr[j]);
        }
    }

    // Place pivot at its final sorted position
    swapMovie(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive QuickSort function
void quickSort(Movie arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printHeader() {
    cout << left
         << setw(35) << "Movie Name"
         << setw(8) << "Rating"
         << setw(15) << "Genre"
         << setw(8) << "Year"
         << setw(15) << "Released"
         << setw(8) << "Score"
         << setw(25) << "Director"
         << setw(25) << "Writer"
         << setw(10) << "Runtime" << endl;

    cout << string(150, '=') << endl;
}

void printMovie(Movie m) {
    cout << left
         << setw(35) << m.name.substr(0, 34)
         << setw(8) << m.rating
         << setw(15) << m.genre
         << setw(8) << m.year
         << setw(15) << m.released.substr(0, 14)
         << setw(8) << fixed << setprecision(1) << m.score
         << setw(25) << m.director.substr(0, 24)
         << setw(25) << m.writer.substr(0, 24)
         << setw(10) << m.runtime
         << endl;
}

int main() {
    ifstream file("movies.csv");

    if (!file) {
        cout << "Cannot open movies.csv";
        return 0;
    }

    string line;
    getline(file, line); // Skip CSV header row

    // Read and parse movie dataset records
    while (getline(file, line) && countMovie < 10000) {
        stringstream ss(line);
        string temp;

        getline(ss, movies[countMovie].name, ',');
        getline(ss, movies[countMovie].rating, ',');
        getline(ss, movies[countMovie].genre, ',');

        getline(ss, temp, ',');
        movies[countMovie].year = atoi(temp.c_str());

        getline(ss, movies[countMovie].released, ',');

        getline(ss, temp, ',');
        movies[countMovie].score = atof(temp.c_str());

        getline(ss, temp, ','); // skip votes
        getline(ss, movies[countMovie].director, ',');
        getline(ss, movies[countMovie].writer, ',');

        getline(ss, temp, ','); // skip star
        getline(ss, temp, ','); // skip country
        getline(ss, temp, ','); // skip budget
        getline(ss, temp, ','); // skip gross
        getline(ss, temp, ','); // skip company

        getline(ss, temp);
        movies[countMovie].runtime = atof(temp.c_str());

        countMovie++;
    }

    file.close();

    // Sort movies ascending by IMDb score
    quickSort(movies, 0, countMovie - 1);

    printHeader();

    cout << "\nFIRST 5 MOVIES AFTER SORTING\n\n";

    int first = countMovie < 5 ? countMovie : 5;
    for (int i = 0; i < first; i++) {
        printMovie(movies[i]);
    }

    cout << "\n" << string(150, '=') << "\n";

    cout << "\nLAST 5 MOVIES AFTER SORTING\n\n";

    int start = (countMovie > 5) ? countMovie - 5 : 0;
    for (int i = start; i < countMovie; i++) {
        printMovie(movies[i]);
    }

    return 0;
}
