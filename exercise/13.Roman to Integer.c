

int romanToInt(char * s){
    int total = 0;
    while(*s){
        switch(*s){
            case 'I':
                if( *(s+1) != '\0'){
                    if( *(s+1) == 'V' ){
                        total+=4;
                        s+=2;
                    }
                    else if( *(s+1) == 'X' ){
                        total+=9;
                        s+=2;
                    }
                    else{
                        total+=1;
                        s+=1;
                    }
                }
                else{
                    total+=1;
                    s+=1;
                }
                break;
            case 'V':
                total+=5;
                s+=1;
                break;
            case 'X':
                if( *(s+1) != '\0'){
                    if( *(s+1) == 'L' ){
                        total+=40;
                        s+=2;
                    }
                    else if( *(s+1) == 'C' ){
                        total+=90;
                        s+=2;
                    }
                    else{
                        total+=10;
                        s+=1;
                    }
                }
                else{
                    total+=10;
                    s+=1;
                }
                break;
            case 'L':
                total+=50;
                s+=1;
                break;
            case 'C':
                if( *(s+1) != '\0'){
                    if( *(s+1) == 'D' ){
                        total+=400;
                        s+=2;
                    }
                    else if( *(s+1) == 'M' ){
                        total+=900;
                        s+=2;
                    }
                    else{
                        total+=100;
                        s+=1;
                    }
                }
                else{
                    total+=100;
                    s+=1;
                }
                break;
            case 'D':
                total+=500;
                s+=1;
                break;
            case 'M':
                total+=1000;
                s+=1;
                break;
            default:
                break;
                
        }
        
    }
    return total;
}