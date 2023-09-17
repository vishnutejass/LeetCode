class Solution {
public:
   
//    example for dry run   graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//    =>connections
//    0  [1]
//    1  [0,2,4]
//    2  [1,3,4]
//    3  [2]
//    4  [1,2]

   int solve(vector<vector<int>>&g){
       int n=g.size();
       int all= (1<<n)-1 ; //mask eg: 11111

       queue<pair<int,pair<int,int>>>q;
       set<pair<int,int>>vis;

       for(int i=0;i<n;i++){   //insert mask and dist as 0 and node in to queue

           int mask= (1<<i);
           q.push({i,{0,mask}});
           vis.insert({i,mask});

       }

       while(!q.empty()){
           auto node=q.front();
           q.pop();

           int val=node.first, dist=node.second.first , mask=node.second.second;

           for(auto nbr:g[val]) {  //iterating through every nodes neighbors  eg:0 will iterates to its neighbor 1
             
             int newmask = (mask|(1<<nbr));  //updates mask as it is visited the nbr 1
             
             if(newmask==all)
             return dist+1;

             else if(vis.count({nbr,newmask})){
                 continue;
             }

             else{
                 q.push({nbr,{dist+1,newmask}});
                 vis.insert({nbr,newmask});

             }

           }
           
       }
   return 0;
   }
      
   
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
        return 0;

        return solve(graph);
    }
};