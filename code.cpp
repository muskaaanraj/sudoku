#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool isValid(vector<vector<char>>& board, int row, int col, char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)
        {
            return false;
        }
        if(board[row][i]==c)
        {
            return false;
        }
        if(board[3*(row/3)+i%3][3*(col/3)+i%3]==c)
        {
            return false;
        }
        
    }
    return true;
}

bool solve(vector<vector<char>>& board)
{
   for(int i=0;i<board.size();i++)
 {
      for(int j=0;j<board[0].size();j++)
      {
         if(board[i][j]=='0')
        {
          for(char c='1';c<='9';c++)
          {
            if(isValid(board,i,j,c))
            {
                board[i][j]=c;

                if(solve(board)==true)
                {
                    return true;
                }
                else
                {
                  board[i][j]='0';
                }
         
            }
          }
          return false;
      }
    }
  }
 return true;
}

class Solution
{
    public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solve (board);
    }
};

void printGrid(const vector<vector<char>>& board)
{
    for (const auto& row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}



int main()
{
    vector<vector<char>> board = {
        {'3', '0', '6', '5', '0', '8', '4', '0', '0'},
        {'5', '2', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '8', '7', '0', '0', '0', '0', '3', '1'},
        {'0', '0', '3', '0', '1', '0', '0', '8', '0'},
        {'9', '0', '0', '8', '6', '3', '0', '0', '5'},
        {'0', '5', '0', '0', '9', '0', '6', '0', '0'},
        {'1', '3', '0', '0', '0', '0', '2', '5', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '7', '4'},
        {'0', '0', '5', '2', '0', '6', '3', '0', '0'}
    };

    Solution solution;
    solution.solveSudoku(board);

    printGrid(board);

    return 0;
}
