#include<iostream>//����������� �����-������
#include<limits.h>
#include<math.h>//����������� �������������� �������

using namespace std;//������������� ����������� ����
int main() {
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n;
	cout << "������� ���������� �����: " << endl;//������ ����� � ����������
	cin >> n;//���� � ����������
	int** mas = new int* [n];//��������� ������ ��� ������
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];//��������� ������ ��� ������� ���������

	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "������� ����� �� ������" << endl;//���� ������� ���������
			cin >> mas[i][j];
		}
	}
	cout << "������: \n"; // ����� ��������� �������
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	for (int j = 0; j < n - 1; j += 2) {
		for (int i = 0; i < n; i++) {
			swap(mas[i][j], mas[i][j + 1]);        //������ 1 �� 2, 3 � 4 
		}
	}
	cout << "����� ������:\n";                     //����� ������ �������
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	return 0;//���������� ������ �������
}

		

