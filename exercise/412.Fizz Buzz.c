

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef unsigned char           uint8_t;
typedef unsigned int            uint32_t;  
typedef unsigned long int       uint64_t; 

#define MSG_LEN 8

static inline bool is_divisible(uint32_t n, uint64_t M) {
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;
static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;


char ** fizzBuzz(int n, int* returnSize){
    char **a = (char**)malloc(n*sizeof(char*));
    char s[15];
    for (int i = 0; i < n; i++) 
        a[i] = (char*)malloc(15*sizeof(char)); 
    *returnSize = n;
    
    for (int i = 0; i < n; i++){
        int j = i + 1;
        uint8_t div3 = is_divisible(j, M3);
        uint8_t div5 = is_divisible(j, M5);
        unsigned int length = (2 << div3) << div5;
        strncpy(a[i], &"FizzBuzz%u"[(MSG_LEN >> div5) >> (div3 << 2)], length);
        a[i][length] = '\0';
        if( a[i][0] == '%' && a[i][1] == 'u'){
            sprintf(s,"%d",j);
            strcpy(a[i], s);
        }
    }
    // for (int i = 0; i < n; i++){
    //     int j = i+1;
    //     if(j % 3 == 0 && j % 5 != 0)
    //         strcpy(a[i], "Fizz");
    //     else if(j % 3 != 0 && j % 5 == 0)
    //         strcpy(a[i], "Buzz");
    //     else if(j % 3 == 0 && j % 5 == 0)
    //         strcpy(a[i], "FizzBuzz");
    //     else{
    //         sprintf(s,"%d",j);
    //         strcpy(a[i], s);
    //     }
    // }
    return a;
}