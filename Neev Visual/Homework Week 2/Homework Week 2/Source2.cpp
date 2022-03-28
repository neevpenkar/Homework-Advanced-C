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
void printList(WorkerList* head) {
	WorkerList* temphead = head;
	while (temphead) {
		printWorker(temphead->workerdata, 1);
		temphead = temphead->next;
	}
	return;
}
WorkerList* deleteWorstWorker(WorkerList* head) {
	//Worker* worst = head->workerdata;
	WorkerList* tmp = head, * temp;
	temp = head;
	if (!head)
		return head;
	while (tmp->next != NULL) {
		if (tmp->next->workerdata->salary < temp->workerdata->salary)
			temp = tmp;
		tmp = tmp->next;
	}
	if (tmp->workerdata->salary < temp->workerdata->salary) {
		temp = tmp;
		temp->next = temp->next->next;
	}
	else
		temp->next = temp->next->next;
	free(temp);
	return head;
}

WorkerList* addWorker(WorkerList* head, Worker* newworker) {
	WorkerList* newlist = (WorkerList*)malloc(sizeof(WorkerList));
	newlist->workerdata = newworker;
	WorkerList* temp = head;

	while (temp->workerdata->salary > newworker->salary) {
		if (temp->next == NULL) break;
		temp = temp->next;
	}
	if (temp == head) {
		newlist->next = head;
		return newlist;
	}
	else {
		newlist->next = temp->next;
		temp->next = newlist;
		return head;
	}
}

int main() {
	char name1[] = "Neev Penkar";
	char name2[] = "Adan Esaid";
	char name3[] = "Bibi Netanyahu";
	char name4[] = "Lukkha";

	Worker* newworker1 = createWorker(841, 200, name1, {2020});
	Worker* newworker2 = createWorker(763, 4000, name2, { 2019 });
	Worker* newworker3 = createWorker(925, 40000, name3, { 1996 });
	Worker* worker4 = createWorker(487, 1200, name4, { 1996 });

	WorkerList* list = (WorkerList*)malloc(sizeof(WorkerList));
	*list = {newworker1, NULL};

	list = addWorker(list, worker4);
	list = addWorker(list, newworker2);
	list = addWorker(list, newworker3);
	printList(list);
	return 0;
}
void foo() {
	//WorkerList* list;
	////printList(list);
	//list = addWorker(list, newworker2);
	////printList(list);
	//list = addWorker(list, newworker3);
	////printList(list);
}