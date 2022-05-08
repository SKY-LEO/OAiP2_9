#pragma once

#include <iostream>
#include <vector>

#include "Students.h"
#include "Sorts.h"
#include "Validations.h"

using namespace std;

const string MAIN_MENU_ADMIN = "�� ���������� � ������� ���� ��������������.\n1) ������ ������ � �������������\n0) �����";

const string MENU_OF_SORTS_STUDENTS = "�� ���������� � ���� ���������� ������������.\n0) �����";
const string MENU_OF_ASCENDING_DESCENDING = "����������� ��:\n1) �����������\n2) ��������";
const string STUDENT_MENU_ADMIN = "�� ���������� � ���� ������ � �������������.\n1) �����\n2) ����������\n3) �������� �����������\n4) ������������� ������\n5) ������� �����������\n0) �����";

const string MENU_OF_STUDENTS_EXAMS = "�� ���������� � ���� ������ ��������.\n�������� �������:\n1) ����\n2) ��\n3) ����\n4) ������\n0) �����";
const string MENU_OF_EDIT_STUDENT = "�� ���������� � ���� �������������� ������������.\n���������������: \n1) ���\n2) ��������\n0) �����";
const string MENU_OF_SEARCH_STUDENTS_ADMIN = "�� ���������� � ���� ������ ������������.\n0) �����";
const string ERROR_MESSAGE = "������!";

void core();

void workWithStudents();
void sortStudentExams();
void editStudent();
void editExams(Student& temp_student);
void searchStudents();

bool isAscending();