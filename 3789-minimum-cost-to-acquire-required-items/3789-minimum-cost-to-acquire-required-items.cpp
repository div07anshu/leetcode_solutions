using ll = long long;
class Solution {
public:
    long long minimumCost(ll c1, ll c2, ll cb, ll n1, ll n2) {
        long long x = min(n1, n2);
        long long cst1 = n1 * c1 + n2 * c2;
        long long cst2 = x * cb + (n1 - x) * c1 + (n2 - x) * c2;
        long long cst3 = max(n1, n2) * cb;

        return min({cst1, cst2, cst3});
    }
};