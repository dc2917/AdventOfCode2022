#include <stdio.h>
#include <string.h>

int calc_priority(char c) {

    int priority;
    if((c>='a') && (c<='z')) {
        priority = c-'`';
    } else if ((c>='A') && (c<='Z')) {
        priority = c - '@'+26;
    }
    return(priority);
}

int main(int argc, char* argv[]) {

    char line[64];
    int line_len;

    char line_lh[32];
    char line_rh[32];

    char* common;

    int priority;
    int priority_sum = 0;

    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 64, fid) != NULL) {
        line_len = strlen(line) - 1;

        strncpy(line_lh, line, line_len/2);
        strcpy(line_rh, &(line[line_len/2]));

        common = strpbrk(line_lh, line_rh);

        priority = calc_priority(*common);

        priority_sum += priority;
    }

    printf("Total priority = %d\n", priority_sum);
    
    fclose(fid);

    return(0);
}
