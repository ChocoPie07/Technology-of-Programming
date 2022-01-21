#include <iostream>
using namespace std;
class vect {
	static int count;
	int dim;
	double* coords;
public:
	int number = 0;
	vect() {
		dim = 0;
		coords = new double[dim];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	vect(int dim) {
		this->dim = dim;
		coords = new double[dim];
		for (int i = 0; i < dim; i++) coords[i] = 0;
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	vect(int dim, double* coords) {
		this->dim = dim;
		this->coords = new double[dim];
		for (int i = 0; i < dim; i++) this->coords[i] = coords[i];
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	vect(vector& other) {
		dim = other.dim;
		coords = other.coords;
		count++;
		number = count;
		cout << "Вызван конструктор № " << number << "\n";
	}
	vect(const vector& other) {
		this->number = other.number;
		this->dim = other.dim;
		this->coords = new double[dim];
		this->coords = other.coords;
		cout << "Вызван конструктор копирования" << "\n";
	}
	~vect() {
		cout << "Вызван деструктор № " << number << "\n";
	}
	vect operator + (vector const& other) {
		vect temp;
		temp.dim = this->dim;
		temp.coords = new double[this->dim];
		for (int i = 0; i < this->dim; i++) temp.coords[i] = this->coords[i] + other.coords[i];
		return temp;
	}
	vect operator - (vector const& other) {
		vect temp;
		temp.dim = this->dim;
		temp.coords = new double[this->dim];
		for (int i = 0; i < this->dim; i++) temp.coords[i] = this->coords[i] - other.coords[i];
		return temp;
	}
	vect& operator = (vector const& other) {
		this->dim = other.dim;
		this->coords = new double[this->dim];
		for (int i = 0; i < dim; i++) this->coords[i] = other.coords[i];
		cout << "Присваивание выполнено\n";
		return *this;
	}
	vect operator * (double x) {
		vect temp;
		temp.dim = this->dim;
		temp.coords = new double[this->dim];
		for (int i = 0; i < dim; i++) temp.coords[i] = this->coords[i] * x;
		cout << "Умножение выполнено\n";
		return temp;
	}
	friend const vector operator - (vector const& other) {
		vect temp;
		temp.dim = other.dim;
		temp.coords = new double[other.dim];
		for (int i = 0; i < other.dim; i++) temp.coords[i] = other.coords[i] * -1;
		cout << "Инвертирование выполнено\n";
		return temp;
	}
	void print() {
		cout << "Dimension = " << this->dim << endl;
		cout << "Coords: "; for (int i = 0; i < dim; i++) cout << coords[i] << " ";
		cout << "\nNumber = " << number << endl;
	}
};
int vect::count = 0;
int main() {
	setlocale(LC_ALL, "ru");
	double Aarr[2] = { 0,1 };
	double Barr[2] = { 2,3 };
	vect a(2, Aarr);
	vect b(2, Barr);
	vect c, d, e, f, g;
	c = a;
	d = c + b;
	e = d - c;
	f = a * 1;
	g = -e;
	g.print();
	return 0;
}