#include"Students.h"

Student read(FILE *in)
{
	Student student;

	fscanf(in, "%s%d%d%d%d%d", student.FIO, &student.group, &student.num_zuch, &student.marks[0], &student.marks[1], &student.marks[2]);
	return student;
}
void output(Student student,FILE *out)
{
	fprintf(out, "%s %d %d %d %d %d", student.FIO, student.group, student.num_zuch, student.marks[0], student.marks[1], student.marks[2]);
	
}

float avg(Student student)
{
	float sred = 0;
	for (int i = 0; i < 3; i++)
		sred += student.marks[i];

	return sred / 3;
}

float whole_avg(Student *student, int size)
{
	float w_sred = 0;
	for (int i = 0; i < size; i++)
		w_sred += avg(student[i]);

	return w_sred / size;
}

bool otlichniki(Student student)
{
	bool flag = 1;
	for (int i = 0; i < 3; i++)
	if (student.marks[i] < 9) flag = 0;

	return flag;
