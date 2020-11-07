// Compute the `n`-th value of the fibonacci series at compile time.
#include <iostream>

// Generic implementation
template<int N>
struct Fib {
  static constexpr int value = Fib<N-2>::value +  Fib<N-1>::value;
};

// Template specialisation for the initial condition.
template<>
struct Fib<1> {
  static constexpr int value = 1;
};

template<>
struct Fib<2> {
  static constexpr int value = 1;
};

int main() {

  constexpr int res = Fib<5>::value;
  // Make sure it really happens at compile time
  // Change the value 5 to something else and recompilation
  // will fail.
  static_assert(res == 5, "Failure");
  std::cout << res << std::endl;

}
