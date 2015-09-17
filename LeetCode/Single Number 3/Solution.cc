class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            vector<int> retVal;
            int res = 0;
            int size = nums.size();
            for(int i=0;i<size;i++) {
                res ^= nums[i];
            }
            int bit = 0;
            int cmp = 1;
            for(bit = 0; bit < 64; bit++) {
                cmp = 1 << bit;
                if((cmp & res) != 0) break;
            }
            cmp = 1 << bit;
            int a = 0;
            int b = 0;
            for(int i=0;i<size;i++) {
                if((nums[i] & cmp) != 0) a ^= nums[i];
                else b ^= nums[i];
            }
            retVal.push_back(a);
            retVal.push_back(b);
            return retVal;
        }
}
