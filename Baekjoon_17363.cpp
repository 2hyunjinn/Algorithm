#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
void print_aya(char w) {
	if (w == '.')
		printf(".");
	else if (w == 'O')
		printf("O");
	else if (w == '-')
		printf("|");
	else if (w == '|')
		printf("-");
	else if (w == '/')
		printf("\\");
	else if (w == '\\')
		printf("/");
	else if (w == '^')
		printf("<");
	else if (w == '<')
		printf("v");
	else if (w == 'v')
		printf(">");
	else if (w == '>')
		printf("^");
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	char word[100][100];
	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}

	for (int i = m-1; i >= 0; i--) { // 맨 뒷줄 부터 탐색
		for (int k = 0; k < n; k++) {
			print_aya(word[k][i]); // 문자 자체를 왼쪽으로 돌리기
		}
		printf("\n");
	}
	return 0;
}
