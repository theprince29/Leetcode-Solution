class Solution {
public:
     vector<vector<int>> create_adj_list(vector<vector<int>> &graph, int n) {
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && i != j) {
                    adj_list[i].push_back(j);
                }
            }
        }
        return adj_list;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj = create_adj_list(isConnected, n);
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};