class Solution {
public:
    int findMin(vector<int>& arr) {
        int minn =INT_MAX;
        int low =0; int high = arr.size()-1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            
             if(arr[low]<=arr[high]){
                minn = min(arr[low],minn);
                break;
            }
           
            if(arr[low]<=arr[mid]){
                minn = min(minn,arr[low]);
                low=mid+1;
            }
            else{
                minn = min(arr[mid],minn);
                high = mid-1;
            }
        }
       return minn;
        }
};