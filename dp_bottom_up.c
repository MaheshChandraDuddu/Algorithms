#include <stdio.h>
#include <stdlib.h>


int maxval(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int valid(int a, int b, int rows, int columns)
{
    if(a >= 1 && a <= rows)
    {
        if(b >= 1 && b <= columns)
        {
           // printf("Valid Cell");
            return 1;
        }
    } 
    //printf("Invalid Cell");
    return 0;
}

int start_or_end(int a, int b, int no_of_rows, int no_of_columns)
{
    if(a == 1 && b == 1)
    {
        return 1;
    }
    else if(a == no_of_rows && b == no_of_columns)
    {
        return 1;
    }
    return 0;
}

void printarr(int rows, int columns, int arr[][columns])
{
    int i, j;

    for(i = 1; i <= rows-1; i++)
    {
        for(j = 1; j <= columns-1; j++)
        {
            printf("%d ", arr[i][j]);        
        }
        printf("\n");
    }
    return;
}

int main()
{
    int t;
    printf("Enter No. of Test Cases : ");
    scanf("%d", &t);
    
    while(t--)
    {
        int N, M;
        printf("Enter the Size of matrix N x M :");
        scanf("%d %d", &N, &M);
        
        int arr[N+1][M+1], dp[N+1][M+1], i, j, K;
        
        for(i = 0; i < N+1; i++)
        {
            for(j = 0; j < M+1; j++)
            {
                arr[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        printarr(N+1, M+1, arr);
        printf("Enter the no. of special-cells:");
        scanf("%d", &K);

        for(i = 1; i <= K;)
        {
            int X, Y;
            printf("Enter the Cell (i, j):");
            scanf("%d %d", &X, &Y);
            if(valid(X, Y, N, M))
            {
                printf("Cell is now chosen\n");
                printf("Enter the happiness quotient value that you want to add\n");
                int happiness;
                //scanf("%d", &happiness);
                if(start_or_end(X, Y, N, M))
                {
                    printf("Choose a cell other than source and destination cells\n");
                }
                else
                {
                    scanf("%d", &happiness);
                    arr[X][Y] = happiness;
                    dp[X][Y] = happiness;
                    i++;
                }
            }
            else
            {
                printf("Choose a valid cell\n");
            }
        }
        
        printf("------------------------Array-----------------\n");
        printarr(N+1, M+1, arr);
        printf("------------------------------------------------\n");
        printf("-----------------------------Dynamic Programming Lookup Table--------------------\n");
        printarr(N+1, M+1, dp);
        printf("--------------------------------------------------------------------------------\n");
        
        for(i = N; i >= 1; i--)
        {
            for(j = M; j >=1; j--)
            {
                if(i == N && j == M)
                {
                    continue;
                }
                if(valid(i, j+1, N, M))
                {
                    if(valid(i+1, j, N, M))
                    {
                        dp[i][j] += maxval(dp[i][j+1], dp[i+1][j]);
                    }
                    else
                    {
                        dp[i][j] += dp[i][j+1];
                    }
                    
                }
                else
                {
                    if(valid(i+1, j, N, M))
                    {
                        dp[i][j] += dp[i+1][j];
                    }
                }
            }
        }
        printf("-----------------------------Final Dynamic Programming Lookup Table--------------------\n");
        printarr(N+1, M+1, dp);
        printf("--------------------------------------------------------------------------------\n");
        printf("Dynamic Programming Approach's answer to the problem is : %d\n", dp[1][1]);
    }
    exit(0);
}