# Parallel-Sorting

Compare the runtimes of parallel and sequential sorting algorithms. 

## Project Description

This project compares the runtimes of parallel and sequential versions of sorting algorithms. 
The algorithms consists of bubble sort, quick sort, and count sort. Each of the parallel algorithms utilize openMP. 

## Group members:

Angarag Gansukh - angaraggansukh@csu.fullerton.edu

Cristopher Briseno - cbriseno@csu.fullerton.edu

Cody Cole - cwcole@csu.fullerton.edu

## Setup

### Download files:

```
git clone https://github.com/angyb00/Parallel-Sorting.git
```

### Install Python3

Use preferred method for installation

### Install Matplotlib:

```
pip3 install matplotlib
```

## Compilation

This project utilizes 16 threads for the completion of the parallel algorithms. In this case, it will be necessary to login to the schools remote server. 
A sample output of running times has been provided within the projects root folder ("algo_times.csv"). To see the visualization of the times, without gathering a new list of times, 
Run: ```python3 visualizer.py``` in the projects root folder. 


### Login to remote server

```
ssh -l <username> ecs.fullerton.edu 
```

### Compile Parallel Algorithms
Navigate to parallel folder: ```cd parallel```

Compile: ```g++ -c par_algos.cpp```

### Compile Sequential Algorithms
Navigate to sequential folder: ```cd ../sequential```

Compile: ```g++ -c seq_algos.cpp```

### Compile and Run Driver Code

Navigate to root folder: ```cd ..```

Compile: ```g++ -c compare_algos.cpp```

Link files: ```g++ sequential/seq_algos.o parallel/par_algos.o compare_algos.o``` 

Run: ```./a.out```

### Run visualization 
A csv file, ("algo_times.csv"), of the running times has been generated within the project folder. This cannot be run on the remote server. 
This can be copied over to your local device by any means but below will be a supplemental option. 

The only file necessary to make the visualization is "visualizer.py". So make sure this file or the project has been downloaded onto the local device. 

Print and copy the contents of CSV file found on the remote desktop in the root folder ("PARALLEL-SORTING"): ```cat algo_times.csv```

Locate the pre-existing CSV file containing samples outputs within the root folder ("PARALLEL-SORTING")

Paste the contents found on the remote desktop in the local CSV file ("algo_times.csv"): :  ```nano algo_times.csv```

Run: ```python3 visualizer.py```

### Example Output: 
*Picture goes here*

