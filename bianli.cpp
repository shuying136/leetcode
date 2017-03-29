// 属于线性dp，从左上角到右下角，再从右下角到左上角更新距离


int row=matrix.size(),col=matrix[0].size();
        vector<vector<int> >dp(row, vector<int>(col,INT_MAX));
        for(int times=0;times<=1;times++)
            for(int i=times?row-1:0;times?i>=0:i<row;times?i--:i++)
                for(int j=times?col-1:0;times?j>=0:j<col;times?j--:j++)
                    if(!matrix[i][j]){
                        dp[i][j]=0;
                    }
                    else if(dp[i][j]){
                        if(i&&dp[i-1][j]!=INT_MAX&&dp[i][j]>dp[i-1][j]+1)
                            dp[i][j]=dp[i-1][j]+1;
                        if(j+1<col&&dp[i][j+1]!=INT_MAX&&dp[i][j]>dp[i][j+1]+1)
                            dp[i][j]=dp[i][j+1]+1;
                        if(i+1<row&&dp[i+1][j]!=INT_MAX&&dp[i][j]>dp[i+1][j]+1)
                            dp[i][j]=dp[i+1][j]+1;
                        if(j&&dp[i][j-1]!=INT_MAX&&dp[i][j]>dp[i][j-1]+1)
                            dp[i][j]=dp[i][j-1]+1;
                    }
        return dp;
