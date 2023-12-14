class Solution
{
public:
    int helper(int i, int n, int calculate_money, vector<int> &nums)
    {
        if (i >= n)
            return calculate_money;
        calculate_money += nums[i];
        int aux1 = helper(i + 2, n, calculate_money, nums);
        calculate_money -= nums[i];
        int aux2 = helper(i + 1, n, calculate_money, nums);
        return max(aux1, aux2);
    };
    int rob(vector<int> nums)
    {
        vector<int> freq_arr(401, 0);
        vector<int> temp;
        return this->helper(0, nums.size(), 0, nums);
    }
};
