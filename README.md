# ishaan_nn

canonical mini neural network library in c++, built from scratch after watching karpathy's micrograd video.

inspired by [micrograd](https://github.com/karpathy/micrograd) but with a different goal — micrograd builds a scalar computation graph and walks it for autograd. this library uses manual backward passes per layer, written out explicitly as math. no graph, no tape.

## differences from micrograd

- **manual backward** — each layer owns its gradient formula. chain rule is just calling `.backward()` in reverse order
- **first-class types** — scalars, vectors, matrices, and tensors are all proper classes with operator overloading, not just graph nodes
- **flat memory** — all data lives in a contiguous `float*`. no nested allocations
- **cuda-ready** — every compute operation is a standalone free function. swapping cpu → cuda means replacing those function bodies, nothing else

## goal

build a working cpu neural net with clean layer abstractions, then fork it and replace the compute kernels with cuda. the architecture stays the same — only the math functions change.

## structure

```
scalar → vector → matrix → tensor → nn layers → network
```

each layer in the stack builds on the one below it. the nn layers only talk to tensor.
