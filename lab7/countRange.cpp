class Solution {
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        std::vector<long long> prefixSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        return mergeSortAndCount(prefixSum, lower, upper, 0, prefixSum.size() - 1);
    }

private:
    int mergeAndCount(std::vector<long long>& nums, int lower, int upper, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = mid + 1;
        int count = 0;
        std::vector<long long> temp(right - left + 1);

        for (int p = left, q = mid + 1; p <= mid; p++) {
            while (k <= right && nums[k] - nums[p] <= upper)
             k++;
            while (j <= right && nums[j] - nums[p] < lower)
             j++;
            count += k - j;
        }


        for (int p = left, q = mid + 1, r = 0; p <= mid || q <= right; r++) {
            if (p > mid || (q <= right && nums[q] < nums[p]))
                temp[r] = nums[q++];
            else
                temp[r] = nums[p++];
        }

        for (int p = left, r = 0; p <= right; p++, r++)
            nums[p] = temp[r];

        return count;
    }

    int mergeSortAndCount(std::vector<long long>& nums, int lower, int upper, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, lower, upper, left, mid) +
                    mergeSortAndCount(nums, lower, upper, mid + 1, right) +
                    mergeAndCount(nums, lower, upper, left, mid, right);

        return count;
    }
};

