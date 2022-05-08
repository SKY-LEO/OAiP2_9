#include "Sorts.h"

//--------------------Students--------------------

void sortStudentsBy(bool (*comparisonFunction)(Student&, Student&))
{
	//sort(vec_of_students.begin(), vec_of_students.end(), comparisonFunction);
}


bool mySortByOaipAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.oaip < stu_2.exam.oaip;
}

bool mySortByOaipDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.oaip > stu_2.exam.oaip;
}

bool mySortByMathAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.math < stu_2.exam.math;
}

bool mySortByMathDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.math > stu_2.exam.math;
}

bool mySortByEnglishAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.english < stu_2.exam.english;
}

bool mySortByEnglishDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.english > stu_2.exam.english;
}

bool mySortByPhysicsAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.physics < stu_2.exam.physics;
}

bool mySortByPhysicsDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.physics > stu_2.exam.physics;
}