class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double s = succProb[i];
            g[a].push_back({b, s});
            g[b].push_back({a, s});
        }

        vector<double> d(n, 0.0);
        d[start_node] = 1.0;

        queue<pair<double, int>> q;
        q.push({1.0, start_node});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            double w = p.first;
            int u = p.second;

            if (d[u] > w) continue;

            for (auto& e : g[u]) {
                int v = e.first;
                double t = e.second;

                if (d[v] < d[u] * t) {
                    d[v] = d[u] * t;
                    q.push({d[v], v});
                }
            }
        }

        
        return d[end_node];
    }
};
