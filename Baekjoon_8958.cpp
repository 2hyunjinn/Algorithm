#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	char word[80];
	
	while (n--) {
		scanf("%s", word);
		getchar();
		int cnt = 0, sum = 0;
		for (int i = 0; i < strlen(word); i++) {
			if (word[i] == 'X') {
				cnt = 0;
				continue;
			}
			sum += ++cnt;
		}
		printf("%d\n", sum);
	}
	return 0;
}
