#ifndef _LISTFUNC_H
#define _LISTFUNC_H

//List
template <class T> struct Cell
{
	T data;
	Cell<T> *next;
};

template <class T> class List
{
	Cell<T>* head;
	Cell<T>* tail;
public:
	List();
	~List();
	void print();
	int size();
	void addBack(T value);
	void deleteBack();
	//add/deleteFront?
};

template <class T> List<T>::List() {
	head = NULL;
	tail = NULL;
}

template <class T> List<T>::~List()  {
	Cell <T> * tmp;
	tmp = head;
	while (tmp != NULL) {
		tmp = tmp->next;
		delete(head);
		head = tmp;
	}
}

//adding to end
template <class T> void List<T>::addBack(T value) {
	Cell<T> *newCell;
	newCell->data = value; 
	newCell->next = NULL;

	Cell<T> *tmp = head;
	if (tmp != NULL) { //find end
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newCell;
	}
	else { head = newCell; }
}

//deleting last
template <class T> void List<T>::deleteBack()  {
	if (head == NULL && tail == NULL) { cout << "List is empty." << endl; }
	else if (head == tail) {
		delete(head);
		head = tail = NULL;
	}
	else {
		Cell<T> *tmp = head;
		//just to find out num of cells
		int NmCell = 0;
		while (tmp != NULL)  {
			NmCell++;
			tmp = tmp->next;
		}

		tmp = head;
		for (int i = 1; i < (NmCell-1); i++) {
			tmp = tmp->next;
		}

		delete(tmp->next);
		tail = tmp;
		tail->next = NULL;
	}
}

//print
template <class T> void List<T>::print()  {
	Cell<T> *tmp = head;

	if (tmp == NULL) { cout << "Null"; }
	else if (tmp->next == NULL) { cout << tmp->data; }
	else {
		while (tmp != NULL) {
			cout << tmp->data;
			tmp = tmp->next;
			cout << " ";
		}
	}
}

//size
template <class T> int List<T>::size()  {
	if (head == NULL && tail == NULL) { return 0; }

	Cell<T> *tmp = head;
	int NmCell = 0;

	while (tmp != NULL) {
		NmCell++;
		tmp = tmp->next;
	}
	return NmCell;
}
#endif 
