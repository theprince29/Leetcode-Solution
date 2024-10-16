class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
           // Generate the longest string with at most two consecutive instances of the same character when given counts of 'a', 'b', and 'c'
    
        // Define a pair of character and int to store the character and its remaining count
        using CharIntPair = pair<char, int>;

        // Define a custom comparator for the max priority queue that will sort by the second value of the pair in descending order
        auto compare = [](const CharIntPair& x, const CharIntPair& y) { return x.second < y.second; };

        // Create a max priority queue to store the characters and their counts
        priority_queue<CharIntPair, vector<CharIntPair>, decltype(compare)> maxHeap(compare);

        // Add characters to the priority queue if their counts are greater than zero
        if (a > 0) maxHeap.push({'a', a});
        if (b > 0) maxHeap.push({'b', b});
        if (c > 0) maxHeap.push({'c', c});

        string result;

        // Generate the string by using the top element of the priority queue as long as it's not empty
        while (!maxHeap.empty()) {
            CharIntPair current = maxHeap.top();
            maxHeap.pop();

            int length = result.size();
            // Check if the last two characters of the result are the same as the current character
            if (length >= 2 && result[length - 1] == current.first && result[length - 2] == current.first) {
                if (maxHeap.empty()) {
                    // If there are no alternative characters, stop the process as no more characters should be consecutive
                    break;
                }

                // Use the next character in the priority queue since the current character cannot be used due to the consecutive limit
                CharIntPair next = maxHeap.top();
                maxHeap.pop();
                result.push_back(next.first);

                // Decrease the count of the used character and add it back to the queue if it's still greater than zero
                if (--next.second > 0) {
                    maxHeap.push(next);
                }

                // Re-add the current character back to the queue without decrementing its count since it wasn't used
                maxHeap.push(current);
            } else {
                // Add the current character to the result as it’s not forming a triplet and decrement its count
                result.push_back(current.first);
                if (--current.second > 0) {
                    // Only re-add it to the queue if there are more instances of that character available
                    maxHeap.push(current);
                }
            }
        }

        // Return the generated string which is the longest possible string without three consecutive characters being the same
        return result;
    
    }
};