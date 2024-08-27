class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Graph representation: adjacency list with node and probability pairs
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double s = succProb[i];
            g[a].push_back({b, s});
            g[b].push_back({a, s});
        }

        // Distance (probability) array initialized to 0
        vector<double> d(n, 0.0);
        d[start_node] = 1.0;

        // Priority queue for BFS/DFS, starting with the start node
        queue<pair<double, int>> q;
        q.push({1.0, start_node});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            double w = p.first;
            int u = p.second;

            // If current probability is less than recorded, skip
            if (d[u] > w) continue;

            // Traverse neighbors
            for (auto& e : g[u]) {
                int v = e.first;
                double t = e.second;

                // If the path through u offers a higher probability, update and push to queue
                if (d[v] < d[u] * t) {
                    d[v] = d[u] * t;
                    q.push({d[v], v});
                }
            }
        }

        // Return the max probability to reach end_node
        return d[end_node];
    }
};
