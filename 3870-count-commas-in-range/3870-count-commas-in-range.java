class Solution {

    public int countCommas(int n) {
        if(n<1000)return 0;// no commas required
        return n-1000+1;
        
    }
}