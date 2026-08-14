class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0;
        int n = arr.size();
        int high = n - 1;
        int ans = -1;
        if (n == 1)
            return 0;
        if (n == 2)
            return arr[0] > arr[1] ? 0 : 1;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;
        low = 1;
        high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid + 1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};