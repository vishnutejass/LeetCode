class Solution {
public:

    char findTheDifference(string s, string t) {
     
    s=s+t;
    int c=0;
    for(auto x:s){
        c=c^x;
    }
    return c;
    }
};