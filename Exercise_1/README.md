# 2022 Final project Foundation of High Performance Computing
### Group: Enrico Malcapi Gaia Marsich
## Exercise 1 Repository
This is the folder containing all the files regarding the Exercise 1 for the final project of HPC. 


The content of this folder is the following: 
| Folder      | Description |
| :---        |    :----:   |
| Files      | Folder containing all the files needed for the compilation       |
| check_set_ups   | Folder containing some initial configurations used to check the correctness of the program|
|data | Folder containing all the data generated during the scalability studies | 

### Compilation of the program 
To compile the program ensure first to have downloaded the gcc and mpicc compilers (on ORFEO load the compilers with the command `module load openMPI/4.1.5/gnu/12.2.1`). If somone wish to change compilers remember to change them into the Make file. 

To run the compilation just use the command `make` inside the Files folder. 

After the compilation the following files and folder will be created: 
1. game_of_life.x: executable of the program game_of_life
2. converter.x: executable of the converter program
3. results: folder required to the game_of_life program to write the results

**(!NOTE: if you wish to run the executable game_of_life.x on a different directory remember to move also the results folder!)**

### Execution of the program 
1.The *converter.x* executable is used to produce an image from an arbitrary grid set up built in the set_up.txt file. To create the configuration use . to denote dead cells and O (big o) do denote an alive cell. After creating the configuration in the set_up.txt file run the program as follow: 

`./converter.x <number_of_rows> <number_of_columns> <cell_size>` 

The program will create two images representing the original and scaled version of the desired grid configuration. This program was meanly used to check the correctness of the game_of_life program. 

2.The *game_of_life.x* executable is the parallelized implementation of the game of life. It has the following options:
- `-i` to run the initialization mode and produce an initial set_up (See the report for more details on the initial configuration)
- `-k <size>` to specify the size of the square grid initial set up
- `-f <file_name>` to secify the name of the output for the configuration or to specify the name of the initial set_up for the evolution mode
- `-r` to run the evolution mode
- `-n <iteration>` to specify the number of evolution steps
- `-s <frequency>` to specify the frequency to return the result of the current step evolution
- `-e` to run the ordered evolution (by defoult it runs the static evolution)
- `-c <cell_size>` to print the results in a scaled version with each cell of dimension cell_size x cell_size (meanly used to check the correctnes of the program)



To execute the program use the mpirun command as follow

`mpirun <mpirun_options> ./game_of_life.x <game_of_life_options>`

Remember that the program is an hybrid parallelization and to specify the number of openMP threads each MPI process will spawn use the environmental variable OPENMP_NUM_THREADS as follow `export OPENMP_NUM_THREADS=<number_of_threads_per_process>`. 
  
    


