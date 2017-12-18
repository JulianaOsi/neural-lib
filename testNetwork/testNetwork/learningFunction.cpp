#include "stdafx.h"
#include "learningFunction.h"

double wDelta;
double learningRate = 0.5;

//double ** learningEpoch(double ** weights, int * input layer)					//�������� ��� ��������
/* ������ ��� �����,������� ���� � ���������� ���� */
void weights_delta_last(double actual, double expected) {
	double error = actual - expected;					//2.1				//2.2*
	wDelta = error*actual*(1 - actual);		//2.2
}

/*����� �������� �����,������� ���� � ���������� ����*/
double new_weight_last(double valueOfNeu, double weightFrom) {      //valueOfNeu-�������� �������,�� �������� ���� ��� weightFrom.
	double new_weight = weightFrom - valueOfNeu*wDelta*learningRate;
	return new_weight;
}

double error_of_neu(double weightFrom) {
	double error = weightFrom*wDelta;
	return error;
}

/*����� �������� ����� ��� ���������� �����*/
double new_weight(double valueOfNeu, double weightTo, double error) {
	wDelta = error*valueOfNeu*(1 - valueOfNeu);
	double new_weight = weightTo - valueOfNeu*wDelta*learningRate;
	return new_weight;
}
