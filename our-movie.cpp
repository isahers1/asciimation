/**
 * \file our-movie.cpp
 * \author Anonymized for Peer Review
 *
 * \brief Provides the main() function for creating and running
 * a specific asciimation movie.
 *
 * \details
 *
 * \remarks
 *
 */

#include <iostream>
#include <string>
#include "asciimation.hpp"

using namespace std;

void makeExampleMovie() {
    Asciimation exampleMovie(20, 80, 30, 15, "sprite-images/mystery1.txt");
    exampleMovie.generateMovie("example-movie.mp4", 25);
}

void makeStudentMovie() {
    Asciimation exampleMovie(20, 80, 30, 15, "sprite-images/mystery1.txt");
    exampleMovie.generateMovie("student-movie.mp4", 25);
}

int main() {
    // makeExampleMovie();
    makeStudentMovie();
}
