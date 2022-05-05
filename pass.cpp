#include <iostream>
#include <string>
using namespace std;

const int SUBJECT_NUM = 6;

struct Student{
    string name;
    string surname;
    string schoolName;
    string subjects[SUBJECT_NUM] = {
        "English",
        "Mathematics",
        "Life Orientation",
        "History",
        "Computer literacy",
        "Art"
    };
    float subjectMarks[SUBJECT_NUM];
    float averageMark;
    string distinctions[SUBJECT_NUM + 1];
    int code[SUBJECT_NUM];
    int averageCode;
    string symbol[SUBJECT_NUM];
    string averageSymbol;
};

// Get student's details
void studentDetails(Student & student);
// Get student's marks
void getMarks(Student & student);
// Calculate student's average mark
float calcAverageYearMark(float subjectMarks[SUBJECT_NUM]);
// Get minimum and maximum marks
void minMax(float & min, float & max, Student & student);
// Check whether student has passed or failed
bool passOrFail(Student & student);
// Get student's distinctions
void awardDistinction(Student & student);
// Get student's code and symbol for each subject
void codeSymbol(float averageMark, Student & student);
// Display the student report
void displayStudentReport(const Student & student, float min, float max, float averageMark, string passOrFailString);

int main(){
    Student student;
    float min = 100, max = 0, averageMark;
    string passOrFailString = "failed";

    studentDetails(student);
    getMarks(student);
    averageMark = calcAverageYearMark(student.subjectMarks);
    minMax(min, max, student);
    if(passOrFail(student)){
        passOrFailString = "passed";
    };
    awardDistinction(student);
    codeSymbol(averageMark, student);
    displayStudentReport(student, min, max, averageMark, passOrFailString);

    return 0;
}

void studentDetails(Student & student){
    cout << "Enter your name: ";
    getline(cin, student.name, '\n');
    cout << "Enter your surname: ";
    getline(cin, student.surname, '\n');
    cout << "Enter your school name: ";
    getline(cin, student.schoolName, '\n');
}

void getMarks(Student & student){
    int count = 0;
    while(count < SUBJECT_NUM){
        cout << "Enter your " << student.subjects[count] << " mark: ";
        cin >> student.subjectMarks[count];

        // Subject mark validation
        if(student.subjectMarks[count] < 0 || student.subjectMarks[count] > 100){
            cout << "\nInvalid mark. Please enter a mark between 0 and 100." << endl;
        } else {
            count++;
        }
    }
}

float calcAverageYearMark(float subjectMarks[SUBJECT_NUM]){
    float sum = 0;
    for (int i = 0; i < SUBJECT_NUM; i++){
        sum += subjectMarks[i];
    }
    float average = sum / SUBJECT_NUM;
    return average;
}

void minMax(float & min, float & max, Student & student){

    for (int i = 0; i < SUBJECT_NUM; i++){
        if (student.subjectMarks[i] < min){
            min = student.subjectMarks[i];
        }
        if (student.subjectMarks[i] > max){
            max = student.subjectMarks[i];
        }
    }
}

bool passOrFail(Student & student){
    // Returns true if the student has passed English and at least 3 other subjects
    if(student.subjectMarks[0] >= 50){
        int count = 1;
        for(int i = 1; i < SUBJECT_NUM; i++){
            if(student.subjectMarks[i] >= 50){
                count++;
            }
        }
        if(count >= 4){
            return true;
        }
        return false;
    }
    return false;
}

void awardDistinction(Student & student){
    for(int i = 0; i < SUBJECT_NUM; i++){
        if(student.subjectMarks[i] >= 75){
            student.distinctions[i] = "Destinction";
        } else {
            student.distinctions[i] = "None";
        }
    }
    if(student.averageMark >= 75){
        student.distinctions[SUBJECT_NUM] = "Destinction";
    } else {
        student.distinctions[SUBJECT_NUM] = "None";
    }
}

void codeSymbol(float averageMark, Student & student){
    // Calculate the student code and symbol
    for(int i = 0; i < SUBJECT_NUM; i++){
        if(student.subjectMarks[i] >= 80){
            student.code[i] = 7;
            student.symbol[i] = "A";
        } else if(student.subjectMarks[i] >= 70){
            student.code[i] = 6;
            student.symbol[i] = "B";
        } else if(student.subjectMarks[i] >= 60){
            student.code[i] = 5;
            student.symbol[i] = "C";
        } else if(student.subjectMarks[i] >= 50){
            student.code[i] = 4;
            student.symbol[i] = "D";
        } else if(student.subjectMarks[i] >= 40) {
            student.code[i] = 3;
            student.symbol[i] = "E";
        } else if(student.subjectMarks[i] >= 30) {
            student.code[i] = 2;
            student.symbol[i] = "F";
        } else {
            student.code[i] = 1;
            student.symbol[i] = "FF";
        }
    }

    // Calculate average code and symbol
    if(averageMark >= 80){
        student.averageCode = 7;
        student.averageSymbol = "A";
    } else if(averageMark >= 70){
        student.averageCode = 6;
        student.averageSymbol = "B";
    } else if(averageMark >= 60){
        student.averageCode = 5;
        student.averageSymbol = "C";
    } else if(averageMark >= 50){
        student.averageCode = 4;
        student.averageSymbol = "D";
    } else if(averageMark >= 40) {
        student.averageCode = 3;
        student.averageSymbol = "E";
    } else if(averageMark >= 30) {
        student.averageCode = 2;
        student.averageSymbol = "F";
    } else {
        student.averageCode = 1;
        student.averageSymbol = "FF";
    }
}

void displayStudentReport(const Student & student, float min, float max, float averageMark, string passOrFailString){
    cout.setf(ios::fixed);
    cout.precision(0);

    cout << "\n***********************************************" << endl;
    cout << "STUDENT ACADEMIC RECORD" << endl;
    cout << "This program inputs the learner marks of matric level subjects and prints the student final report." << endl;
    cout << "***********************************************" << endl;

    cout << "\nName: " << student.name << " " << student.surname;
    cout << "\tSchool name: " << student.schoolName << endl;
    
    cout << "\nSubject:\tCode:\tSymbol:\tMark: " << endl;
    for(int i = 0; i < SUBJECT_NUM; i++){
        cout << student.subjects[i].substr(0, 3) << "\t\t" << student.code[i] << "\t" << student.symbol[i] << "\t" << student.subjectMarks[i] << "%" << endl;
    }

    cout << "\nAverage code: " << student.averageCode << endl;
    cout << "Average symbol: " << student.averageSymbol << endl;
    cout << "Average year mark: " << averageMark << "%" << endl;
    cout << "Lowest mark: " << min << "%" << endl;
    cout << "Highest mark: " << max << "%" << endl;
    cout << "Distinctions: ";

    int count = 0;
    for(int i = 0; i < SUBJECT_NUM; i++){
        if(student.distinctions[i] == "Destinction"){
            if(count != 0){
                cout << ", " << student.subjects[i];
                count++;
            } else {
                cout << student.subjects[i];
                count++;
            }
        }
    }
    cout << "\n\nYou have " << passOrFailString << " Grade 12." << endl;
}