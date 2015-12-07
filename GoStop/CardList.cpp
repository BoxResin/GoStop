#include "CardList.h"

// ī�� ����Ʈ�� �����ϴ� �Լ�
// �� ������ ī�� ����Ʈ�� �ݵ�� free�� �����ؾ� �Ѵ�.
// ��ȯ		ī�� ����Ʈ
CardList *CreateCardList(void)
{
	CardList *list = (CardList *) malloc(sizeof(CardList));
	list->head.id = -1;
	list->head.lpNext = NULL;
	list->tail = &list->head;

	return list;
}

// ī�� ����Ʈ�� ����ִ� ī���� ������ �������� �Լ�
// list		ī�� ����Ʈ
// ��ȯ		ī���� ����
int GetCardCount(CardList *list)
{
	Card *tmp = &list->head;
	int count = 0;

	// head�� tail�� ������ ��尡 ���� ���̹Ƿ�
	if (&list->head == list->tail)
		return 0;

	while (tmp != list->tail)
	{
		tmp = tmp->lpNext; // ����: ���� �߻� ���� ����
		count++;
	}

	return count;
}

// ����Ʈ�� ��� ���Ҹ� Ư�� �Լ��� ��Ī���� ���, �� ���� �� �� �ְ� �ϴ� �Լ�
// list		ī�� ����Ʈ
// handler	ī�� ����Ʈ�� ���ҿ� ������ �Լ�
void ForEachCard(CardList *list, void (*handler)(const Card *))
{
	Card *tmp = &list->head;
	while (tmp != list->tail)
	{
		handler(tmp->lpNext);
		tmp = tmp->lpNext;
	}
}

// ī�� ����Ʈ�� ���� ī�带 �߰��ϴ� �Լ�
// list		ī�� ����Ʈ
// card		�߰��� ī��
void PushCardBack(CardList *list, Card *card)
{
	list->tail->lpNext = card;
	list->tail = card;
	card->lpNext = NULL;
}

// ī�� ����Ʈ ���� ī�带 ������ �Լ� (�� ī�� ������ŭ�� �ð����⵵�� ����)
// list		ī�� ����Ʈ
// ��ȯ		���� ī�� (���� ī�尡 ������ NULL ��ȯ)
Card *PopCardBack(CardList *list)
{
	if (GetCardCount(list) == 0)
		return NULL;

	Card *tmp = &list->head;
	Card *last = list->tail;

	// tail�� �ٷ� �� ��带 ã�´�. tmp: tail�� �ٷ� �� ���
	while (tmp->lpNext != list->tail)
		tmp = tmp->lpNext; // ����: ���� �߻� ���� ����

	// ������ ������ ���� ������ ���´�.
	list->tail = tmp;
	list->tail->lpNext = NULL;

	return last;
}

// ī�� ����Ʈ�� �� �տ� ī�带 �߰��ϴ� �Լ�
// list		ī�� ����Ʈ
// card		�߰��� ī��
void PushCardFront(CardList *list, Card *card)
{
	// �� ����Ʈ�̸�
	if (list->head.lpNext == NULL)
	{
		// ����Ʈ�� head�� card�� �������� �����ϰ�, ����Ʈ�� tail�� card�� �����Ѵ�.
		list->head.lpNext = card;
		list->tail = card;
		card->lpNext = NULL;
	}

	else
	{
		// head�� head�� ���� ��� ���̿� card�� �����ִ´�.
		Card *tmp = list->head.lpNext;
		list->head.lpNext = card;
		card->lpNext = tmp;
	}
}

// ī�� ����Ʈ �� ���� ī�带 ������ �Լ�
// list		ī�� ����Ʈ
// ��ȯ		���� ī�� (���� ī�尡 ������ NULL ��ȯ)
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