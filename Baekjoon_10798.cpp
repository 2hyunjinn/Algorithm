#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
char word[5][16];

void input() {
    for (int i = 0; i < 5; i++)
        scanf("%s", word[i]);
}

void print_length() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if ((word[j][i] >= 'a' && word[j][i] <= 'z')
                || (word[j][i] >= 'A' && word[j][i] <= 'Z')
                || (word[j][i] >= '0' && word[j][i] <= '9'))
                printf("%c", word[j][i]);
        }
    }
}

int main()
{
    input();
    print_length();
    return 0;
}
