#include <iostream>
#include"basic_card_list.h"
#include"deal_cards.h"

int main()
{
	deal_cards test(54);
	card out= test.begin();
	std::cout << out.mark << " " << out.suit << std::endl;
	out = test.end();
	std::cout << out.mark << " " << out.suit << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << "*";
	std::cout << std::endl;

	for (int i = 0; i < test.size(); i++)
	{
		out = test.at(i);
		std::cout << out.mark << " " << out.suit << std::endl;
	}
	for (int i = 0; i < 20; i++)
		std::cout << "*";
	std::cout << std::endl;

	test.random_shuffle();
	for (int i = 0; i < test.size(); i++)
	{
		out = test.at(i);
		std::cout << out.mark << " " << out.suit << std::endl;
	}
	for (int i = 0; i < 20; i++)
		std::cout << "*";
	std::cout << std::endl;

	test.sort();
	for (int i = 0; i < test.size(); i++)
	{
		out = test.at(i);
		std::cout << out.mark << " " << out.suit << std::endl;
	}

	return 0;
}
