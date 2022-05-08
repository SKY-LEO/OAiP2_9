#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Validations.h"

using namespace std;

struct Exams
{
	int oaip;
	int math;
	int english;
	int physics;
};

struct Student
{
	string FIO;
	Exams exam;
};

const string FILE_OF_STUDENTS = "students.txt";

const int MIN_EXAM = 0;
const int MAX_EXAM = 10;

const string SEPARATOR_STUDENT = "|-------+---------------------+--------------+-------+--------+--------+-------+--------+--------+------+--------+----------+------------+-------------+--------------+-------------|";
const string SEPARATOR_OFFSETS_EXAMS = "------------------------------------------|-----------------------------------";
const string OAIP = "Œ¿Ëœ";
const string MATH = "Ã¿";
const string ENGLISH = "»ÌﬂÁ";
const string PHYSICS = "‘ËÁËÍ‡";

void showStudents();
void drawHeader();
void showStudent(Student& temp_student, int i);

void addStudent();
string enterFio();
bool isGoodFio(string fio);
void setFio(Student& temp_student);

void setExams(Student& temp_student);
void setOaip(Student& temp_student);
void setMath(Student& temp_student);
void setEnglish(Student& temp_student);
void setPhysics(Student& temp_student);
//void setAverageScore(Student& temp_student);
int rateStudent(int min_range, int max_of_range, string subject);

int indexOfVectorForChange();
void deleteStudent();

void searchByAverageScore();
bool isGoodAverageScoreMin(double min);
bool isGoodAverageScoreMax(double max);
bool isMinLessMax(double min, double max);

void readFileOfStudents(Student* vec_of_students);
void writeFileOfStudents(Student& vec_of_students);
void writeFullFileOfStudents(Student* arr, int n, int index_for_delete);
int getCountOfStructuresStudent(string file_path);