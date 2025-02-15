# Linear Space Parametrized Range Mode Query Data Structures 

This repository contains implementations of 2 range mode data structures, requiring linear space, and answering queries in parametrized time. Data Structure 1 answers queries in $O(\sqrt{j-i+1})$ time, and supports appending an element to the end of the array in $O(\sqrt{n})$ worst-case time. Data Structure 2 answers queries in $O(\sqrt{j/w})$ time, and supports appending elements to the end of the array $O(\sqrt{n\cdot w})$ time.

In order to run the experiments, you must download the Succint Data Structures Library  by Gog et al. : 
https://github.com/simongog/sdsl-lite

The experiments have been conducted using the Linux operating system.

# Experiments with Data Structure 1

In order to obtain the experimental results for data structure 1, you have to create a folder named $\textbf{clean}\textunderscore\textbf{data}$ in the directory $\textbf{dataStructure1}$ of the repository. In this directory, you have to include the input file, which must contain the array of numbers which represent the array $A$. The value of $N$ must be changed from the file $\textbf{analysisDataStructure1Succint.cpp}$, as well as the name of the input file. 

In order to compile the experiment file, you must use the following command, while in directory $\textbf{dataStructure1}$:

 `g++ -O3 -DNDEBUG -I ~/include -L ~/lib  analysisDataStructure1Succint.cpp -o analysisDataStructure1Succint.exe -lsdsl` 


# Experiments with Data Structure 2

In order to obtain the experimental results for data structure 1, you have to create a folder named $\textbf{clean}\textunderscore\textbf{data}$ in the directory $\textbf{dataStructure2}$ of the repository. In this directory, you have to include the input file, which must contain the array of numbers which represent the array $A$. The value of $N$ must be changed from the file $\textbf{analysisDataStructure2Succint.cpp}$, as well as the name of the input file. 

In order to compile the experiment file, you must use the following command, while in directory $\textbf{dataStructure1}$:

 `g++ -O3 -DNDEBUG -I ~/include -L ~/lib  analysisDataStructure2Succint.cpp -o analysisDataStructure2Succint.exe -lsdsl` 

