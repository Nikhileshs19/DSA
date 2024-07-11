class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adjList(V);

    // Iterate over the edges to fill the adjacency list
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        // Since the graph is undirected, add the edge in both directions
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
    }
};