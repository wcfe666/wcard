#pragma once
#include "basic_card_list.h"
class deal_cards :
	public basic_card_list
{
private:
	int now_site;
public:
	deal_cards();//默认构造函数
	deal_cards(int num_of_cards);//自动构建牌堆
	deal_cards(basic_card_list& bc_list);//基类拷贝
	deal_cards(deal_cards& dc);//拷贝构造函数
	~deal_cards();//析构函数
	int remain();//剩余牌数	
	bool is_tail();//是否指向最后一张牌
	bool is_head() const;//是否指向第一张牌
	int extract(int num_of_cards, card* outlist);//抽取指定张数的牌
	void anew(); //重新洗牌
};

