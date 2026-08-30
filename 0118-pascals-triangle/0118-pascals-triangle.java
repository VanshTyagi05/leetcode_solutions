class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle=new ArrayList<>();
        if(numRows==0)return triangle;
        List<Integer> firstRow=new ArrayList<>();
        firstRow.add(1);
        triangle.add(firstRow);

        for(int i=1;i<numRows;i++){
            List<Integer> row=new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0|| j==i){
                    row.add(1);
                }else{
                    int leftValue=triangle.get(i-1).get(j-1);
                    int rightValue=triangle.get(i-1).get(j);
                    row.add(leftValue+rightValue);
                }
            }
            triangle.add(row);
        }
        return triangle;
    }
}