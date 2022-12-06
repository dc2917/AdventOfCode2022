#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int elf_idx;
    int max_cal, max_cal_idx;
    int cal, cal_sum;

    char line[8];
    
    FILE* fid = fopen("input.txt", "r");

    elf_idx = 0;
    max_cal = 0;
    max_cal_idx = 0;
    while(fgets(line, 8, fid) != NULL) {
        printf("%s", line);
        if(line[0] == '\n') {
            if(cal_sum > max_cal) {
                max_cal = cal_sum;
                max_cal_idx = elf_idx;
            }
            printf("Elf #%d is carrying %d calories\n", elf_idx, cal_sum);
            ++elf_idx;
            cal_sum = 0;
        } else {
            cal = atoi(line);
            cal_sum += cal;
        }
    }
    fclose(fid);

    printf("Elf #%d has the most calories (%d)\n", max_cal_idx, max_cal);
    return(0);
}
