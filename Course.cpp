#include "Course.hpp"

using namespace std;

Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time)
        : title(title), day(day), start_time(start_time), finish_time(finish_time) {}

Course::Course(const Course &m)
        : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {}

Course &Course::operator=(const Course &m) {
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;
    return *this;
}

bool Course::operator==(const Course &m) const {
    return title == m.title &&
           day == m.day &&
           start_time == m.start_time &&
           finish_time == m.finish_time;
}

bool Course::operator<(const Course &m) const {
    return finish_time < m.start_time;
}

ostream &operator<<(ostream &os, const Course &m) {
    os << m.title << " " << m.day << " " << m.start_time << " " << m.finish_time;
    return os;
}