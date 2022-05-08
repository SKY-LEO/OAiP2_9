#include "Menus.h"

void core()
{
	bool flag = true;
	while (flag)
	{
		cout << MAIN_MENU_ADMIN << endl;
		int number = enterNumberInRange(0, 1);
		switch (number)
		{
		case 1:
			system("cls");
			workWithStudents();
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
}

void workWithStudents()
{
	int number;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showStudents();
		cout << STUDENT_MENU_ADMIN << endl;
		number = enterNumberInRange(0, 5);
		switch (number)
		{
		case 1:
			system("cls");
			searchStudents();
			break;
		case 2:
			system("cls");
			sortStudentExams();
			break;
		case 3:
			system("cls");
			addStudent();
			break;
		case 4:
			editStudent();
			break;
		case 5:
			deleteStudent();
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
}

void sortStudentExams()
{
	int number;
	cout << MENU_OF_STUDENTS_EXAMS << endl;
	number = enterNumberInRange(0, 4);
	/*switch (number)
	{
	case 1:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByOaipAscending);
		else sortStudentsBy(vec_of_students, mySortByOaipDescending);
		break;
	case 2:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByMathAscending);
		else sortStudentsBy(vec_of_students, mySortByMathDescending);
		break;
	case 3:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByEnglishAscending);
		else sortStudentsBy(vec_of_students, mySortByEnglishDescending);
		break;
	case 4:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByPhysicsAscending);
		else sortStudentsBy(vec_of_students, mySortByPhysicsDescending);
		break;
	case 0:
		break;
	default:
		cout << ERROR_MESSAGE << endl;
	}*/
}

void editStudent()
{
	bool flag = true;
	cout << "Какого студента вы хотите отредактировать?\nНазад - 0" << endl;
	int index_for_change = indexOfVectorForChange();
	if (index_for_change == 0)return;
	else index_for_change--;
	Student temp_student;
	while (flag)
	{
		system("cls");
		drawHeader();
		showStudents();
		//displayStudent(vec_of_students.at(index_for_change), index_for_change);
		cout << endl;
		cout << MENU_OF_EDIT_STUDENT << endl;
		int number = enterNumberInRange(0, 2);
		switch (number)
		{
		case 1:
			setFio(temp_student);
			break;
		case 2:
			editExams(temp_student);
			//setAverageScore(vec_of_students.at(index_for_change));
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
}

void editExams(Student& temp_student)
{
	cout << MENU_OF_STUDENTS_EXAMS << endl;
	int number = enterNumberInRange(0, 4);
	switch (number)
	{
	case 1:
		setOaip(temp_student);
		break;
	case 2:
		setMath(temp_student);
		break;
	case 3:
		setEnglish(temp_student);
		break;
	case 4:
		setPhysics(temp_student);
		break;
	case 0:
		break;
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void searchStudents()
{
	int number ;
	bool flag = true;
	vector <Student> vec_of_finded_students;
	while (flag)
	{
		searchByAverageScore();
		//system("cls");
		//if (!vec_of_finded_students.empty())
		//{
			//showStudents();
			cout << MENU_OF_SEARCH_STUDENTS_ADMIN << endl;
			number = enterNumberInRange(0, 1);

		//}
		if (number == 0) {
			flag = false;
		}
	}
}

bool isAscending()
{
	int number;
	cout << MENU_OF_ASCENDING_DESCENDING << endl;
	number = enterNumberInRange(1, 2);
	switch (number)
	{
	case 1:
		return true;
	case 2:
		return false;
	default:
		cout << ERROR_MESSAGE << endl;
		return false;
	}
}