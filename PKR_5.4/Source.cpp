#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void find_5();
void find_3();
void print(string name);
void ignore(fstream& from);
void ignore_3(fstream& from);
void copy(fstream& from, fstream& to);
void full_once(fstream& from, fstream& to);
void read();
void find_2();
void find_more_2();
void delete_2();
bool check(int a, int b, int c, int d, int e);
int menu();
bool check(int math);
void add();
void all_copy(fstream& from, fstream& to);

int main() {
	int cont;
	string name;
	string m = "main.txt";
	string s = "save1.txt";
	do {
		do {
			cont = menu();
		} while (check(cont));

		switch (cont)
		{
		case 1:
			cout << "enter name: "; cin >> name;
			print(name);
			break;
		case 2:
			read();
			print(m);
			break;
		case 3:
			find_5();
			print(s);
			break;
		case 4:
			find_3();
			print(s);
			break;
		case 5:
			find_2();
			print(s);
			break;
		case 6:
			delete_2();
			print(s);
			break;
		case 7:
			find_more_2();
			print(s);
			break;
		case 8:
			add();
			print(m);
			break;
		case 0:
			break;
		default:
			break;
		}

	} while (cont != 0);
}

void print(string name) {
	ifstream f(name, ios::binary);
	int n;
	char s[100];
	char q;
	//char t;
	int k;
	/*int fis;
	int pkr;
	int oop;
	int angl*/;
	f.read((char*)&n, sizeof(n));
	cout << "---------------------------------------------------------" << endl;
	cout << "|      Student      | Math  | Phisics| PKR | OOP | Angl |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		//f >> a;
		//f >> q;
		//f >> t;
		//f >> math;
		//f >> fis;
		//f >> pkr;
		//f >> oop;
		//f >> angl;
		//cout << "|" << setw(13) << a << " " << q << "." << t << ". " << "|"
		//	<< setw(7) << math << "|" << setw(8) << fis << "|" << setw(5) << pkr << "|"
		//	<< setw(5) << oop << "|" << setw(6) << angl << "|\n" <<
		f.read((char*)&s, sizeof(s));
		cout << "|" << setw(13) << s << " ";

		f.read((char*)&q, sizeof(q));
		cout << q << ".";

		f.read((char*)&q, sizeof(q));
		cout << q << ". " << "|";

		f.read((char*)&k, sizeof(k));
		cout << setw(7) << k << "|";

		f.read((char*)&k, sizeof(k));
		cout << setw(8) << k << "|";
		

		f.read((char*)&k, sizeof(k));
		cout << setw(5) << k << "|";

		f.read((char*)&k, sizeof(k));
		cout << setw(5) << k << "|";

		f.read((char*)&k, sizeof(k));
		cout << setw(6) << k << "|" << endl;

		cout <<	"---------------------------------------------------------" << endl;
	}
}

void ignore(fstream& from) {
	//char a[100];
	//for (int i = 0; i < 8; i++) {
	//	from.read((char*)&a, sizeof(a));
	//}
	char s[100];
	char q;
	int k;
	from.read((char*)&s, sizeof(s));

	from.read((char*)&q, sizeof(q));

	from.read((char*)&q, sizeof(q));

	for (int i = 0; i < 5; i++) {
		from.read((char*)&k, sizeof(k));
	}
}

void copy(fstream& from, fstream& to) {
	char s[100];
	char q;
	int k;
	from.read((char*)&s, sizeof(s));
	to.write((char*)&s, sizeof(s));

	from.read((char*)&q, sizeof(q));
	to.write((char*)&q, sizeof(q));

	from.read((char*)&q, sizeof(q));
	to.write((char*)&q, sizeof(q));

	for (int i = 0; i < 5; i++) {
		from.read((char*)&k, sizeof(k));
		to.write((char*)&k, sizeof(k));
	}

}

void find_5() {
	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);
	fstream main("main.txt", ios::binary | ios::in);
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main.read((char*)&n, sizeof(n));
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main.read((char*)&math, sizeof(math));
		main.read((char*)&fis, sizeof(fis));
		main.read((char*)&pkr, sizeof(pkr));
		main.read((char*)&oop, sizeof(oop));
		main.read((char*)&angl, sizeof(angl));
		if (math == 5 && fis == 5 && pkr == 5 && oop == 5 && angl == 5) {
			w[k] = i;
			k++;
		}
	}

	main.close();
	main.open("main.txt", ios::binary| ios::in);
	main.read((char*)&n, sizeof(n));
	save.write((char*)&k, sizeof(k));
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	delete[]w;
}

void ignore_3(fstream& from) {
	char a[100];
	char q;
	from.read((char*)&a, sizeof(a));
	from.read((char*)&q, sizeof(q));
	from.read((char*)&q, sizeof(q));
}

void full_once(fstream& from, fstream& to) {
	//string tmp;
	//int tmp_i;
	//for (int i = 0; i < 3; i++) {
	//	from >> tmp;
	//	to << tmp << endl;
	//}
	//for (int i = 0; i < 5; i++) {
	//	from >> tmp_i;
	//	to << tmp_i << endl;
	//}
	char s[100];
	char q;
	int k;
	from.read((char*)&s, sizeof(s));
	to.write((char*)&s, sizeof(s));

	from.read((char*)&q, sizeof(q));
	to.write((char*)&q, sizeof(q));

	from.read((char*)&q, sizeof(q));
	to.write((char*)&q, sizeof(q));

	for (int i = 0; i < 5; i++) {
		from.read((char*)&k, sizeof(k));
		to.write((char*)&k, sizeof(k));
	}
}

void find_3() {
	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);
	fstream main("main.txt", ios::binary | ios::in);
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main.read((char*)&n, sizeof(n));
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main.read((char*)&math, sizeof(math));
		main.read((char*)&fis, sizeof(fis));
		main.read((char*)&pkr, sizeof(pkr));
		main.read((char*)&oop, sizeof(oop));
		main.read((char*)&angl, sizeof(angl));
		if (math == 3 || fis == 3 || pkr == 3 || oop == 3 || angl == 3) {
			w[k] = i;
			k++;
		}
	}


	main.close();
	main.open("main.txt", ios::binary | ios::in);
	main.read((char*)&n, sizeof(n));
	save.write((char*)&k, sizeof(k));
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}

	delete[]w;
}

void read() {
	fstream main("main.txt", ios::binary);
	fstream save2("save2.txt", ios::binary);
	copy(main, save2);
	main.close();

	int n;
	char a[100];
	int b;
	char ch;

	cout << "Enter amount of students: "; cin >> n;
	main.open("main.txt", ios::trunc | ios::out| ios::binary);
	main.write((char*)&n, sizeof(n));
	for (int i = 0; i < n; i++) {
		cout << "Last name: ";	 cin >> a;		main.write((char*)&a, sizeof(a));
		cout << "Initial 1: ";	cin >> ch;		main.write((char*)&ch, sizeof(ch));
		cout << "Initial 2: ";	cin >> ch;		main.write((char*)&ch, sizeof(ch));
		cout << "Enter math: "; cin >> b;		main.write((char*)&b, sizeof(b));
		cout << "Enter fis: "; cin >> b;		main.write((char*)&b, sizeof(b));
		cout << "Enter pkr: "; cin >> b;		main.write((char*)&b, sizeof(b));
		cout << "Enter oop: "; cin >> b;		main.write((char*)&b, sizeof(b));
		cout << "Enter angl:"; cin >> b;		main.write((char*)&b, sizeof(b));
	}
}

void find_2() {
	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);
	fstream main("main.txt", ios::binary | ios::in);
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;

	main.read((char*)&n, sizeof(n));
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main.read((char*)&math, sizeof(math));
		main.read((char*)&fis, sizeof(fis));
		main.read((char*)&pkr, sizeof(pkr));
		main.read((char*)&oop, sizeof(oop));
		main.read((char*)&angl, sizeof(angl));
		if (math == 2 || fis == 2 || pkr == 2 || oop == 2 || angl == 2) {
			w[k] = i;
			k++;
		}
	}

	main.close();
	main.open("main.txt", ios::binary | ios::in);
	main.read((char*)&n, sizeof(n));
	save.write((char*)&k, sizeof(k));
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}

	delete[]w;
}

void delete_2() {

	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);
	fstream main("main.txt", ios::binary | ios::in);
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;
	int contr = 0;

	main.read((char*)&n, sizeof(n));
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main.read((char*)&math, sizeof(math));
		main.read((char*)&fis, sizeof(fis));
		main.read((char*)&pkr, sizeof(pkr));
		main.read((char*)&oop, sizeof(oop));
		main.read((char*)&angl, sizeof(angl));

		if (check(math, fis, pkr, oop, angl)) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt", ios::binary | ios::in);
	main.read((char*)&n, sizeof(n));
	save.write((char*)&k, sizeof(k));

	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}

	delete[]w;
}

bool check(int a, int b, int c, int d, int e) {
	int k = 0;
	if (a == 2) {
		k++;
	}
	if (b == 2) {
		k++;
	}
	if (c == 2) {
		k++;
	}
	if (d == 2) {
		k++;
	}
	if (e == 2) {
		k++;
	}
	if (k > 1) {
		return false;
	}
	else {
		return true;
	}
}

int menu() {
	int n;
	cout << "Choose operation:\n print list(1)\n enter list(2)\n find all 5(3)\n "
		<< "find with 3(4)\n find with 2(5)\n delete with more 2(6)\n find with more 2(7)\n add(8)\n exit(0)\n ";
	cin >> n;
	return n;
}

bool check(int math) {
	if (math == 0 || math == 1 || math == 2 || math == 3 || math == 4 || math == 5 || math == 6 || math == 7 || math == 8) {
		return false;
	}
	return true;
}

void add() {
	fstream main("main.txt", ios::binary | ios::in);
	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);

	int n;
	char a[100];
	int b;
	char ch;

	main.read((char*)&n, sizeof(n));
	b = n + 1;
	save.write((char*)&b, sizeof(b));

	for (int i = 0; i < n; i++) {
		full_once(main, save);
	}
	cout << "Last name: ";	 cin >> a;		save.write((char*)&a, sizeof(a));
	cout << "Initial 1: ";	cin >> ch;		save.write((char*)&ch, sizeof(ch));
	cout << "Initial 2: ";	cin >> ch;		save.write((char*)&ch, sizeof(ch));
	cout << "Enter math: "; cin >> b;		save.write((char*)&b, sizeof(b));
	cout << "Enter fis: "; cin >> b;		save.write((char*)&b, sizeof(b));
	cout << "Enter pkr: "; cin >> b;		save.write((char*)&b, sizeof(b));
	cout << "Enter oop: "; cin >> b;		save.write((char*)&b, sizeof(b));
	cout << "Enter angl:"; cin >> b;		save.write((char*)&b, sizeof(b));
	main.close();
	save.close();
	main.open("main.txt", ios::trunc | ios::out | ios::binary);
	save.open("save1.txt" , ios::binary | ios::in );
	all_copy(save, main);

}

void all_copy(fstream& from, fstream& to) {
	int n;
	from.read((char*)&n, sizeof(n));
	to.write((char*)&n, sizeof(n));
	//from >> n;
	//to << n << endl;
	for (int i = 0; i < n; i++) {
		full_once(from, to);
	}
}

void find_more_2() {
	fstream save("save1.txt", ios::trunc | ios::out | ios::binary);
	fstream main("main.txt", ios::binary | ios::in);
	int* w = new int[100];
	int n;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
	int t = 0;
	int contr = 0;

	main.read((char*)&n, sizeof(n));
	int k = 0;
	for (int i = 0; i < n; i++) {
		ignore_3(main);
		main.read((char*)&math, sizeof(math));
		main.read((char*)&fis, sizeof(fis));
		main.read((char*)&pkr, sizeof(pkr));
		main.read((char*)&oop, sizeof(oop));
		main.read((char*)&angl, sizeof(angl));

		if (!check(math, fis, pkr, oop, angl)) {
			w[k] = i;
			k++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	q[i] = w[i];
	//}
	main.close();
	main.open("main.txt", ios::binary | ios::in);
	main.read((char*)&n, sizeof(n));
	save.write((char*)&k, sizeof(k));
	for (int i = 0; i < n; i++) {
		if (i != w[t]) {
			ignore(main);
		}
		else {
			full_once(main, save);
			t++;
		}
	}
	//while (i < n) {
	//	if (i != w[i]) {
	//		ignore(main);
	//	}
	//	else {
	//		full_once(main, save);
	//	}
	//}
	delete[]w;
}
