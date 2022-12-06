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

char common_char(char* str1, char* str2, char* str3) {

    char common;
    char c;
    for(int i=0; i<strlen(str1); i++) {
        c = str1[i];
        if(strchr(str2, c) != NULL) {
            if(strchr(str3, c) != NULL) {
                common = c;
                return(common);
            }
        }
    }
}


int main(int argc, char* argv[]) {

    char line[64];
    char lines[3][64];
    char common;

    int priority;
    int priority_sum = 0;

    int count = 0;

    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 64, fid) != NULL) {
        strcpy(lines[count], line);
        count++;
        if(count==3) {
            common = common_char(lines[0], lines[1], lines[2]);
            priority = calc_priority(common);
            printf("Common character: %c\tpriority = %d\n", common, priority);
            count = 0;
            priority_sum += priority;
        }
    }

    printf("Total priority = %d\n", priority_sum);
    
    fclose(fid);

    return(0);
}
