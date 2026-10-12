
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        vector<int> bits(32, 0);

        // Count set bits at each position
        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1LL << b)) {
                    bits[b]++;
                }
            }
        }

        long long ans = 0;

        // Construct the largest possible numbers
        for (int i = 0; i < k; i++) {
            long long value = 0;

            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    value |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + value * value) % MOD;
        }

        return ans;
    }
};
