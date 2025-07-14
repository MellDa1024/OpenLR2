#include "En_value.h"

//401ec0
int LoopInRange(int min, int max, int add, int *num){
	*num = *num + add;
	if (max < *num) {
		*num = min;
		return 1;
	}
	if (*num < min) {
		*num = max;
	}
	return 1;
}

//for convenience (DSTDbyTime())
double ByTime(double v1, double v2, double t1, double t2, double tO) {
	double ret, temp;

	ret = v1;
	if (v2 != v1) {
		if (t2 < tO || tO < t1 || t2 <= t1) {
			ret = v2;
			if (tO <= t1) {
				ret = v1;
			}
		}
		else {
			temp = (tO - t1) / (t2 - t1);
			ret = (1 - temp) * v1 + temp * v2;
		}
	}
	return ret;
}

//49a790
double ChangeValueByTime(double val1, double val2, double time1, double time2, double timenow, int type){
	double dVar1;

	if (val1 != val2) {
		if ( (time2 < timenow) || (time1 > timenow) || (time2 <= time1) ) {
			if (time1 < timenow) {
				return val2;
			}
		}
		else {
			if (type == 0) {
				dVar1 = (timenow - time1) / (time2 - time1);
				return (1.0 - dVar1) * val1 + dVar1 * val2;
			}
			if (type == 1) {
				dVar1 = (timenow - time1) / (time2 - time1);
				dVar1 = dVar1 * dVar1 * dVar1;
				return (1.0 - dVar1) * val1 + dVar1 * val2;
			}
			if (type == 2) {
				dVar1 = 1.0 - (timenow - time1) / (time2 - time1);
				dVar1 = 1.0 - dVar1 * dVar1 * dVar1;
				return (1.0 - dVar1) * val1 + dVar1 * val2;
			}
		}
	}
	return val1;
}