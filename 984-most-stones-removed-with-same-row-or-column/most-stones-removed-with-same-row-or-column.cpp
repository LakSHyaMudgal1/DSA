class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionByRank(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if(ult_v == ult_u) return;
        if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }else if(rank[ult_v] > rank[ult_u]){
            parent[ult_u] = ult_v;
        }else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution {
public:
int removeStones(vector<vector<int>>& stones) {
    int row=0;
    int col=-0;
    for(int i=0;i<stones.size();i++){
      row=max(row,stones[i][0]);
      col=max(col,stones[i][1]);
    }
    int cnt=0;
    unordered_map<int,int>mp;
    DisjointSet d1(row+col+1);
    for(int i=0;i<stones.size();i++){
        d1.unionByRank(stones[i][0],stones[i][1]+row+1);
        mp[stones[i][0]]=1;
        mp[stones[i][1]+row+1]=1;
    }
    for(int i=0;i<(row+col+2);i++){
        if(d1.findParent(i) == i && mp.find(i) != mp.end()){
           cnt++;
        }
    }
    return (stones.size()-cnt);
    }
};