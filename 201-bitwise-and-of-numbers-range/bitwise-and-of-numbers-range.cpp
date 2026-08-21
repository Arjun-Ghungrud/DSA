class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftc=0;
        while(left!=right){
            left=(left>>1);
            right=(right>>1);
            shiftc++;
        }
        return left<<shiftc;
    }
};