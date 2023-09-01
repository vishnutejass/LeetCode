
#include <unordered_map>
#include <cmath>
#include <vector>

class Solution {
public:
  int check(int n) {
    int cnt = 0;
    while (n != 0) {
        n &= (n - 1);  
        cnt++;
    }
    return cnt;
}

    
    std::vector<int> countBits(int n) {
        std::vector<int> arr(n + 1);
        std::vector<int> a;
        for(int i = 0; i <= n; i++) {
            arr[i] = check(i);
            a.push_back(arr[i]);
        }
        return a;
    }
};





















// #include<unordered_map>
// #include<cmath>
// class Solution {
// public:
//     int check(int n){
//         int x,cnt=0;
//         while(n!=0){
            
//         for(int i=0;i<n;i++){
//            if(pow(2,i)<n){
//                x=pow(2,i);
//                break;
//            }
//         }  
//           n=n-x;
//             cnt++;   
//         }
//         return cnt;
//     }
    
//     vector<int> countBits(int n) {
//         int arr[n];
//         vector<int>a;
//         for(int i=0;i<=n;i++){
            
//             arr[i]=check(i);
//             a.push_back(arr[i]);
//         }
    
//     return a;
//     }
// };