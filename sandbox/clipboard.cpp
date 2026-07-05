class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size(); 
  
        // Pick a starting point 
        for (int i = 0; i < n; i++) 
        { 
            // Initialize sum of current subarray 
            int sum = nums[i]; 
  
            // Try different end points for current 
            // subarray nums[i..j] 
            for (int j = i + 1; j <= n; j++) 
            { 
                // If sum equals k, then increment 
                // count 
                if (sum == k) 
                    count++; 
  
                // Add this element to the sum 
                if (j < n) 
                    sum += nums[j]; 
            } 
        } 
        return count; 
    }
};