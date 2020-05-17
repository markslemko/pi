#include <iostream>
#include <boost/multiprecision/cpp_bin_float.hpp>

namespace boost {
    namespace multiprecision {
        typedef number<cpp_bin_float<150>> cpp_bin_float_150;
        typedef number<cpp_bin_float<200>> cpp_bin_float_200;
        typedef number<cpp_bin_float<250>> cpp_bin_float_250;
    }
}

//#define PI_ITERATIVE
#include "pi.h"

int main()
{
    std::cout << "PI:\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<int>::max_digits10);
    std::cout << "<long long>:\n" << pi<long long>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<float>::max_digits10);
    std::cout << "<float>:\n" << pi<float>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<double>::max_digits10);
    std::cout << "<double>:\n" << pi<double>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<long double>::max_digits10);
    std::cout << "<long double>:\n" << pi<long double>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_double_extended>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_double_extended>:\n" << pi<boost::multiprecision::cpp_bin_float_double_extended>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_50>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_50>:\n" << pi<boost::multiprecision::cpp_bin_float_50>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_100>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_100>:\n" << pi<boost::multiprecision::cpp_bin_float_100>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_150>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_150>:\n" << pi<boost::multiprecision::cpp_bin_float_150>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_200>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_200>:\n" << pi<boost::multiprecision::cpp_bin_float_200>() << "\n\n" << std::flush;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_bin_float_250>::max_digits10);
    std::cout << "<boost::multiprecision::cpp_bin_float_250>:\n" << pi<boost::multiprecision::cpp_bin_float_250>() << "\n\n" << std::flush;
}
