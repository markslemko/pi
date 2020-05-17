#include <iostream>
#include <chrono>
#include <boost/multiprecision/cpp_bin_float.hpp>
#define PI_ITERATIVE
#include "pi.h"

namespace boost {
    namespace multiprecision {
        // add types that don't normally exist in boost, but can
        typedef number<cpp_bin_float<150>> cpp_bin_float_150;
        typedef number<cpp_bin_float<200>> cpp_bin_float_200;
        typedef number<cpp_bin_float<250>> cpp_bin_float_250;
        typedef number<cpp_bin_float<500>> cpp_bin_float_500;
        typedef number<cpp_bin_float<1000>> cpp_bin_float_1000;
        typedef number<cpp_bin_float<2000>> cpp_bin_float_2000;
        typedef number<cpp_bin_float<5000>> cpp_bin_float_5000;
    }
}

template<typename T>
void outputPi(std::string myTypeName) {
    std::chrono::high_resolution_clock::time_point timerStart = std::chrono::high_resolution_clock::now();
    std::cout.precision(std::numeric_limits<T>::max_digits10);

    std::cout << "<" << myTypeName << ">:\n" << pi<T>() << "\n";

    std::chrono::high_resolution_clock::time_point timerEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timespan = std::chrono::duration_cast<std::chrono::duration<double>>(timerEnd - timerStart);
    std::cout.precision(std::numeric_limits<float>::max_digits10);
    std::cout << "took " << timespan.count() << " seconds to calculate.\n\n" << std::flush;
}

int main()
{
    std::cout << "PI:\n\n" << std::flush;

    outputPi<int>("int");
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

