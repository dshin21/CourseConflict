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
    return start_time < m.start_time;
}

ostream &operator<<(ostream &os, const Course &m) {
    os << m.title << " " << m.get_day_string(m.day) << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}

string Course::get_day_string(unsigned int day) const {
    switch (day) {
        case 0:
            return "M";
        case 1:
            return "T";
        case 2:
            return "W";
        case 3:
            return "R";
        case 4:
            return "F";
        default:
            break;
    }
}