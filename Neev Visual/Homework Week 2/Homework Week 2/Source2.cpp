#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef union Date {
	int date;
	char hebYear[4];
};
typedef struct Worker {
	int id;
	int salary;
	char* name;
	Date startDate;
};
typedef struct WorkerList{
	Worker* workerdata;
	WorkerList* next;
};
Worker* createWorker(int id, int salary, char* name, Date date) {
	Worker* tempWorker = (Worker*)malloc(sizeof(Worker));
	
	// Filling the fields of the new object with info given by the params.

	tempWorker->name = (char*)malloc(strlen(name) + 1);
	strcpy(tempWorker->name, name);
	*(tempWorker->name + strlen(name)) = '\0';

	tempWorker->id = id;
	tempWorker->salary = salary;

	return tempWorker;
}
void printWorker(Worker* worker, int flag) {
	// printf("------------------------\n");
	printf("ID: %d\n", worker->id);
	printf("Name: %s\n", worker->name);
	printf("Salary: %d\n", worker->salary);
	printf("------------------------\n");
	return;
}
WorkerList* addWorker2List(WorkerList* head, Worker* newworker) {
	// אני לא יודע איך לבדוק אם ברשימה יש איברים לכן הנחתי שיש איבר כלשהו שמצביע לNULL
	WorkerList* temphead = head;
	WorkerList* templist = (WorkerList*)malloc(sizeof(WorkerList));
	templist->workerdata = newworker;
	templist->next = temphead;
	return templist;
}
int Workerindex(WorkerList* head, short int id) {
	WorkerList* templist = head;
	if (templist == NULL) return -1;

	int count = 1;
	while (templist->workerdata->id != id) {
		count++;
		templist = templist->next;
		if (templist == NULL) return -1;
	}
	return count;
}
int main() {
	char name1[] = "Neev Penkar";
	char name2[] = "Adan Esaid";
	char name3[] = "Bibi Netanyahu";

	Worker* newworker1 = createWorker(841, 200, name1, {2020});
	Worker* newworker2 = createWorker(763, 4000, name2, { 2019 });
	Worker* newworker3 = createWorker(925, 40000, name3, { 1996 });
	

	WorkerList* list = (WorkerList*)malloc(sizeof(WorkerList));
	*list = {newworker1, NULL};
	list = addWorker2List(list, newworker2);
	list = addWorker2List(list, newworker3);

	// printWorker(list->workerdata, 1);
	printf("Index: %d", Workerindex(list, 763));
	
	return 0;
}