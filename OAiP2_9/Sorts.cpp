#include "Sorts.h"

void sortStudentsLite(Student* arr, int n)
{
	int m;
	Student temp;
	for (int i = 0; i < n - 1; i++)
	{
		m = i;
		for (int j = 1; j < n; j++)
		{
			if (arr[j].exam.average_score > arr[m].exam.average_score)
			{
				m = j;
			}
		}
		if (m != i)
		{
			temp = arr[m];
			arr[m] = arr[i];
			arr[i] = temp;
		}
	}
}

void sortStudentsQuickSort(Student* arr, int begin, int end)
{
	Student temp;
	int left, right;
	left = begin;
	right = end;
	temp = arr[(left + right) / 2];
	do
	{
		while (arr[left].exam.average_score > temp.exam.average_score) left++;
		while (temp.exam.average_score > arr[right].exam.average_score) right--;
		if (left <= right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) sortStudentsQuickSort(arr, begin, right);
	if (left < end) sortStudentsQuickSort(arr, left, end);
}

void binarySearch()
{
	system("cls");
	int count = 0;
	int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
	Student* arr = new Student[size];
	readFileOfStudents(arr);
	sortStudentsQuickSort(arr, 0, size - 1);
	double average_score;
	do
	{
		cout << "Введите средний балл: ";
		average_score = correctInputDouble();
	} while (!isGoodAverageScoreMax(average_score)
		|| !isGoodAverageScoreMin(average_score));
	int i = search(arr, 0, size - 1, average_score);
	if (arr[i].exam.average_score == average_score)
	{
		cout << "Вот, что нашлось:" << endl;
		drawHeader();
		showStudent(arr[i], i);
	}
	else
	{
		cout << "Ничего не нашлось" << endl;
		system("pause");
	}
	cout << endl;
	delete[]arr;
}

int search(Student* arr, int begin, int end, double x)
{
	int m;
	while (begin < end)
	{
		m = (begin + end) / 2;
		if (x < arr[m].exam.average_score)
		{
			begin = m + 1;
		}
		else
		{
			end = m;
		}
	}
	return begin;
}