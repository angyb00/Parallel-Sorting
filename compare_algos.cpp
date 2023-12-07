#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>

#include "sequential/seq_algos.h"
#include "parallel/par_algos.h"

using namespace std;

/****************************************************
 * Create vector of random values 
 * @param size - Size of array 
 * @param bound - Max bound for values
*****************************************************/
void randomize_vector(std::vector<int> &nums, int size){

    // Random functionality 
    random_device dev;
    std::mt19937 rng(dev());

    for (int i = 0; i < size; i++) {
        nums[i] = i + 1;
    }
    shuffle(nums.begin(), nums.end(), rng);
}

int main(){
    // TEST VECTORS 
    std::vector<int> test_arr_1(100);
    std::vector<int> test_arr_2(1000);
    std::vector<int> test_arr_3(10000);

    // ALGORITHM TIMES || [[SEQUENTIAL TIMES],[PARALLLEL TIMES]] 
    double quick_sort_times[2][3], bubble_sort_times[2][3], merge_sort_times[2][3],  count_sort_times[2][3]; 

    // TIMER
    time_t startTime, endTime;

    /* SEQUENTIAL ALGORITHMS */
    // QUICK SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    quick_sort(test_arr_1, 0, test_arr_1.size());
    endTime = clock();
    quick_sort_times[0][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    quick_sort(test_arr_2, 0, test_arr_2.size());
    endTime = clock();
    quick_sort_times[0][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    quick_sort(test_arr_3, 0, test_arr_3.size());
    endTime = clock();
    quick_sort_times[0][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // BUBBLE SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    bubble_sort(test_arr_1);
    endTime = clock();
    bubble_sort_times[0][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    bubble_sort(test_arr_2);
    endTime = clock();
    bubble_sort_times[0][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    bubble_sort(test_arr_3);
    endTime = clock();
    bubble_sort_times[0][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // COUNT SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    count_sort(test_arr_1);
    endTime = clock();
    count_sort_times[0][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    count_sort(test_arr_2);
    endTime = clock();
    count_sort_times[0][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    count_sort(test_arr_3);
    endTime = clock();
    count_sort_times[0][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // PARALLEL ALGORITHMS 
    // QUICK SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    call_par_quick_sort(test_arr_1, 0, test_arr_1.size()-1);
    endTime = clock();
    quick_sort_times[1][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    call_par_quick_sort(test_arr_2, 0, test_arr_2.size()-1);
    endTime = clock();
    quick_sort_times[1][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    call_par_quick_sort(test_arr_3, 0, test_arr_3.size()-1);
    endTime = clock();
    quick_sort_times[1][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // BUBBLE SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    par_bubble_sort(test_arr_1, test_arr_1.size());
    endTime = clock();
    bubble_sort_times[1][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    par_bubble_sort(test_arr_2, test_arr_2.size());
    endTime = clock();
    bubble_sort_times[1][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    par_bubble_sort(test_arr_3, test_arr_3.size());
    endTime = clock();
    bubble_sort_times[1][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // COUNT SORT
    randomize_vector(test_arr_1, test_arr_1.size());
    randomize_vector(test_arr_2, test_arr_2.size());
    randomize_vector(test_arr_3, test_arr_3.size());

    // Small data set
    startTime = clock();
    par_count_sort(test_arr_1);
    endTime = clock();
    count_sort_times[1][0] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Medium data set
    startTime = clock();
    par_count_sort(test_arr_2);
    endTime = clock();
    count_sort_times[1][1] = double(endTime - startTime)/CLOCKS_PER_SEC;

    // Large data set
    startTime = clock();
    par_count_sort(test_arr_3);
    endTime = clock();
    count_sort_times[1][2] = double(endTime - startTime)/CLOCKS_PER_SEC;

    return 0;
}