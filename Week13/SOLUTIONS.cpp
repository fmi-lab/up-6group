###Задача 1.
#include <iostream>
using namespace std;
void func(int &x) {
	x = x*x;
}
void map(void(*m)(int&), int* array, int size) {
	for (int i = 0; i < size; i++) m(array[i]);
}
int main() {
	int array[5] = { 1, 2, 3, 4, 5 };
	map(func, array, 5);
	for (int i = 0; i < 5; i++) cout << array[i] << " ";
	cout << endl;
	//system("pause");
	return 0;
}
###Задача 2.
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream fin;
	fin.open("file.txt");
	double sum = 0;
	int br = 0, x;
	while (fin >> x) {
		sum += x;
		br++;
	}
	cout << sum / br << endl;
	fin.close();
	//за файл с пряк достъп(двоичен файл)
	ifstream bin;
	bin.open("secondfile.bin", ios::binary | ios::app);
	double sumofBin = 0; int brofBin = 0,xofBin;
	while (bin.read((char*)&xofBin, sizeof(int))) {
		sumofBin += x;
		brofBin++;
	}
	cout << sumofBin / brofBin << endl;
	bin.close();
	//system("pause");
	return 0;
}
###Задача 3.
#include <iostream>
using namespace std;
struct Movie{
	char name[30];
	int year;
	bool oscar;
};
void hasWonOscar(Movie* Netflix, int size) {
	cout << "These movies have an Oscar: "<<endl;
	for (int i = 0; i < size; i++) {
		if (Netflix[i].oscar) cout << Netflix[i].name << endl;
	}
}
bool after2010(int year) {
	return year >= 2010;
}
void filter(bool(*f)(int), Movie* Netflix, int size) {
	for (int i = 0; i < size; i++) {
		if (f(Netflix[i].year)) cout << Netflix[i].name << endl;
	}
}
void sort(Movie* Netflix, int size) {
	int maxYear,index;
	for (int i = 0; i < size - 1; i++) {
		maxYear = Netflix[i].year;
		index = i;
		for (int j = i + 1; j < size; j++) {
			if (Netflix[j].year>maxYear) { maxYear = Netflix[j].year; index = j; }
		}
		Movie swap(Netflix[i]);
		strcpy_s(Netflix[i].name, Netflix[index].name);
		Netflix[i].year = Netflix[index].year;
		Netflix[i].oscar = Netflix[index].oscar;
		strcpy_s(Netflix[index].name, swap.name);
		Netflix[index].year = swap.year;
		Netflix[index].oscar = swap.oscar;
	}
}
void print(Movie* Netflix, int size) {
	for (int i = 0; i < size; i++) {
		cout << Netflix[i].name << " " << Netflix[i].year << " " << boolalpha << Netflix[i].oscar << endl;
	}
}
int main() {
	Movie Netflix[8];
	for (int i = 0; i < 8; i++) {
		cout << "Information for movie No." << i+1<<endl;
		cout << "Name: "; cin.getline(Netflix[i].name, 30);
		cout << "Year: "; cin >> Netflix[i].year;
		cout << "Oscar: "; cin >> Netflix[i].oscar;
		cin.ignore();
	}
	hasWonOscar(Netflix, 8);
	filter(after2010, Netflix, 8);
	sort(Netflix, 8);
	print(Netflix, 8);
	//system("pause");
	return 0;
}
