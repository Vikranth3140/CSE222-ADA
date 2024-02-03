#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> dp(1e6+11, 0);
    dp[a[0]] = 1;
    ll l = 0;
    for(ll r = 1; r < n; r++) {
        while(2*a[l] < a[r]) l++;
        dp[a[r]] = 1;
        dp[a[r] - a[l]] = 1;
    }
    for(ll r = n-1; r >= l; r--) dp[a[r] - a[l]] = 1;
    for(ll i = 1; i < dp.size(); i++) dp[i] += dp[i-1];
    while(q--) {
        ll s;
        cin >> s;
        cout << (dp[s] ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}