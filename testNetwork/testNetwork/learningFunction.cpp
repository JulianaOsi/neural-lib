#include "stdafx.h"
#include "learningFunction.h"

double wDelta;
double learningRate=0.1;

/* ������ ��� �����,������� ���� � ���������� ���� */
void weights_delta_last(double actual,double expected) {   
	double error = actual - expected;					//2.1
	double sigmoidDX = actual*(1 - actual);				//2.2*
     wDelta = error*sigmoidDX;							//2.2
}

/*����� �������� �����,������� ���� � ���������� ����*/
double new_weight_last(double valueOfNeu, double weightFrom) {      
	double new_weight = weightFrom - valueOfNeu*wDelta*learningRate;
	return new_weight;
}

double error_of_neu(double weightFrom) {
	double error = weightFrom*wDelta;
	return error;
}

/*����� �������� ����� ��� ���������� �����*/
double new_weight(double valueOfNeu, double weightTo,double error) {
	
	double sigmoidDX = valueOfNeu*(1 - valueOfNeu);
	wDelta = error*sigmoidDX;
	double new_weight = weightTo - valueOfNeu*wDelta*learningRate; 
	return new_weight;
}

