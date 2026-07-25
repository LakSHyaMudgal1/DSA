class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int smaxi = 0;

        while(n != 0) {
            int val = n % 10;
            n /= 10;
            if(val >= maxi) {
                smaxi = maxi;
                maxi = val;
            }
            if(val > smaxi && val < maxi) smaxi = val;
        }

        return maxi * smaxi;
    }
};