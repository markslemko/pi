#pragma once
/*
 * arctan series 
 * arctan(1/2) * 6 => pi
 */

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

#else 

// recursive version 
#pragma comment(linker, "/STACK:4194304") // 4MB Stack needed instead of default 1MB
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
		// eben semifactorial
		denominator1 * theNextDenominatorFactor1, 
		denominator2 + 2, // odd numbers
		denominator3 * 4, // odd powers of 2
		// book keeping
		theNextNumeratorFactor, 
		theNextDenominatorFactor1, 
		newPi);
}

#endif