class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsUtil(int node, vector<int> adj[], vector<bool>& visited, vector<int>& dfs) {
        stack<int> s;
        s.push(node);

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                dfs.push_back(curr);

                // Push adjacent vertices in reverse order to maintain order
                for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<bool> visited(V, false);

        // Start DFS from vertex 0
        dfsUtil(0, adj, visited, dfs);

        return dfs;
    }
};