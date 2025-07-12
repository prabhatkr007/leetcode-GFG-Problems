
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        
        // Build the graph and calculate the indegree of each course
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }
        
        queue<int> q;
        
        // Add courses with indegree 0 to the queue
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0)
                q.push(course);
        }
        
        // Perform BFS
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            numCourses--; // Decrement the number of courses
            
            // Decrement the indegree of neighboring courses and add them to the queue if their indegree becomes 0
            for (int neighbor : graph[current]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // If all courses are visited, return true; otherwise, return false
        return numCourses == 0;
    }
};
