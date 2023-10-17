class Solution {
    bool util(vector<int> adj[],vector<bool> &vis,vector<bool> &st_vis,int u){
        vis[u] = true;
        st_vis[u] = true;
        for(auto v:adj[u]){
            if(!vis[v]){
                if(util(adj,vis,st_vis,v))
                    return true;
            }else{
                if(st_vis[v])
                    return true;
            }
        }
        st_vis[u] = false;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false),st_vis(V,false);
        vector<int> ans;
        for(int i = 0;i < V; i++){
            if(!vis[i]){
                util(adj,vis,st_vis,i);
            }
        }
        for(int i=0;i<V;i++){
            if(!st_vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};