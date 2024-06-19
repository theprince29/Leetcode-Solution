class Solution {
public:
   int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    // Combine difficulty and profit into a single list of pairs and sort by difficulty
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); ++i) {
        jobs.emplace_back(difficulty[i], profit[i]);
    }
    sort(jobs.begin(), jobs.end());

    // Sort the worker array
    sort(worker.begin(), worker.end());

    int totalProfit = 0;
    int j = 0;
    priority_queue<int> maxHeap;

    // Iterate over each worker
    for (int ability : worker) {
        // Push all jobs that this worker can do into the maxHeap
        while (j < jobs.size() && ability >= jobs[j].first) {
            maxHeap.push(jobs[j].second);
            ++j;
        }
        // Add the best available profit for this worker to the total profit
        if (!maxHeap.empty()) {
            totalProfit += maxHeap.top();
        }
    }

    return totalProfit;
}
};