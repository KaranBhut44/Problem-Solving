class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i=0,j=m-1;
        while(i< m/2)
        {
            for(int k=i;k<m-i-1;k++)
            {
                int first = matrix[i][k];
                int second = matrix[k][j-i];
                int third = matrix[j-i][j-k];
                int fourth = matrix[j-k][i];
                
                matrix[i][k] = fourth;
                matrix[k][j-i] = first;
                matrix[j-i][j-k] = second;
                matrix[j-k][i] = third;
            }
            i++;
        }

    }
};