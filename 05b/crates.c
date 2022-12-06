#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct stack {
    int index;
    int num_crates;
    char top_crate;
    char crates[60];
};

void print_stack(struct stack* s) {
    printf("Stack %d has %d crates.\n", s->index, s->num_crates);
    printf("[%c] is at the top.\n", s->top_crate);
    for(int i=0; i<s->num_crates; i++) {
        printf("[%c]\n", s->crates[s->num_crates-(1+i)]);
    }
}

int move_crates(int n, struct stack* giver, struct stack* receiver) {

    int error = 0;

    int m;
    
    if(giver->num_crates<n) {
        printf("No more crates to move!\n");
        error = 1;
    } else if(receiver->num_crates > 60) {
        printf("Too many crates!\n");
        error = 1;
    } else {
        for(m=n; m>0; m--) {
            printf("Moving crate [%c] from stack %d to stack %d\n",
                giver->crates[giver->num_crates-m], giver->index, receiver->index);
            receiver->crates[receiver->num_crates] = giver->crates[giver->num_crates-m];
            giver->crates[giver->num_crates-m] = '\0';

            receiver->num_crates++;
        }
        giver->num_crates -= n;
        giver->top_crate = giver->crates[giver->num_crates-1];
        receiver->top_crate = receiver->crates[receiver->num_crates-1];
    }
    return(error);
}

int main(int argc, char* argv[]) {

    char line[64];
    char prev_line[64];
//    char** stack_lines;

    int i, j;
    char c;
    int num_stacks;
    int max_crates;

    struct stack* stacks;
    
    FILE* fid = fopen("input.txt", "r");

    max_crates = 0;
    while(fgets(line, 64, fid) != NULL) {
        if(line[0] == '\n') {
            max_crates--;
            break;
        } else {
            max_crates++;
            strcpy(prev_line, line);
        }
    }
    fclose(fid);

    num_stacks = (int)(prev_line[strlen(prev_line)-3])-48;
    printf("There are %d stacks, the maximum height of which is %d\n", num_stacks, max_crates);

    char (*stack_lines)[64] = malloc(max_crates * sizeof(char[max_crates][64]));
    
    stacks = malloc(num_stacks * sizeof(struct stack));
    for(i=0; i<num_stacks; i++) {
        stacks[i].index = i+1;
        stacks[i].num_crates = 0;
    }

    fid = fopen("input.txt", "r");

    // Crates
    for(j=0; j<max_crates; j++) {
        fgets(line, 64, fid);
        strcpy(stack_lines[j], line);
    }

    for(j=0; j<max_crates; j++) {
        for(i=0; i<strlen(stack_lines[max_crates-(1+j)]); i++) {
            if(i%4 == 1){
                if(stack_lines[max_crates-(1+j)][i] == ' ') {
                    stacks[(i-1)/4].crates[j] = '\0';
                } else {
                    stacks[(i-1)/4].crates[j] = stack_lines[max_crates-(1+j)][i];
                    stacks[(i-1)/4].num_crates++;
                }
            }
        }
    }

    for(i=0; i<num_stacks; i++) {
        stacks[i].top_crate = stacks[i].crates[stacks[i].num_crates-1];
    }

    // Indices
    fgets(line, 64, fid);

    // Blank line
    fgets(line, 64, fid);
    
    // Instructions
    int i1, i2, i3;
    while(fgets(line, 64, fid) != NULL) {
        printf("%s", line);
        sscanf(line, "move %d from %d to %d\n", &i1, &i2, &i3);
        move_crates(i1, &(stacks[i2-1]), &(stacks[i3-1]));
    }
    fclose(fid);

    // Print stacks
//    print_stack(&(stacks[0]));
//    print_stack(&(stacks[1]));
//    print_stack(&(stacks[2]));

    // Print top crates
    for(i=0; i<num_stacks; i++) {
        printf("%c", stacks[i].top_crate);
    }
    printf("\n");

    return(0);
}
