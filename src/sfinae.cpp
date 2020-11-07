// A very simple example for SFINAE.
//
// SFINAE: Substitution Failure Is Not An Error.
#include <iostream>
#include <type_traits>

template <typename T>
class AwesomeType {
  public:
    T value;
    AwesomeType(T&& t) : value(std::move(t)) {}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const AwesomeType<T>& awesome) {
  return os << "AwesomeType[" << awesome.value << "]";
}

template <typename T>
struct is_awesome : public std::false_type {};

template <typename T>
struct is_awesome<AwesomeType<T>> : public std::true_type {};

template <typename T>
void print_awesomeness(const T& t) {
  if constexpr(is_awesome<T>::value) {
    std::cout << t << " is awesome!" << std::endl;
  } else {
    std::cout << t << " is not awesome." << std::endl;
  }
}

int main() {
  int i = 7;
  AwesomeType awesome(std::string("Chaos"));
  print_awesomeness(i);
  print_awesomeness(awesome);
}
