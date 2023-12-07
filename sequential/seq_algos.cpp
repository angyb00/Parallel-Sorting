#include<iostream>
#include<algorithm>
#include<random>
#include<vector>

#include "seq_algos.h"

/****************************************************
 * COUNT SORT
 * @param nums - Vector to be sorted
*****************************************************/
void count_sort(std::vector<int> &nums){
    int k = nums.size();
    int valueEnd = *std::max_element(std::begin(nums), std::end(nums)); 
    
    //Create array to store count of value found in nums 
    std::vector<int> count(valueEnd +1, 0);

    //Iterate through nums and increment each value in count array 
    for (int i = 0; i < k; i++){
        count[nums[i]]++;
    }

    //Iterate through each count and insert values into sorted array 
    int numsIndex = 0;
    for (int i = 0; i < count.size(); i++){
        while (count[i] > 0){
            nums[numsIndex] = i;
            numsIndex++;
            count[i]--;
        }
    }
}

/****************************************************
 * BUBBLE SORT
 * @param nums - Vector to be sorted
*****************************************************/
void bubble_sort(std::vector<int> &nums){
    //Bring ith largest value to front
    int sorted = 0; 
    int n = nums.size();

    while (sorted < n){
        for(int i = 0; i < n - sorted -1; i++){
            // Bubble current value if it is larger
            if (nums[i] > nums[i+1]){
                std::swap(nums[i], nums[i+1]);
            }
        }
        sorted++;
    }
}

/****************************************************
 * Helper function to merge sort
 * @param nums - Vector to be sorted
 * @param start - Start index of given vector 
 * @param lSize - Size of left sub array  
 * @param rSize - Size of right sub array 
*****************************************************/
void merge(std::vector<int> &nums, int start, int lSize, int rSize){
    
    // Temp array to store sorted values 
    int sorted [lSize + rSize]; 

    // Add values into sorted array 
    int lIndx = start, rIndx = start + lSize, i = 0;
    while (i < lSize + rSize){
        // Left is exghausted, add the remainder of right
        if (lIndx >= start + lSize){
            sorted[i] = nums[rIndx];
            i++; rIndx++; continue;
        }
        // Right is exghausted, add the remainder of left
        else if (rIndx >= start + lSize + rSize){
            sorted[i] = nums[lIndx];
            i++; lIndx++; continue;
        }

        else {
            // Compare values
            if (nums[lIndx] < nums[rIndx]) {
                sorted[i] = nums[lIndx];
                i++, lIndx++;
            }
            else {
                sorted[i] = nums[rIndx];
                i++, rIndx++;
            }
        }
    }

    // Copy sorted values into array 
    int j = start;
    for (int i = 0; i < lSize + rSize; i++){
        nums[j] = sorted[i]; 
        j++;
    }
}

/****************************************************
 * MERGE SORT 
 * @param nums - Vector to be sorted
 * @param start - Start index of given vector 
 * @param size - Size of vector
*****************************************************/
void merge_sort(std::vector<int> &nums, int start, int size){
    //std::cout << "here";
    if (size > 1){
        // Compute size of sub arrays
        int lSize, rSize; 
        lSize = size/2;
        if (size % 2 == 1)
            rSize = lSize + 1;
        else
            rSize = lSize;

        // Continue to break into smaller sub arrays
        merge_sort(nums, start, lSize);
        merge_sort(nums, start + lSize, rSize);

        // Merge arrays back together
        merge(nums, start, lSize, rSize);
    }
}

/****************************************************
 * Helper function to quick sort 
 * @param nums - Vector to be sorted
 * @param low - Min bound of array 
 * @param high - Max bound of array   
*****************************************************/
int partition(std::vector<int> &nums, int low, int high){
   int pivot = low;
   int lowIndx = pivot + 1;
  
   // iterating through all elements and putting them in right set
   for (int i=pivot+1; i<=high; i++) {
       if (nums[i] < nums[pivot] ) {
           std::swap(nums[i], nums[lowIndx]);
           lowIndx+=1;
       }
   }

   // move the pivot in correct position
   std::swap(nums[pivot], nums[lowIndx-1]);

   return lowIndx-1;
}

/****************************************************
 * QUICK SORT
 * @param nums - Vector to be sorted
 * @param low - Min bound of array 
 * @param high - Max bound of array   
*****************************************************/
void quick_sort(std::vector<int> &nums, int low, int high){
    if(low >= high ) 
        return;

   int partitionIndx = partition(nums, low, high);

   quick_sort(nums, low, partitionIndx - 1);
   quick_sort(nums, partitionIndx + 1, high);
}