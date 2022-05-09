#include "Menus.h"

void core()
{
	int number;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showStudents();
		cout << STUDENT_MENU_ADMIN << endl;
		number = enterNumberInRange(0, 6);
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
		case 6:
			system("cls");
			individualTask();
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

void individualTask()
{
	int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
	Student* arr = new Student[size];
	readFileOfStudents(arr);
	double average_score_university = 0.;
	for (int i = 0; i < size; i++)
	{
		average_score_university += arr[i].exam.average_score;
	}
	average_score_university /= size;
	cout << "Средний балл по университету: " << average_score_university << endl;
	sortStudentsQuickSort(arr, 0, size - 1);
	drawHeader();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].exam.average_score <= average_score_university)break;
		showStudent(arr[i], i);
	}
	delete[]arr;
	system("pause");
}

void sortStudentExams()
{
	int number;
	int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
	Student* arr = new Student[size];
	readFileOfStudents(arr);
	cout << MENU_OF_SORTS_STUDENTS << endl;
	number = enterNumberInRange(0, 2);
	switch (number)
	{
	case 1:
		sortStudentsLite(arr, size);
		break;
	case 2:
		sortStudentsQuickSort(arr, 0, size - 1);
		break;
	case 0:
		break;
	default:
		cout << ERROR_MESSAGE << endl;
	}
	writeFullFileOfStudents(arr, size);
	delete[]arr;
}

void editStudent()
{
	bool flag = true;
	cout << "Какого абитуриента вы хотите отредактировать?\nНазад - 0" << endl;
	int index_for_change = indexOfArrayForChange();
	if (index_for_change == 0)return;
	else index_for_change--;
	int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
	Student* arr = new Student[size];
	readFileOfStudents(arr);
	while (flag)
	{
		system("cls");
		drawHeader();
		showStudent(arr[index_for_change], index_for_change);
		cout << endl;
		cout << MENU_OF_EDIT_STUDENT << endl;
		int number = enterNumberInRange(0, 2);
		switch (number)
		{
		case 1:
			setFio(arr[index_for_change]);
			break;
		case 2:
			editExams(arr[index_for_change]);
			setAverageScore(arr[index_for_change]);
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
	writeFullFileOfStudents(arr, size);
	delete[]arr;
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
	int number;
	bool flag = true;
	while (flag)
	{
		cout << MENU_OF_SEARCH_STUDENTS_ADMIN << endl;
		number = enterNumberInRange(0, 2);
		switch (number)
		{
		case 1:
			searchByAverageScore();
			break;
		case 2:
			binarySearch();
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
}