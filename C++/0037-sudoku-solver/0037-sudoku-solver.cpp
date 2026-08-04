class Solution {
public:
    bool rows[9][9]={}, cols[9][9]={}, boxes[9][9]={}, f=false;
    vector<vector<char>> *h;


    void place(int x, int &i, int &j){
        rows[i][x-1]=true;
        cols[j][x-1]=true;
        boxes[(i/3)*3 + j/3][x-1]=true;
        (*h)[i][j]='0'+x;
    }

    bool can(int x, int &i, int &j){
        return !(rows[i][x-1] || cols[j][x-1] || boxes[(i/3)*3 + j/3][x-1]);
    }
    void next(int i, int j){
        if(i==8 and j==8){
            f=true;
        }else if(j==8) help(i+1,0);
        else help(i, j+1);
    }

    void help(int i, int j){
        if( (*h)[i][j]=='.' ){
            for(int x=1; x<=9; x++){
                if(can(x,i,j)){
                    place(x, i, j);
                    next(i,j);
                    if(!f) unplace(x,i,j);
                }
            }
        }else next(i,j);
    }

    void unplace(int x,int &i, int &j){
        rows[i][x-1]=false;
        cols[j][x-1]=false;
        boxes[(i/3)*3 + j/3][x-1]=false;
        (*h)[i][j]='.';
    }




    void solveSudoku(vector<vector<char>>& board) {
        h=&board;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') place(board[i][j]-'0', i, j);
            }
        }
        int a=0, b=0;
        help(a,b);
    }
};