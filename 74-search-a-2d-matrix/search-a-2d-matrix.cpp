class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0;
        int col=matrix[0].size();
        for(int i=0;i<matrix.size();i++)
        {
            
            if(matrix[i][0]<=target && matrix[i][col-1]>=target)
            {
                r=i;
            }
        }

        //appling bs on it 
        int m;
        int l=0;
        int h=col-1;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(matrix[r][m]>target)
            {
                h=m-1;
            }
            else if(matrix[r][m]<target)
            {
                l=m+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};