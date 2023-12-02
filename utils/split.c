
void strrep(const char *s, const char *target, const char replace) {
    char final[80];
    int filled = 0;
    while (strlen(s) > 0) {
        if(!strcmp(s, target)) {
            s += strlen(target);
        }
        final[filled++] = s[0];
        s++;
    }
    printf("%c\n", final);
}