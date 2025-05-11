#pragma once
//�����ƺźͻ�ɫö��
enum mark { THREE=1, FOUR=2, FIVE=3, SIX=4, SEVEN=5, EIGHT=6, NINE=7, TEN=8, JACK=9, QUEEN=10, KING=11, ACE=12 , TWO=13 , JOKER=14};   //�ƺ�
enum suit { CLUB=1, DIAMOND=2, HEART=3, SPADE=4 , SMALL =5,BIG=6};   //��ɫ
struct card   //������
{          
	mark mark;
	suit suit;
};

/*����һ����ſ����б�Ļ���
 *���ϸ�Ҫ�󳤶�ƥ�䣬���ϸ��ճ��Ƚ��г�ʼ�������ڽ��г��ȵĹ��죬���Զ�������б�
 *���������Զ��������б���Ҫ�ֶ�����
 *���������κ���Ҫ���б�ĵط�
 *������˳��ģ����Խ�������Ȳ���
 *������һ���İ�ȫ�Լ�飬������֤���԰�ȫ
*/
class basic_card_list
{
	private:
		int list_size;  //����
		card* card_list;  //���б�ָ��
	public:
		basic_card_list();//���캯��
		basic_card_list(int size);//���г��ȵĹ���
		//basic_card_list(card* list);//�Զ�����
		basic_card_list(int size, card* list);//�Զ��幹��
		basic_card_list(const basic_card_list& other);//��������
		basic_card_list& operator=(const basic_card_list& other);//������ֵ
		virtual ~basic_card_list();//����������
		card at(int index) const;//��ȡָ��λ�õ���
		card begin() const;//��ȡ��һ����
		card end() const;//��ȡ���һ����
		int size() const;//��ȡ����
		bool empty() const;//�ж��б��Ƿ�Ϊ��
		void push_back(card card);//��ĩβ�����
		void pop_back();//ɾ��ĩβ����
		void clear();//����б�
		void sort(); //����
		void random_shuffle(); //��������б�
		card operator[](int index) const;//�±����
		basic_card_list& operator+=(const card& card);//�б�ĩβ�����
		basic_card_list operator+(const basic_card_list& other);//�б�ϲ�
		basic_card_list& operator<<(const card& card);//����Ƶ��б�ĩβ
};

