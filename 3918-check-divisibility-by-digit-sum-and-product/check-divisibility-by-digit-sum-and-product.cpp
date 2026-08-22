class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0;
        int val = n;
        while(val) {
          sum += (val % 10);
          prod *= (val % 10);
          val /= 10;  
        }
        return (n % (sum + prod)== 0);
    }
};