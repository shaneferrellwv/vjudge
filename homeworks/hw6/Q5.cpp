class Solution {
 public:
	int maxSatisfaction(vector<int>& satisfaction) {
		sort(satisfaction.rbegin(), satisfaction.rend());
        
		/*
        for(int i = 0; i < satisfaction.size(); i++) {
            cout << satisfaction[i] << " ";
        }*/
        
		int total = 0, res = 0, curr = 0;

		for (int i = 0; i < satisfaction.size(); i++) {
			curr += satisfaction[i];
			if (curr > 0) {
				res += curr;
			}
			else {
				break;
			}
		}
		return res;
        
	}
};