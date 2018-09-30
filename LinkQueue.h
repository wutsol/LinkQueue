#pragma once
#ifndef LinkQueue_h
#define LinkQueue_h
#include <iostream>
#define Status int
#define EMPTY 0
#define NOT_EMPTY 1
#define OK 1
template <class T>
struct Node 
{
	T data;
	Node<T> *next;
};
template <class T>
class LinkQueue
{
private:
	Node<T> * front;
	Node<T> *rear;
public:
	LinkQueue();
	~LinkQueue();
	Status EnQueue(T e);//����
	Status DeQueue(T &e);//ɾ��
	int QueueLength();//���г���
	Status IsEmpty();//�ж��Ƿ��
	void DisQueue();//�������
};
template <class T>
LinkQueue<T>::LinkQueue()
{
	front = new Node<T>;
	front->next = NULL;
	rear = front;
}
template <class T>
LinkQueue<T>::~LinkQueue()
{
	delete[] front;
}
template <class T>
Status LinkQueue<T>::EnQueue(T e)
{
	Node<T> *p = new Node<T>;
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	rear->next = p;//�����򽨱�ԭ����ͬ
	rear = p;
	return OK;
}
template <class T>
Status LinkQueue<T>::DeQueue(T &e)
{
	Node<T> *p;
	if (rear == front) return EMPTY;
	p = front->next;
	e = p->data;
	front->next = p->next;
	if (rear == p) rear = front;//���ԭ����ֻ��һ��Ԫ�أ�ɾ����rearָ�뻹ԭ��frontָ��
	delete p;
	return OK;
}
template <class T>
int LinkQueue<T>::QueueLength()
{
	Node<T> *p=front->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	delete[] p;
	return i;
}
template <class T>
Status LinkQueue<T>::IsEmpty()
{
	if (rear == front) return EMPTY;
	else
		return NOT_EMPTY;
}
template <class T>
void LinkQueue<T>::DisQueue()
{
	Node<T> *p = front->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
#endif // !LinkQueue_h
