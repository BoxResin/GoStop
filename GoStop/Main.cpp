#include <stdio.h>
#include <time.h>
#include "CardList.h"

void PrintCard(const Card *card)
{
	printf("%s  ", card->name);
}

int main(void)
{
	// �ʱ� �� ����
	Card cards[] = {
		{ 1, "1��" },{ 2, "1ȫ" },{ 3, "1��" },{ 4, "1��2" },
		{ 5, "2��" },{ 6, "2ȫ" },{ 7, "2��" },{ 8,"2��2" },
		{ 9, "3��" },{ 10, "3ȫ" },{ 11, "3��" },{ 12, "3��2" },
		{ 13, "4��" },{ 14, "4��" },{ 15, "4��" },{ 16, "4��2" },
		{ 17, "5����" },{ 18, "5��" },{ 19, "5��" },{ 20, "5��2" },
		{ 21, "6����" },{ 22, "6û��" },{ 23, "6��" },{ 24, "6��2" },
		{ 25, "7����" },{ 26, "7��" },{ 27, "7��" },{ 28, "7��2" },
		{ 29, "8��" },{ 30, "8��" },{ 31, "8��" },{ 32, "8��2" },
		{ 33, "9�ֲ�" },{ 34, "9û" },{ 35, "9��" },{ 36, "9��2" },
		{ 37, "10��" },{ 38, "10��" },{ 39, "10��" },{ 40, "10��2" },
		{ 41, "11��" },{ 42, "11��" },{ 43, "11��" },{ 44, "11��2" },
		{ 45, "12��" },{ 46, "12��" },{ 47, "12��" },{ 48, "12��" } };

	int nDust, nSour;
	Card nTemp;
	int i, j;

	CardList *UnopenedCard = CreateCardList(); // �� �� �� ����Ʈ
	CardList *OpenedCard = CreateCardList();   // �� �� ����Ʈ
	CardList *PlayerCard[3]; // �÷��̾� ��
	CardList *PlayerGottenCard[3]; // �÷��̾ �� ��
	for (i = 0; i < 3; i++)
	{
		PlayerCard[i] = CreateCardList();
		PlayerGottenCard[i] = CreateCardList();
	}

	srand(unsigned int(time(NULL)));

	// �и� ���´�.
	for (i = 0; i < 10000; i++)
	{
		nDust = rand() % 48;
		nSour = rand() % 48;

		nTemp = cards[nDust];
		cards[nDust] = cards[nSour];
		cards[nSour] = nTemp;
	}

	// ���� �и� UnopenedCard ����Ʈ�� ������� �ִ´�.
	for (int i = 0; i < 48; i++)
		PushCardBack(UnopenedCard, &cards[i]);

	// �� �÷��̾�� 7�徿 �����ش�.
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 7; j++)
			PushCardBack(PlayerCard[i], PopCardBack(UnopenedCard));
	}

	// �� 6���� �ٴڿ� ���.
	for (i = 0; i < 6; i++)
		PushCardBack(OpenedCard, PopCardBack(UnopenedCard));

	// ��Ȳ�� ����Ѵ�.
	for (i = 0; i < 3; i++)
	{
		printf(" %c\t        ��) ", 'A' + i);
		ForEachCard(PlayerCard[i], PrintCard);
		printf("\n");

		printf(" (����: )  �� ȭ��) ");
		ForEachCard(PlayerGottenCard[i], PrintCard);
		printf("\n\n\n");
	}
	printf(" �� ��) ");
	ForEachCard(OpenedCard, PrintCard);
	printf("\n\n\n");

	printf(" ��� ?\n");

	// �����Ҵ��� ����Ʈ�� �����Ѵ�.
	free(UnopenedCard);
	free(OpenedCard);
	for (i = 0; i < 3; i++)
	{
		free(PlayerCard[i]);
		free(PlayerGottenCard[i]);
	}

	return 0;
}