#include "common.h"

double add(double n1, double n2){ return n1+n2;}
double sub(double n1, double n2){ return n1-n2;}
double mul(double n1, double n2){ return n1*n2;}
double divide(double n1, double n2){ 
	if (n2==0) return 0;
	return n1/n2;
}

double (*opsFuncs[4])(double,double) = {divide,mul,sub,add};

double evaluate(int nums[], int ops[], int size){
	double sum = nums[0];
	for (int i = 0; i < size-1; i++){
		if (ops[i] == 47) ops[i] = 0;
		if (ops[i] == 42) ops[i] = 1;
		if (ops[i] == 45) ops[i] = 2;
		if (ops[i] == 43) ops[i] = 3;
	}
	for (int i = 0; i < size-1; i++){
		sum = (*opsFuncs[ops[i]])(sum, nums[i+1]);
	}
	return sum;
}