class Solution {
public:
    int findPeakElement(vector<int>& arr) {
      int n = arr.size();
      if(n == 1) return 0;
      if(arr[0]>arr[1]) return 0;
      if(arr[n-1]>arr[n-2]) return n-1;
    //   if 1st or last elements are not peak   now i am checking others
      int low =1,high = n-2;
       
      while(low<=high){
       int mid = (low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]<arr[mid-1] ) {
             //checking whether mid is in decresing curve
            //  then defientily the peak element wont be after mid value 
            high = mid-1;
      }
      else //checking whether mid is in increasing curve ,if yes we will trim the before mid values
        low = mid+1;
      
      } 
      
     
    
      return -1;    
    }
   
};

// class Solution {
// public:
//     int findPeakElement(vector<int>& arr) {
//         int n = arr.size();
//         if (n == 0) return -1; // handle empty array
//         if (n == 1) return 0;  // handle single element array
//         if (arr[0] > arr[1]) return 0; // check if the first element is a peak
//         if (arr[n-1] > arr[n-2]) return n-1; // check if the last element is a peak

//         // if the first or last elements are not peaks, check others
//         int low = 1, high = n - 2; // adjust boundaries to not include already checked first and last elements
//         while (low <= high) {
//             int mid = low + (high - low) / 2; // avoid potential overflow
//             if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
//                 return mid;
//             }
//             else if (arr[mid] < arr[mid - 1]) {
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }
//         return -1;
//     }
// };
