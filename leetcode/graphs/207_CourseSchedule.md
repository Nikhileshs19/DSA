207. Course Schedule
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Hint
     There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses,prerequisites);
        vector<int> degrees = compute(g);
        for(int i=0;i<numCourses;i++){
            int j = 0;
            for(;j<numCourses;j++){
                if(!degrees[j]) break;
            }
            if(j==numCourses) return false;
            degrees[j]--;
            for(int v : g[j]){
                degrees[v]--;
            }
        }
        return true;
    }


private:
    typedef vector<vector<int>> graph;
    graph buildGraph(int num, vector<vector<int>>& prereq){
        graph g(num);
        for(auto p : prereq){
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    vector<int> compute(graph& g){
        vector<int> degrees(g.size(),0);
        for(auto adj : g){
            for(int v : adj){
                degrees[v]++;
            }
        }
        return degrees;
    }
};
```
