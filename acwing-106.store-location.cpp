#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int pos = a[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += abs(pos - a[i]);
    cout << ans << endl;
    return 0;
}
