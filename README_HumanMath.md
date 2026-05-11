# Human Math

A project based on the method of solving algebraic operations (Human Math). Its goal is to reduce the time required for computation and algebraic processing by drawing inspiration from algorithms and the workings of the human brain, as well as mathematical methods for algebraic calculation.

## 🎯 Goals

Human Math was created to build a transparent big-integer library from scratch in C++, without relying on GMP or Boost. The main objectives are:

1. **Understand the fundamentals** – implement addition, subtraction, multiplication, division and modulo using string-based arithmetic, similar to how humans calculate on paper.

2. **Combine human methods with algorithms** – use classical techniques alongside Karatsuba multiplication to improve speed while keeping code readable.

3. **Provide a clean C API** – expose simple functions (`dot_add`, `dot_sub`, `dot_mul`, `dot_div`, `dot_mod`) that can be called from Python, JavaScript, or any language via ctypes.

4. **Enable learning and experimentation** – serve as an educational tool for cryptography students who want to see how Diffie-Hellman, modular exponentiation, and hash chains work internally.

5. **Optimize gradually** – start with correctness, then improve performance through better modular reduction and future Montgomery implementation.

## 🚀 Features

- Arbitrary precision integers (no 64-bit limit)
- Full signed number support
- Karatsuba multiplication
- Safe memory management with `free_string`
- Tested with 2048-bit DH and custom hashes

## 📦 Build

```bash
g++ -shared -fPIC -O3 human_math.cpp -o libhuman_math.so
```

## 💡 Example

```cpp
const char* r = dot_add("99999999999999999999", "1");
// r = "100000000000000000000"
free_string((char*)r);
```

## 📄 License
MIT License – free for learning and modification.
