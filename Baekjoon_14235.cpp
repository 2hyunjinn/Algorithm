#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);

    int x;
    priority_queue<int> pq;
    while(n--){
        scanf("%d", &x);
        if(x==0){// visit childeren
            if(pq.empty()) {
                printf("-1\n");
                continue;
            }
            int top_=pq.top(); 
            pq.pop();
            printf("%d\n", top_);
        }
        else {
            while(x--){
                int top_;
                scanf("%d", &top_);
                pq.push(top_);
            }
        }
    }
    return 0;
}
