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

Sbatch script is in _ring.sbatch_, the output of greene is in ring_\<N\>.out

**N=50**

Running nodes: cs420.hpc.nyu.edu, cs421.hpc.nyu.edu, cs422.hpc.nyu.edu, cs423.hpc.nyu.edu

ring latency: 3.408950e-01 ms

ring bandwidth: 1.132149e+01 GB/s

**N=500**

Running nodes: cs420.hpc.nyu.edu, cs421.hpc.nyu.edu, cs422.hpc.nyu.edu, cs423.hpc.nyu.edu

ring latency: 3.389094e-02 ms

ring bandwidth: 1.192369e+01 GB/s

**N=5000**

Running nodes: cs394.hpc.nyu.edu, cs395.hpc.nyu.edu, cs396.hpc.nyu.edu, cs397.hpc.nyu.edu

ring latency: 4.603736e-03 ms

ring bandwidth: 1.181979e+01 GB/s

**N=10000**

Running nodes: cs506.hpc.nyu.edu, cs507.hpc.nyu.edu, cs508.hpc.nyu.edu, cs509.hpc.nyu.edu

ring latency: 2.730601e-03 ms

ring bandwidth: 1.182999e+01 GB/s

## Problem 3

I achieved an mpi-scan in _scan.cpp_. Sbatch script is in _scan.sbatch_, the output of greene is in _scan.out_

Running nodes: cs490.hpc.nyu.edu, cs491.hpc.nyu.edu, cs492.hpc.nyu.edu, cs493.hpc.nyu.edu

