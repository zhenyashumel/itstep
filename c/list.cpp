#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*next;
};
Node *insert(Node *head, int value, int pos)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cur->next = NULL;
	if (pos == 0)//добавление элемента в начало списка
	{

		cur->next = head;//указатель нового элемента направляем на голову списка
		head = cur;//смещение головы
		return head;
	}
	Node *element = head;//создали вспомогательный элемент для продвижения по списку
	for (int i = 0; i < pos&&element;
		i++, element = element->next);//поиск позиции для вставки
	if (element)//проверка на допустимость позиции
	{
		cur->next = element->next;//присвоение новому элементу указателя на элемент после него в списке
		element->next = cur;//присвоение предыдущему элементу указателя на новый элемент
	}
	else cout << " Error!!!";
	return head;
}
void print(Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
void remove(Node **head, int value)
{
	Node *cur = *head, *prev = NULL;
	while (cur->data != value&&cur)//поиск элемента по значению||конца списка
	{
		prev = cur;//сохраняем текущий элемент
		cur = cur->next;//переход к следующему элементу
	}
	if (cur)//если нашли 
	{
		if (prev) //если перед ним  есть предыдущий
			prev->next = cur->next;//переставляем указатель из предыдущего элемента на следующий за удаляемым
		else //если удаляем первый
			*head = cur->next; //изменяем голову списка на следующий за удаляемым
		free(cur);
		return;
	}
	if (*head) cout << "Element not found" << endl;
	else cout << "List is empty" << endl;

}
void delete_back(Node **head)
{
	Node *cur = *head, *prev = NULL;
	while (cur->next )
	{
		prev = cur;//сохраняем текущий элемент
		cur = cur->next;//переход к следующему элементу
	}
	prev->next = NULL;
	free(cur);

}
void insert_back(Node *head, int value)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cur->next = NULL;
	Node *element = head;
	Node *prev = NULL;
	if (head = NULL)
	{
		head = cur;
		return;
	}
	while (element)
	{
		prev = element;
		element = element->next;
	}
	prev->next = cur;

}
int main()
{
	setlocale(0, "");
	Node *list = NULL;
	list = insert(list, 10, 0);
	list = insert(list, 20, 0);
	list = insert(list, 11, 1);
	print(list);
	cout << endl;
	list = insert(list, 100, 1);
	list = insert(list, 201, 1);
	list = insert(list, 113, 1);
	print(list);
	cout << endl;
	remove(&list, 100);
	print(list);
	cout << endl;
	remove(&list, 20);
	print(list);
	cout << endl;
	remove(&list, 11);
	print(list);
	insert_back(list,11);
	print(list);
	delete_back(&list);
	cout << endl;
	print(list);
	
	
	return 0;
}
