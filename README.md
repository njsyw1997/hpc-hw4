# HPC Homework 4

Yiwei Shao, ys5070  

**Experiment Platform:** 

greene.hpc.nyu.edu

All codes should be compiled with mpic++

## Problem 1

Running nodes:gr003.hpc.nyu.edu, gr004.hpc.nyu.edu.

latency: 1.841483e-03 ms

bandwidth: 1.118808e+01 GB/s

Sbatch script is in _pingpong.sbatch_, the output of greene is in pingpong.out

## Problem 2

Sbatch script is in _ring.sbatch_, the output of greene is in ring.out

**N=50**

Running nodes: cs502.hpc.nyu.edu, cs503.hpc.nyu.edu, cs504.hpc.nyu.edu, cs505.hpc.nyu.edu

ring latency: 3.250911e-01 ms

ring bandwidth: 2.391322e+00 GB/s

**N=500**

Running nodes: cs490.hpc.nyu.edu, cs493.hpc.nyu.edu, cs491.hpc.nyu.edu, cs492.hpc.nyu.edu

ring latency: 3.085484e-02 ms

ring bandwidth: 3.208729e+00 GB/s

**N=5000**

Running nodes: cs488.hpc.nyu.edu, cs489.hpc.nyu.edu, cs490.hpc.nyu.edu, cs491.hpc.nyu.edu

ring latency: 4.992107e-03 ms

ring bandwidth: 2.960891e+00 GB/s

**N=10000**

Running nodes: cs465.hpc.nyu.edu, cs466.hpc.nyu.edu, cs467.hpc.nyu.edu, cs468.hpc.nyu.edu

ring latency: 2.662704e-03 ms

ring bandwidth: 3.181080e+00 GB/s

## Problem 3

I achieved an mpi-scan in _scan.cpp_. Sbatch script is in _scan.sbatch_, the output of greene is in _scan.out_

Running nodes: cs490.hpc.nyu.edu, cs491.hpc.nyu.edu, cs492.hpc.nyu.edu, cs493.hpc.nyu.edu

