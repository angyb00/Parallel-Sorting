#include <vector>

/*COUNT SORT*/
std::vector<int> count_sort(std::vector<int> nums){
    int k = nums.size();
    int valueEnd = nums[0];

    //Iterate through nums and find largest value 
    for (int i = 1; i < k; i++){
        if(valueEnd < nums[i])
            valueEnd = nums[i];
    }
    
    //Create array to store count of value found in nums 
    std::vector<int> count(valueEnd +1, 0);

    //Iterate through nums and increment each value in count array 
    for (int i = 0; i < k; i++){
        count[nums[i]]++;
    }

    //Iterate through each count and insert values into sorted array 
    int numsIndex = 0;
    for (int i = 0; i < count.size(); i++){
        if (count[i] != 0){
            while (count[i] > 0){
                nums[numsIndex] = i;
                numsIndex++;
                count[i]--;
            }
        }
    }
    return nums;
}

/*BUBBLE SORT*/
void bubble_sort(std::vector<int> nums){
    //Bring ith largest value to front
    for (int i = 0; i < nums.size(); i++){
        for (int j = )
    }
}

/*MERGE SORT*/
void merge_sort(){

}

int main(){

    return 0;
}