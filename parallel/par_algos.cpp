#include <omp.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "par_algos.h"

void par_bubble_sort(std::vector<int> &nums, int size) {
    int phase, i, temp;

    for(phase = 0; phase < size; ++phase) {
        // even phase
        if(phase % 2 == 0) {
            #pragma omp parallel for num_threads(16) default(none) shared(nums,size) private(i,temp)
                for(i = 1; i < size; i += 2)
                    if(nums[i-1] > nums[i]) {
                        temp = nums[i];
                        nums[i] = nums[i-1];
                        nums[i-1] = temp;
                    }
            }
        // odd phase
        else {
            #pragma omp parallel for num_threads(16) default(none) shared(nums,size) private(i,temp)
                for(i = 1; i < size-1; i += 2)
                    if(nums[i] > nums[i+1]) {
                        temp = nums[i];
                        nums[i] = nums[i+1];
                        nums[i+1] = temp;
                    }
        }
    }
}

void par_count_sort(std::vector<int> &nums){
    int nthreads, tid; 
    int maxVal = *std::max_element(std::begin(nums), std::end(nums)); 
    std::vector<int> counts(maxVal +1, 0);
    
    // Iterate through nums and increment each value in count array 
    #pragma omp parallel private(nthreads, tid) num_threads(16) 
    {
        #pragma omp for
            for (int i = 0; i < nums.size(); i++) {
                #pragma omp critical
                    counts[nums[i]]++; 
            }
    }

    // Iterate through each count and insert values into sorted array 
    #pragma omp parallel private(nthreads, tid) num_threads(16) 
    {
    int numsIndex = 0;
        #pragma omp for
            for (int i = 0; i < counts.size(); i++) {
                    for (int j = 0; j < counts[i]; j++) {
                        #pragma omp critical
                            nums[numsIndex] = i;
                        #pragma omp critical
                            numsIndex++; 
                    }
                }
            }
    }    

void par_quick_sort(std::vector<int> &array, int first, int last) {
  if (first < last) {
    int pivot = array[first + (last - first) / 2];
    int i = first, j = last;

    // Partition
    while (i <= j) {
      while (array[i] < pivot)
          i++;
      while (array[j] > pivot)
          j--;

      if (i <= j) {
          std::swap(array[i], array[j]);
          i++;
          j--;
      }
    }

        // Recursive calls
    #pragma omp parallel sections 
    {
        #pragma omp section 
        {
            if (j > first) {
                par_quick_sort(array, first, j);
            }
        }
        #pragma omp section 
        {
            if (i < last) {
                par_quick_sort(array, i, last);
            }
        }
    }
  }
}

void call_par_quick_sort (std::vector<int> &array, int first, int last) {
    #pragma omp parallel num_threads(16) 
    {
        #pragma omp single 
        {
            par_quick_sort(array, first, last);
        }
    }
}

