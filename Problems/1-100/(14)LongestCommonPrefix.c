char* longestCommonPrefix(char** strs, int strsSize) {
    char* out = (char*)malloc((200) * sizeof(char));
    unsigned int idx = 0;
    
    for (unsigned int o = 0; o < 200; o++) {
        char now = strs[0][o];

        for (unsigned int i = 1; i < strsSize; i++) {
            if (strs[i][o] == '\0' || now != strs[i][o]) {
                out[idx] = '\0';
                return out;
            }
        }
        
        out[idx] = now;
        idx++;
    }
    
    out[idx] = '\0';
    return out;
}