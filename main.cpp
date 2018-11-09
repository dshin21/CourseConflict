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

bool sort_by_day(Course i, Course j) { return i.day < j.day; }

vector<string> find_conflicts(vector<Course> &course_vector) {
    vector<string> conflict_vector;
    for (std::vector<Course>::const_iterator i = course_vector.begin(); i != course_vector.end(); ++i) {
        for (auto j = i + 1; j != course_vector.end(); ++j) {
            if (i->day == j->day && (j->start_time <= i->finish_time)) {
                ostringstream oss{};
                oss << "CONFLICT: " << endl;
                oss << i->title << " " << i->get_day_string(i->day) << " " << i->start_time << " " << i->finish_time
                    << endl;
                oss << j->title << " " << j->get_day_string(j->day) << " " << j->start_time << " " << j->finish_time
                    << endl;
                oss << "\n";
                conflict_vector.push_back(oss.str());
            }
        }
    }
    return conflict_vector;
}

void printSchedule(vector<Course> &course_vector) {
    std::copy(find_conflicts(course_vector).begin(), find_conflicts(course_vector).end(),
              std::ostream_iterator<string>(cout));
    std::sort(course_vector.begin(), course_vector.end(), sort_by_day);
    std::copy(course_vector.begin(), course_vector.end(), std::ostream_iterator<Course>(cout));
}

int main() {
    ifstream is{"../courses.txt"};

    map<string, Course::dayOfWeek> day_map;
    day_map.insert(pair<string, Course::dayOfWeek>("M", Course::dayOfWeek::MON));
    day_map.insert(pair<string, Course::dayOfWeek>("T", Course::dayOfWeek::TUE));
    day_map.insert(pair<string, Course::dayOfWeek>("W", Course::dayOfWeek::WED));
    day_map.insert(pair<string, Course::dayOfWeek>("R", Course::dayOfWeek::THUR));
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
        Course temp(title, day_map.find(day)->second, start_time, finish_time);
        course_vector.push_back(temp);
    }

    std::sort(course_vector.begin(), course_vector.end());

    printSchedule(course_vector);
    return 0;
}