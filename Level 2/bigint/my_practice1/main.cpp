#include "bigint.hpp"
#include <iostream>

int main(){
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);


    // Test for leading zeros
    bigint f("00001234");
    std::cout << "f = " << f << std::endl; // Expected output: 1234

    bigint g("00000000");
    std::cout << "g = " << g << std::endl; // Expected output: 0

    bigint h("00000123");
    bigint i("00000456");
    std::cout << "h + i = " << h + i << std::endl; // Expected output: 579

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "a+b " << a + b << std::endl;
    std::cout << "c+=a " << (c += a) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b " << ++b << std::endl;
    std::cout << "b++ " << b++ << std::endl;
    std::cout << "(b << 10) + 42 " << (b << 10) + 42 << std::endl;
    std::cout << "d<<=4 " << (d <<= 4) << std::endl;
    std::cout << "d>>=(const bigint)2 " << (d >>= (const bigint)2) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "d < a " << (d < a) << std::endl;
    std::cout << "d > a " << (d > a) << std::endl;
    std::cout << "d == a " << (d == a) << std::endl;
    std::cout << "d != a " << (d != a) << std::endl;
    std::cout << "d <= a " << (d <= a) << std::endl;
    std::cout << "d >= a " << (d >= a) << std::endl;

    return 0;
}
