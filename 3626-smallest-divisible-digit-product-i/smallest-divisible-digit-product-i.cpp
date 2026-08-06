class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            int val = n;
            int temp = 1;
            while(val) {
                temp *= val % 10;
                val /= 10;
            }
            if (temp % t != 0) {
                n++;
            } else {
                return n;
            }
        }
        return 0;
    }
};