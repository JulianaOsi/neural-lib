#include "stdafx.h"
#include "learningFunction.h"
#include "mainNeural.h"

struct wmatrix														//weights matrix type	
{
	int CountOfNeurons;												//comes out of the neuron
																	//enters the neuron
	double **weights;
};
const int numberOfLayers = 3;										//кол-во слоев	(Подумать как их лучше задать, мб вынести в файл)
int addition[numberOfLayers + 1];									//массив с добавлениями к кол-ву нейронов в каждом слое
int CountOfNeurons = 6;												//убрать

wmatrix sweights;													//глобальное объявление,что бы не передавать в ф-ии 

int main() {

	sweights.CountOfNeurons = CountOfNeurons;
	sweights.weights = new double*[CountOfNeurons];					//создание одномерного дин массива

	for (int i = 0; i < CountOfNeurons; i++)						//создание треугольной матрицы
		sweights.weights[i] = new double[i + 1];

	for (int i = 0; i < sweights.CountOfNeurons; i++) {
		for (int j = 0; j < i + 1; j++) {
			sweights.weights[i][j] = 0;								//обнуление матрицы
		}
	}

	srand((unsigned)time(NULL));

	int numOfNeuInLayer[] = { 2,3,1 };								//кол-во нейронов в каждом слое(перенести)

	addition[0] = 0;												//Найс колхозим, логика у меня значит неверная была,
	addition[4] = 6;												//А я хотел этого избежать

	for (int i = 1; i <= numberOfLayers; i++) {
		addition[i] = addition[i - 1] + numOfNeuInLayer[i - 1];
		cout << "addition to neurons in" << i << " layer is " << addition[i] << endl;
	}

	for (int i = 0; i < numberOfLayers; i++)
		for (int k = addition[i]; k < addition[i + 1]; k++) {
			for (int j = addition[i + 1]; j < addition[i + 2]; j++) {
				sweights.weights[j][k] = random(0, 1);
				cout << sweights.weights[j][k] << "	";
			}
			cout << endl;
		}
	cout << endl;

	for (int i = 0; i < numOfNeuInLayer[0]; i++) {
		sweights.weights[i][i] = rand() % 2 + 0;					//1 или 0 во входных значениях
	}

	cout << endl;
	valueOfNeuron(0);
	valueOfNeuron(1);
	print();
	cout << "answer is " << answer() << endl;
	system("pause");

	/*TRAINING*/
	int  epochs = 10;
	for (int e = 0;e < epochs;e++) {
		weights_delta_last(sweights.weights[CountOfNeurons - 1][CountOfNeurons - 1], expectedValue()); //считаем дельту весов для последнего слоя

		for (int i = addition[numberOfLayers - 2];i < addition[numberOfLayers - 1];i++) {       //присваиваем новые значения весам ,идущим к последнему слою (52,53,54) |потом изменить числа на цикл|
			sweights.weights[addition[numberOfLayers - 1]][i] = new_weight_last(sweights.weights[i][i], sweights.weights[addition[numberOfLayers - 1]][i]);
		}
		//изменить алг:
		for (int i = addition[numberOfLayers - 2];i < addition[numberOfLayers - 1];i++) {
			double error = error_of_neu(sweights.weights[addition[numberOfLayers - 1]][i]);						//считаем ошибку для каждого нейрона
			for (int k = 0;k < addition[numberOfLayers - 2];k++) {
				sweights.weights[i][k] = new_weight(sweights.weights[i][i], sweights.weights[i][k], error);     //присваиваем новые значения весам,идущим к остальным нейронам.
			}
		}

		for (int i = 0;i < 2;i++) {
			valueOfNeuron(i);
		}
	}
	print();
	cout << "answer is " << answer() << endl;
	system("pause");

}

double random(int min, int max) {
	double random = (double)rand() / (RAND_MAX + 1) * (max - min) + min;
	return random;
}

void print() {
	{

		for (int i = 0; i < sweights.CountOfNeurons; i++) {
			for (int j = 0; j < i + 1; j++) {
				cout << sweights.weights[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void valueOfNeuron(int inputLayer) {

	for (int j = addition[inputLayer + 1]; j < addition[inputLayer + 2]; j++)
		for (int k = addition[inputLayer]; k < addition[inputLayer + 1]; k++) {

			sweights.weights[j][j] = sweights.weights[j][j] + sweights.weights[k][k] * sweights.weights[j][k];
		}

	sigm(inputLayer);
}

void sigm(int inputLayer) {
	for (int j = addition[inputLayer + 1]; j < addition[inputLayer + 2]; j++) {
		sweights.weights[j][j] = (1 / (1 + exp(-sweights.weights[j][j])));
		//cout << "[" << j << "]""[" << j << "]" << " " << sweights.weights[j][j] << endl;
	}
}

int answer() {

	if ((sweights.weights[CountOfNeurons - 1][CountOfNeurons - 1]) > 0.5)
		return 1;
	else
		return 0;
}


double expectedValue() {
	if ((sweights.weights[0][0] == 1) || (sweights.weights[1][1] == 1)) {
		return 1;
	}
	else return 0;	
}

