#include "deal_cards.h"

deal_cards::deal_cards():
	basic_card_list(),now_site(0)
{

}

/*自动构建牌堆
* 根据 num_of_cards 自动构建牌堆，并打乱顺序
* 54：标准扑克牌
* 52：不带王牌的扑克牌
*/
deal_cards::deal_cards(int num_of_cards):
	basic_card_list(),now_site(0)
{
	card new_card[54];
	switch(num_of_cards)
	{
		case 54:         // 54：标准扑克牌
			for (int i = 0; i < 52; i++)
			{
				new_card[i].mark =static_cast<mark>(i / 4 + 1);
				switch (i % 4)
				{
					case 0:
						new_card[i].suit = static_cast<suit>(1);
						break;
					case 1:
						new_card[i].suit = static_cast<suit>(2);
						break;
					case 2:
						new_card[i].suit = static_cast<suit>(3);
						break;
					case 3:
						new_card[i].suit = static_cast<suit>(4);
						break;
				}
			}
			new_card[52] = { JOKER ,SMALL };
			new_card[53] = { JOKER,BIG };
			break;
		case 52:         // 52：不带王牌的扑克牌
			for (int i = 0; i < 52; i++)
			{
				new_card[i].mark = static_cast<mark>(i / 4);
				switch (i % 4)
				{
				case 0:
					new_card[i].suit = static_cast<suit>(0);
					break;
				case 1:
					new_card[i].suit = static_cast<suit>(1);
					break;
				case 2:
					new_card[i].suit = static_cast<suit>(2);
					break;
				case 3:
					new_card[i].suit = static_cast<suit>(3);
					break;
				}
			}
			break;
		default:
			throw"错误大小";
			break;
	}
	basic_card_list temp_list(num_of_cards, new_card);
	basic_card_list::operator=(temp_list);
	basic_card_list::sort();
}

deal_cards::deal_cards(basic_card_list& bc_list)://拷贝基类构造函数
	basic_card_list(bc_list),now_site(0)
{
}

deal_cards::deal_cards(deal_cards& dc)://拷贝构造函数
	basic_card_list(dc),now_site(dc.now_site)
{

}

deal_cards::~deal_cards()//析构函数
{
}

bool deal_cards::is_head() const//是否是头
{
	return now_site == 0;
}

bool deal_cards::is_tail()//是否是尾
{
	return now_site == basic_card_list::size() - 1;
}

int deal_cards::remain()//获取剩余牌数
{
	return basic_card_list::size() - now_site;
}

/*抽取指定数量的牌，并放入 outlist
* 返回剩余牌数
*/
int deal_cards::extract(int num_of_cards, card* outlist)
{
	if (num_of_cards > remain())
	{
		throw "抽取数量大于剩余牌数";
	}
	for (int i = 0; i < num_of_cards; i++)
	{
		outlist[i] = basic_card_list::at(i);
	}
	now_site += num_of_cards;
	return remain();
}

void deal_cards::anew()//重新洗牌
{
	basic_card_list::sort();
	now_site = 0;
}
