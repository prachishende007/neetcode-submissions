class Solution {
public:
        typedef pair<int, int> FrequencyPair;

    vector<int> topKFrequent(const vector<int>& numbers, int k) {
        unordered_map<int, int> frequencyMap;
        
        // 1. Count frequencies of each element
        for (int num : numbers) {
            frequencyMap[num]++;
        }

        // 2. Use a min-heap to keep the top K elements
        // The heap sorts by the first element of the pair (frequency) automatically
        priority_queue<FrequencyPair, vector<FrequencyPair>, greater<FrequencyPair>> minHeap;

        for (const auto& [element, count] : frequencyMap) {
            minHeap.push({count, element});
            
            // If heap size exceeds k, pop the element with the lowest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // 3. Extract the elements from the heap into a result vector
        vector<int> topKElements;
        while (!minHeap.empty()) {
            topKElements.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topKElements;
    }
};
