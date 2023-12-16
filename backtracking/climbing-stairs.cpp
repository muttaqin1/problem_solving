void get_stair_paths(int n, vector<int> temp, vector<vector<int>> &res)
{
    if (n == 0)
    {
        res.push_back(temp);
        return;
    }
    else if (n < 0)
        return;
    temp.push_back(1);
    get_stair_paths(n - 1, temp, res);
    temp.pop_back();
    temp.push_back(2);
    get_stair_paths(n - 2, temp, res);
    temp.pop_back();
}
