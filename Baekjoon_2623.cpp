#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int arr[1010];
vector<int> v[1010];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        vector<int> Temp;
        int num; scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            int a; scanf("%d", &a);
            Temp.push_back(a);
        }
        for (int j = 0; j < Temp.size(); j++) {
            for (int k = j + 1; k < Temp.size(); k++) {
                v[Temp[j]].push_back(Temp[k]);
                arr[Temp[k]]++;
            }
        }
    }
}

void solution() {
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) Q.push(i);
    }

    vector<int> Answer;
    while (Q.empty() == 0)
    {
        int Num = Q.front();
        Q.pop();
        Answer.push_back(Num);

        for (int i = 0; i < v[Num].size(); i++) {
            int Next = v[Num][i];
            arr[Next]--;

            if (arr[Next] == 0) Q.push(Next);
        }
    }
    if (Answer.size() != n) printf("0\n");
    else {
        for (int i = 0; i < Answer.size(); i++) printf("%d\n", Answer[i]);
    }
}

int main(void)
{
    input();
    solution();

    return 0;
}
