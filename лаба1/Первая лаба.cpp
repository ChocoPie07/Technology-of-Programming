#include <iostream>
#include <string>
using namespace std;
struct Product {
	string productname;
	int cost;
};
struct node {
	Product data;
	node* next;
}; 
class List {
	node* start;
	node* finish;
	node* tempo;
	int number = 0;
	bool isEmpty(){
		return start == NULL;
	}
public:
	List(){
		start = NULL;
		finish = NULL;
	}
	void addatfinish(Product p) {
		tempo = new node;
		tempo->data = p;
		tempo->next = NULL;
		if (isEmpty()) {
			start = tempo;
			finish = tempo;
		}
		else {
			finish->next = tempo;
			finish = tempo;
		}
		number++;
	}
	void addatbeginning(Product p){
		tempo = new node;
		tempo->data = p;
		if (isEmpty()){
			tempo->next = NULL;
			finish = tempo;
		}
		else
			tempo->next = start;
		start = tempo;
		number++;
	}
	
	void addbefore(Product p, Product pos){
		if (isEmpty()){
			cout << "Пустой список";
		}
		else if (number == 1){
			addatbeginning(p);
			number++;
		}
		else{
			node* prev;
			node* after;
			prev = start;
			after = start->next;
			while (after->next != NULL && after->data.productname != pos.productname){
				prev = after;
				after = after->next;
			}
			if (after->data.productname == pos.productname){
				node* pNode = new node;
				pNode->data = p;
				pNode->next = prev->next;
				prev->next = pNode;

				number++;
			}
			else{
				cout << "Ошибка";
			}
		}
	}
	void addafter(Product p, Product pos){
		if (isEmpty()){
			cout << "Пустой список";
		}
		else if (number == 1){
			addatfinish(p);
		}
		else{
			tempo = new node;
			tempo = start;
			while (tempo->next != NULL && tempo->data.productname != pos.productname){
				tempo = tempo->next;
			}
			if (tempo->data.productname == pos.productname){
				node* targetNext = tempo->next;
				node* pNode = new node;
				pNode->data = p;
				pNode->next = targetNext;
				tempo->next = pNode;
				number++;
			}
			else{
				cout << "Ошибка";
			}
		}
	}
	void removeN(Product p){
		tempo = start;
		node* prev;
		while (tempo->next != NULL && tempo->data.productname != p.productname){
			prev = tempo;
			tempo = tempo->next;
		}
		if (tempo->data.productname == p.productname){
			if (number > 1){
				prev->next = tempo->next;
				delete tempo;
			}
			else{
				cout << "нельзя удалить без добавления узла";
			}
		}
		else{
			cout << "Ошибка";
		}
	}
	void display(){
		if (!isEmpty()){
			for (tempo = start; tempo != NULL; tempo = tempo->next){
				cout << tempo->data.productname << " ";
				cout << tempo->data.cost << " ";
			}
			cout << endl;
		}
		else{
			cout << "Пустой список";
		}
	}
};
int main(){
	List l;
	Product product1, product2, product3, product4, product5, product6, product7, product8, product9;
	product1.productname = "Масло";
	product1.cost = 1;
	l.addatbeginning(product1);
	product2.productname = "Мясо";
	product2.cost = 2;
	l.addatbeginning(product2);
	product3.productname = "Яица";
	product3.cost = 3;
	l.addatfinish(product3);
	product6.productname = "Молоко";
	product6.cost = 5;
	l.addatfinish(product6);
	product6.productname = "Чай";
	product6.cost = 6;
	l.addatfinish(product6);
	product6.productname = "Яблоки";
	product6.cost = 7;
	l.addatfinish(product6);
	l.display();
	product4.productname = "Чипсы";
	product4.cost = 4;
	product9.productname = "Вода";
	product9.cost = 10;
	l.addafter(product4, product1);
	l.addbefore(product9, product1);
	l.display();

	return 0;
}
