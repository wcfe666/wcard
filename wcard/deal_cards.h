#pragma once
#include "basic_card_list.h"
class deal_cards :
	public basic_card_list
{
private:
	int now_site;
public:
	deal_cards();//Ĭ�Ϲ��캯��
	deal_cards(int num_of_cards);//�Զ������ƶ�
	deal_cards(basic_card_list& bc_list);//���࿽��
	deal_cards(deal_cards& dc);//�������캯��
	~deal_cards();//��������
};

