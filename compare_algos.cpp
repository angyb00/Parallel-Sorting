#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <seq_algos.cpp>

/****************************************************
 * Create vector of random values 
 * @param size - Size of array 
 * @param bound - Max bound for values
*****************************************************/
std::vector<int> random_vector(int size, int bound){
    std::vector<int> randVector; 
    for (int i = 0; i < size; i++){
        randVector.push_back(rand() % bound);
    }
    return randVector;
}

int main(){
    // Test vectors
    std::vector<int> test_arr_1 = random_vector(1000, 1000);
    std::vector<int> test_arr_2 = random_vector(1000, 1000);
    std::vector<int> test_arr_3 = random_vector(1000, 1000);
    std::vector<int> test_arr_4 = random_vector(1000, 1000);
    std::vector<int> test_arr_5 = random_vector(1000, 1000);

    // Test Sequential Algos
    quick_sort(test_arr_1, 0, 1);
    

    for (int i = 0; i < rand1.size(); i++){
        std::cout << rand1[i] << " "; 
    }
    std::cout << "\n";

    for (int i = 0; i < rand2.size(); i++){
        std::cout << rand2[i] << " "; 
    }
    std::cout << "\n";

    return 0;
}