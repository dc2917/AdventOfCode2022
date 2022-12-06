#include <stdio.h>

int get_my_choice(char a, char outcome) {

    char my_choice;

    if(a == 'A') { //rock
        if(outcome == 'X') { //lose
            my_choice = 'C';
        } else if(outcome == 'Y') { //draw
            my_choice = 'A';
        } else if(outcome == 'Z') { //win
            my_choice = 'B';
        } else {
            printf("Error\n");
        }
    } else if (a == 'B') { //paper
        if(outcome == 'X') { //lose
            my_choice = 'A';
        } else if(outcome == 'Y') { //draw
            my_choice = 'B';
        } else if(outcome == 'Z') { //win
            my_choice = 'C';
        } else {
            printf("Error\n");
        }
    } else if (a == 'C') { //scissors
        if(outcome == 'X') { //lose
            my_choice = 'B';
        } else if(outcome == 'Y') { //draw
            my_choice = 'C';
        } else if(outcome == 'Z') { //win
            my_choice = 'A';
        } else {
            printf("Error\n");
        }
    } else {
        printf("Error\n");
    }

    return(my_choice);
}

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
    char elf_choice, my_choice, desired_outcome;
    char line[5];
    
    total = 0;

    FILE* fid = fopen("input.txt", "r");

    while(fgets(line, 5, fid) != NULL) {
        elf_choice = line[0];
        desired_outcome = line[2];
        my_choice = get_my_choice(elf_choice, desired_outcome);
        score = outcome(elf_choice, my_choice);
        printf("%c | %c\t%d\n", elf_choice, my_choice, score);
        total += score;
    }
    
    fclose(fid);

    printf("Total score = %d\n", total);
    
    return(0);
}
