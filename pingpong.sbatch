#!/bin/bash

#SBATCH --job-name=pingpong
#SBATCH --nodes=2
#SBATCH --tasks-per-node=1  
#SBATCH --cpus-per-task=1
#SBATCH --mem=2GB 
#SBATCH --time=01:00:00 
#SBATCH --verbose
#SBATCH --output=pingpong.out

module purge 
module load openmpi/gcc/4.0.5 

mpiexec ./pingpong 0 1