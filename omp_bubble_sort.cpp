#include<iostream>
#include<omp.h>
#include<algorithm>
#include<random>
#include<vector>

using namespace std;


void generate_random_array(vector<int> &a, int n) {
    random_device dev;
    mt19937 rng(dev());
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    shuffle(a.begin(), a.end(), rng);
}


int main(int argc, char **argv) {

    int phase, i, temp, n;
    n = 100000;
    vector<int> a(n);

    generate_random_array(a, n);

    double start_time, end_time, exec_time;
    start_time = omp_get_wtime();

    for(phase = 0; phase < n; ++phase) {
        // even phase
        if(phase % 2 == 0) {
            #pragma omp parallel for num_threads(16) default(none) shared(a,n) private(i,temp)
                for(i = 1; i < n; i += 2)
                    if(a[i-1] > a[i]) {
                        temp = a[i];
                        a[i] = a[i-1];
                        a[i-1] = temp;
                    }
            }
        // odd phase
        else {
            #pragma omp parallel for num_threads(16) default(none) shared(a,n) private(i,temp)
                for(i = 1; i < n-1; i += 2)
                    if(a[i] > a[i+1]) {
                        temp = a[i];
                        a[i] = a[i+1];
                        a[i+1] = temp;
                    }
        }
    }
    end_time = omp_get_wtime();
    exec_time = end_time - start_time;

    printf("%f\n", exec_time);
    
    return 0;
}