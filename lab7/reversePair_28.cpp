class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, int left, int right) {
    if(left>=right) return 0;
    int mid = (left+right)/2;
    int count = mergeSort(nums,left,mid) + mergeSort(nums,mid+1,right);
    vector<int> tmp(right-left+1);
    int i=left,j=mid+1,k=0;
    while(i<=mid && j<=right)
    {
        if(nums[i] > 2LL * nums[j]) {
            count += mid-i+1;
            j++;
        } else {
            i++;
        }
    }
    i = left, j = mid+1, k = 0;
    while(i<=left && j<= right)
    {
         if(nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
     while(i <= mid) tmp[k++] = nums[i++];
    while(j <= right) tmp[k++] = nums[j++];
    int l = left;
    for(int in = 0; in < k; in++) {
        nums[l++] = tmp[in];
    }
  return count;
}

};
