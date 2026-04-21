class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;
        while(x){
            if(reverseNum>INT_MAX/10||reverseNum<INT_MIN/10) return false;
            reverseNum = reverseNum*10 + x%10;
            x=x/10;
        }
        return reverseNum;
    }
};
