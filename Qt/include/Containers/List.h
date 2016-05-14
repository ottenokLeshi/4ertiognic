#ifndef _LIST_H
#define _LIST_H


template <class T> class List
{
	struct Cell
	{
		T data;
		Cell *next;
		Cell *prev;
	};

	Cell *first;
	Cell *last;
	unsigned size;
public:

	friend class Marker;

	//----------------------------
	class Marker {
	private:
		Cell *current;
	public:
		friend class List<T>;

		Marker(const List& L) {
			current = L.first;
		}

		Marker(Cell *mar) {
			current = mar;
		}

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

		T& operator*() { return current->data; }

		bool exist() { 
			if (current) return true; 
			return false; 
		}

		Marker operator++() { return Marker(current->next); }

		Marker operator--() { return Marker(current->prev); }

		bool valid(){
			if (current) return true;
			return false;
		}

		bool operator==(const Marker& mar){
			return current == mar.current;
		}

		bool operator!=(const Marker& mar){
			return current != mar.current;
		}

		void operator=(const Marker& mar){
			current = mar.current;
		}

		
	};
	//-----------------------------------------------------


	List()
	{
		first = NULL;
		last = NULL;
		size = 0;
    }

	~List() {
		if (first){
			Cell* current = first;
			do
			{
				Cell *newcur = current->next;
				delete current;
				current = newcur;
			} while (current);
			first = 0;
			last = 0;
			size = 0;
		}
		return;
    }

	// get first or last, current element
	T& firstElem() const { return first->data; }
	T& lastElem() const { return last->data; }

	//get size
	unsigned sizeList() { return size; }

	// search element
	Marker search(const T& elem) {
		for (Marker mar(first);mar.exist();mar++) {
			if (*mar == elem) return mar;
		}
		return Marker(0);
	}

	// add element
	Marker addElem(Marker, const T&);

	//delete element
	void deleteElem(Marker);
	void push_front(const T&);
	void push_back(const T&);
	//delete all elements
	void deleteAll();

	// marker in begin
	Marker inBegin() { return Marker(first); }

	//marker in end
	Marker inEnd() { return Marker(last); }

};

template <typename T> typename List<T>::Marker List<T>::addElem(Marker mar, const T& elem) {
	if (mar.exist()) {
		Cell* newmar = new Cell;
		newmar->data = elem;
		newmar->next = mar.current->next;
		mar.current->next = newmar;
		if (newmar->next) newmar->next->prev = newmar;
		newmar->prev = mar.current;
		size++;
		return Marker(newmar);
	}
	return Marker(0);
}

template<typename T> void List<T>::deleteElem(Marker mar){
	if (mar.current)
	{
		Cell* prev, *next;
		prev = mar.current->prev;
		next = mar.current->next;
		if (!prev && !next)
		{
			delete mar.current;
			first = 0;
			last = 0;
		}
		else {
			if (prev) prev->next = next; else first = first->next;
			if (next) next->prev = prev; else last = last->prev;
			delete mar.current;
		    }
		size--;
	}
}

template<typename item_type> void List<item_type>::deleteAll(){
	if (first){
		Cell* current = first;
		do
		{
			Cell *newmar = current->next;
			delete current;
			current = newmar;
		} while (current);
		first = 0;
		last = 0;
		size = 0;
	}
	return;
}

template<typename T> void List<T>::push_front(const T &elem)
{
	if (first)
	{
		Cell *c = new Cell;
		first->prev = c;
		first->prev->next = first;
		first = c;
		first->data = elem;
		first->prev = 0;
		size++;
	}
	else
	{
		first = new Cell;
		first->data = elem;
		first->next = 0;
		first->prev = 0;
		last = first;
		size = 1;
	}
}

template<typename T> void List<T>::push_back(const T &elem)
{
	if (first)
	{
		Cell *c = new Cell;
		last->next = c;
		last->next->prev = last;
		last = c;
		last->data = elem;
		last->next = 0;
		size++;
	}
	else
	{
		first = new Cell;
		first->data = elem;
		first->next = 0;
		first->prev = 0;
		last = first;
		size = 1;
	}
}
#endif

