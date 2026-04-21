class Solution {
public:
    bool func(vector<vector<char>>& board, char c, int i, int j){
        int rowCnt = 0;
        for(int x=0;x<board[0].size();x++){
            if(board[i][x]==c) rowCnt++;
            if(rowCnt>1) return false;
        }
        int colCnt = 0;
        for(int x=0;x<board.size();x++){
            if(board[x][j]==c) colCnt++;
            if(colCnt>1) return false;
        }
        int gridCnt = 0;
        int srow = i - i%3, scol = j - j%3;
        for(int x = srow; x<srow+3;x++){
            for(int y=scol; y<scol+3;y++){
                if(board[x][y]==c) gridCnt++;
                if(gridCnt>1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!func(board,board[i][j],i,j)) return false;
                }
            }
        }
        return true;
    }
};
