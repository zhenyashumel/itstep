#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
const int size = 5;

struct Student
{
	char FIO[40];
	short group;
	unsigned long num_zuch;
	int marks[3];
};

Student read(FILE *in);
void output(Student student,FILE *out);
float avg(Student student);
float whole_avg(Student *student, int size);
bool otlichniki(Student student);
void change_marks(Student *student, char *name);


