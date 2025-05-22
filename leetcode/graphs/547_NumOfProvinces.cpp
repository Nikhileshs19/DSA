class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        int provinceCount = 0;
      
        bool visited[cities];
        std::memset(visited, false, sizeof(visited));
      
        std::function<void(int)> dfs = [&](int cityIndex) {
            visited[cityIndex] = true;
          
            for (int j = 0; j < cities; ++j) {
                if (!visited[j] && isConnected[cityIndex][j]) {
                    dfs(j);
                }
            }
        };
      
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                dfs(i); 
                ++provinceCount;
            }
        }
      
        return provinceCount;
    }
};