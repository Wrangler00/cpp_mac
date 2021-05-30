#include <bits/stdc++.h>
using namespace std;
// class Solution {
vector<vector<string>> ans;
int n;
// public:
void placeQueen(vector<string> pos, int row, vector<int> colOcc)
{
    if (row >= n)
    {
        ans.push_back(pos);
        return;
    };

    for (int col = 0; col < n; col++)
    {
        if (colOcc[col])
            continue;

        int r = row - 1, c = col - 1;

        while (r >= 0 && c >= 0)
        {
            if (pos[r][c] != '.')
                break;
            --r, --c;
        }

        if (r >= 0 && c >= 0)
            continue;
        r = row - 1, c = col + 1;

        while (r >= 0 && c < n)
        {
            if (pos[r][c] != '.')
                break;
            --r, ++c;
        }

        if (r >= 0 && c < n)
            continue;

        pos[row][col] = 'Q';
        colOcc[col] = 1;

        placeQueen(pos, row + 1, colOcc);

        pos[row][col] = '.';
        colOcc[col] = 0;
    }
}
vector<vector<string>> solveNQueens(int nn)
{
    n = nn;

    vector<int> col = vector<int>(n, 0);
    vector<string> pos = vector<string>(n, string(n, '.'));

    placeQueen(pos, 0, col);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<solveNQueens(n).size();
    return 0;
}
// };