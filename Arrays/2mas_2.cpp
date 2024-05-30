#include<iostream> //���������� �����-������
#include<limits.h> // ���������� �������� INT_MIN � INT_MAX
#include<math.h> //���������� �������������� ������

using namespace std;//������������� ����������� ����
int main() {
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n, max_i, min_i, raznica;
	int minim = INT_MAX;//���������� ���������� ��������
	int maxim = INT_MIN;//�
	cout << "������� ����� n ="; cin >> n;//������ ����� ����� � ����������
	int** mas = new int* [n];                //��������� ������ ��� ������ ����������
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];                //��������� ������ ��� ������� ���������
	}
	cout << " ������� ����� �� ������ (������������ �������) " << endl; //������ ����� ����� � ���������� ���������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j]; //���� � ����������
		}
	}
	cout << "������: \n";                             // �������� ������ 
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	for (int i = 0; i < n; i++) {                       // ����� ������������
		for (int j = 0; j < n; j++) {
			if (mas[i][j] < minim) {
				minim = mas[i][j];
				min_i = i;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (mas[i][j] > maxim) {                      // ����� �������������
				maxim = mas[i][j];
				max_i = i;
			}
		}
	}
	raznica = abs(max_i - min_i);
	cout << min_i << " " << max_i;
	for (int i = min_i; i <= min_i; i++) {                     // ������ �������� �� �������� � ��������
		for (int j = 0; j < n; j++) {
			swap(mas[i][j], mas[i + raznica][j]);
		}
	}
	cout << "����� ������: \n";                            //������� ����� ������
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
}