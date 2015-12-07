#include "CardList.h"

// 카드 리스트를 생성하는 함수
// ※ 생성한 카드 리스트는 반드시 free로 해제해야 한다.
// 반환		카드 리스트
CardList *CreateCardList(void)
{
	CardList *list = (CardList *) malloc(sizeof(CardList));
	list->head.id = -1;
	list->head.lpNext = NULL;
	list->tail = &list->head;

	return list;
}

// 카드 리스트에 들어있는 카드의 개수를 가져오는 함수
// list		카드 리스트
// 반환		카드의 개수
int GetCardCount(CardList *list)
{
	Card *tmp = &list->head;
	int count = 0;

	// head와 tail이 같으면 노드가 없는 것이므로
	if (&list->head == list->tail)
		return 0;

	while (tmp != list->tail)
	{
		tmp = tmp->lpNext; // 주의: 오류 발생 위험 있음
		count++;
	}

	return count;
}

// 리스트의 모든 원소를 특정 함수에 매칭시켜 출력, 비교 등을 할 수 있게 하는 함수
// list		카드 리스트
// handler	카드 리스트의 원소에 접근할 함수
void ForEachCard(CardList *list, void (*handler)(const Card *))
{
	Card *tmp = &list->head;
	while (tmp != list->tail)
	{
		handler(tmp->lpNext);
		tmp = tmp->lpNext;
	}
}

// 카드 리스트의 끝에 카드를 추가하는 함수
// list		카드 리스트
// card		추가할 카드
void PushCardBack(CardList *list, Card *card)
{
	list->tail->lpNext = card;
	list->tail = card;
	card->lpNext = NULL;
}

// 카드 리스트 끝의 카드를 꺼내는 함수 (※ 카드 개수만큼의 시간복잡도를 가짐)
// list		카드 리스트
// 반환		꺼낸 카드 (꺼낼 카드가 없으면 NULL 반환)
Card *PopCardBack(CardList *list)
{
	if (GetCardCount(list) == 0)
		return NULL;

	Card *tmp = &list->head;
	Card *last = list->tail;

	// tail의 바로 전 노드를 찾는다. tmp: tail의 바로 전 노드
	while (tmp->lpNext != list->tail)
		tmp = tmp->lpNext; // 주의: 오류 발생 위험 있음

	// 마지막 노드와의 논리적 연결을 끊는다.
	list->tail = tmp;
	list->tail->lpNext = NULL;

	return last;
}

// 카드 리스트의 맨 앞에 카드를 추가하는 함수
// list		카드 리스트
// card		추가할 카드
void PushCardFront(CardList *list, Card *card)
{
	// 빈 리스트이면
	if (list->head.lpNext == NULL)
	{
		// 리스트의 head와 card를 논리적으로 연결하고, 리스트의 tail을 card로 지정한다.
		list->head.lpNext = card;
		list->tail = card;
		card->lpNext = NULL;
	}

	else
	{
		// head와 head의 다음 노드 사이에 card를 끼워넣는다.
		Card *tmp = list->head.lpNext;
		list->head.lpNext = card;
		card->lpNext = tmp;
	}
}

// 카드 리스트 맨 앞의 카드를 꺼내는 함수
// list		카드 리스트
// 반환		꺼낸 카드 (꺼낼 카드가 없으면 NULL 반환)
Card *PopCardFront(CardList *list)
{
	if (&list->head == list->tail)
		return NULL;
	else if (list->head.lpNext == list->tail)
		list->tail = &list->head;

	Card *tmp = list->head.lpNext;
	list->head.lpNext = tmp->lpNext;

	return tmp;
}