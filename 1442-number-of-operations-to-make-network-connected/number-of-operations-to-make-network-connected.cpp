class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int x){
        if(parent[x] == x) return x;
        return parent[x] = findUPar(parent[x]);
    }
    void unionByRank(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(rank[ult_v] > rank[ult_u]){
            parent[ult_u] = ult_v;
        }else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }else{
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
    void unionBySize(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }
};


class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet A(n);
        int extra = 0;
        int ans = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(A.findUPar(u) == A.findUPar(v)){
                extra++;
            }else{
                A.unionBySize(u,v);
            }
        }
        for(int i = 0;i < n; i++){
            if(A.parent[i] == i){
                ans++;
            }
        }
        if(ans-1 <= extra) return ans-1;
        return -1;

    }
};