#include <stdio.h>
#include <time.h>
#include "CardList.h"

void PrintCard(const Card *card)
{
	printf("%s  ", card->name);
}

int main(void)
{
	// 초기 패 정보
	Card cards[] = {
		{ 1, "1광" },{ 2, "1홍" },{ 3, "1피" },{ 4, "1피2" },
		{ 5, "2고" },{ 6, "2홍" },{ 7, "2피" },{ 8,"2피2" },
		{ 9, "3광" },{ 10, "3홍" },{ 11, "3피" },{ 12, "3피2" },
		{ 13, "4고" },{ 14, "4초" },{ 15, "4피" },{ 16, "4피2" },
		{ 17, "5열끗" },{ 18, "5초" },{ 19, "5피" },{ 20, "5피2" },
		{ 21, "6열끗" },{ 22, "6청단" },{ 23, "6피" },{ 24, "6피2" },
		{ 25, "7열끗" },{ 26, "7초" },{ 27, "7피" },{ 28, "7피2" },
		{ 29, "8광" },{ 30, "8고" },{ 31, "8피" },{ 32, "8피2" },
		{ 33, "9쌍끗" },{ 34, "9청" },{ 35, "9피" },{ 36, "9피2" },
		{ 37, "10열" },{ 38, "10초" },{ 39, "10피" },{ 40, "10피2" },
		{ 41, "11광" },{ 42, "11쌍" },{ 43, "11피" },{ 44, "11피2" },
		{ 45, "12광" },{ 46, "12열" },{ 47, "12초" },{ 48, "12쌍" } };

	int nDust, nSour;
	Card nTemp;
	int i, j;

	CardList *UnopenedCard = CreateCardList(); // 안 깐 패 리스트
	CardList *OpenedCard = CreateCardList();   // 깐 패 리스트
	CardList *PlayerCard[3]; // 플레이어 패
	CardList *PlayerGottenCard[3]; // 플레이어가 딴 패
	for (i = 0; i < 3; i++)
	{
		PlayerCard[i] = CreateCardList();
		PlayerGottenCard[i] = CreateCardList();
	}

	srand(unsigned int(time(NULL)));

	// 패를 섞는다.
	for (i = 0; i < 10000; i++)
	{
		nDust = rand() % 48;
		nSour = rand() % 48;

		nTemp = cards[nDust];
		cards[nDust] = cards[nSour];
		cards[nSour] = nTemp;
	}

	// 섞은 패를 UnopenedCard 리스트에 순서대로 넣는다.
	for (int i = 0; i < 48; i++)
		PushCardBack(UnopenedCard, &cards[i]);

	// 각 플레이어에게 7장씩 나눠준다.
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 7; j++)
			PushCardBack(PlayerCard[i], PopCardBack(UnopenedCard));
	}

	// 패 6장을 바닥에 깐다.
	for (i = 0; i < 6; i++)
		PushCardBack(OpenedCard, PopCardBack(UnopenedCard));

	// 상황을 출력한다.
	for (i = 0; i < 3; i++)
	{
		printf(" %c\t        패) ", 'A' + i);
		ForEachCard(PlayerCard[i], PrintCard);
		printf("\n");

		printf(" (점수: )  딴 화투) ");
		ForEachCard(PlayerGottenCard[i], PrintCard);
		printf("\n\n\n");
	}
	printf(" 깔린 패) ");
	ForEachCard(OpenedCard, PrintCard);
	printf("\n\n\n");

	printf(" 명령 ?\n");

	// 동적할당한 리스트를 해제한다.
	free(UnopenedCard);
	free(OpenedCard);
	for (i = 0; i < 3; i++)
	{
		free(PlayerCard[i]);
		free(PlayerGottenCard[i]);
	}

	return 0;
}