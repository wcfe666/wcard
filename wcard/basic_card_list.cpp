#include "basic_card_list.h"
#include<algorithm>

static bool pred(card a, card b);//������

basic_card_list::basic_card_list()//���캯��
{
	list_size = 0;
	card_list = nullptr;
}

basic_card_list::basic_card_list(int size)//���ṩ���ȣ��б�Ĭ��Ϊ��
{
	if (size < 0)
		throw "����С��0";
	list_size = size;
	card_list = new card[size];
	for (int i = 0; i < size; i++)
	{
		card_list[i] = card();
	}
}

/*
basic_card_list::basic_card_list(card* list)
{
	list_size=sizeof(list)/sizeof(card);
	card_list = new card[list_size];
	for (int i = 0; i < list_size; i++)
	{
		card_list[i] = list[i];
	}
}
*/

basic_card_list::basic_card_list(int size, card* list)//�Զ��幹�캯�����������������С����ƥ��
{
	list_size = size;
	card_list = new card[size];
	for (int i = 0; i < size; i++)
	{
		card_list[i] = list[i];
	}
}

basic_card_list::basic_card_list(const basic_card_list& other)//�������캯��
{
	list_size = other.list_size;
	card_list = new card[list_size];
	for (int i = 0; i < list_size; i++)
	{
		card_list[i] = other.card_list[i];
	}
}

basic_card_list& basic_card_list::operator=(const basic_card_list& other)//��ֵ�����
{
	if (this == &other)
		return *this;
	list_size = other.list_size;
	delete[] card_list;
	card_list = new card[list_size];
	for (int i = 0; i < list_size; i++)
	{
		card_list[i] = other.card_list[i];
	}	
	// TODO: �ڴ˴����� return ���
	return *this;
}

basic_card_list::~basic_card_list()//��������
{
	delete[] card_list;
}

card basic_card_list::at(int index) const//����ָ��λ�õĿ��ƣ����Խ����б�Ϊ���򷵻ؿտ���
{
	if(index < 0 || index >= list_size|| card_list == nullptr)
		return card();
	return card_list[index];
}

card basic_card_list::begin() const//���ص�һ�����ƣ�����б�Ϊ���򷵻ؿտ���
{
	if (list_size == 0 || card_list == nullptr)
		return card();
	return card_list[0];
}

card basic_card_list::end() const//�������һ�����ƣ�����б�Ϊ���򷵻ؿտ���
{
	if (list_size == 0 || card_list == nullptr)
		return card();
	return card_list[list_size - 1];
}

int basic_card_list::size() const//�����б���
{
	return list_size;
}

bool basic_card_list::empty() const
{
	return list_size == 0;
}

void basic_card_list::push_back(card incard)//���б�ĩβ��ӿ���
{
	if (list_size == 0)
	{
		card_list = new card[1];
		card_list[0] = incard;
	}
	else
	{
		card* new_list = new card[list_size + 1];
		for (int i = 0; i < list_size; i++)
		{
			new_list[i] = card_list[i];
		}
		new_list[list_size] = incard;
		delete[] card_list;
		card_list = new_list;
	}
	list_size++;
}

void basic_card_list::pop_back()//ɾ���б�ĩβ�Ŀ���
{
	if (list_size == 0)
		return;
	list_size--;
	card* new_list = new card[list_size];
	for (int i = 0; i < list_size; i++)
	{
		new_list[i] = card_list[i];
	}
	delete[] card_list;
	card_list = new_list;
}

void basic_card_list::clear()//����б�
{
	list_size = 0;
	delete[] card_list;
	card_list = nullptr;
}

void basic_card_list::sort()//����ɫ�͵�������
{
	std::sort(card_list, card_list + list_size, pred);
}

void basic_card_list::random_shuffle()//��������б�
{
	std::random_shuffle(card_list, card_list + list_size);
}

card basic_card_list::operator[](int index) const
{
	if (index < 0 || index >= list_size)
		throw "����Խ��";
	if(card_list == nullptr)
		throw "�б�Ϊ��";
	return card_list[index];
}

basic_card_list& basic_card_list::operator+=(const card& card)
{
	push_back(card);
	return *this;
}

basic_card_list basic_card_list::operator+(const basic_card_list& other)
{
	basic_card_list result(list_size + other.list_size);
	for (int i = 0; i < list_size; i++)
	{
		result.card_list[i] = card_list[i];
	}
	for (int i = 0; i < other.list_size; i++)
	{
		result.card_list[list_size + i] = other.card_list[i];
	}
	return result;
}

basic_card_list& basic_card_list::operator<<(const card& card)
{
	push_back(card);
	return *this;
}


static bool pred(card a, card b)//������
{
	if (a.mark==b.mark)
		return a.suit<b.suit;
	else
		return a.mark<b.mark;
}

