// Illustrate usage of constexpr functions that can be evaluated at compile time.
//
// This example is two-fold.
//
// 1. The fact that the function is constexpr, allows to evaluate it at compile time,
//    if its argument is known at compile time. If it is not known at compile time,
//    its result will be computed at runtime.
// 2. The template parameter of the function is a boolean flag that is used to
//    choose either a recursive or a procedural implementation. This is done
//    at compile time using an `if constexpr` branching that chooses the required
//    implementation at compile time, such that the if-branching is not present
//    at runtime and therefore there is no performance penality at runtime.
#include <iostream>

template <int B>
constexpr unsigned long long fibonacci(unsigned long n) {
  // If B==true choose a recursive implementation at compile time.
  if constexpr(B) {
    return (n < 3) ? 1 : fibonacci<B>(n-1) + fibonacci<B>(n-2);
  // If B==false choose a procedural implementation at compile time.
  } else {
    unsigned long long n1 = 1;
    unsigned long long n2 = 1;
    unsigned long tmp = 0;
    for (size_t i=2; i < n; ++i) {
      tmp = n2;
      n2 += n1;
      n1 = tmp;
    }
    return n2;
  }
}

int main() {
  // Computations to be performed at compile time.
  constexpr auto result_recursive = fibonacci<true>(5);
  static_assert(result_recursive == 5, "Error");
  std::cout << result_recursive << std::endl;
  constexpr auto result_procedural = fibonacci<false>(5);
  static_assert(result_procedural == 5, "Error");

  // Computations to be performed at runtime.
  // We use the procedural approach to avoid running into recursive limits
  // depending on the user input!
  std::cout << result_procedural << std::endl;
  unsigned long long n;
  std::cout << "Enter index of number in fibonacci series to compute: ";
  std::cin >> n;
  std::cout << "fibonacci(" << n << ") = " << fibonacci<false>(n);
}
