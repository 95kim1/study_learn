//[boj 10828 : 스택](https://www.acmicpc.net/problem/10828)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node *TOP;
typedef struct _Node {
	int data;
	TOP link;
} Node;

void push(TOP *Top, int n);
int pop(TOP *Top);
int size(TOP Top);
int empty(TOP Top);
int top(TOP Top);
void Delete(TOP Top);

TOP Top = NULL;

int main(void) {
	char opcode[6];
	int N, n;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%s", opcode);

		if (strcmp(opcode, "push") == 0) {
			scanf("%d", &n);
			push(&Top, n);
		}
		else if (strcmp(opcode, "pop") == 0) printf("%d\n", pop(&Top));
		else if (strcmp(opcode, "size") == 0) printf("%d\n", size(Top));
		else if (strcmp(opcode, "empty") == 0) printf("%d\n", empty(Top));
		else if (strcmp(opcode, "top") == 0) printf("%d\n", top(Top));
		else printf("잘못입력하셨습니다.\n");
	}

	Delete(Top);

	return 0;
}

void push(TOP *Top, int n) {
	TOP temp = (Node*)malloc(sizeof(Node));
	temp->data = n; temp->link = NULL;

	if (*Top == NULL) {
		*Top = temp;
		return;
	}

	temp->link = *Top;
	*Top = temp;
}

int pop(TOP *Top) {
	int temp; TOP tempTop;

	if (*Top == NULL) return -1;

	temp = (*Top)->data;

	tempTop = *Top;
	*Top = (*Top)->link;
	free(tempTop);

	return  temp;
}

int size(TOP Top) {
	int i = 0; TOP cur = Top;

	while (cur != NULL) {
		++i;
		cur = cur->link;
	}

	return i;
}

int empty(TOP Top) {
	return (Top == NULL) ? 1 : 0;
}

int top(TOP Top) {
	return (Top == NULL) ? -1 : Top->data;
}

void Delete(TOP Top) {
	int n = size(Top);
	for (int i = 0; i < n; ++i) {
		pop(&Top);
	}
	free(Top);
}

