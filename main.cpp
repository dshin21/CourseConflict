#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule() {
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

int main() {
    //TODO read from courses.txt
    ifstream is{"../courses.txt"};

    //TODO store data in an STL container
    map<string, Course::dayOfWeek> day_map;
    day_map.insert(pair<string, Course::dayOfWeek>("M", Course::dayOfWeek::MON));
    day_map.insert(pair<string, Course::dayOfWeek>("T", Course::dayOfWeek::TUE));
    day_map.insert(pair<string, Course::dayOfWeek>("W", Course::dayOfWeek::WED));
    day_map.insert(pair<string, Course::dayOfWeek>("TH", Course::dayOfWeek::THUR));
    day_map.insert(pair<string, Course::dayOfWeek>("F", Course::dayOfWeek::FRI));

    vector<Course> course_vector;
    string line;
    string title;
    string day;
    unsigned int start_time;
    unsigned int finish_time;

    while (getline(is, line)) {
        istringstream iss{line};
        iss >> title;
        iss >> day;
        iss >> start_time;
        iss >> finish_time;
        course_vector.push_back(Course(title, day_map.find(day)->second, start_time, finish_time));
    }
    //TODO sort your STL container with the sort algorithm

    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}