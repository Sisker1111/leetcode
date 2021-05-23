class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return nums.size();
        }
        int number=nums[0];
        int idx=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==number ){
                nums.erase(nums.begin()+idx);
                i--;
            } 
            else{
                number=nums[i];
                idx++;
            }
                
        }
        return nums.size();
    }
};

