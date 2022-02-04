#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	char chess[9];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%s", chess);
		for (int j = 0; j < 8; j++) {
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1)))
				if (chess[j] == 'F') cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
