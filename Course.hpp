// Course.h
#include <iostream>
#include <map>

using namespace std;

struct Course {
    enum dayOfWeek {
        MON, TUE, WED, THUR, FRI, SAT, SUN
    };

    Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);

    Course(const Course &m);

    Course &operator=(Course &m);

    bool operator<(const Course &m) const;

    bool operator==(const Course &m) const;

    friend void swap(Course &first, Course &second);

    string title; // Name of Course
    dayOfWeek day; // Day of Course
    unsigned int start_time; // Course start time in HHMM format
    unsigned int finish_time; // Course finish time in HHMM format
};

// Helper operator for output
ostream &operator<<(ostream &os, const Course &m);