#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int elf_idx;
    int max_cal1, max_cal1_idx;
    int max_cal2, max_cal2_idx;
    int max_cal3, max_cal3_idx;
    int cal, cal_sum;

    char line[8];
    
    FILE* fid = fopen("input.txt", "r");

    elf_idx = 0;
    max_cal1 = max_cal2 = max_cal3 = 0;
    max_cal1_idx = max_cal2_idx = max_cal3_idx = 0;
    while(fgets(line, 8, fid) != NULL) {
        printf("%s", line);
        if(line[0] == '\n') {
            if(cal_sum > max_cal1) {
                max_cal3 = max_cal2;
                max_cal3_idx = max_cal2_idx;
                max_cal2 = max_cal1;
                max_cal2_idx = max_cal1_idx;
                max_cal1 = cal_sum;
                max_cal1_idx = elf_idx;
            } else if(cal_sum > max_cal2) {
                max_cal3 = max_cal2;
                max_cal3_idx = max_cal2_idx;
                max_cal2 = cal_sum;
                max_cal2_idx = elf_idx;
            } else if(cal_sum > max_cal3) {
                max_cal3 = cal_sum;
                max_cal3_idx = elf_idx;
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

    printf("Elf #%d has the most calories (%d)\n", max_cal1_idx, max_cal1);
    printf("Elf #%d has the second most calories (%d)\n", max_cal2_idx, max_cal2);
    printf("Elf #%d has the third most calories (%d)\n", max_cal3_idx, max_cal3);
    printf("Collectively, they are carrying %d calories\n", max_cal1+max_cal2+max_cal3);
    return(0);
}
