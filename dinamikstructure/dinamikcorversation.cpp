#include <iostream>
using namespace std;

struct Element
{
	// ������
	char data;
	//������
	int indexe;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();
	void delegir(char data, int index);
	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}
void List::delegir(char data, int index)
{
	if (index <= 0 && !(this->Head)) {
		Add(data); ++(this->Count); return;
	}
	Element* tf = this->Head;
	for (int i = 1; i < index && tf->Next; ++i)
		tf = tf->Next;
	Element* temp = new Element;
	temp->data = data;
	temp->Next = tf->Next;
	tf->Next = temp;
	++(this->Count);
}
// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello \n";
	int index = 0;
	char a;
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.Print();
	cin >> a;
	cin >> index;
		
	// ������������� ���������� ������
	lst.Print();
	// ������� ��� �������� ������
	lst.Del();
	lst.Del();
	lst.Del();
	//������������� ���������� ������
	lst.Print();

}

