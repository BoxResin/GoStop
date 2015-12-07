#ifndef _CARD_LIST_H_
#define _CARD_LIST_H_

#include <stdlib.h>

// ī�� ����ü
typedef struct _Card
{
	int id;
	char name[10];

	_Card *lpNext;
} Card;

// ī�� ����Ʈ ����ü
typedef struct
{
	Card head;
	Card *tail;
} CardList;


// ī�� ����Ʈ�� �����ϴ� �Լ�
// �� ������ ī�� ����Ʈ�� �ݵ�� free�� �����ؾ� �Ѵ�.
// ��ȯ		ī�� ����Ʈ
CardList *CreateCardList(void);


// ī�� ����Ʈ�� ����ִ� ī���� ������ �������� �Լ�
// list		ī�� ����Ʈ
// ��ȯ		ī���� ����
int GetCardCount(CardList *list);


// ����Ʈ�� ��� ���Ҹ� Ư�� �Լ��� ��Ī���� ���, �� ���� �� �� �ְ� �ϴ� �Լ�
// list		ī�� ����Ʈ
// handler	ī�� ����Ʈ�� ���ҿ� ������ �Լ�
void ForEachCard(CardList *list, void(*handler)(const Card *));


// ī�� ����Ʈ�� ���� ī�带 �߰��ϴ� �Լ�
// list		ī�� ����Ʈ
// card		�߰��� ī��
void PushCardBack(CardList *list, Card *card);


// ī�� ����Ʈ ���� ī�带 ������ �Լ� (�� ī�� ������ŭ�� �ð����⵵�� ����)
// list		ī�� ����Ʈ
// ��ȯ		���� ī�� (���� ī�尡 ������ NULL ��ȯ)
Card *PopCardBack(CardList *list);


// ī�� ����Ʈ�� �� �տ� ī�带 �߰��ϴ� �Լ�
// list		ī�� ����Ʈ
// card		�߰��� ī��
void PushCardFront(CardList *list, Card *card);


// ī�� ����Ʈ �� ���� ī�带 ������ �Լ�
// list		ī�� ����Ʈ
// ��ȯ		���� ī�� (���� ī�尡 ������ NULL ��ȯ)
Card *PopCardFront(CardList *list);

#endif