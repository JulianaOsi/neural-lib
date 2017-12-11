#include "stdafx.h"
#include "matrix.h"


/*void fileOpen(string path) {
	ofstream file(path);
}
*/
/*void searchInFile(string name, int rows, int cols) {
	char str[256];
	ifstream file(name);
	file.getline(str, 255, '\n');
	cout << str;
}

/*void fileWrite(string path, const char str[]) {
	ofstream file;
	file.open(path);
	file << str;
}

void file() {
	ofstream file("sas.txt");
	file << "sas";
}
*/

void matrixCreation(int* neuronsPerLayer, int layersNum) {
	ofstream weightsFile("weights.txt");
	srand((unsigned)time(NULL));
	int *layerStart;
	int neuronsNum = 0;
	double **weights;
	layerStart = new int[layersNum];														//���������� �� ��� ��������
	for (int i = 0; i < layersNum; i++) {
		layerStart[i] = neuronsNum;
		neuronsNum += neuronsPerLayer[i];
		cout << "layer " << i + 1 << " starting is " << layerStart[i] << " index" << endl;
	}
	weights = new double*[neuronsNum];
	for (int i = 0; i < neuronsNum; i++) {
		weights[i] = new double[i + 1];
		for (int j = 0; j < i + 1; j++) {
			weights[i][j] = 0;
			cout << weights[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < layersNum - 1; i++)
		for (int k = layerStart[i]; k < layerStart[i] + neuronsPerLayer[i]; k++) {
			for (int j = layerStart[i + 1]; j < layerStart[i + 1] + neuronsPerLayer[i + 1]; j++) {
				weights[j][k] = (double)rand() / (RAND_MAX + 1) * (1 - 0) + 0;
				cout << "[" << j << "][" << k << "]=" << weights[j][k] << endl;
			}
		}
	cout << endl;
	for (int i = 0; i < neuronsNum; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << fixed << weights[i][j] << "\t";
			weightsFile << fixed << weights[i][j] << "\t";
		}
		weightsFile << "\n";
		cout << endl;
	}
	cout << endl;
	weightsFile.close();
	searchInFile(2, 1);

}

void searchInFile(int row, int col) {
	/*
	setlocale(LC_ALL, "rus");
	char buff[256];
	ifstream fin("weights.txt");					//������� ���� ��� ������
	for (int i = 0; i <= row; i++) {
		fin.getline(buff, 256, '\n');				//��������� ������
	}
	cout << "������: " << buff << endl;				//��������
	char element[8];
	int k = 0, m = 0;
	for (int i = 0; i < 256; i++) {
		if (buff[i] == '\t')
			k++;
		if (k == col) {
			for (int j = i; j < i + 8; j++) {
				element[m] = buff[j + 1];
				m++;
			}
			i = 256;
		}

	}
	*/

	/*
	int start = 8 * (col-1) + 4 * (col - 1); //������ ������� ��-��
	int k = 0;
	for (int j = start;j < 8;j++) {
		element[k] = buff[j];
		k += 1;
	}
	*/
	/*
	double value = 0;
	value = atof(element);
	cout << value << endl;
	*/

	 //��������

}

/*
void forwardWay(int* inputLayer, int* neuronsPerLayer, int layersNum) {
	for (int i = 0; i < layerStart[1]; i++) {
		cout << weights[0][0];
		weights[i][i] = inputLayer[i];
	}
	for (int i = 2; i <= layersNum; i++)
		for (int j = layerStart[i - 1]; j < layerStart[i - 1] + neuronsPerLayer[i - 1]; j++)
			for (int k = layerStart[i - 2]; k < layerStart[i - 2] + neuronsPerLayer[i - 2]; k++) {
				weights[j][j] = weights[j][j] + weights[j][j - 1] * weights[j - 1][j - 1];
				cout << "[" << j << "][" << j << "]=" << weights[j][j] << endl;
			}
}

double getWeight(int fNeuron, int tneuron) {						// from/to neuron
	return weights[tneuron][fNeuron];
}

void setWeight(int fNeuron, int tNeuron, double value) {			// from/to neuron
	weights[tNeuron][fNeuron] = value;
}
*/