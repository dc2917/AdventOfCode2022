#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_contained(char* set1, char* set2) {
    int contained;

    char set1_copy[8];
    char set2_copy[8];
    
    strcpy(set1_copy, set1);
    strcpy(set2_copy, set2);

    int set1_lims[2], set2_lims[2];

    set1_lims[0] = atoi(strtok(set1_copy, "-"));
    set1_lims[1] = atoi(strtok(NULL, "-"));
    set2_lims[0] = atoi(strtok(set2_copy, "-"));
    set2_lims[1] = atoi(strtok(NULL, "-"));

    if((set1_lims[0] >= set2_lims[0]) && (set1_lims[1] <= set2_lims[1])) {
        // set1 contained in set 2
        contained = 1;
//        printf("%s contains %s\n", set2, set1);
    } else if((set2_lims[0] >= set1_lims[0]) && (set2_lims[1] <= set1_lims[1])) {
        // set1 contained in set 2
        contained = 1;
//        printf("%s contains %s", set1, set2);
    } else {
        contained = 0;
    }
    return(contained);
}

int main(int argc, char* argv[]) {

    char line[16];
    char* line_lh;
    char* line_rh;
    char delim[2] = ",";

    int contained;
    int sum_contained = 0;
    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 16, fid) != NULL) {

        // Split by comma
        line_lh = strtok(line, delim);
        line_rh = strtok(NULL, delim);

        contained = is_contained(line_lh, line_rh);
        if(contained) {
            sum_contained++;
        }
    }
    fclose(fid);

    printf("Total number contained is %d\n", sum_contained);
    return(0);
}
