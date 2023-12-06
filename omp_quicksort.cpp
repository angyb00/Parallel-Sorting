
#include<iostream>
#include<omp.h>
#include<algorithm>
#include<random>
#include<vector>


void rand_array(std::vector<int> &array, int N) {
  std::random_device dev;
  std::mt19937 rng(dev());

  for(int i = 0; i < N; i++) {
    array[i] = i + 1;
  }

  std::shuffle(array.begin(), array.end(), rng);
}

void q_sort(std::vector<int> &array, int first, int last) {
    if (first < last) {
        int pivot = array[first + (last - first) / 2];
        int i = first, j = last;

        // partition
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

        // recursive calls
#pragma omp parallel sections
        {
#pragma omp section
	  {
            if (j > first) {
                q_sort(array, first, j);
	    }
	  }
#pragma omp section
	  {
            if (i < last) {
                q_sort(array, i, last);
	    }
	  }
        }
    }
}


int main(int argc, char **argv) {

  int  N = 100000;;
  std::vector<int> array(N);
  
  // generate random array
  rand_array(array, N);

  // timer
  double start_time, end_time, exec_time;
  start_time = omp_get_wtime();

  /*
  std::cout << "Random Array: ";
  for(int i = 0; i < N; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl; */

  // parallel quicksort
#pragma omp parallel num_threads(16)
  {
    #pragma omp single
    {
      std::cout << "--Sorting in parallel using " << omp_get_num_threads() << " threads!--\n";
      q_sort(array, 0, N - 1);
    }
  }

  // end timer
  end_time = omp_get_wtime();
  exec_time = end_time - start_time;
  std::cout << "--Execute time: " << exec_time << "--\n";

  /*// show sorted array
  std::cout << "Sorted Array: ";
  for(int i = 0; i < N; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl; */
  
  return 0;
}
