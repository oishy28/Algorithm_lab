class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;

        // Construct the adjacency list representation of the graph
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
            inDegree[course]++;
        }

        // Perform topological sorting using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            result.push_back(course);

            for (int adjacentCourse : graph[course]) {
                inDegree[adjacentCourse]--;

                if (inDegree[adjacentCourse] == 0) {
                    q.push(adjacentCourse);
                }
            }
        }

        // Check if there is a valid course order
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};
