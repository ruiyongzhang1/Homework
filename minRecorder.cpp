#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dfs(int currentx,int dad,vector<vector<pair<int,int>>>&e){
        int ans=0;
        for(auto edge: e[currentx]){
            if(edge.first==dad)continue;
            ans+=edge.second+dfs(edge.first,currentx,e);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>e(n);
        for(auto ei: connections){
            e[ei[0]].push_back(make_pair(ei[1],1));
            e[ei[1]].push_back(make_pair(ei[0],0));
        }
        return dfs(0,-1,e);
    }
};
int main(){
    int n;
    int ans;
    cin>>n;
    vector<vector<int>> connections;
    for (int i = 0; i < n - 1; ++i) {  
        int u, v;  
        cin >> u >> v;  
        connections.push_back({u, v});  
    }  
    Solution myobject;
    ans=myobject.minReorder(n,connections);
    cout<<ans<<endl;
    return 0;
}