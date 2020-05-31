#pragma once
/*
 * arctan series 
 * arctan(1/2) * 6 => pi
 */

//#define PI_ITERATIVE
//#define FULL_PARAMETER_RECURSION
//#define MINIMAL_PARAMETER_RECURSION

#ifdef PI_ITERATIVE

// iterative version
template<typename T>
constexpr T pi() {
	T prevPi = 0;
	T nextNumerator = 1;
	T numerator = 1;
	T denominator1 = 2;
	T nextDenominatorFactor1 = 2;
	T denominator2 = 3;
	T denominator3 = 8; // 2^3
	T pi = (T)3; // start with this in the series 6/2
	do {
		prevPi = pi;
		pi += ((T)6 * numerator) / (denominator1 * denominator2 * denominator3);

		// odd semifactorial 
		nextNumerator += 2; // odd numbers
		numerator *= nextNumerator;

		// even semifactorial 
		nextDenominatorFactor1 += 2; // even numbers
		denominator1 *= nextDenominatorFactor1;

		denominator2 += 2; // odd numbers
		denominator3 *= 4; // odd powers of 2
	} while (pi != prevPi); // is there further refinement?
	return pi;
}

#elif defined(FULL_PARAMETER_RECURSION)

// recursive version 

// 4MB stack required for cpp_bin_float_250 - larger values would need more stack, iterative method is obviously better with memory
template<typename T>
constexpr T pi(const T numerator = 1, const T denominator1 = 2, const T denominator2 = 3, const T denominator3 = 8, const T nextNumeratorFactor = 1, const T nextDenominatorFactor1 = 2, const T antecedentPi = (T)3)
{
	const T newPi = antecedentPi + (6 * numerator) / (denominator1 * denominator2 * denominator3);
	if (newPi == antecedentPi) {
		// we can refine no further
		return antecedentPi;
	}
	const T theNextNumeratorFactor = nextNumeratorFactor + 2;
	const T theNextDenominatorFactor1 = nextDenominatorFactor1 + 2;
	return pi(
		// odd semifactorial
		numerator * theNextNumeratorFactor, 
		// even semifactorial
		denominator1 * theNextDenominatorFactor1, 
		denominator2 + 2, // odd numbers
		denominator3 * 4, // odd powers of 2
		// book keeping
		theNextNumeratorFactor, 
		theNextDenominatorFactor1, 
		newPi);
}
#else 

// recursive minimal parameter version

// represent n!! 
template<typename T>
constexpr T doubleFactorial(const T num)
{
	if (num > 1) {
		return num * doubleFactorial(num - 2);
	} else {
		return 1;
	}
}

// simplistic - positive powers only ( > 0 )
template<typename T>
constexpr T pow2(const T exponent)
{
	if (exponent > 1) {
		return 2 * pow2(exponent - 1);
	}
	else {
		return 2;
	}
}


template<typename T>
constexpr T pi(const T iteration = 0, const T antecedentPi = (T)3)
{
	// calculate the iteration's simple Factors
	const T nextNumeratorFactor = (iteration) * 2 + 1;
	const T nextDenominatorFactor1 = (iteration) * 2 + 2;
	const T denominator2 = iteration * 2 + 3;

	// fully calculate iteration's function Factors
	const T numerator = doubleFactorial<T>(nextNumeratorFactor);
	const T denominator1 = doubleFactorial<T>(nextDenominatorFactor1);
	const T denominator3 = pow2(denominator2);

	// pi increment at iteration
	const T newPi = antecedentPi + (6 * numerator) / (denominator1 * denominator2 * denominator3);

	if (newPi == antecedentPi) {
		// we can refine no further
		return antecedentPi;
	}
	return pi(
		iteration + 1,
		newPi);
}


#endif