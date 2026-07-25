class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;

        while (n != 0) {
            pq.push(n % 10);
            n = n / 10;
        }

        int top = pq.top();
        pq.pop();
        int sec = pq.top();

        return top * sec;
    }
};