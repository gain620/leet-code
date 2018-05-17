class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniqueId = 0;
        int saveId = 0;
        int prevNum = 0;

        for (auto num : nums)
        {
        	//int initNum = uniqueId;
        	uniqueId ^= num;

        	if (prevNum == uniqueId)
        	{
        		saveId ^= num;
        		prevNum = -1; // init
        	}
        	prevNum = uniqueId;
        }

        uniqueId ^= saveId;
        return uniqueId;
    }
};