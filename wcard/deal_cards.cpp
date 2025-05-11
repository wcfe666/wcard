#include "deal_cards.h"

deal_cards::deal_cards():
	basic_card_list(),now_site(0)
{

}

/*�Զ������ƶ�
* ���� num_of_cards �Զ������ƶ�
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
}

deal_cards::deal_cards(basic_card_list& bc_list):
	basic_card_list(bc_list),now_site(0)
{
}

deal_cards::deal_cards(deal_cards& dc):
	basic_card_list(dc),now_site(dc.now_site)
{

}

deal_cards::~deal_cards()
{
}
