#include <iostream>
#include <boost/multiprecision/cpp_bin_float.hpp>

namespace boost {
    namespace multiprecision {
        typedef number<cpp_bin_float<150>> cpp_bin_float_150;
        typedef number<cpp_bin_float<200>> cpp_bin_float_200;
        typedef number<cpp_bin_float<250>> cpp_bin_float_250;
        typedef number<cpp_bin_float<500>> cpp_bin_float_500;
        typedef number<cpp_bin_float<1000>> cpp_bin_float_1000;
        typedef number<cpp_bin_float<2000>> cpp_bin_float_2000;
        typedef number<cpp_bin_float<5000>> cpp_bin_float_5000;
    }
}

#define PI_ITERATIVE
#include "pi.h"

template<typename T>
void outputPi(std::string myTypeName) {
    std::cout.precision(std::numeric_limits<int>::max_digits10);
    std::cout << "<" << myTypeName << ">:\n" << pi<T>() << "\n\n" << std::flush;
}

int main()
{
    std::cout << "PI:\n\n" << std::flush;

    outputPi<long long>("long long");
    outputPi<float>("float");
    outputPi<double>("double");
    outputPi<long double>("long double");
    outputPi<boost::multiprecision::cpp_bin_float_double_extended>("boost::multiprecision::cpp_bin_float_double_extended");
    outputPi<boost::multiprecision::cpp_bin_float_50>("boost::multiprecision::cpp_bin_float_50");
    outputPi<boost::multiprecision::cpp_bin_float_100>("boost::multiprecision::cpp_bin_float_100");
    outputPi<boost::multiprecision::cpp_bin_float_150>("boost::multiprecision::cpp_bin_float_150");
    outputPi<boost::multiprecision::cpp_bin_float_200>("boost::multiprecision::cpp_bin_float_200");
    outputPi<boost::multiprecision::cpp_bin_float_250>("boost::multiprecision::cpp_bin_float_250");
    outputPi<boost::multiprecision::cpp_bin_float_500>("boost::multiprecision::cpp_bin_float_500");
    outputPi<boost::multiprecision::cpp_bin_float_1000>("boost::multiprecision::cpp_bin_float_1000");
    outputPi<boost::multiprecision::cpp_bin_float_2000>("boost::multiprecision::cpp_bin_float_2000");
    outputPi<boost::multiprecision::cpp_bin_float_5000>("boost::multiprecision::cpp_bin_float_5000");
}

