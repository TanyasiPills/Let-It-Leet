int romanToInt(char* s) {
    int out = 0;

    for (unsigned int i = 0; s[i] != '\0'; i++)
    {
       switch (s[i])
       {
        case 'I':
            if(s[i+1] == 'V') {
                out += 4;
                i++;
            }
            else if(s[i+1] == 'X') {
                out += 9;
                i++;
            }
            else {
                out++;
            }
            break;

        case 'V':
            out += 5;
            break;

        case 'X':
            if(s[i+1] == 'L') {
                out += 40;
                i++;
            }
            else if(s[i+1] == 'C') {
                out += 90;
                i++;
            }
            else {
                out += 10;
            }
            break;
        
        case 'L':
            out += 50;
            break;
        
        case 'C':
            if(s[i+1] == 'D') {
                out += 400;
                i++;
            }
            else if(s[i+1] == 'M') {
                printf("heo");
                out += 900;
                i++;
            }
            else {
                out += 100;
            }
            break;
        
        case 'D':
            out += 500;
            break;
        
        case 'M':
            out += 1000;
            break;
       
        default:
            break;
        }
    }

    return out;
}