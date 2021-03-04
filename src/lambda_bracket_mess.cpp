/**
 * This one is not difficult to understand, it just looks funny.
 *
 * I found it in this blog post:
 * https://shaharmike.com/cpp/lambdas-and-functions/
 *
 * It consists of a lambda declaration with an empty capture
 * and no parameters, that it is immediately called.
 * */
int main() {
    // create a single lambda and call it.
    [](){}();
    // it can also be nested:
    [](){[](){}();}();
    [](){[](){[](){[](){}();}();}();}();
}
