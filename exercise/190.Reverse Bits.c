uint32_t reverseBits(uint32_t n) {
    // uint32_t new;
    // new = n;
    // new = ((new & 0xffff0000) >> 16) | ((new & 0x0000ffff) << 16);
    // new = ((new & 0xff00ff00) >> 8) | ((new & 0x00ff00ff) << 8);
    // new = ((new & 0xf0f0f0f0) >> 4) | ((new & 0x0f0f0f0f) << 4);
    // new = ((new & 0xcccccccc) >> 2) | ((new & 0x33333333) << 2);
    // new = ((new & 0xaaaaaaaa) >> 1) | ((new & 0x55555555) << 1);
    // return new ;
    for(int i=0;i<=15;i++){
        if((1u<<i) & n ){
            if( (1u<<(31-i)) & n ){
               continue;
            }
            else{
                n &= ~(1u << i);
                n |= 1u <<(31-i);
            }
                  
        }
        else{
            if( (1u<<(31-i)) & n ){
               n &= ~(1u << (31-i));
               n |= 1u << i;
            }
            
        }
    }
    return n;
}