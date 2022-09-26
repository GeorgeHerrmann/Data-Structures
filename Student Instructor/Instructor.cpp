#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Instructor.h"
#include "Student.h"

using namespace std;

/*
 * Project: 1
 * Quiz: 2
 * Midterm: 3
 * Final: 4
 * Overall: 5
 */

Student Instructor::arr[20] = {}; //Holds the Students for easy access

/**
 * Creates an Instructor object with access to all the students from "students.txt".
 */
Instructor::Instructor() {
    ifstream file;
    file.open("students.txt", ios::binary);
    for (long unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        string word = "";
        string firstName, lastName;
        if (getline(file, word)) {
            istringstream issLine(word);
            issLine >> arr[i].username >> arr[i].password >> firstName >> lastName >> arr[i].projectGrade >> arr[i].quizGrade >> arr[i].midtermGrade >> arr[i].finalGrade;
            arr[i].fullName = firstName + " " + lastName;
        } else i = sizeof(arr)/sizeof(arr[0]);
    }
    
} //Instructor

/**
 * Allows the user to login as an instructor.
 *
 * @param username the instructor's username.
 * @param password the instructor's password.
 * @return true on successful login false on unsuccessful login.
 */
bool Instructor::login(string username, string password) {
    ifstream file;
    file.open("instructors.txt", ios::binary);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            if (strcmp(word.c_str(), username.c_str()) == 0) {
                file >> word;
                if (strcmp(word.c_str(), password.c_str()) == 0) {
                    file >> word;
                    fullName = word + " ";
                    file >> word;
                    fullName += word;
                    return true;
                }
            }
        }
    }
    return false;
}//login

/**
 * Returns the full name of the instructor.
 *
 * @return the full name of the instructor.
 */
string Instructor::getInstructorName() {
    return fullName;
} //getInstructorName

/**
 * Returns the Student with the associated username.
 * Searches through the array of students to find them.
 *
 * @param username the username of the Student to return.
 * @return the Student with the associated username.
 * @throws invalid_argument if no student could be found.
 */
Student Instructor::getStudent(string username) {
    for (long unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (strcmp((arr[i].getUsername()).c_str(), username.c_str()) == 0) {
            return arr[i];
        }
    }
    throw invalid_argument("");
} //getStudent

/**
 * Returns the Student with the lowest grade of the associated gradeType.
 * gradeType can be interperated to mean the following:
 * 1: Project Grade
 * 2: Quiz Grade
 * 3: Midterm Grade
 * 4: Final Exam Grade
 * 5: Overall Grade.
 *
 * @param gradeType the gradeType for the type of grade to be used.
 * @return the Student with the lowest grade using gradeType.
 */
Student Instructor::getMinStudent(int gradeType) {
    Student minStudent = arr[0];
    for (long unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (gradeType == 1) {
            if (arr[i].getProjectGrade() < minStudent.getProjectGrade()) {
                minStudent = arr[i];
            }
        } else if (gradeType == 2) {
            if (arr[i].getQuizGrade() < minStudent.getQuizGrade()) {
                minStudent = arr[i];
            }
        } else if (gradeType == 3) {
            if (arr[i].getMidtermGrade() < minStudent.getMidtermGrade()) {
                minStudent = arr[i];
            }
        } else if (gradeType == 4) {
            if (arr[i].getFinalGrade() < minStudent.getFinalGrade()) {
                minStudent = arr[i];
            }
        } else if (gradeType == 5) {
            if (arr[i].getOverallGrade() < minStudent.getOverallGrade()) {
                minStudent = arr[i];
            }
        }
    }
    return minStudent;
} //getMinStudent

/**
 * Returns the student with the highest grade of the associated gradeType.
 * gradeType can be interperated to mean the following:
 * 1: Project Grade
 * 2: Quiz Grade
 * 3: Midterm grade
 * 4: Final Exam Grade
 * 5: Overall Grade.
 *
 * @param gradeType the gradeType for the type of grade to be used.
 * @return the Student with the highest grade using gradeType.
 */
Student Instructor::getMaxStudent(int gradeType) {
    Student maxStudent = arr[0];
    for (long unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (gradeType == 1) {
            if (arr[i].getProjectGrade() > maxStudent.getProjectGrade()) {
                maxStudent = arr[i];
            }
        } else if (gradeType == 2) {
            if (arr[i].getQuizGrade() > maxStudent.getQuizGrade()) {
                maxStudent = arr[i];
            }
        } else if (gradeType == 3) {
            if (arr[i].getMidtermGrade() > maxStudent.getMidtermGrade()) {
                maxStudent = arr[i];
            }
        } else if (gradeType == 4) {
            if (arr[i].getFinalGrade() > maxStudent.getFinalGrade()) {
                maxStudent = arr[i];
            }
        } else if (gradeType == 5) {
            if (arr[i].getOverallGrade() > maxStudent.getOverallGrade()) {
                maxStudent = arr[i];
            }
        }
    }
    return maxStudent;
} //getMaxStudent

/**
 * Returns the average grade of the associated gradeType.
 * gradeType can be interperated to mean the following:
 * 1: Project Grade
 * 2: Quiz Grade
 * 3: Midterm Grade
 * 4: Final Exam Grade
 * 5: Overall Grade.
 *
 * @param gradeType the gradeType for the type of grade to be used.
 * @return the average grade of the associated gradeType.
 */
double Instructor::getAvg(int gradeType) {
    double average = 0;
    long unsigned int i;
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (gradeType == 1) {
            average += arr[i].getProjectGrade();
        } else if (gradeType == 2) {
            average += arr[i].getQuizGrade();
        } else if (gradeType == 3) {
            average += arr[i].getMidtermGrade();
        } else if (gradeType == 4) {
            average += arr[i].getFinalGrade();
        } else if (gradeType == 5) {
            average += arr[i].getOverallGrade();
        }
    }
    return average/i;
} //getAvg

/**
 * Sets this instructor's name.
 *
 * @param fullName the name of the instructor.
 */
void Instructor::setInstructorName(string fullName) {
    this->fullName = fullName;
} //setInstructorName
