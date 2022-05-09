#pragma once

#include <iostream>

#include "Students.h"
#include "Sorts.h"
#include "Validations.h"

using namespace std;

const string STUDENT_MENU_ADMIN = "Вы находитесь в меню работы с абитуриентами.\n1) Поиск\n2) Сортировка\n3) Добавить абитуриента\n4) Редактировать данные\n5) Удалить абитуриента\n6) Индивидуальное задание\n0) Выход";
const string MENU_OF_SEARCH_STUDENTS_ADMIN = "Вы находитесь в меню поиска абитуриентов.\n1) Линейный поиск\n2) Бинарный поиск\n0) Назад";
const string MENU_OF_SORTS_STUDENTS = "Вы находитесь в меню сортировки абитуриентов.\n1) Метод прямого выбора\n2) Сортировка с помощью разделения\n0) Назад";
const string MENU_OF_EDIT_STUDENT = "Вы находитесь в меню редактирования абитуриентов.\nОтредактировать: \n1) ФИО\n2) Экзамены\n0) Назад";
const string MENU_OF_STUDENTS_EXAMS = "Вы находитесь в меню выбора экзамена.\nВыберите предмет:\n1) ОАиП\n2) МА\n3) ИнЯз\n4) Физика\n0) Назад";
const string ERROR_MESSAGE = "Ошибка!";

void core();

void sortStudentExams();
void editStudent();
void editExams(Student& temp_student);
void searchStudents();

void individualTask();