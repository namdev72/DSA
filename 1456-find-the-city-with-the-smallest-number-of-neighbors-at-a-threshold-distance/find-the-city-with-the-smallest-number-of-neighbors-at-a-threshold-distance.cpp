class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) mat[i][j]=0;
            }
        }
        for(auto it:edges){
            int i=it[0];
            int j=it[1];
            int w=it[2];
            mat[i][j]=w;
            mat[j][i]=w;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX && mat[i][k]+mat[k][j]<mat[i][j])
                    {
                        mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }

        ////
        int count=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]<=distanceThreshold) ct++;
            }
            if(city==-1 || ct<=count)
            {
                city=i;
                count=ct;
            }
        }
        return city;
    }
};