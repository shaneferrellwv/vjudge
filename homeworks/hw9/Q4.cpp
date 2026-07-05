class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        deque<int> q;
        vector<int> result;

        while(j < n)
        {
            while(!q.empty() && q.back() < nums[j])
            {
                q.pop_back();
            }
            q.push_back(nums[j]);

            if(j - i + 1 == k)
            {
                int front = q.front();
                if(nums[i] == front)
                {
                    q.pop_front();
                }
                result.push_back(front);
                i++;
            }
            j++;
        }
        return result;
    }
};