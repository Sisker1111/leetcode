class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
            if(temp == nums[i]){
                count++;
                if(count > nums.size()/2)
                    return temp;
            }
            else{
                temp = nums[i];
                count = 1;
            }
        }
        return temp;
    }
};