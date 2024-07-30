class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0; int high = arr.size()-1;
        int mid ;
        int minn = INT_MAX;
       
        while(low<=high){
            mid = (low+high)/2;
            if(arr[mid] == arr[low] && arr[mid] == arr[high]){
                minn = min(minn, arr[low]);
                low++;
                high--;
                continue;
            }
            if(arr[low]<=arr[mid]){
                 minn = min(minn,arr[low]);
                 low = mid+1;
            }
            else{
                minn = min(arr[mid],minn);
                high = mid-1;
            }
        }
        return minn;
    }
};