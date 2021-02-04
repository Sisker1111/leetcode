int getSum(int a, int b){
        if(b == 0)
            return a;
        return getSum(a^b, ((unsigned)(a&b))<<1);
}

// int getSum(int a, int b){
//     int temp = 0, carry = 0; 
//     for(int i=0; i<32; i++){
//         if( carry ){
//             if( a & (1u<<i) ){
//                 if( b & (1u<<i) ){
//                     temp |= 1u<<i;
//                 }
//                 carry = 1;
//             }
//             else{
//                 if( b & (1u<<i) )
//                     carry = 1;
//                 else{
//                     temp |= 1u<<i;
//                     carry = 0;
//                 }
//             }
//         }
//         else{
//             if( a & (1u<<i) ){
//                 if( b & (1u<<i) ){
//                     carry = 1;
//                 }
//                 else
//                     temp |= 1u<<i;
//             }
//             else{
//                 if( b & (1u<<i) )
//                     temp |= 1u<<i;
//             }
//         }
        
//     }
//     return temp;
// }

