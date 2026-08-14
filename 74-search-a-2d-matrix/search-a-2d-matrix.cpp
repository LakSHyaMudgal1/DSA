class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = (n * m) - 1; // gives the size of the 2d matrix
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (target == matrix[mid / m][mid % m])
                return true;
            if (target > matrix[mid / m][mid % m]) {
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return false;
    }
};