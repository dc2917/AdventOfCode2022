#include <stdio.h>
#include <string.h>

int are_all_diff(char* chars) {

    int diff = 1;
    printf("%s\n", chars);
    for(int i=1; i<4; i++) {
        if(strchr(&(chars[i]), chars[i-1]) != NULL) {
            printf("Repeated character\n");
            diff = 0;
        }
    }

    return(diff);
}

int main(int argc, char* argv[]) {

    char packet[8192];
    char nibble[5];
    int start_pos;

    FILE* fid = fopen("input.txt", "r");
    fgets(packet, 8192, fid);
    fclose(fid);

    start_pos = 4;
    for(int i=0; i<strlen(packet)-4; i++) {
        strncpy(nibble, &(packet[i]), 4);
        nibble[4] = '\0';
        if(are_all_diff(nibble)) {
            start_pos += i;
            break;
        }
    }
    printf("First marker after character %d\n", start_pos);
        
    return(0);
}
