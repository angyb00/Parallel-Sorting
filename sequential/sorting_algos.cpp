#include <vector>
#include <algorithm>
#include <iostream>

/*COUNT SORT*/
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

/*BUBBLE SORT*/
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

/*MERGE*/
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

/*MERGE SORT*/
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

void quick_sort(std::vector<int> &nums, int low, int high){
    if(low >= high ) 
        return;

   int partitionIndx = partition(nums, low, high);

   quick_sort(nums, low, partitionIndx - 1);
   quick_sort(nums, partitionIndx + 1, high);
}

int main(){
    //Test array 
    std::vector<int> arr1;
    arr1.push_back(5);
    arr1.push_back(4);
    arr1.push_back(3);
    arr1.push_back(2);
    arr1.push_back(1);

    //Run Count Sort
    count_sort(arr1);
    for(int i = 0; i < arr1.size(); i++){
       std::cout << arr1[i] << " "; 
    }
    std::cout << "\n"; 

    //Test array
    std::vector<int> arr2;
    arr2.push_back(5);
    arr2.push_back(4);
    arr2.push_back(3);
    arr2.push_back(2);
    arr2.push_back(1);
    
    //Run bubble Sort
    bubble_sort(arr2);
    for(int i = 0; i < arr2.size(); i++){
        std::cout << arr2[i] << " "; 
    }
    std::cout << "\n";

    // Test array
    std::vector<int> arr3;
    arr3.push_back(5);
    arr3.push_back(4);
    arr3.push_back(3);
    arr3.push_back(2);
    arr3.push_back(1);

    // Run merge Sort
    merge_sort(arr3, 0, arr3.size());
    for(int i = 0; i < arr3.size(); i++){
        std::cout << arr3[i] << " "; 
    }
    std::cout << "\n"; 

    // Test array
    std::vector<int> arr4;
    arr4.push_back(5);
    arr4.push_back(4);
    arr4.push_back(3);
    arr4.push_back(2);
    arr4.push_back(1);

    // Run quick Sort
    quick_sort(arr4, 0, arr4.size()-1);
    for(int i = 0; i < arr4.size(); i++){
        std::cout << arr4[i] << " "; 
    }
    std::cout << "\n"; 
    
    return 0;
}