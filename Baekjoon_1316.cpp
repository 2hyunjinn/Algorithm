#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int n, cnt = 0;
	scanf("%d", &n); // 단어의 개수 입력

	/* 단어의 개수만큼 반복문 */
	for (int i = 0; i < n; i++) {
		char word[101];
		scanf("%s", word); // 단어 입력

		int alpha[26] = { 0, }; // 나왔던 문자인지 판단하기 위해
		int flag = 0;
		for (int j = 0; j < strlen(word); j++) {
			if (alpha[word[j] - 'a'] == 1) { // 이미 나왔던 문자라면
				if (word[j] != word[j - 1]) { // 바로 전 문자와 같지 않다면
					flag = 1; // 그룹 단어 아니기 때문에 탈출
					break;
				}
			}
			else alpha[word[j] - 'a'] = 1; // 나온 문자라고 바꾸기
		}
		if (flag == 0) // 그룹단어라면 cnt++
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
