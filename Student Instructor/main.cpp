#include <iostream>
#include <cstring>
#include "Instructor.h"

using namespace std;

/**
 * A driver program for Instructors.cpp and Students.cpp.
 *
 * @param argc how many command-line arguments there are.
 * @param argv the command-line arguments.
 * @return the exit status of the program.
 */
int main(int argc, char * argv[]) {
    /*
     * In theory this for loop only runs once, however any time I need to return to this main prompt,
     * the program will i--, having it loop back to the main prompt again.
     */
    for (int i = 0; i < 1; i++) {
        cout << "User types,\n\t1 - Instructor\n\t2 - Student\nSelect a login user type or enter 3 to exit: ";
        int firstInput;
        cin >> firstInput;
        if (firstInput < 1 || firstInput > 3) {
            cout << "Invalid option. Please enter a valid option." << endl;
            i--;
        }

        if (firstInput == 1) { //Input 1 means Instructor
            string username, password;
            cout << "Enter credentials to login,\n\tEnter username: ";
            cin >> username;
            cout << "\tEnter password: ";
            cin >> password;
            Instructor instructor;
            if (instructor.login(username, password)) {
                cout << "You are now logged in as instructor " << instructor.getInstructorName() << endl;
                int optionNum = 0;
                /*
                 * This j for loop does the same as the i one, however the returning prompt here
                 * is the query options for the instructor.
                 */
                for (int j = 0; j < 1; j++) {
                    cout << "Query options,\n\t1 - view grades of a student\n\t2 - view stats\t\nEnter option number: ";
                    cin >> optionNum;
                    if (optionNum < 1 || optionNum > 2) {
                        cout << "Invalid option. Please enter a valid option." << endl;
                        j--;
                    } else {
                        if (optionNum == 1) {
                            /*
                             * This k for loop does the same, but the returning prompt is the student's username entry.
                             */
                            for (int k = 0; k < 1; k++) {
                                string studentUsername;
                                cout << "Enter a student username to view grades: ";
                                cin >> studentUsername;
                                try {
                                    instructor.getStudent(studentUsername); //This prevents Student name: from printing when invalid username is input
                                    cout << "Student name: " << instructor.getStudent(studentUsername).getStudentName() << endl;
                                    cout << "\tProject\t" << instructor.getStudent(studentUsername).getProjectGrade() << "%" << endl;
                                    cout << "\tQuiz\t" << instructor.getStudent(studentUsername).getQuizGrade() << "%" << endl;
                                    cout << "\tMidterm\t" << instructor.getStudent(studentUsername).getMidtermGrade() << "%" << endl;
                                    cout << "\tFinal\t" << instructor.getStudent(studentUsername).getFinalGrade() << "%" << endl;
                                    cout << "\tOverall\t" << instructor.getStudent(studentUsername).getOverallGrade() << "%" << endl;
                                    i--;
                               } catch (const invalid_argument& e) { //This will be thrown from getStudent if an invalid username is input
                                    cout << "Student username is not valid." << endl;
                                    k--;
                               }
                            }
                        } else if (optionNum == 2) {
                             /*
                             * Same for this k for loop, but the returning prompt is the grade type entry.
                             */
                            for (int k = 0; k < 1; k++) {
                                cout << "Grade types," << endl;
                                cout << "\t1 - Project grade" << endl;
                                cout << "\t2 - Quiz grade" << endl;
                                cout << "\t3 - Midterm grade" << endl;
                                cout << "\t4 - Final grade" << endl;
                                cout << "\t5 - Overall grade" << endl;
                                cout << "Select a grade type to view stats: ";
                                cin >> optionNum;
                                if (optionNum == 1) {
                                    cout << "Project grade stats," << endl;
                                    cout << "\tmin\t " << instructor.getMinStudent(1).getProjectGrade() << "% (" << instructor.getMinStudent(1).getStudentName() << ")" << endl;
                                    cout << "\tmax\t " << instructor.getMaxStudent(1).getProjectGrade() << "% (" << instructor.getMaxStudent(1).getStudentName() << ")" << endl;
                                    cout << "\tavg\t " << instructor.getAvg(1) << "%" << endl;
                                    i--;
                                    j = 1; //This forces the j for loop to exit once this code is done
                                } else if (optionNum == 2) {
                                    cout << "Quiz grade stats," << endl;
                                    cout << "\tmin\t " << instructor.getMinStudent(2).getQuizGrade() << "% (" << instructor.getMinStudent(2).getStudentName() << ")" << endl;
                                    cout << "\tmax\t " << instructor.getMaxStudent(2).getQuizGrade() << "% (" << instructor.getMaxStudent(2).getStudentName() << ")" << endl;
                                    cout << "\tavg\t " << instructor.getAvg(2) << "%" << endl;
                                    i--;
                                    j = 1;
                                } else if (optionNum == 3) {
                                    cout << "Midterm grade stats," << endl;
                                    cout << "\tmin\t " << instructor.getMinStudent(3).getMidtermGrade() << "% (" << instructor.getMinStudent(3).getStudentName() << ")" << endl;
                                    cout << "\tmax\t " << instructor.getMaxStudent(3).getMidtermGrade() << "% (" << instructor.getMaxStudent(3).getStudentName() << ")" << endl;
                                    cout << "\tavg\t " << instructor.getAvg(3) << "%" << endl;
                                    i--;
                                    j = 1;
                                } else if (optionNum == 4) {
                                    cout << "Final grade stats," << endl;
                                    cout << "\tmin\t " << instructor.getMinStudent(4).getFinalGrade() << "% (" << instructor.getMinStudent(4).getStudentName() << ")" << endl;
                                    cout << "\tmax\t " << instructor.getMaxStudent(4).getFinalGrade() << "% (" << instructor.getMaxStudent(4).getStudentName() << ")" << endl;
                                    cout << "\tavg\t " << instructor.getAvg(4) << "%" << endl;
                                    i--;
                                    j = 1;
                                } else if (optionNum == 5) {
                                   cout << "Overall grade stats," << endl;
                                   cout << "\tmin\t " << instructor.getMinStudent(5).getOverallGrade() << "% (" << instructor.getMinStudent(5).getStudentName() << ")" << endl;
                                   cout << "\tmax\t " << instructor.getMaxStudent(5).getOverallGrade() << "% (" << instructor.getMaxStudent(5).getStudentName() << ")" << endl;
                                   cout << "\tavg\t " << instructor.getAvg(5) << "%" << endl;
                                   i--;
                                   j = 1;
                                } else {
                                    cout << "Invalid option. Please enter a valid option." << endl;
                                    k--;
                                }
                            }
                        }
                    }
                }
            } else {
                cout << "Login as instructor failed." << endl;
                i--; //Returns to the main prompt
            }

        } else if (firstInput == 2) { //Input 2 means Student
            string username, password;
            cout << "Enter credentials to login,\n\tEnter username: ";
            cin >> username;
            cout << "\tEnter password: ";
            cin >> password;
            Student student;
            if (student.login(username, password)) {
                cout << "You are now logged in as student " << student.getStudentName() << endl;
                cout << "Do you want to view grades (y/n)? ";
                char gradeInput;
                cin >> gradeInput;
                if (gradeInput == 'y') {
                    cout << "Student name: " << student.getStudentName() << endl;
                    cout << "\tProject\t" << student.getProjectGrade() << "%" << endl;
                    cout << "\tQuiz\t" << student.getQuizGrade() << "%" << endl;
                    cout << "\tMidterm\t" << student.getMidtermGrade() << "%" << endl;
                    cout << "\tFinal\t" << student.getFinalGrade() << "%" << endl;
                    cout << "\tOverall\t" << student.getOverallGrade() << "%" << endl;
                    i--;
                } else { //Anything other than "y" returns to the main prompt
                    i--;
                }
            } else {
                cout << "Login as student failed." << endl;
                i--;
            }

        } else if (firstInput == 3) { //Input 3 means exit
            return 0;
        }
    } //for
} //main
