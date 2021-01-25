
int Tribonacci_number(int n, int *map){
    if(n==0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    if(map[n])
        return map[n];
    return  (map[n-1] = Tribonacci_number(n-1,map)) + (map[n-2] = Tribonacci_number(n-2,map))
        + (map[n-3] = Tribonacci_number(n-3,map)) ;
    
}
int tribonacci(int n){
    int *map = (int *)malloc((n+1)*sizeof(int));
    memset(map,0,(n+1)*sizeof(int));
    return Tribonacci_number(n,map);
}