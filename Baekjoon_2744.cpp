#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char word[101];
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z')
			printf("%c", word[i] -('A' - 'a'));
		else printf("%c", word[i] + ('A' - 'a'));
	}
	return 0;
}
