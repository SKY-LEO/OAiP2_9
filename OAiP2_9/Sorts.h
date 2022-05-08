#pragma once

#include <algorithm>
#include <vector>

#include "Students.h"

void sortStudentsBy(bool (*comparisonFunction)(Student&, Student&));
//bool mySortBySurnameAscending(Student& stu_1, Student& stu_2);
//bool mySortBySurnameDescending(Student& stu_1, Student& stu_2);

bool mySortByOaipAscending(Student& stu_1, Student& stu_2);
bool mySortByOaipDescending(Student& stu_1, Student& stu_2);
bool mySortByMathAscending(Student& stu_1, Student& stu_2);
bool mySortByMathDescending(Student& stu_1, Student& stu_2);
bool mySortByEnglishAscending(Student& stu_1, Student& stu_2);
bool mySortByEnglishDescending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsAscending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsDescending(Student& stu_1, Student& stu_2);