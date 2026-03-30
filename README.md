# ishaan_nn

canonical mini neural network library in c++, built from scratch after watching Karpathy's micrograd video

inspired by [micrograd](https://github.com/karpathy/micrograd) — but operates on tensors instead of scalars, and is built to be forked for cuda.

## differences from micrograd

- **tensor-level autograd** — the computation graph is built on tensors, not individual scalars. each tensor op records its backward_fn, and `loss.backward()` walks the graph automatically
- **first-class types** — scalar, vector, matrix, and tensor are all proper classes with operator overloading
- **flat memory** — all data lives in a contiguous `float*`. no nested allocations
- **cuda-ready** — every compute op is a standalone free function. swapping cpu → cuda means replacing those function bodies, nothing else

## goal

build a working cpu neural net with tensor autograd, then fork it and replace the compute functions with cuda kernels. the layer and network code stays untouched.

