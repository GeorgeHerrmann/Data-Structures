#include <cstring>
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

/**
 * Default constructor for a Student object.
 */
Student::Student() {

} //Student

/**
 * Allows a user to login as a student.
 *
 * @param username the student's username.
 * @param password the student's password.
 * @return true on successful login, false on unsuccessful login.
 */
bool Student::login(string username, string password) {
    ifstream file;
    file.open("students.txt");
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
                    file >> word;
                    projectGrade = stoi(word);
                    file >> word;
                    quizGrade = stoi(word);
                    file >> word;
                    midtermGrade = stoi(word);
                    file >> word;
                    finalGrade = stoi(word);
                    return true;
                }
            }
        }
    }
    return false;
} //login

/**
 * Returns this student's full name.
 *
 * @return the full name of this student.
 */
string Student::getStudentName() {
    return fullName;
} //getStudentName

/**
 * Returns the username of this student.
 *
 * @return the username of this student.
 */
string Student::getUsername() {
    return username;
} //getUsername

/**
 * Returns the project grade of this student.
 *
 * @return this student's project grade.
 */
int Student::getProjectGrade() {
    return projectGrade;
} //getProjectGrade

/**
 * Returns the quiz grade of this student.
 *
 * @return this student's quiz grade.
 */
int Student::getQuizGrade() {
    return quizGrade;
} //getQuizGrade

/**
 * Returns the midterm grade of this student.
 *
 * @return this student's midterm grade.
 */
int Student::getMidtermGrade() {
    return midtermGrade;
} //getMidtermGrade

/**
 * Returns the final grade of this student.
 *
 * @return this student's final grade.
 */
int Student::getFinalGrade() {
    return finalGrade;
} //getFinalGrade

/**
 * Calculates and returns this student's overall grade using these weights:
 * Project: 30%
 * Quiz: 10%
 * Midterm: 20%
 * Final: 40%.
 *
 * @return this student's overall grade.
 */
double Student::getOverallGrade() {
    return ((double)(projectGrade * 30) +
        (quizGrade * 10) +
        (midtermGrade * 20) +
        (finalGrade * 40)) / 100.0;
} //getOverallGrade

/**
 * Sets this student's name.
 *
 * @param fullName the full name of the student.
 */
void Student::setStudentName(string fullName) {
    this->fullName = fullName;
} //setStudentName

/**
 * Sets this student's username.
 *
 * @param username the username of the student.
 */
void Student::setUsername(string username) {
    this->username = username;
} //setUsername

/**
 * Sets this student's project grade.
 *
 * @param grade the grade of the student.
 */
void Student::setProjectGrade(int grade) {
    projectGrade = grade;
} //setProjectGrade

/**
 * Sets this student's quiz grade.
 *
 * @param grade the grade of the student.
 */
void Student::setQuizGrade(int grade) {
    quizGrade = grade;
} //setQuizGrade

/**
 * Sets this student's midterm grade.
 *
 * @param grade the grade of the student.
 */
void Student::setMidtermGrade(int grade) {
    midtermGrade = grade;
} //setMidtermGrade

/**
 * Sets this student's final exam grade.
 *
 * @param grade the grade of the student.
 */
void Student::setFinalGrade(int grade) {
    finalGrade = grade;
} //setFinalGrade
