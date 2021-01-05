

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **a = (char**)malloc(n*sizeof(char*));
    char s[15];
	for (int i = 0; i < n; i++) 
		a[i] = (char*)malloc(15*sizeof(char)); 
    *returnSize = n;

    for (int i = 0; i < n; i++){
        int j = i+1;
        if(j % 3 == 0 && j % 5 != 0)
            strcpy(a[i], "Fizz");
        else if(j % 3 != 0 && j % 5 == 0)
            strcpy(a[i], "Buzz");
        else if(j % 3 == 0 && j % 5 == 0)
            strcpy(a[i], "FizzBuzz");
        else{
            sprintf(s,"%d",j);
            strcpy(a[i], s);
        }
    }
    return a;
}