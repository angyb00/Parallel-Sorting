import matplotlib.pyplot as plt
import numpy as np
import csv 

# READ IN DATA 
times = open("algo_times.csv", "r");
times.readline();
seq_times = times.readline().split(" ");
par_times = times.readline().split(" ");

quick_sort_times = [list(map(float, seq_times[0].split(","))), list(map(float, par_times[0].split(",")))]
bubble_sort_times = [list(map(float, seq_times[1].split(","))), list(map(float, par_times[1].split(",")))]
count_sort_times = [list(map(float, seq_times[2].split(","))), list(map(float, par_times[2].split(",")))]

# PLOT DATA 
xpoints = np.array([100, 1000, 10000])
# QUICK SORT 
plt.figure(1)
plt.title("Quick Sort")
seq_quick_sort_ypoints = np.array(quick_sort_times[0])
par_quick_sort_ypoints = np.array(quick_sort_times[1])
plt.plot(xpoints, seq_quick_sort_ypoints, label = "Sequenial")
plt.plot(xpoints, par_quick_sort_ypoints, label = "Parallel")
plt.xlabel("Number of Elements")
plt.ylabel("Time in seconds")

# BUBBLE SORT 
plt.figure(2)
plt.title("Bubble Sort")
seq_bubble_sort_ypoints = np.array(bubble_sort_times[0])
par_bubble_sort_ypoints = np.array(bubble_sort_times[1])
plt.plot(xpoints, seq_bubble_sort_ypoints, label = "Sequenial")
plt.plot(xpoints, par_bubble_sort_ypoints, label = "Parallel")
plt.xlabel("Number of Elements")
plt.ylabel("Time in seconds")

# COUNT SORT 
plt.figure(3)
plt.title("Count Sort")
seq_count_sort_ypoints = np.array(count_sort_times[0])
par_count_sort_ypoints = np.array(count_sort_times[1])

plt.plot(xpoints, seq_count_sort_ypoints, label = "Sequenial")
plt.plot(xpoints, par_count_sort_ypoints, label = "Parallel")
plt.xlabel("Number of Elements")
plt.ylabel("Time in seconds")
plt.show()

