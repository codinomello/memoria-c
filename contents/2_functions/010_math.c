#include <stdio.h>

#include "011_math.h"

float snek_score(
    int num_files,
    int num_contributors,
    int num_commits,
    float avg_bug_criticality
) {
    int size_factor = num_files * num_commits;
    int complexity_factor = num_contributors + size_factor;
    
    return avg_bug_criticality * complexity_factor;
}

int main() {
    float score = snek_score(10, 5, 100, 0.5);
    printf("snek score: %.1f\n", score);
    
    return 0;
}