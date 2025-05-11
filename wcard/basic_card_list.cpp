#include "basic_card_list.h"
#include<algorithm>

static bool pred(card a, card b);//排序函数

basic_card_list::basic_card_list()//构造函数
{
	list_size = 0;
	card_list = nullptr;
}

basic_card_list::basic_card_list(int size)//仅提供长度，列表默认为空
{
	if (size < 0)
		throw "长度小于0";
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

basic_card_list::basic_card_list(int size, card* list)//自定义构造函数，但长度与数组大小必须匹配
{
	list_size = size;
	card_list = new card[size];
	for (int i = 0; i < size; i++)
	{
		card_list[i] = list[i];
	}
}

basic_card_list::basic_card_list(const basic_card_list& other)//拷贝构造函数
{
	list_size = other.list_size;
	card_list = new card[list_size];
	for (int i = 0; i < list_size; i++)
	{
		card_list[i] = other.card_list[i];
	}
}

basic_card_list& basic_card_list::operator=(const basic_card_list& other)//赋值运算符
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
	// TODO: 在此处插入 return 语句
	return *this;
}

basic_card_list::~basic_card_list()//析构函数
{
	delete[] card_list;
}

card basic_card_list::at(int index) const//返回指定位置的卡牌，如果越界或列表为空则返回空卡牌
{
	if(index < 0 || index >= list_size|| card_list == nullptr)
		return card();
	return card_list[index];
}

card basic_card_list::begin() const//返回第一个卡牌，如果列表为空则返回空卡牌
{
	if (list_size == 0 || card_list == nullptr)
		return card();
	return card_list[0];
}

card basic_card_list::end() const//返回最后一个卡牌，如果列表为空则返回空卡牌
{
	if (list_size == 0 || card_list == nullptr)
		return card();
	return card_list[list_size - 1];
}

int basic_card_list::size() const//返回列表长度
{
	return list_size;
}

bool basic_card_list::empty() const
{
	return list_size == 0;
}

void basic_card_list::push_back(card incard)//在列表末尾添加卡牌
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

void basic_card_list::pop_back()//删除列表末尾的卡牌
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

void basic_card_list::clear()//清空列表
{
	list_size = 0;
	delete[] card_list;
	card_list = nullptr;
}

void basic_card_list::sort()//按花色和点数排序
{
	std::sort(card_list, card_list + list_size, pred);
}

void basic_card_list::random_shuffle()//随机打乱列表
{
	std::random_shuffle(card_list, card_list + list_size);
}

card basic_card_list::operator[](int index) const
{
	if (index < 0 || index >= list_size)
		throw "索引越界";
	if(card_list == nullptr)
		throw "列表为空";
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


static bool pred(card a, card b)//排序函数
{
	if (a.mark==b.mark)
		return a.suit<b.suit;
	else
		return a.mark<b.mark;
}

