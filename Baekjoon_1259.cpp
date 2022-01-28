#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	while(1){
    string input;
		int flag = 0, i;
		cin >> input;
		if (input == "0")
			break;
		for (i = 0; i < input.length() / 2; i++) {
			if (input[i] != input[input.length() - i - 1]) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
