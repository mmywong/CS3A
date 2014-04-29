//Reads quiz scores for each student into the two-dimensional array grade (but
//the input code is not shown in this display). Computes the average score
//for each student and the average score for each quiz. Displays the quiz scores
//and the averages.
#include <iostream>
#include <iomanip>
const int NUMBER_STUDENTS = 5, NUMBER_QUIZZES = 5;
using namespace std;
void fill_grade(int grade[][NUMBER_QUIZZES]); //write by you
void compute_st_ave(const int grade[][NUMBER_QUIZZES], double st_ave[]);
 //Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES
 //are the dimensions of the array grade. Each of the indexed variables
 //grade[st_num− 1, quiz_num− 1] contains the score for student st_num on quiz
 //quiz_num.
 //Postcondition: Each st_ave[st_num− 1] contains the average for student
 //number stu_num.
void compute_quiz_ave(const int grade[][NUMBER_QUIZZES], double quiz_ave[]);
 //Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES
 //are the dimensions of the array grade. Each of the indexed variables
 //grade[st_num− 1, quiz_num− 1] contains the score for student st_num on quiz
 //quiz_num.
 //Postcondition: Each quiz_ave[quiz_num− 1] contains the average for quiz number
 //quiz_num.
void display(const int grade[][NUMBER_QUIZZES], const double st_ave[], const double quiz_ave[]);
 //Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES are the
 //dimensions of the array grade. Each of the indexed variables grade[st_num− 1,
 //quiz_num− 1] contains the score for student st_num on quiz quiz_num. Each
 //st_ave[st_num− 1] contains the average for student stu_num. Each
 //quiz_ave[quiz_num − 1] contains the average for quiz number quiz_num.
 //Postcondition: All the data in grade, st_ave, and quiz_ave has been output.

int main( )
{

    int grade[NUMBER_STUDENTS][NUMBER_QUIZZES];
    double st_ave[NUMBER_STUDENTS];
    double quiz_ave[NUMBER_QUIZZES];
    fill_grade(grade);
    compute_st_ave(grade, st_ave);
    compute_quiz_ave(grade, quiz_ave);
    display(grade, st_ave, quiz_ave);
    return 0;
}

void fill_grade(int grade[][NUMBER_QUIZZES])
{
    for (int st_i = 0; st_i < NUMBER_STUDENTS; st_i++)
    {
        cout << "\nInput student " << st_i + 1 << " grades ("<<NUMBER_QUIZZES<<") ";
        for (int quiz_num = 0; quiz_num < NUMBER_QUIZZES; quiz_num++)
            cin >> grade[st_i][quiz_num];
    }
}
void compute_st_ave(const int grade[][NUMBER_QUIZZES], double st_ave[])
{
    for (int st_num = 0; st_num < NUMBER_STUDENTS; st_num++)
        {//Process one st_num:
            double sum = 0;
            for (int quiz_num = 0; quiz_num < NUMBER_QUIZZES; quiz_num++)
                sum = sum + grade[st_num][quiz_num];
            //sum contains the sum of the quiz scores for student number st_num.
            st_ave[st_num] = sum/NUMBER_QUIZZES;
            //Average for student st_num is the value of st_ave[st_num-1]
        }
}


void compute_quiz_ave(const int grade[][NUMBER_QUIZZES], double quiz_ave[])
 {
    for (int quiz_num = 0; quiz_num < NUMBER_QUIZZES; quiz_num++)
    {//Process one quiz (for all students):
        double sum = 0;
        for (int st_num = 0; st_num < NUMBER_STUDENTS; st_num++)
            sum = sum + grade[st_num][quiz_num];
        //sum contains the sum of all student scores on quiz number quiz_num.
        quiz_ave[quiz_num] = sum/NUMBER_STUDENTS;
        //Average for quiz quiz_num is the value of quiz_ave[quiz_num-1]
    }
 }


//Uses iostream and iomanip:
void display(const int grade[][NUMBER_QUIZZES], const double st_ave[], const double quiz_ave[])
    {
        using namespace std;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout << setw(10) << "Student"
             << setw(10) << "Average"
             << setw(17) << "Quizzes\n";
        for (int st_num = 0; st_num < NUMBER_STUDENTS; st_num++)
        {//Display for one st_num:
            cout << setw(5) << st_num + 1
                 << setw(15) << st_ave[st_num] << " ";
        //How does this work? (INdentation)
            for (int quiz_num = 0; quiz_num < NUMBER_QUIZZES; quiz_num++)
                cout << setw(10) << grade[st_num][quiz_num];
            cout << endl;
        }
        cout << "Quiz averages =        ";
        for (int quiz_num = 0; quiz_num < NUMBER_QUIZZES; quiz_num++)
            cout << setw(10) << quiz_ave[quiz_num];
        cout << endl;
}
