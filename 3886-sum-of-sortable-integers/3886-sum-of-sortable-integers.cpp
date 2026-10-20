class Solution {
private:
    bool isSortable(const vector<int>& nums, int n, int k) {
        int prevMax = 0;

        for (int start = 0; start < n; start += k) {
            int drops = 0;
            int blockMin = nums[start];
            int blockMax = nums[start];

            // Check circular order within the current block of length k
            for (int i = 0; i < k; i++) {
                int cur = nums[start + i];
                int next = nums[start + (i + 1) % k];

                if (cur > next) {
                    drops++;
                }
                if (cur < blockMin) blockMin = cur;
                if (cur > blockMax) blockMax = cur;
            }

            // A block can be rotated into non-decreasing order iff it has at most 1 circular drop
            if (drops > 1) {
                return false;
            }

            // The elements of the current block must all be >= elements of the previous block
            if (start > 0 && prevMax > blockMin) {
                return false;
            }

            prevMax = blockMax;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Find all divisors k of n
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        // Test each divisor
        for (int k : divisors) {
            if (isSortable(nums, n, k)) {
                totalSum += k;
            }
        }

        return totalSum;
    }
};