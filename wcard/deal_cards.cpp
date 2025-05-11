#include "deal_cards.h"

deal_cards::deal_cards():
	basic_card_list(),now_site(0)
{

}

/*�Զ������ƶ�
* ���� num_of_cards �Զ������ƶѣ�������˳��
* 54����׼�˿���
* 52���������Ƶ��˿���
*/
deal_cards::deal_cards(int num_of_cards):
	basic_card_list(),now_site(0)
{
	card new_card[54];
	switch(num_of_cards)
	{
		case 54:         // 54����׼�˿���
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
		case 52:         // 52���������Ƶ��˿���
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
			throw"�����С";
			break;
	}
	basic_card_list temp_list(num_of_cards, new_card);
	basic_card_list::operator=(temp_list);
	basic_card_list::sort();
}

deal_cards::deal_cards(basic_card_list& bc_list)://�������๹�캯��
	basic_card_list(bc_list),now_site(0)
{
}

deal_cards::deal_cards(deal_cards& dc)://�������캯��
	basic_card_list(dc),now_site(dc.now_site)
{

}

deal_cards::~deal_cards()//��������
{
}

bool deal_cards::is_head() const//�Ƿ���ͷ
{
	return now_site == 0;
}

bool deal_cards::is_tail()//�Ƿ���β
{
	return now_site == basic_card_list::size() - 1;
}

int deal_cards::remain()//��ȡʣ������
{
	return basic_card_list::size() - now_site;
}

/*��ȡָ���������ƣ������� outlist
* ����ʣ������
*/
int deal_cards::extract(int num_of_cards, card* outlist)
{
	if (num_of_cards > remain())
	{
		throw "��ȡ��������ʣ������";
	}
	for (int i = 0; i < num_of_cards; i++)
	{
		outlist[i] = basic_card_list::at(i);
	}
	now_site += num_of_cards;
	return remain();
}

void deal_cards::anew()//����ϴ��
{
	basic_card_list::sort();
	now_site = 0;
}
