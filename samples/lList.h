template <typename T>
struct Cell 
{
	T data;
	Cell *next;
};

template <class T> 
class List 
{
	Cell<T> *first;
	Cell<T> *last;
public:
	List()
	{
		first = NULL;
		last = NULL;
	};
	~List() {};

	void add_item(T d)
	{
		Cell <T> *New = new Cell<T>;
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

	void show_list()
	{
		if (first == NULL) { cout << "0" << endl; }
		Cell<T> *current = first;
		while (current != last) 
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data;
		cout << endl;
	};

	void del(int start, int stop) //delete in range
	{
		// iteration starts by 1
		Cell<T> *start_el = first;
		Cell<T> *stop_el = first;
		int i;
		for (i = 1; i < start - 1; i++, start_el = start_el->next);
		for (i = 1; i < stop; i++, stop_el = stop_el->next);

		if (start_el == first) 
		{
			first = stop_el->next;
		}
		else if (stop_el == last) // stop = length
		{ 
			last = start_el;
		}
		else start_el->next = stop_el->next;
	};
};
