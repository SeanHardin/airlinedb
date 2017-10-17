/*
 * LinkedList.h
 *
 *  Created on: Oct 5, 2017
 *      Author: fatma.serce
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <assert.h>
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class LinkedList{
   protected:
		node<T> *head, *last;
		int count;
   public:
		LinkedList();
		bool isEmpty();
		int length();

		void printList();

		void insertFirst(T& item);
//		T back();
//		T front();
//		node<T>* search(T& value);
		void insertLast(T& item);
//		void deleteNode(T& item);
//		void destroy();
//		~LinkedList();

};
template <class T>
LinkedList<T>::LinkedList(){
	head = last = NULL;
	count = 0;
}
template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}

template <typename T>
void LinkedList<T>::printList(){
	if (last!=NULL){
		node<T>* current = head;
		while(current!=NULL){
			cout << current->data <<'\n';
			current = current->next;
		}
	}
}

template <class T>
int LinkedList<T>::length(){
	return count;
}
template <class T>
void LinkedList<T>::insertFirst(T& item){
	node<T> *p = new node<T>;
	p->data = item;
	p->next = head;
	head = p;
	if(last==NULL)
		last = p;
	count++;

}

template <class T>
void LinkedList<T>::insertLast(T& item){
	node<T> *p = new node<T>;
	p->data=item;
	p->next = NULL;
	if (last==NULL){
		head=last=p;
	} else {
		last->next = p;
		last=p;
		count++;
	}
}


#endif /* LINKEDLIST_H_ */
