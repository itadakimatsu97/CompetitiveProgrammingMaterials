#include <bits/stdc++.h>

using namespace std;

struct X {
    X(int X, int Y): x(X), y(Y){}
    int x, y;
    bool operator<( const X& val ) const { 
        return y > val.y; 
    }
};
int main() {
    priority_queue<X> pq;
    pq.push(X(0, -0));
    pq.push(X(10, -10));
    pq.push(X(2, -2));
    pq.push(X(2, -3));
    pq.push(X(6, -6));
    pq.push(X(5, -5));

    while (!pq.empty()) {
        X temp = pq.top();
        pq.pop();
        printf("%d %d\n", temp.x, temp.y);
    }
    return 0;
}