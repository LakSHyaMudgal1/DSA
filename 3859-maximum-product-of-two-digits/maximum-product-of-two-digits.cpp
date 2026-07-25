class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n != 0) {
            int val = n % 10;
            n /= 10;
            pq.push(val);
        }

        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        pq.pop();
        return v1 * v2;
    }
};