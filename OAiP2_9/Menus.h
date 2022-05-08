#pragma once

#include <iostream>
#include <vector>

#include "Students.h"
#include "Sorts.h"
#include "Validations.h"

using namespace std;

const string MAIN_MENU_ADMIN = "Вы находитесь в главном меню администратора.\n1) Модуль работы с абитуриентами\n0) Выход";

const string MENU_OF_SORTS_STUDENTS = "Вы находитесь в меню сортировки абитуриентов.\n0) Назад";
const string MENU_OF_ASCENDING_DESCENDING = "Упорядочить по:\n1) Возрастанию\n2) Убыванию";
const string STUDENT_MENU_ADMIN = "Вы находитесь в меню работы с абитуриентами.\n1) Поиск\n2) Сортировка\n3) Добавить абитуриента\n4) Редактировать данные\n5) Удалить абитуриента\n0) Назад";

const string MENU_OF_STUDENTS_EXAMS = "Вы находитесь в меню выбора экзамена.\nВыберите предмет:\n1) ОАиП\n2) МА\n3) ИнЯз\n4) Физика\n0) Назад";
const string MENU_OF_EDIT_STUDENT = "Вы находитесь в меню редактирования абитуриентов.\nОтредактировать: \n1) ФИО\n2) Экзамены\n0) Назад";
const string MENU_OF_SEARCH_STUDENTS_ADMIN = "Вы находитесь в меню поиска абитуриентов.\n0) Назад";
const string ERROR_MESSAGE = "Ошибка!";

void core();

void workWithStudents();
void sortStudentExams();
void editStudent();
void editExams(Student& temp_student);
void searchStudents();

bool isAscending();