#!/bin/bash

#SBATCH --job-name=scan
#SBATCH --nodes=4
#SBATCH --tasks-per-node=1  
#SBATCH --cpus-per-task=1
#SBATCH --mem=2GB 
#SBATCH --time=01:00:00 
#SBATCH --verbose
#SBATCH --output=scan.out

module purge 
module load openmpi/gcc/4.0.5 

mpiexec ./scan