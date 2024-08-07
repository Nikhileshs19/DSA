class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;
    
        q.push(0);
        visited[0] = true;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
    
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    
        return bfs;
    }
};