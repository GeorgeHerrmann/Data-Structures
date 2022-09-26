#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

/*
 * The class definition for a Student.
 */
class Student {
    public:
        string firstName;
        string lastName;
        string fullName;
        string username;
        string password;
        int projectGrade;
        int quizGrade;
        int midtermGrade;
        int finalGrade;
        Student();
        bool login(string username, string password);
        string getStudentName();
        string getUsername();
        int getProjectGrade();
        int getQuizGrade();
        int getMidtermGrade();
        int getFinalGrade();
        double getOverallGrade();
        void setStudentName(string fullName);
        void setUsername(string username);
        void setProjectGrade(int grade);
        void setQuizGrade(int grade);
        void setMidtermGrade(int grade);
        void setFinalGrade(int grade);
}; //Student

#endif
