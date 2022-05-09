#include "Students.h"

void showStudents()
{
	double average_score_university = 0.;
	int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
	int i = 0;
	drawHeader();
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	Student temp_student;
	if (!fin.is_open())
	{
		cout << "Файла с абитуриентами не существует! Создан новый." << endl;
	}
	else
	{
		if (fin.peek() != EOF)
		{
			while (!fin.eof())
			{
				fin >> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
					>> temp_student.exam.physics >> temp_student.exam.average_score;
				getline(fin, temp_student.FIO, '\n');
				showStudent(temp_student, i);
				average_score_university += temp_student.exam.average_score;
				i++;
			}
			average_score_university /= size;
			cout << "Средний балл по университету: " << average_score_university << endl;
		}
		else
		{
			cout << "Файл с абитуриентами пуст!" << endl;
		}
	}
	fin.close();
	cout << endl;
}

void showStudent(Student& temp_student, int i)
{
	cout << "|" << setw(4) << i + 1 << setw(4) << "|" << setw(21) << left << temp_student.FIO
		<< "|" << setw(5) << right << temp_student.exam.oaip << setw(4)
		<< "|" << setw(4) << temp_student.exam.math << setw(3)
		<< "|" << setw(5) << temp_student.exam.english << setw(4)
		<< "|" << setw(6) << temp_student.exam.physics << setw(5)
		<< "|" << setw(8) << temp_student.exam.average_score << setw(5)
		<< "|" << endl;
	cout << SEPARATOR_STUDENT << endl;
}

void drawHeader()
{
	cout << endl;
	cout << SEPARATOR_STUDENT << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|"
		<< setw(22) << "Экзамены" << setw(14) << "|" << setw(13) << "|" << endl;
	cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(12) << "ФИО" << setw(10) << "|" << SEPARATOR_EXAMS << "|"
		<< setw(10) << "Ср. балл" << setw(3) << "|" << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|"
		<< setw(6) << "ОАиП" << setw(3) << "|"
		<< setw(4) << "МА" << setw(3) << "|" << setw(6) << "ИнЯз" << setw(3) << "|" << setw(8) << "Физика" << setw(3) << "|"
		<< setw(13) << "|" << endl;
	cout << SEPARATOR_STUDENT << endl;
}

void addStudent()
{
	char code;
	Student temp_student;
	do
	{
		setFio(temp_student);
		setExams(temp_student);
		writeFileOfStudents(temp_student);
		cout << "\nВы хотите добавить ещё одного абитуриента?(Д/Н)" << endl;
		code = (char)_getch();
	} while (code == 'Д' || code == 'д');
}

string enterFio()
{
	string fio;
	while (true)
	{
		cout << "ФИО: ";
		fio = enterStringWithoutNumbers();
		if (isGoodFio(fio))
		{
			return fio;
		}
	}
}

bool isGoodFio(string fio)
{
	Student temp_student;
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	while (!fin.eof())
	{
		fin >> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
			>> temp_student.exam.physics;
		getline(fin, temp_student.FIO, '\n');
		if (fio == temp_student.FIO)
		{
			system("cls");
			cout << "\nАбитуриент с таким ФИО уже существует! Введите другое." << endl;
			return false;
		}
	}
	fin.close();
	return true;
}

void setFio(Student& temp_student)
{
	temp_student.FIO = enterFio();
}

void setExams(Student& temp_student)
{
	cout << "\nЭкзамены (Минимальная оценка - " << MIN_EXAM << ", Максимальная оценка - " << MAX_EXAM << ")" << endl;
	setOaip(temp_student);
	setMath(temp_student);
	setEnglish(temp_student);
	setPhysics(temp_student);
	setAverageScore(temp_student);
}

void setOaip(Student& temp_student)
{
	temp_student.exam.oaip = rateStudent(MIN_EXAM, MAX_EXAM, OAIP);
}

void setMath(Student& temp_student)
{
	temp_student.exam.math = rateStudent(MIN_EXAM, MAX_EXAM, MATH);
}

void setEnglish(Student& temp_student)
{
	temp_student.exam.english = rateStudent(MIN_EXAM, MAX_EXAM, ENGLISH);
}

void setPhysics(Student& temp_student)
{
	temp_student.exam.physics = rateStudent(MIN_EXAM, MAX_EXAM, PHYSICS);
}

void setAverageScore(Student& temp_student)
{
	temp_student.exam.average_score = (temp_student.exam.oaip + temp_student.exam.math + temp_student.exam.english + temp_student.exam.physics) / 4.;
}

int rateStudent(int min_range, int max_of_range, string subject)
{
	cout << subject << ": ";
	return enterNumberInRange(min_range, max_of_range);
}

int indexOfArrayForChange()
{
	return enterNumberInRange(0, getCountOfStructuresStudent(FILE_OF_STUDENTS));
}

void deleteStudent()
{
	int answer, index_for_delete;
	cout << "Какого абитуриента вы хотите удалить?\n Отмена - 0" << endl;
	index_for_delete = indexOfArrayForChange();
	if (index_for_delete != 0)
	{
		int size = getCountOfStructuresStudent(FILE_OF_STUDENTS);
		Student* arr = new Student[size];
		readFileOfStudents(arr);
		index_for_delete--;
		system("cls");
		cout << "Вы действительно хотите удалить студента " << arr[index_for_delete].FIO << "? \nДа - 1 \nНет - 0" << endl;
		answer = enterNumberInRange(0, 1);
		if (answer == 1)
		{
			for (int i = index_for_delete; i < size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			writeFullFileOfStudents(arr, size - 1);
			cout << "Успешно удалён!" << endl;
			system("pause");
		}
		delete[]arr;
	}
}

void searchByAverageScore()
{
	double average_score_min, average_score_max;
	do
	{
		cout << "От: ";
		average_score_min = correctInputDouble();
		cout << "До: ";
		average_score_max = correctInputDouble();
	} while (!isGoodAverageScoreMax(average_score_max)
		|| !isGoodAverageScoreMin(average_score_min) || !isMinLessMax(average_score_min, average_score_max));
	system("cls");
	Student temp_student;
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	int i = 0;
	drawHeader();
	while (!fin.eof())
	{
		fin >> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
			>> temp_student.exam.physics >> temp_student.exam.average_score;
		getline(fin, temp_student.FIO, '\n');
		if (temp_student.exam.average_score >= average_score_min && temp_student.exam.average_score <= average_score_max)
		{
			showStudent(temp_student, i);
			i++;
		}
	}
	if (i == 0)
	{
		cout << "Ничего не нашлось..." << endl;
		system("pause");
	}
	fin.close();
	cout << endl;
}

bool isGoodAverageScoreMin(double min)
{
	if (min > MAX_EXAM)
	{
		cout << "Оценка больше максимально возможной!" << endl;
		return false;
	}
	return true;
}

bool isGoodAverageScoreMax(double max)
{
	if (max < MIN_EXAM)
	{
		cout << "Оценка меньше минимально возможной!" << endl;
		return false;
	}
	return true;
}

bool isMinLessMax(double min, double max)
{
	if (max < min)
	{
		cout << "Максимальное число меньше минимального!" << endl;
		return false;
	}
	else if (min > max)
	{
		cout << "Минимальное число больше максимального!" << endl;
		return false;
	}
	return true;
}

void readFileOfStudents(Student* vec_of_students)
{
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	Student temp_student;
	if (!fin.is_open())
	{
		cout << "Файла с абитуриентами не существует! Создан новый." << endl;
	}
	else
	{
		if (fin.peek() != EOF)
		{
			int i = 0;
			while (!fin.eof())
			{
				fin >> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
					>> temp_student.exam.physics >> temp_student.exam.average_score;
				getline(fin, temp_student.FIO, '\n');
				vec_of_students[i] = temp_student;
				i++;
			}
		}
		else
		{
			cout << "Файл с абитуриентами пуст!" << endl;
		}
	}
	fin.close();
}

void writeFileOfStudents(Student& arr_of_students)
{
	ofstream fout(FILE_OF_STUDENTS, ios::app);
	fout << endl
		<< arr_of_students.exam.oaip << " " << arr_of_students.exam.math
		<< " " << arr_of_students.exam.english << " " << arr_of_students.exam.physics << " " << arr_of_students.exam.average_score
		<< arr_of_students.FIO;
	fout.close();
}

void writeFullFileOfStudents(Student* arr, int n)
{
	ofstream fout(FILE_OF_STUDENTS, ios::out);
	for (int i = 0; i < n; i++)
	{
		fout
			<< arr[i].exam.oaip << " " << arr[i].exam.math
			<< " " << arr[i].exam.english << " " << arr[i].exam.physics << " " << arr[i].exam.average_score
			<< arr[i].FIO;
		if (i < n - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

int getCountOfStructuresStudent(string file_path)
{
	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open())
	{
		while (file.ignore(256, '\n'))
		{
			number_of_strings++;
		}
	}
	file.close();
	return number_of_strings;
}