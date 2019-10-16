#include <stdlib.h>
#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <limits.h>

#define MAX_REFERENCE_COUNTER 256

struct PageFrame {
	int page_number;
	int reference_counter;
};

int updatePages(struct PageFrame *page_frames, int next_page_number, 
    int *used_pages_amount, int frames_num) {
    int minimal_reference_counter = MAX_REFERENCE_COUNTER, 
        swap_candidate_page_number = 0;
    for (int i = 0; i < *used_pages_amount; ++i) {
        if (page_frames[i].reference_counter < minimal_reference_counter) {
            minimal_reference_counter = page_frames[i].reference_counter;
            swap_candidate_page_number = i;
        }
    }

    int hit = 0;
    for (int i = 0; i < *used_pages_amount; ++i) {
        page_frames[i].reference_counter >> 1;
        if (page_frames[i].page_number == next_page_number) {
            page_frames[i].reference_counter += MAX_REFERENCE_COUNTER / 2;
            hit = 1;
        }
    }

    if (hit) {
        return 1;
    }

    if (*used_pages_amount < frames_num) {
        page_frames[*used_pages_amount].page_number = next_page_number;
        page_frames[*used_pages_amount].reference_counter = 
            MAX_REFERENCE_COUNTER / 2;
        *used_pages_amount += 1;
    } else {
        page_frames[swap_candidate_page_number].page_number = next_page_number;
        page_frames[swap_candidate_page_number].reference_counter = 
            MAX_REFERENCE_COUNTER / 2;
    }

    return 0;
}

int simulateAgeing(int frames_num) {
    FILE *input_file;
    input_file = fopen("Lab 09 input.txt", "r");
    if (input_file == NULL) {
        printf("No input file named 'Lab 09 input.txt'\n");
        return 1;
    }

    int next_page_number = 0, status = 0, hits = 0, misses = 0, 
        used_pages_amount = 0;
    struct PageFrame *page_frames = malloc(frames_num * sizeof(struct PageFrame));
    while (fscanf(input_file, "%d", &next_page_number) == 1) {
        status = updatePages(
            page_frames, next_page_number, &used_pages_amount, frames_num);
        if (status == 1) {
            hits++;
        } else {
            misses++;
        }
    }
    free(page_frames);
    
    float total_references = (float) hits + misses;
    printf("Hit rate: %g, miss rate: %g\n",
        hits / total_references,
        misses / total_references);
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter the number of page frames as a program's parameter\n");
        return 1;
    }

    char *p;
    int frames_num = strtol(argv[1], &p, 10);
    if (errno != 0 || *p != '\0' || frames_num > INT_MAX) {
        printf("Error while reading number of page frames happened\n");
        return 1;
    }

    return simulateAgeing(frames_num);
}
