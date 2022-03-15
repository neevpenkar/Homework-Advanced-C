#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union Date {
	char hebdate[6];
	unsigned int date;
};
typedef struct Worker {
	unsigned int ID;
	char* name;
	int salary;
	Date startdate;
};
typedef struct WorkerList
{
	Worker* data;
	struct WorkerList* next;
} WorkerList;

Worker* createWorker(int id, char* name1, int salary, Date startdate) {
	Worker newworker;
	newworker.ID = id;
	newworker.salary = salary;

	newworker.name = (char*)malloc(strlen(name1) + 1);
	if (!newworker.name) exit(-1);
	strcpy(newworker.name, name1);
	//newworker.name[strlen(name1)] = '\0';

	newworker.startdate = startdate;
	return &newworker;
}

void printWorker(Worker* w, int flag)
{
	printf("%d\n", w->ID);
	printf("%s\n", w->name);
	printf("%d\n", w->salary);
	/*if (flag == 0)
		printf("%s\n", w->startdate.hebdate);
	else*/
		printf("%d\n", w->startdate.date);
}

int main() {

	Worker *newworker;
	Date date1 = { 2022 };
	char t[] = "Adan Esaid";
	int flag = 1;

	newworker = createWorker(3412, t, 20000, date1);
	//printWorker(newworker, flag);
	printf("%d\n", newworker->ID);
	printf("%s\n", newworker->name);
	//printf("%d\n", newworker->startdate.date);
	return 0;
}