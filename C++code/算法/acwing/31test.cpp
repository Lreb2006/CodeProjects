#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> s, t;
ll max_s = 0;

bool check(ll mid) {
    vector<ll> k_max(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] > mid) return false;
        ll k = (mid - s[i]) / t[i];
        k = min(k, (ll)(n - 1));
        k_max[i] = k;
    }
    sort(k_max.begin(), k_max.end());
    for (int i = 0; i < n; ++i) {
        if (k_max[i] < i) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    s.resize(n);
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
        if (s[i] > max_s) max_s = s[i];
    }
    ll l = max_s;
    ll r = 1e18;
    ll ans = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}