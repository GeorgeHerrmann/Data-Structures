#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Student.h"
using namespace std;

/*
 * The class definition for an Instructor.
 */
class Instructor {
    public:
        string fullName;
        string firstName;
        string lastName;
        static Student arr[20];
        Instructor();
        bool login(string username, string password);
        string getInstructorName();
        Student getStudent(string username);
        Student getMinStudent(int gradeType);
        Student getMaxStudent(int gradeType);
        double getAvg(int gradeType);
        void setInstructorName(string fullName);
};

#endif
