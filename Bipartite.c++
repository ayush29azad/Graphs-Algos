#include <iostream>
using namespace std;
#include<bits/stdc++.h>



class Solution {
  public:
    typedef long long ll;

  bool dfs(ll V, vector< int > adj[], ll c, bool * vis, ll * col) {

    vis[V] = 1;
    col[V] = c;

    for (int i = 0; i < adj[V].size(); i++) {
      if (!vis[adj[V][i]]) {

        if (!dfs(adj[V][i], adj, c ^ 1, vis, col)) {
          return false;
        }

      } else
      if (col[V] == col[adj[V][i]]) {

        return false;

      }

    }
    return true;

  }

  bool isBipartite(ll V, vector < int > adj[]) {

    bool vis[V] = { 0};
    ll col[V];
    bool ans = true;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {

        ans = ans && dfs(i, adj, 0, vis, col);

      }

    }

    return ans;

  }

};