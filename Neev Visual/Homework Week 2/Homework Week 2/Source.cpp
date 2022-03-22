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
typedef struct WorkerList {
	Worker* workerdata;
	struct WorkerList* next;
};

WorkerList* addWorker(WorkerList* head, Worker* worker) {
	WorkerList* newworker = (WorkerList*)malloc(sizeof(WorkerList));
	newworker->workerdata = worker;
	newworker->next = head;
	return newworker;
}
void printWorker(Worker* w, int flag)
{
	printf("ID: %d\n", w->ID);
	printf("Name: %s\n", w->name);
	printf("Salary: %d\n", w->salary);
	if (flag == 0)
		printf("%s\n", w->startdate.hebdate);
	else
		printf("Start Date: %d\n", w->startdate.date);
}
void printList(WorkerList *list) {
	
	while (list != NULL) {
		printWorker(list->workerdata, 1);
		list = list->next;
	}
	printf("---------------------\n");
	printWorker(list->workerdata, 1);
}
Worker* createWorker(int id, char* name1, int salary, Date startdate) {
	Worker* newworker;
	newworker = (Worker*)malloc(sizeof(Worker));

	newworker->ID = id;
	newworker->salary = salary;

	newworker->name = (char*)malloc(strlen(name1) + 1);
	if (!newworker->name) exit(-1);
	strcpy(newworker->name, name1);
	//newworker.name[strlen(name1)] = '\0';

	newworker->startdate = startdate;
	return newworker;
}

//WorkerList* deleteWorstWorker(WorkerList* head) {
//	/*Worker* worstworker = head->workerdata, *secondworstworker = NULL;
//	secondworstworker = head->workerdata;
//
//	while (head != NULL) {
//		if ()
//	}*/
//
//}
int index (WorkerList* head, long unsigned id) {
	int count = 0;
	for (int i = 0; head != NULL; i++) {
		if (head->workerdata->ID == id)
			return i;
		head = head->next;
	}
	return -1;
	/*while (head->workerdata->ID != id) {
		count++;
		head = head->next;
		if (head == NULL)
			return -1;
	}*/
	//return count;
}
int recursiveIndex(WorkerList* head, long unsigned id) {
	if (head == NULL) return -1;

	if (head->workerdata->ID == id) return 1;
	
	if (recursiveIndex(head->next, id) == -1)
		return -1;
	else return recursiveIndex(head->next, id) + 1;
}
void updateWorkers(WorkerList* head, int percent) {
	while (head != NULL) {
		//head->workerdata->salary *= (percent / 100);
		printf("%d", head->workerdata->salary);
		head = head->next;
	}
}
int main() {

	Worker *newworker, *worker2, *worker3, *worker4;
	
	Date date1 = { 2022 };
	char name[] = "Adan Esaid";
	char name2[] = "Neev Penkar";
	char name3[] = "Lolo Esaid";
	char name4[] = "Bibi Netanyahu";
	int flag = 1;

	newworker = createWorker(3412, name, 20000, date1);
	worker2 = createWorker(4384, name2, 19999, date1);
	worker3 = createWorker(8967, name3, 21000, date1);
	worker4 = createWorker(2389, name4, 00012, date1); // BIBI

	WorkerList* list = (WorkerList*)malloc(sizeof(WorkerList));
	list = addWorker(NULL, newworker);
	list = addWorker(list, worker2);
	list = addWorker(list, worker3);
	list = addWorker(list, worker4);

	//deleteWorstWorker(list);
	printList(list);
	updateWorkers(list, 110); // Increment will be all values over 100 percent. Decrement for all values below.
	printList(list);
	
	return 0;
}