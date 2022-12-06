#include <stdio.h>

int outcome(char a, char b) {

    int score;

    if(a == 'A') { //rock
        if(b == 'A') { //rock
            score = 3;
        } else if(b == 'B') { //paper
            score = 6;
        } else if(b == 'C') { //scissors
            score = 0;
        } else {
            score = -1;
            printf("Error\n");
        }
    } else if (a == 'B') { //paper
        if(b == 'A') { //rock
            score = 0;
        } else if(b == 'B') { //paper
            score = 3;
        } else if(b == 'C') { //scissors
            score = 6;
        } else {
            score = -1;
            printf("Error\n");
        }
    } else if (a == 'C') { //scissors
        if(b == 'A') { //rock
            score = 6;
        } else if(b == 'B') { //paper
            score = 0;
        } else if(b == 'C') { //scissors
            score = 3;
        } else {
            score = -1;
            printf("Error\n");
        }
    } else {
        score = -1;
        printf("Error\n");
    }

    if(b == 'A') score += 1;
    if(b == 'B') score += 2;
    if(b == 'C') score += 3;
    
    return(score);
}

int main(int argc, char* argv[]) {

    int score;
    int total;
    char elf_choice, my_choice;
    char line[5];
    
    total = 0;

    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 5, fid) != NULL) {
        elf_choice = line[0];
        my_choice = line[2];
        score = outcome(elf_choice, my_choice-('X'-'A'));
        printf("%c | %c\t%d\n", elf_choice, my_choice, score);
        total += score;
    }
    
    fclose(fid);

    printf("Total score = %d\n", total);
    
    return(0);
}
