#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	char word[1000001];
	scanf("%[^\n]", word); // 띄어쓰기까지 입력받기

	int i, cnt = 0;
	/* word의 길이만큼 탐색 */
	for (i = 0; i < strlen(word); i++) {
		/* 첫번째와 마지막을 제외하고 공백이 있으면 cnt++ */
		if (word[i] == ' ' && i != 0 && i != strlen(word) - 1)
			cnt++;
	}

	if (strlen(word) < 2 && word[0] == ' ') // 단어가 공백 한글자로만 이뤄졌다면
		printf("0\n"); // 단어의 개수 = 0개
	else // 아니라면
		printf("%d\n", cnt + 1); // 단어의 개수 = ( 공백의 개수 + 1 )
	return 0;
}
