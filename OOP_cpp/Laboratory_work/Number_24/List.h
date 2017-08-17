template<class T>
struct node {
	T data;
	node* next;
	node* prev;
};

template<class T>
class List
{
	node<T>* head;
	node<T>* tail;

	void init(const T& value);
public:
	size_t size;
	List();
	~List();
	void push_front(const T& value);
	bool push_back(const T& value);
	bool pop_front();
	bool pop_back();
	node<T>* find(const T& value);
	bool insert(const T& value, const T& prev_value);
	bool erase(const T& value);
	void print() const;
	void printReverse() const;
	void replaceValue(const T&, const T&);
	void eraseAll(const T&);
};

template<class T>
void List<T>::eraseAll(const T& value)
{
	if (head == nullptr)
	{
		return;
	}

	node<T>*  tmp = head;
	while (tmp)
	{
		if (tmp->data == value)
		{
			if (tmp->next == nullptr)
			{
				pop_back();
				break;
			}
			else if (tmp->prev == nullptr)
			{
				pop_front();
				tmp = head;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				--size;
				auto del = tmp->next;
				delete tmp;
				tmp = del;
			}
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

template<class T>
void List<T>::replaceValue(const T& search, const T& val)
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		node<T>*  it = head;
		while (it)
		{
			if (it->data == search)
			{
				it->data = val;
				return;
			}
			it = it->next;
		}
	}
}

template<class T>
void List<T>::printReverse() const
{
	node<T>* tmp = tail;
	while (tmp)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	std::cout << std::endl;
}

template<class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<class T>
List<T>::~List()
{
	while (size != 0) {
		pop_back();
	}
}

template<class T>
void List<T>::init(const T& value)
{
	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	head = newNode;
	tail = newNode;
	++size;
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (head == nullptr) {
		init(value);
		return;
	}

	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = nullptr;
	head->prev = newNode;
	head = newNode;
	++size;
}

template<class T>
bool List<T>::push_back(const T& value)
{
	if (head == nullptr) {
		init(value);
		return true;
	}
	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	++size;

	return true;
}

template<class T>
bool List<T>::pop_front()
{
	if (head == nullptr) {
		return false;
	}
	else if (!head->next && !head->prev)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
		return true;
	}

	node<T>* firstElem = head;
	head = head->next;
	head->prev = nullptr;
	--size;
	delete firstElem;

	return true;
}

template<class T>
bool List<T>::pop_back()
{
	if (tail == nullptr) {
		return false;
	}

	else if (!head->next && !head->prev)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
		return true;
	}

	node<T>* lastElem = tail;
	tail = tail->prev;
	tail->next = nullptr;
	--size;
	delete lastElem;

	return true;
}

template<class T>
node<T>* List<T>::find(const T& value)
{
	if (head == nullptr) {
		return nullptr;
	}

	node<T>* elem = head;
	while (elem) {
		if (elem->data == value) {
			return elem;
		}
		else {
			elem = elem->next;
		}
	}
	return nullptr;
}

template<class T>
bool List<T>::insert(const T& value, const T& prev_value)
{
	node<T>* pos = find(prev_value);

	if (pos == nullptr) {
		return false;
	}

	if (tail == pos) {
		push_back(value);
		return true;
	}

	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->prev = pos;
	newNode->next = pos->next;
	pos->next->prev = newNode;
	pos->next = newNode;
	++size;
	return true;
}

template<class T>
bool List<T>::erase(const T& value)
{
	if (head == nullptr) {
		return false;
	}

	node<T>* pos = find(value);

	if (!pos)
	{
		return false;
	}
	if (pos->next == nullptr)
	{
		pop_back();
		return true;
	}
	if (pos->prev == nullptr)
	{
		pop_front();
		return true;
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	--size;
	delete pos;

	return true;
}

template<class T>
void List<T>::print() const
{
	node<T>* tmp = head;
	while (tmp) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}
