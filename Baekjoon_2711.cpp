#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char word[81];
		int idx;
		scanf("%d ", &idx);
		scanf("%s", word);

		for (int j = 0; j < strlen(word); j++) {
			if (j != idx - 1)
				printf("%c", word[j]);
		}
		printf("\n");
	}
	return 0;
}
