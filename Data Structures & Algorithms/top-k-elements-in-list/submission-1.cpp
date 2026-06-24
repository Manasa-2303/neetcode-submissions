class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto pair : freq){
            int number = pair.first;
            int frequency = pair.second;
            bucket[frequency].push_back(number);
        }
        vector<int> answer;

        for (int i = nums.size(); i >= 1; i--) {
            for (int number : bucket[i]) {
                answer.push_back(number);

                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};
