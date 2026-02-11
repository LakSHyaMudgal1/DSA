class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count =1;
        int n = arr.size();
        int maxx =1;
        if(arr.size()==0){
            return 0 ; 
        }
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]==arr[i-1]+1 ){
                count++;
                maxx = max(maxx,count);
            }else{
                count=1;
            }
        }
        return maxx;
    }
};