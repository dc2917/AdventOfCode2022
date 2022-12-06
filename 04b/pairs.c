#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_overlap(char* set1, char* set2) {
    int overlap;

    char set1_copy[8];
    char set2_copy[8];
    
    strcpy(set1_copy, set1);
    strcpy(set2_copy, set2);

    int set1_lims[2], set2_lims[2];

    set1_lims[0] = atoi(strtok(set1_copy, "-"));
    set1_lims[1] = atoi(strtok(NULL, "-"));
    set2_lims[0] = atoi(strtok(set2_copy, "-"));
    set2_lims[1] = atoi(strtok(NULL, "-"));

    if((set1_lims[0] >= set2_lims[0]) && (set1_lims[0] <= set2_lims[1])) {
        // set1 lower limit contained in set 2
        overlap = 1;
//        printf("%s overlaps %s\n", set2, set1);
    } else if((set1_lims[1] >= set2_lims[0]) && (set1_lims[1] <= set2_lims[1])) {
        // set1 upper limit contained in set 2
        overlap = 1;
//        printf("%s overlaps %s\n", set2, set1);
    } else if((set2_lims[0] >= set1_lims[0]) && (set2_lims[0] <= set1_lims[1])) {
        // set2 lower limit contained in set 1
        overlap = 1;
//        printf("%s overlaps %s\n", set2, set1);
    } else if((set2_lims[1] >= set1_lims[0]) && (set2_lims[1] <= set1_lims[1])) {
        // set2 upper limit contained in set 1
        overlap = 1;
//        printf("%s overlaps %s\n", set2, set1);
    } else {
        overlap = 0;
    }
    return(overlap);
}

int main(int argc, char* argv[]) {

    char line[16];
    char* line_lh;
    char* line_rh;
    char delim[2] = ",";

    int overlap;
    int sum_overlaps = 0;
    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 16, fid) != NULL) {

        // Split by comma
        line_lh = strtok(line, delim);
        line_rh = strtok(NULL, delim);

        overlap = is_overlap(line_lh, line_rh);
        if(overlap) {
            sum_overlaps++;
        }
    }
    fclose(fid);

    printf("Total number of overlaps is %d\n", sum_overlaps);
    return(0);
}
