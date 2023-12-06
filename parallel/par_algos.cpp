#include <omp.h>
#include <vector>
#include <algorithm>
#include <iostream>

void par_bubble_sort(std::vector<int> &nums){
    int phase, i, temp, n;
    n = 100000;

    double start_time, end_time, exec_time;
    start_time = omp_get_wtime();

    for(phase = 0; phase < n; ++phase) {
        // even phase
        if(phase % 2 == 0) {
            #pragma omp parallel for num_threads(16) default(none) shared(nums,n) private(i,temp)
                for(i = 1; i < n; i += 2)
                    if(nums[i-1] > nums[i]) {
                        temp = nums[i];
                        nums[i] = nums[i-1];
                        nums[i-1] = temp;
                    }
            }
        // odd phase
        else {
            #pragma omp parallel for num_threads(16) default(none) shared(nums,n) private(i,temp)
                for(i = 1; i < n-1; i += 2)
                    if(nums[i] > nums[i+1]) {
                        temp = nums[i];
                        nums[i] = nums[i+1];
                        nums[i+1] = temp;
                    }
        }
    }
    end_time = omp_get_wtime();
    exec_time = end_time - start_time;

    printf("%f\n", exec_time);
}