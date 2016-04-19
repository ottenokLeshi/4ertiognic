#ifndef _lLIST_H
#define _lList_H
template <typename T>
struct Cell 
{
	T data;
	Cell *next;
};

template <class T> class List 
{
	Cell<T> *first;
	Cell<T> *last;
public:
	class Marker {
	private:
		Cell<T> *current;
	public:
		//friend class List;
		Marker(Cell<T> *n = 0) {
			current = n;
		};
		~Marker() {};

		bool can_move() {
			if (current->next == NULL) return 0;
			else return 1;
		} 

		void move_next() {
			if (can_move()) {
				current = current->next;
			}
			else return;
		}
		T get_current() {
			return current->data;
		}

	};

	Marker to_start() {
		Marker m(first); //Marker m; m.current = first;
		return m;
	};
	
	List()
	{
		first = NULL;
		last = NULL;
	};
	
	~List() {
		Cell<T> *curr_del;
		for (curr_del = first; curr_del != last; ) {
			Cell<T> *temp = curr_del;
			curr_del = curr_del->next;
			delete temp;
		}
		delete last;
	};

	void add_back(T d)
	{
		Cell <T> *New = new Cell <T>;
		New->data = d;
		if (first == NULL && last == NULL)
		{
			first = New;
			first->next = NULL;
		}
		else if (first != NULL && last == NULL) 
		{
			last = New;
			first->next = last;
			last->next = NULL;
		}
		else if (last != NULL) 
		{
			Cell<T> *current = last;
			current->next = New;
			current->next->next = NULL;
			last = current->next;
		}
	};

	void show_list() //works only if T can be shown
	{
		if (first == NULL) { cout << "Null" << endl; }
		Cell<T> *current = first;
		while (current != last) 
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data;
		cout << endl;
	};

	// delete one element by index
	void del(int index)
	{
		// iteration starts by 1
		Cell<T> *element = first;
		// if we need to delete 3rd element from [1, 2, 3, 4, 5, 6]
		// then element will be 2
		for (int i = 1; i < index - 1; i++, element = element->next);
		if (index == 1) 
		{
			Cell<T> *temp = first;
			first = first->next;
			delete temp;
		}
		else 
		{
			Cell<T> *temp = element->next;
			if (element->next != last) // element is not last
				element->next = element->next->next;
			else {
				element->next = NULL;
				last = element;
			}
			delete temp;
		}
	};

	// delete in range [start, stop]
	void del_range(int start, int stop)
	{
		if (start > stop) {
			cout << "start > stop, exit";
			return;
		}
		// iteration starts by 1
		Cell<T> *start_el = first;
		Cell<T> *stop_el = first;
		int i;

		// if we need to delete 3..5 elements from [1, 2, 3, 4, 5, 6]
		// then start_el will be 2, stop_el will be 5
		for (i = 1; i < start - 1; i++, start_el = start_el->next);
		for ( ; i < stop; i++, stop_el = stop_el->next);

		if (start == 1 && stop_el == last) {
			cout << "Can't delete all list; use destructor for that." << endl;
			return;
		}

		Cell<T> *start_del = (start == 1) ? start_el : start_el->next;
		Cell<T> *stop_del = stop_el;
		Cell<T> *curr_del;
		for (curr_del = start_del; curr_del != stop_del; ) {
			Cell<T> *temp = curr_del;
			curr_del = curr_del->next;
			delete temp;
		}

		if (start == 1) // deleted first
			first = stop_el->next;
		else if (stop_el == last) { // deleted last
			last = start_el;
			last->next = NULL;
		}
		else start_el->next = stop_el->next;
		delete stop_el;
	};

	int size() 
	{
		if (first == NULL) { 
			return 0;
		}
		Cell<T> *current = first;
		int s = 1;
		while (current != last) {
			current = current->next;
			++s;
		}
		return s;
	}; 

	T get_elem(int index) // gets data of a cell with such index; should always be assigned
	{
		Cell<T> *current = first;
		if (index == 1) return current->data;
		int i = 1;
		do {
			current = current->next;
			++i;
		} while (i != index);
		return current->data;
	};


	void set_elem(int index, T d) // change data of a cell
	{
		Cell<T> *current = first;
		if (index == 1) { current->data = d; return; }
		for (int i = 1; i < index; ++i) current = current->next;
		current->data = d;
		return;
	};
};
#endif
