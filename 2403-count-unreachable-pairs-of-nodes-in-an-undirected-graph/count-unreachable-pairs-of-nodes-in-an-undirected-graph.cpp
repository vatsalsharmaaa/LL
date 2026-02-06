class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y){
            return ;
        }
        else if(parent_x!=parent_y){
            if(rank[parent_y]<rank[parent_x]){
                parent[parent_y]=parent_x;
            }
            else if(rank[parent_y]>rank[parent_x]){
                  parent[parent_x]=parent_y;
            }
            else{
                parent[parent_x]=parent_y;
                rank[parent_y]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for(auto x:edges){
           int nx=find(x[0]);
            int ny=find(x[1]);

            Union(nx,ny);
            
        }
        //map mai size of component store krlete h ki 0 parent wale kitne h 1 parent wale kitne h
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int papa= find(i);
            mp[papa]++;
        }
        long long result=0;
        long long rem_nodes=n;

        for(auto x: mp){
            long long size=x.second;
            result+=(size)*(rem_nodes - size);
            rem_nodes-=size;

        }
        return result;
    }
};