// Disjoint Set Union (DSU) data structure
// Source: https://usaco.guide/gold/dsu?lang=cpp

#include <vector>
#include <queue>

template<typename T> constexpr T inf = 0;
template<> constexpr int inf<int> = 1e9;
template<> constexpr long long inf<long long> = 1e18;
template<typename T>
std::vector<T> dijkstra(int s, std::vector<std::vector<std::pair<int,T>>> adj){
    int n=adj.size();
    std::vector<T> dis(n, inf<T>);
    std::vector<int> vis(n);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;
    dis[s]=0, pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]: adj[u]) if(d+w<dis[v]){
            dis[v]=d+w;
            pq.push({dis[v],v});
        }
    }
    return dis;
}
