#define Max_Int 50000
#define MIN(a,b) (((a)<(b))?(a):(b))
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int *dp=(int*)malloc(n*sizeof(int*));
    int *pre_dp=(int*)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        dp[i] = Max_Int ;
    }
    dp[src] = 0;
    for(int i=1; i<=K+1; i++){
        dp[src] = 0;
        for(int i=0;i<n;i++){
            pre_dp[i] = dp[i];
        }
        for(int j=0; j<flightsSize; j++){
            dp[flights[j][1]] = MIN(dp[flights[j][1]],pre_dp[flights[j][0]] + flights[j][2]);
        }
    }
    return (dp[dst] >= Max_Int) ? -1 : dp[dst];
    // int **dp=(int**)malloc((K+2)*sizeof(int*));
    // for(int i=0;i<K+2;i++){
    //     dp[i]=(int*)malloc(n*sizeof(int));
    // }
    // for(int i=0;i<K+2;i++){
    //     for(int j=0;j<n;j++)
    //         dp[i][j] = Max_Int;
    // }
    // dp[0][src] = 0;
    // for(int i=1; i<=K+1; i++){
    //     dp[i][src] = 0;
    //     for(int j=0; j<flightsSize; j++){
    //         dp[i][flights[j][1]] = MIN(dp[i][flights[j][1]],dp[i-1][flights[j][0]] + flights[j][2]);
    //     }
    // }
    // return (dp[K+1][dst] >= Max_Int) ? -1 : dp[K+1][dst];
}