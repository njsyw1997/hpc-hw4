# HPC Homework 4

Yiwei Shao, ys5070  

**Experiment Platform:** 

greene.hpc.nyu.edu

## Problem 1

Running nodes:gr003.hpc.nyu.edu, gr004.hpc.nyu.edu.

latency: 1.841483e-03 ms

bandwidth: 1.118808e+01 GB/s

Sbatch script is in _pingpong.sbatch_, the output of greene is in pingpong.out

## Problem 2

Sbatch script is in _ring.sbatch_, the output of greene is in ring.out

**N=50**

Running nodes: cs465.hpc.nyu.edu, cs466.hpc.nyu.edu, cs467.hpc.nyu.edu, cs468.hpc.nyu.edu

ring latency: 1.495675e-03 ms

ring bandwidth: 1.135069e+03 GB/s

**N=500**

Running nodes: cs490.hpc.nyu.edu, cs493.hpc.nyu.edu, cs491.hpc.nyu.edu, cs492.hpc.nyu.edu

ring latency: 1.847632e-05 ms

ring bandwidth: 1.282237e+04 GB/s  

**N=5000**

Running nodes: cs488.hpc.nyu.edu, cs489.hpc.nyu.edu, cs490.hpc.nyu.edu, cs491.hpc.nyu.edu

ring latency: 2.061470e-07 ms

ring bandwidth: 1.292213e+05 GB/s

## Problem 3

I achieved an mpi-scan in _scan.cpp_. Sbatch script is in _scan.sbatch_, the output of greene is in _scan.out_

Running nodes: cs490.hpc.nyu.edu, cs491.hpc.nyu.edu, cs492.hpc.nyu.edu, cs493.hpc.nyu.edu
