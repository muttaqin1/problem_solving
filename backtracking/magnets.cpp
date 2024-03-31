#include <bits/stdc++.h>
using namespace std;
// tested
bool is_first_square_empty(char position, int row, int col, vector<vector<char>> &maze)
{
    switch (position)
    {

    case 'B':
    {
        if (maze[row - 1][col] == '_')
            return true;
        else
            return false;
    }
    case 'R':
    {
        if (maze[row][col - 1] == '_')
            return true;
        else
            return false;
    }
    default:
        return false;
    }
}

// tested
bool matched_neighbouring_cells(char symbol, int row, int col, vector<vector<char>> &maze)
{
    if (symbol == '_')
        return false;
    // check top cell.
    if (maze[row - 1][col] == symbol)
        return true;
    // check left cell.
    if (maze[row][col - 1] == symbol)
        return true;
    return false;
}

// tested
bool validate_slot(int row, int col, vector<int> &arr1, vector<int> &arr2)
{
    int first_val = arr1[col];
    int second_val = arr2[row];
    if (first_val > 0 && second_val > 0)
        return true;
    else if (first_val == -1 && second_val > 0 || first_val > 0 && second_val == -1)
        return true;
    else if (first_val == -1 && second_val == -1)
        return true;
    else
        return false;
}

bool is_valid_for_plus(int row, int col, vector<vector<char>> &maze, vector<int> &top, vector<int> &left)
{
    const char sym = '+';
    if (matched_neighbouring_cells(sym, row, col, maze))
        return false;
    switch (maze[row][col])
    {
    case 'T':
    {
        if (validate_slot(row, col, top, left))
            return true;
        else
            return false;
    }
    case 'B':
    {
        // the first square will be - or _.
        if (is_first_square_empty(maze[row][col], row, col, maze))
            return false;
        // the first square will be -
        if (validate_slot(row, col, top, left))
            return true;
        else
            return false;
    }
    case 'L':
    {
        if (validate_slot(row, col, top, left))
            return true;
        else
            return false;
    }
    case 'R':
    {
        // the first square will be - or _.
        if (is_first_square_empty(maze[row][col], row, col, maze))
            return false;
        // the first square will be -
        if (validate_slot(row, col, top, left))
            return true;
        else
            return false;
    }
    default:
        return false;
    }
}

bool is_valid_for_minus(int row, int col, vector<vector<char>> &maze, vector<int> &bottom, vector<int> &right)
{
    const char sym = '-';
    if (matched_neighbouring_cells(sym, row, col, maze))
        return false;
    switch (maze[row][col])
    {
    case 'T':
    {
        if (validate_slot(row, col, bottom, right))
            return true;
        else
            return false;
    }
    case 'B':
    {
        // the first square will be - or _.
        if (is_first_square_empty(maze[row][col], row, col, maze))
            return false;
        // the first square will be -
        if (validate_slot(row, col, bottom, right))
            return true;
        else
            return false;
    }
    case 'L':
    {
        if (validate_slot(row, col, bottom, right))
            return true;
        else
            return false;
    }
    case 'R':
    {
        // the first square will be - or _.
        if (is_first_square_empty(maze[row][col], row, col, maze))
            return false;
        // the first square will be -
        if (validate_slot(row, col, bottom, right))
            return true;
        else
            return false;
    }
    default:
        return false;
    }
}
bool is_valid_for_empty(int row, int col, vector<vector<char>> &maze, vector<int> &top, vector<int> &left, vector<int> &bottom, vector<int> &right)
{
    if (row == maze.size() - 1)
    {
        int top_val = top[col];
        int bottom_val = bottom[col];
        if (top_val > 0 || bottom_val > 0)
            return false;
    }
    if (col == maze[0].size() - 1)
    {
        int left_val = left[row];
        int right_val = right[row];
        if (left_val > 0 || right_val > 0)
            return false;
    }
    switch (maze[row][col])
    {
    case 'B':
    {

        if (maze[row - 1][col] == '_')
            return true;
        else
            return false;
    }
    case 'R':
    {

        if (maze[row][col - 1] == '_')
            return true;
        else
            return false;
    }
    default:
        return true;
    }
}

bool is_valid(char symbol, int row, int col, vector<vector<char>> &maze, vector<int> &top, vector<int> &left, vector<int> &bottom, vector<int> &right)
{
    switch (symbol)
    {
    case '+':
    {
        return is_valid_for_plus(row, col, maze, top, left);
    }
    case '-':
    {
        return is_valid_for_minus(row, col, maze, bottom, right);
    }
    case '_':
    {
        return is_valid_for_empty(row, col, maze, top, bottom, bottom, right);
    }
    default:
        return false;
    }
}

bool solve(string options, vector<vector<char>> &maze, vector<int> &top, vector<int> &left, vector<int> &bottom, vector<int> &right, int i, int j)
{

    for (int row = i; row < maze.size(); row++)
    {
        for (int col = j + 1; col < maze[0].size(); col++)
        {
            for (char v : options)
            {
                if (!is_valid(v, row, col, maze, top, left, bottom, right))
                    continue;
                int top_data = top[col];
                int left_data = left[row];
                int bottom_data = bottom[col];
                int right_data = right[row];
                if (v == '+')
                {
                    if (left_data > 0)
                        left[row]--;
                    if (top_data > 0)
                        top[col]--;
                }
                else if (v == '-')
                {
                    if (bottom_data > 0)
                        bottom[col]--;
                    if (right_data > 0)
                        right[row]--;
                }
                char temp = maze[row][col];
                maze[row][col] = v;
                if (solve(options, maze, top, left, bottom, right, row, col))
                    return true;
                maze[row][col] = temp;
                top[col] = top_data;
                left[row] = left_data;
                bottom[col] = bottom_data;
                right[row] = right_data;
            }
            return false;
        }
        j = -1;
    }
    return true;
}
int main()
{
    vector<int> top = {1, -1, -1, 2, 1, -1};
    vector<int> left = {2, 3, -1, -1, -1};
    vector<int> bottom = {2, -1, -1, 2, -1, 3};
    vector<int> right = {-1, -1, -1, 1, -1};
    string options = "+-_";
    vector<vector<char>> maze = {
        {'L', 'R', 'L', 'R', 'T', 'T'},
        {'L', 'R', 'L', 'R', 'B', 'B'},
        {'T', 'T', 'T', 'T', 'L', 'R'},
        {'B', 'B', 'B', 'B', 'T', 'T'},
        {'L', 'R', 'L', 'R', 'B', 'B'}};
    solve(options, maze, top, left, bottom, right, 0, -1);
    for (auto row : maze)
    {
        for (char element : row)
        {
            if (element == '_')
                cout << 'E' << ' ';
            else
                cout << element << ' ';
        }
        cout << endl;
    }

    return 0;
}