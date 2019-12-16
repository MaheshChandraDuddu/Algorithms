#include <stdio.h>
#include <stdlib.h>

int validCell(int a, int b, int row, int column)
{
    if(a <= row && a >= 1)
    {
        if(b <= column && b >= 1)
        {
            return 1;
        }        
    }
    return 0;
} 

int neitherStartnorEnd(int start, int end, int x, int y)
{
    if(x <= 1 && y <= 1)
    {
        return 0;
    }
    else if(x >= start && y >= end)
    {
        return 0;
    }
    return 1;
}

/*int solve(int a, int b, int arr[][b], int row, int column)
{
    int max = 0;
    while(a != row || b != column)
    {
        if(validCell(a, b+1, row, column))
        {
            printf("Right Valid\n");
            if(validCell(a+1, b, row, column))
            {
                printf("Down Valid\n");
                printf("a[%d][%d] = %d, a[%d][%d] = %d\n", a, b+1, arr[a][b+1], a+1, b, arr[a+1][b]);
                if(arr[a][b+1] >= arr[a+1][b])
                {
                    printf("Max is right\n");
                    b++;
                }
                else
                {
                    printf("max is down\n");
                    a++;
                }
            }
            else
            {
                printf("Right Valid, Down invalid\n");
                b++;
            }
        }
        else
        {
            printf("Right Invalid\n");
            if(validCell(a+1, b, row, column))
            {
                printf("Down valid\n");
                a++;
            }
        }
        printf("a = %d, b = %d arr[%d][%d] = %d\n", a, b, a, b, arr[a][b]);
        max += arr[a][b];
    }
    return max;
}*/

void printarr(int a, int b, int arr[][b])
{
    int i, j;
    for(i = 1; i <= a-1; i++)
    {
        for(j = 1; j <= b-1; j++)
        {
            //printf("x = %d, y =%d\n", i, j);
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    //printf("\n");
    return ;
}

int main()
{
    int t;
    printf("Enter No. of Test Cases: ");
    scanf("%d", &t);

    while(t--)
    {
        int N, M;
        printf("Enter N, M: ");
        scanf("%d %d", &N, &M);
        int arr[N+1][M+1];
        int K, i, j;
        printf("Enter K: ");
        scanf("%d", &K);

        for(i = 0; i < N+1; i++)
        {
            for(j = 0; j < M+1; j++)
            {
                arr[i][j] = 0;
            }
        }
        printarr(N+1, M+1, arr);
        int x, y;
        for(i = 1; i <= K;)
        {
            //Choose Special Cells
            scanf("%d %d", &x, &y);
            if(validCell(x, y, N, M))
            {
                if(neitherStartnorEnd(N, M, x, y))
                {
                    i++;
                    int happy;
                    printf("Now you can enter happiness quotient of this chosen cell\n");
                    scanf("%d", &happy);
                    printf("x = %d, y = %d\n", x, y);
                    arr[x][y] = happy;
                }
                else
                {
                    printf("Choose a valid cell other than source and destination\n");
                }               
            } 
            else
            {
                printf("Choose a valid Cell\n");
            }  
        }
        printarr(N+1, M+1, arr);
        int ans = 0, a, b, row, column;
        row = N;
        column = M;
        a = 1;
        b = 1;
        while(a != N || b != M)
        {
            if(validCell(a, b+1, row, column))
            {
                //printf("Right Valid\n");
                if(validCell(a+1, b, row, column))
                {
                    //printf("Down Valid\n");
                    //printf("a[%d][%d] = %d, a[%d][%d] = %d\n", a, b+1, arr[a][b+1], a+1, b, arr[a+1][b]);
                    if(arr[a][b+1] >= arr[a+1][b])
                    {
                        //printf("Max is right\n");
                        b++;
                    }
                    else
                    {
                        //printf("max is down\n");
                        a++;
                    }
                }
                else
                {
                    //printf("Right Valid, Down invalid\n");
                    b++;
                }
            }
            else
            {
                //printf("Right Invalid\n");
                if(validCell(a+1, b, row, column))
                {
                    //printf("Down valid\n");
                    a++;
                }
            }
            printf("a = %d, b = %d arr[%d][%d] = %d\n", a, b, a, b, arr[a][b]);
            ans += arr[a][b];
        }
        //ans = solve(i, j, arr, N, M);
        printf("Greedy Method Approach's answer to this problem is : %d\n", ans);
    }
    exit(0);
}