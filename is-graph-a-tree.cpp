/*
GIVEN AN UNDIRECTED GRAPH YOU ARE REQUIRED TO FIND IF IT IS A TREE OR NOT ? n is no of edges , m is no of vertices adj is the adjacency matrix
*/
int isTree(int n, int m, vector<vector<int>> &adj) {
          vector<vector<int>>a(n+1);
          for(auto x:adj){
                    a[x[0]].push_back(x[1]);
                    a[x[1]].push_back(x[0]);
                   
                    }
    vector<int>vis(n,0);
    queue<pair<int,int>>q;
    q.push({0,-1});
    vis[0]=1;
    while(q.size()){
        auto temp=q.front();
        q.pop();
        for(auto it:a[temp.first]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,temp.first});
            }
            else{
                if(it!=temp.second)return 0;
            }
            
        }
        
    }
    for(int i=0;i<n;i++){
        if(!vis[i])return 0;
    }return 1;}
