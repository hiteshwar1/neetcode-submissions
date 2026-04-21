class Solution {
public:
    int recur(int m,int n){
        if(m==0&&n==0) return 1;
        if(m<0||n<0) return 0;
        return recur(m-1,n) + recur(m,n-1);
    }
    int uniquePaths(int m, int n) {
        return recur(m-1,n-1);
    }
};
