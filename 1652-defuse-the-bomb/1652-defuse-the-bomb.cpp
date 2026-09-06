class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0)
            return result;

        // k > 0: sum of next k elements
        if (k > 0) {
            int sum = 0;

            for (int i = 1; i <= k; i++)
                sum += code[i % n];

            for (int i = 0; i < n; i++) {
                result[i] = sum;

                // Remove the first element of the window
                sum -= code[(i + 1) % n];

                // Add the next element
                sum += code[(i + k + 1) % n];
            }
        }

        // k < 0: sum of previous -k elements
        else {
            k = -k;
            int sum = 0;

            for (int i = 1; i <= k; i++)
                sum += code[(n - i) % n];

            for (int i = 0; i < n; i++) {
                result[i] = sum;

                // Remove the oldest element
                sum -= code[(i - k + n) % n];

                // Add the current element
                sum += code[i];
            }
        }

        return result;
    }
};
