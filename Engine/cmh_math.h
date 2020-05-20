#ifndef CMH_MATH_H
#define CMH_MATH_H

#include "typedefs.h"
#include <math.h>

class CMHMath {

public: 
	CMHMath() {}

	static _ALWAYS_INLINE_ double atan(double in) {
		return ::atan(in);
	} 
	static _ALWAYS_INLINE_ float atan(float in) {
		return ::atanf(in);
	}

	static _ALWAYS_INLINE_ double atan2(double in_y, double in_x) {
		return ::atan2(in_y, in_x);
	}
	static _ALWAYS_INLINE_ float atan2(float in_y, float in_x) {
		return ::atan2f(in_y, in_x);
	}
};
#endif 
