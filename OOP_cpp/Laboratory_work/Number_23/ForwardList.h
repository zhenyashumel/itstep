#pragma once
#include<exception>

template <typename T>
class ForwardList {
	struct node {
		T data;
		node* next = nullptr;
	};
	node* head;
	node* tail;
	size_t list_size;

public:
	ForwardList();
	~ForwardList();

	size_t size() const;
	bool empty() const;

	void push_back(const T&);
	void push_front(const T&);
	bool insert(const T&, const T&);

	T pop_back();
	T pop_front();
	bool erase(const T&);

	void print();

private:
	node* create_node(const T&);
	void create_first_node(const T&);
	node* find_node(const T&);
	node* find_previous_node(const T&);
};


template<typename T>
typename ForwardList<T>::node* ForwardList<T>::find_previous_node(const T& val)
{

	node *ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->next->data == val)
			return ptr;
		ptr = ptr->next;
	}
	return nullptr;
}


template<typename T>
typename ForwardList<T>::node* ForwardList<T>::find_node(const T&val)
{
	node *ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data == val)
			return ptr;
		ptr = ptr->next;
	}

	return nullptr;
}
template<typename T>
typename ForwardList<T>::node* ForwardList<T>::create_node(const T& val)
{
	node* tmp = new node;
	tmp->data = val;
	tmp->next = nullptr;

	return tmp;
}

template<typename T>
ForwardList<T>::ForwardList() : head(nullptr), tail(nullptr), list_size(0)
{

}


template<typename T>
ForwardList<T>::~ForwardList()
{
	while (!empty())
		pop_back();
}


template<typename T>
void ForwardList<T>::create_first_node(const T& val)
{
	node* tmp = create_node(val);
	head = tmp;
	tail = tmp;
}

template<typename T>
size_t ForwardList<T>::size() const
{
	return list_size;
}

template<typename T>
bool ForwardList<T>::empty() const
{
	return !size();
}

template<typename T>
void ForwardList<T>::push_back(const T& val)
{
	if (empty())
	{
		create_first_node(val);
	}
	else
	{
		node* tmp = create_node(val);
		tail->next = tmp;
		tail = tmp;
	}
	++list_size;
}

template<typename T>
void ForwardList<T>::push_front(const T& val)
{
	if (empty())
	{
		create_first_node(val);

	}
	else
	{
		node* tmp = create_node(val);
		tmp->next = head;
		head = tmp;
	}
	++list_size;
}

template<typename T>
T ForwardList<T>::pop_front()
{
	
	if (!empty())
	{
		--list_size;
		T data = head->data;
		node* ptr = head;
		head = head->next;
		delete ptr;
		return data;
	}
	else throw std::logic_error("empty_list");


}


template<typename T>
T ForwardList<T>::pop_back()
{
	//if(size() == 1)
	if (!empty()) {
		
		T data = tail->data;

		node*ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->next == nullptr) {
				ptr->next = nullptr;
				break;
			}
			ptr = ptr->next;
		}
		tail = ptr;
		--list_size;
		return data;
	}
	else throw std::logic_error("empty_list");
}

template<typename T>
void ForwardList<T>::print()
{
	node* ptr = head;
	while (ptr != nullptr)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}


template<typename T>
bool ForwardList<T>::insert(const T& val, const T& wher)
{

	if (empty()) return false;
	if (wher == tail->data)
		push_back(val);

	else
	{

		node* ptr = find_node(wher);
		if (ptr == nullptr)
		{
			return false;
		}
		node *cur = create_node(val);
		cur->next = ptr->next;
		ptr->next = cur;
		++list_size;
		return true;

	}
	return false;
	
}

template<typename T>
bool ForwardList<T>::erase(const T& val)
{
	if (empty()) throw std::logic_error("empty_list");

	 if (val == head->data)
		pop_front();
	else if (val == tail->data)
		pop_back();

	else 
	{
		node* prev = find_previous_node(val);
		if (prev == nullptr)
			return false;
		node* del = prev->next;
		prev->next = del->next;
		delete del;
		--list_size;
		return true;
	}

	return false;
}
