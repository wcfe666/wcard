#pragma once
//定义牌号和花色枚举
enum mark { THREE=1, FOUR=2, FIVE=3, SIX=4, SEVEN=5, EIGHT=6, NINE=7, TEN=8, JACK=9, QUEEN=10, KING=11, ACE=12 , TWO=13 , JOKER=14};   //牌号
enum suit { CLUB=1, DIAMOND=2, HEART=3, SPADE=4 , SMALL =5,BIG=6};   //花色
struct card   //单张牌
{          
	mark mark;
	suit suit;
};

/*这是一个存放卡牌列表的基类
 *它严格要求长度匹配，请严格按照长度进行初始化，对于仅有长度的构造，会自动构造空列表
 *它并不会自动构造牌列表，需要手动传入
 *可以用于任何需要牌列表的地方
 *其是有顺序的，可以进行排序等操作
 *进行了一定的安全性检查，但不保证绝对安全
*/
class basic_card_list
{
	private:
		int list_size;  //长度
		card* card_list;  //牌列表指针
	public:
		basic_card_list();//构造函数
		basic_card_list(int size);//仅有长度的构造
		//basic_card_list(card* list);//自动构造
		basic_card_list(int size, card* list);//自定义构造
		basic_card_list(const basic_card_list& other);//拷贝构造
		basic_card_list& operator=(const basic_card_list& other);//拷贝赋值
		virtual ~basic_card_list();//虚析构函数
		card at(int index) const;//获取指定位置的牌
		card begin() const;//获取第一个牌
		card end() const;//获取最后一个牌
		int size() const;//获取长度
		bool empty() const;//判断列表是否为空
		void push_back(card card);//在末尾添加牌
		void pop_back();//删除末尾的牌
		void clear();//清空列表
		void sort(); //排序
		void random_shuffle(); //随机打乱列表
		card operator[](int index) const;//下标访问
		basic_card_list& operator+=(const card& card);//列表末尾添加牌
		basic_card_list operator+(const basic_card_list& other);//列表合并
		basic_card_list& operator<<(const card& card);//添加牌到列表末尾
};

