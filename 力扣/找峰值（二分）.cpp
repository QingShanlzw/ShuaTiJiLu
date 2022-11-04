class Solution {
public:
/*
https://www.nowcoder.com/practice/fcf87540c4f347bcb4cf720b5b350c76?tpId=295&tqId=2227748&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
*/
    int findPeakElement(vector<int>& nums) {
        // write code here
        if(nums.size()<=1)return 0;
        int l = 0,r = nums.size()-1;
        while(l<r){
            int mid  =  l + r >> 1;
            if(nums[mid]>nums[mid+1])
                r =  mid;
            else l  = mid+1;    
        }
        return r;
    }
};