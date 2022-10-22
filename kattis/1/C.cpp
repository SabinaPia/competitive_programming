#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010000;
long long n, m;
long long a[maxn];

int main() {
	
    while(cin >> n >> m) {
        if(n == m && n == 0)
            break;
        long long x, cnt = 0;
        memset(a, 0, sizeof(a));
        for(long long i = 0; i < n; i++) {
            cin >> x;
            a[x] = 1;
        }
        for(long long i = 0; i < m; i++) {
            cin >> x;
            if(a[x])
                cnt++;
        }
        cout << cnt << endl;
    }
}
