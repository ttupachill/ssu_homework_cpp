#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "������� ������ ������� ";
	cin >> n;
	int** a = new int* [n];            //��������� ������������ ������ � n ��������
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];            //��������� ������ ��� ������� ���������
	}
	cout << " ������� ����� ���������" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << "�������� ������\n";
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
	int mn = a[0][0], mx = a[0][0];                 //mn 1-�� ����������� ��� �� ���������    mx 1-�� ������������ ����� �� �� ���������
	int i_mn, i_mx, j_mn, j_mx;                    //i-� mn � mx, j-� mn � mx
	int k1 = 0, k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (a[i][j] % 2 == 0 and a[i][j] < mn) {                //����������� ��� ��������, �������������� �������
				mn = a[i][j];
				i_mn = i;
				j_mn = j;
				k1++;                 //�������
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] % 2 != 0 and a[i][j] > mx) {               //������������ ����� ��������, �� �������������� �������
				mx = a[i][j];
				i_mx = i;
				j_mx = j;
				k++;             //�������
			}
		}
	}
	if (k1 != 0 and k != 0) {                           //������� ����� ���� ��� ������ �������� � �������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				swap(a[i_mn][j_mn], a[i_mx][j_mx]);            //������ �� �������
			}
		}
	}
	else {                                                   //�����
		if (k == 0) {
			cout << "��������� �������� ��� � �������\n ";
		}
		if (k1 == 0) {
			cout << "׸����� �������� ��� � �������\n ";
		}
	}
	cout << "����� ������\n";
	for (int i = 0; i < n; i++, cout << endl) {                        //����� ������ �������
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}

	}

}