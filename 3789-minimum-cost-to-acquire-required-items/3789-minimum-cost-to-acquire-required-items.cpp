using ll = long long;
class Solution {
public:
    long long minimumCost(ll c1, ll c2, ll cb, ll n1, ll n2) {
        ll x = min(n1, n2);
        ll cst1 = n1 * c1 + n2 * c2;
        ll cst2 = x * cb + (n1 - x) * c1 + (n2 - x) * c2;
        ll cst3 = max(n1, n2) * cb;

        return min({cst1, cst2, cst3});
    }
};