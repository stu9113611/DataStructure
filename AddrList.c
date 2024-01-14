#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NAME_LENGTH 20
#define MAX_QUEUE_SIZE 100
#define NAN -999999999 // Not a number

struct AddrNode {
	void* addr;
	struct AddrNode* next;
};
typedef struct AddrNode AddrNode;

AddrNode* AddrList_Create(void* addr) {
	AddrNode* p_head = (AddrNode*)malloc(sizeof(AddrNode));
	p_head->addr = addr;
	p_head->next = NULL;
	return p_head;
}

AddrNode* AddrList_GetLastRef(AddrNode* p_head) {
	AddrNode* it = p_head;
	for (; it->next; it = it->next);
	return it;
}

void AddrList_Add(AddrNode* p_head, void* v)
{
	AddrNode* p_node = (AddrNode*)malloc(sizeof(AddrNode));
	p_node->addr = v;
	p_node->next = NULL;

	AddrNode* p_buf = AddrList_GetLastRef(p_head);
	p_buf->next = p_node;
}

void* AddrList_Pop(AddrNode* p_head)
{
	if (!p_head->next) {
		void* v = p_head->addr;
		free(p_head);
		return v;
	}

	AddrNode* p_buf = p_head;
	while (p_buf->next->next) {
		p_buf = p_buf->next;
	}
	void* addr = p_buf->next->addr;
	free(p_buf->next);
	p_buf->next = NULL;
	return addr;
}

void AddrList_Print(AddrNode* p_head)
{
	AddrNode* buf = p_head;
	while (buf->next) {
		printf("%p, ", buf->addr);
		buf = buf->next;
	}
	printf("%p\n", buf->addr);
}

typedef struct {
	unsigned int id;
	char name[MAX_NAME_LENGTH];
	unsigned int grade;
} Student;

void Student_Print(Student s)
{
	printf("Student(id=%d, name=%s, grade=%d)\n", s.id, s.name, s.grade);
}

typedef struct {
	int buffer[MAX_QUEUE_SIZE];
	int start;
	int end;
} Queue;

Queue Queue_Create()
{
	Queue queue = { .start = 0, .end = 0 };
	return queue;
}

void Queue_Enqueue(Queue* queue, int v)
{
	queue->buffer[queue->end++] = v;
}

bool Queue_IsEmpty(Queue* queue)
{
	return queue->start > queue->end - 1;
}

int Queue_Dequeue(Queue* queue)
{
	return Queue_IsEmpty(queue) ? NAN : queue->buffer[queue->start++];
}
//
//typedef struct {
//	IntNode* p_head;
//	int start;
//	int end;
//} Dynamic_Queue;
//
//void Dynamic_Queue_enqueue(Dynamic_Queue* queue, int v)
//{
//
//}
//
//bool Dynamic_Queue_isEmpty(Dynamic_Queue* queue)
//{
//
//}
//
//int Dynamic_Queue_dequeue(Dynamic_Queue* queue)
//{
//
//}

int main() {

	Student s1 = { .id = 611415029, .name = "Ian", .grade = 50 };
	Student s2 = { .id = 611415044, .name = "Eva", .grade = 60 };
	Student s3 = { .id = 611415105, .name = "Fat", .grade = 70 };

	Student_Print(s1);

	AddrNode* p_head = AddrList_Create(&s1);
	AddrList_Add(p_head, &s2);
	AddrList_Add(p_head, &s3);

	AddrList_Print(p_head);

	Student_Print(*(Student*)AddrList_Pop(p_head));
	Student_Print(*(Student*)AddrList_Pop(p_head));
	Student_Print(*(Student*)AddrList_Pop(p_head));

	Queue queue = Queue_Create();
	Queue_Enqueue(&queue, 50);
	Queue_Enqueue(&queue, 100);
	Queue_Enqueue(&queue, 150);
	Queue_Enqueue(&queue, 200);
	int output = Queue_Dequeue(&queue);
	printf("%d\n", output);
	output = Queue_Dequeue(&queue);
	printf("%d\n", output);
	output = Queue_Dequeue(&queue);
	printf("%d\n", output);
	output = Queue_Dequeue(&queue);
	printf("%d\n", output);
	output = Queue_Dequeue(&queue);
	printf("%d\n", output);

	return 0;
}
