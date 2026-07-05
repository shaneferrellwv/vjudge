class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // edge cases
        // array is one element
        if (nums.size() == 1)
        {
            return 0;
        }
        // peak is first element
        else if(nums[0] > nums[1])
        {
            return 0;
        }
        // peak is last element
        else if (nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            return nums.size() - 1;
        }

        while (left <= right)
        {
            mid = (left + right) / 2;

            // if mid is a peak element
            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
            {
                return mid;
            }
            // if slope increasing
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            // if slope decreasing
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};