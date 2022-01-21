#include <iostream>
using namespace std;
class matrix {
	static int count;
	int dim;
	double* matr;
public:
	int number;
	matrix() {
		dim = 0;
		matr = new double[dim];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	matrix(int dim) {
		this->dim = dim;
		int rdim = dim * dim;
		matr = new double[rdim];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	matrix(int dim, double* matr) {
		this->dim = dim;
		int rdim = dim * dim;
		this->matr = new double[rdim];
		for (int i = 0; i < rdim; i++) this->matr[i] = matr[i];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	matrix(matrix& other) {
		this->dim = other.dim;
		int rdim = dim * dim;
		this->matr = new double[rdim];
		for (int i = 0; i < rdim; i++) this->matr[i] = other.matr[i];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	~matrix() {
		cout << "Вызван деструктор № " << number << "\n";
	}
	matrix(const matrix& other) {
		this->number = other.number;
		this->dim = other.dim;
		int rdim = dim * dim;
		this->matr = new double[rdim];
		for (int i = 0; i < rdim; i++) this->matr[i] = other.matr[i];
		cout << "Вызван конструктор копирования\n";
	}
	matrix operator + (matrix const& other) {
		matrix temp;
		temp.dim = this->dim;
		int rdim = this->dim * this->dim;
		temp.matr = new double[rdim];
		for (int i = 0; i < rdim; i++) temp.matr[i] = this->matr[i] + other.matr[i];
		cout << "Сложение выполнено\n";
		return temp;
	}
	matrix operator - (matrix const& other) {
		matrix temp;
		temp.dim = this->dim;
		int rdim = this->dim * this->dim;
		temp.matr = new double[rdim];
		for (int i = 0; i < rdim; i++) temp.matr[i] = this->matr[i] - other.matr[i];
		cout << "Сложение выполнено\n";
		return temp;
	}
	matrix& operator = (matrix const& other) {
		this->dim = other.dim;
		int rdim = dim * dim;
		this->matr = new double[rdim];
		for (int i = 0; i < rdim; i++) this->matr[i] = other.matr[i];
		cout << "Присваивание выполнено\n";
		return *this;
	}
	friend const matrix operator -(matrix const& other) {
		matrix temp;
		temp.dim = other.dim;
		int rdim = other.dim * other.dim;
		temp.matr = new double[rdim];
		for (int i = 0; i < rdim; i++) temp.matr[i] = other.matr[i] * -1;
		cout << "Инвертирование выполнено\n";
		return temp;
	}
	matrix operator * (matrix const& other) {
		matrix temp;
		temp.dim = other.dim;
		int rdim = other.dim * other.dim;
		temp.matr = new double[rdim];
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				temp.matr[j + dim * i] = 0;
				for (int k = 0; k < dim; k++)
					temp.matr[j + dim * i] += this->matr[k + dim * i] * other.matr[j + dim * k];
			}
		}
		cout << "Умножение выполнено\n";
		return temp;
	}
	matrix operator * (double x) {
		matrix temp;
		temp.dim = this->dim;
		int rdim = dim * dim;
		temp.matr = new double[rdim];
		for (int i = 0; i < rdim; i++) temp.matr[i] = this->matr[i] * x;
		return temp;
	}
	void print() {
		cout << "Dimension = " << this->dim << endl;
		cout << "Matrix:\n";
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				cout << matr[j + dim * i] << " ";
			}
			cout << endl;
		}
		cout << "Number = " << number << endl;
	}
};
int matrix::count = 0;
int main() {
	setlocale(LC_ALL, "ru");
	double Aarr[9], Barr[9];
	for (int i = 1; i < 10; i++) {
		Aarr[i - 1] = i;
		Barr[i - 1] = 10 - i;
	}
	matrix a(3, Aarr);
	matrix b(3, Barr);
	matrix c, d, e, f, g;
	c = a;
	d = c + b;
	e = d - c;
	f = e * d;
	g = -f;
	g.print();
	return 0;
}