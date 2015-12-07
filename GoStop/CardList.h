#ifndef _CARD_LIST_H_
#define _CARD_LIST_H_

#include <stdlib.h>

// 카드 구조체
typedef struct _Card
{
	int id;
	char name[10];

	_Card *lpNext;
} Card;

// 카드 리스트 구조체
typedef struct
{
	Card head;
	Card *tail;
} CardList;


// 카드 리스트를 생성하는 함수
// ※ 생성한 카드 리스트는 반드시 free로 해제해야 한다.
// 반환		카드 리스트
CardList *CreateCardList(void);


// 카드 리스트에 들어있는 카드의 개수를 가져오는 함수
// list		카드 리스트
// 반환		카드의 개수
int GetCardCount(CardList *list);


// 리스트의 모든 원소를 특정 함수에 매칭시켜 출력, 비교 등을 할 수 있게 하는 함수
// list		카드 리스트
// handler	카드 리스트의 원소에 접근할 함수
void ForEachCard(CardList *list, void(*handler)(const Card *));


// 카드 리스트의 끝에 카드를 추가하는 함수
// list		카드 리스트
// card		추가할 카드
void PushCardBack(CardList *list, Card *card);


// 카드 리스트 끝의 카드를 꺼내는 함수 (※ 카드 개수만큼의 시간복잡도를 가짐)
// list		카드 리스트
// 반환		꺼낸 카드 (꺼낼 카드가 없으면 NULL 반환)
Card *PopCardBack(CardList *list);


// 카드 리스트의 맨 앞에 카드를 추가하는 함수
// list		카드 리스트
// card		추가할 카드
void PushCardFront(CardList *list, Card *card);


// 카드 리스트 맨 앞의 카드를 꺼내는 함수
// list		카드 리스트
// 반환		꺼낸 카드 (꺼낼 카드가 없으면 NULL 반환)
Card *PopCardFront(CardList *list);

#endif