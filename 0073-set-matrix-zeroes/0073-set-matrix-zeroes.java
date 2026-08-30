class Solution {
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int[] rows=new int[n];
        int[] cols=new int[m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        // setting all the rows to zero
        for(int i=0;i<n;i++){
            if(rows[i]==1){
                // ye vale row ko zero krna hai
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
         for(int k=0;k<m;k++){
            if(cols[k]==1){
                // ye vale column ko zero krna hai
                for(int j=0;j<n;j++){
                    matrix[j][k]=0;
                }
            }
        }
    }
}