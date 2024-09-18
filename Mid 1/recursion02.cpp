#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<char>> &field, int r, int c)
{
    int rows = field.size();
    int cols = field[0].size();

    if(r < 0 || r>=rows || c<0|| field[r][c]!='T')
    {
        return 0;
    }
    else{
        field[r][c]= 'W';
        int size = 1;

        size+=dfs(field, r+1, c);
        size+=dfs(field, r-1, c);
        size+=dfs(field, r, c+1);
        size+=dfs(field, r, c-1);

        return size;
    }
}

int largestForestSize(vector<vector<char>>& field)
{
    int rows = field.size();
    if(rows == 0)
    {
        return 0;

    }
    int cols = field[0].size();
    int largestForest = 0;

    for(int r = 0; r<rows; r++)
    {
        for(int c = 0; c<cols; c++)
        {
            if(field[r][c]=='T')
            {
                int forestSize = dfs(field, r, c);
                largestForest = max(largestForest, forestSize);
            }
        }
    }

    return largestForest;
}

int main()
{
    vector<vector<char>> field = {
        {'T', 'W', 'T', 'T', 'W'},
        {'T', 'W', 'T', 'W', 'W'},
        {'W', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'W', 'W', 'W'},
        {'T', 'T', 'W', 'W', 'W'}
    };

    cout << "Size of the largest forest: " << largestForestSize(field) << endl;

    return 0;
}
