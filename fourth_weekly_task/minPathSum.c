int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int minSum[gridRowSize][gridColSize];
    int i,j;
    
    minSum[0][0]=grid[0][0];
    
    for(i=1;i<gridRowSize;i++)
        minSum[i][0]=minSum[i-1][0]+grid[i][0];
    for(j=1;j<gridColSize;j++)
        minSum[0][j]=minSum[0][j-1]+grid[0][j];
    
    for(i=1;i<gridRowSize;i++)
        for(j=1;j<gridColSize;j++)
            minSum[i][j]=min(minSum[i][j-1],minSum[i-1][j])+grid[i][j];
    
    return minSum[gridRowSize-1][gridColSize-1];
}
int min(int a,int b)
{
    if(a>=b)
        return b;
    else
        return a;
}