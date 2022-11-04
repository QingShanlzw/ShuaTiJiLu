/*
2022/11/4
二分
技巧是利用归并排序的特点。
*/
const int N = 1e6+7;
const int mod  =  1000000007;
class Solution {
public:   
    int res = 0;
    int temp[N];
    int InversePairs(vector<int> data) {        
        mergeSort(data,0,data.size()-1);
        return res%mod;
    }
    void mergeSort(vector<int>&data,int l,int r){
        if(l>=r)return;
        int mid =  l + r >> 1;
        mergeSort(data,l,mid);
        mergeSort(data,mid+1,r);
        int k  =0,i = l,j = mid+1;
        while(i<=mid&&j<=r){
            if(data[i]<=data[j])temp[k++] = data[i++];
            else {
                res+=(mid-i+1);
                res%=mod;
                temp[k++] = data[j++];
            }
        }
        while(i<=mid)temp[k++] = data[i++];
        while(j<=r)temp[k++]  =data[j++];
        for(i = l,k=0;i<=r;i++,k++)data[i] =temp[k];
    }
};