// Show the usage of the `optional` type.
//
// This allows for error-handling in the spirit.
// of Rust's `Option<T>`.
#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

std::optional<int> get_max(int a, int b) {
  return (a == b) ? std::nullopt : std::optional(std::max(a, b));
}


int main() {
  int a = 0, b = 0;
  std::cout << "Find the maximum of two numbers!\n\n";
  std::cout << "Enter first value: ";
  std::cin >> a;
  std::cout << "Enter second value: ";
  std::cin >> b;

  auto max_val = get_max(a, b);
  if (max_val) {
    std::cout << "max(" << a << "," << b << ") = " << max_val.value() << std::endl;
  } else {
    std::cout << a << " = " << b << std::endl;
  }
}

