#include <iostream>
#include <iomanip>
using namespace std;

void line1(); //объявление (прототип) функции line1
void line2(int, char);
void title(int, int = 3, int = 17, char = '=');
int nod(int, int);
bool QE(double, double, double, double&, double&);
void fun5(double, char = '*', int = 2);
int nn = 1;
void myswap(int&, int&);
void myswap(double&, double&);
void myswap(char&, char&);
void tmout(int, int, double);
void tmout(int, int);
void tmout(int, double);

inline int factorial(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}

void myout(int[], int, int = 4);
int mymax(int[], int);
int mymin(int[], int);

void triangle(int, char);
double myroot(int, int, double = pow(10, -7));

inline void divider(int m)
{
	cout <<"n = "<<m<<endl<< "Делители: 1 ";
	for (int i=2; i<=m; i++)
		if (m%i==0)
		{
			cout << i << " ";
			m /= i;
			i--;
		}
	cout << endl;
}

void arrrRShift(int[], int);
int main()
{
	setlocale(LC_ALL, "rus");

	{title(nn++);
	// 1=й вариант без функции
	int n = 50;
	char ch = '-',
		s[32] = "Модульное построение программ";

	for (int i = 0; i < n; i++) cout << ch;
	cout << endl;
	cout << setw(32) << s << endl;
	for (int i = 0; i < n; i++) cout << ch;
	cout << endl;

	//2-й вариант - используем функцию без параметров
	line1();	//первый вызов функции line1
	cout << setw(32) << s << endl;
	line1();	//второй вызов функции line1

	// 3-й вариант - используем функцию с параметрами
	n = 70;
	ch = '=',
		line2(n, ch);
	int ln = strlen(s);
	cout << setw(n / 2 + ln / 2) << s << endl;
	line2(70, '~');
	}


	{	title(nn++);
	title(15, 10, 10, '-');
	title(10, 6, 12, '~');
	}



	{	title(nn++);
	int m = 17599692, n = 709927218;
	cout << "НОД(" << m << "," << n << ") = " << nod(m, n) << endl;
	m = 514396; n = 309603;
	cout << "НОД(" << m << "," << n << ") = " << nod(m, n) << endl;
	}



	{	title(nn++);
	double a = 2.7, b = 15.2, c = 6.5; //a=5.3, b= 8.1, c=17;
	double root1, root2;
	cout << "Коэффициенты: " << a << " " << b << " " << c << ", корни: " << fixed << setprecision(6);

	if (QE(a, b, c, root1, root2))
		cout << root1 << ", " << root2 << endl;
	else
		cout << "нет вещественных корней";
	}


	{	title(nn++);
	fun5(2.5, '-', 11);
	fun5(2.5, '-');
	fun5(2.5);
	//fun5();	//ошибка!
	//fun(3.85, , 33);
	fun5(3.85, '*', 33);
	}


	{nn = 8; title(nn++);
	{int a = 517, b = 2063;
	cout << setw(14) << left << "Целые: " << a << " " << b << endl;
	cout << "Перестановка: ";
	myswap(a, b);
	cout << a << " " << b << endl;
	}

	{double a = 3.48, b = -5.6;
	cout << "Вещественные: " << a << " " << b << endl;
	cout << "Перестановка: ";
	myswap(a, b);
	cout << a << " " << b << endl;
	}

	{char a = '~', b = '&';
	cout << setw(14) << left << "Символы: " << a << " " << b << endl;
	cout << "Перестановка: ";
	myswap(a, b);
	cout << a << " " << b << endl;
	}
	}


	{title(nn++);
	int h = 14, m = 9; double s = 9.45;
	cout << "Формат 1: ";	tmout(h, m, s);
	cout << endl << "Формат 2: "; tmout(h, m);
	cout << endl << "Формат 3: "; tmout(m, s);
	cout << endl;
	}


	{title(nn++);
	int n = 8, m = 3;
	cout << "Количество сочетаний " << m << " из " << n << " равно "
		<< factorial(n) / factorial(m) / factorial(n - m);
	cout << endl;
	}


	{title(nn++);	//11
	const int na = 10; int A[na] = { 6, -5, 7, 2, -7, -3, 8, 5, 0, 4 };
	cout << "Исходный массив: "; myout(A, na);

	int i = mymax(A, na);
	cout << "Элемент A[" << i << "]= " << A[i] << " максимальный" << endl;

	i = mymin(A, na);
	cout << "Элемент A[" << i << "]= " << A[i] << " минимальный" << endl;
	}


	{title(nn++);	//12
	int M[5] = { 3,7,2,0,5 };
	cout << setw(22) << left << "Исходный массив: "; myout(M, 5);
	int n = mymax(M, 5); myswap(M[n], M[4]); myout(M, 5);

	n = mymax(M, 4); myswap(M[n], M[3]); myout(M, 5);
	n = mymax(M, 3); myswap(M[n], M[2]); myout(M, 5);
	n = mymax(M, 2); myswap(M[n], M[1]); myout(M, 5);
	cout << setw(22) << left << "Упорядоченный массив:"; myout(M, 5);

	const int na = 10;
	int A[na] = { 6, -5, 7, 2, -7, -3, 8, 5, 0, 4 };
	cout << endl << setw(22) << left << "Исходный массив:"; myout(A, na);
	for (int i = na; i > 0; i--)
	{
		n = mymax(A, i);
		myswap(A[n], A[i - 1]);
	}
	cout << setw(22) << left << "Упорядоченный массив:"; myout(A, na);
	}


	{title(nn++);	//13 
	triangle(9, '*');
	triangle(14, 'o');
	}


	{title(nn++);	//14
	line2(25, '-');
	int x; double n = 5;
	cout << setw(6) << right << "x" << setw(12) << right << "x^" << 1 / n << endl;
	line2(25, '-');
	for (x = 0; x <= 32; x += 4)
		cout << setw(6) << right << x << setw(16) << right << fixed << setprecision(5)
		<< myroot(x, n) << endl;
	}


	{title(nn++);	//15
	int n = 7644;
	divider(n);
	n = 3019302;
	divider(n);
	}


	{title(nn++);	//16
	int X[10] = { 38, -82, 29, 46, -63, 24, 29, -75, 69, 44 };
	cout <<setw(17)<<left<< "Исходный массив: "; myout(X,10);
	cout << setw(17)<<left << "Сдвиг вправо: "; myout(X, 10);
	}


	cout << endl; system("pause");
	return 0;
}

void line1()	//определение (текст) функции line1
{
	char ch = '-'; int n = 50;
	for (int i = 0; i < n; i++)
		cout << ch;
	cout << endl;
}

void line2(int len, char c)
{
	for (int i = 0; i < len; i++)
		cout << c;
	cout << endl;
}

void title(int n, int len1, int len2, char ch)
{
	cout.flags(0); cout << endl;
	for (int i = 0; i < len1; i++) cout << ch;
	cout << " Задание №" << n << " ";
	for (int i = 0; i < len2; i++) cout << ch;
	cout << endl;
}

int nod(int m, int n)
{
	int res;	//result
	while (m)
	{
		if (m > n)
		{
			m %= n;
			if (m == 0)
			{
				res = n;
				break;
			}
		}
		else
		{
			n %= m;
			if (n == 0) { res = m; break; }
		}
	}
	return res;
}

bool QE(double a, double b, double c, double& x1, double& x2)
{
	bool out = false;
	double d = b * b - 4 * a * c;
	if (d >= 0)
	{
		d = sqrt(d); x1 = (-b + d) / 2 / a; x2 = (-b - d) / 2 / a;
		out = true;
	}
	return out;
}

void fun5(double f, char ch, int i)
{
	cout << setw(6) << f << setw(6) << ch << setw(6) << i << endl;
}

void myswap(int& u, int& v)
{
	if (u == v) return;
	int t = u; u = v; v = t;
}

void myswap(double& u, double& v)
{
	if (u == v) return;
	double t = u; u = v; v = t;
}

void myswap(char& u, char& v)
{
	if (u == v) return;
	char t = u; u = v; v = t;
}

void tmout(int h, int m, double s)
{
	cout << h << "h:"
		<< setfill('0')
		<< setw(2) << m << "m:"
		<< fixed << setprecision(2) << setw(5) << s << "s"
		<< setfill(' ');
}

void tmout(int h, int m)
{
	cout << h << "h:"
		<< setfill('0')
		<< setw(2) << m << "m"
		<< setfill(' ');
}

void tmout(int m, double s)
{
	cout << setfill('0')
		<< setw(2) << m << "m:"
		<< fixed << setprecision(2) << setw(5) << s << "s"
		<< setfill(' ');
}

void myout(int M[], int nm, int nw)
{
	for (int i = 0; i < nm; i++)
		cout << setw(nw) << right << M[i];
	cout << endl;
}

int mymax(int M[], int nm)
{
	int mx = M[0], imx = 0;
	for (int i = 1; i < nm; i++)
		if (M[i] > mx)
		{
			mx = M[i]; imx = i;
		}
	return imx;
}

int mymin(int M[], int nm)
{
	int mx = M[0], imx = 0;
	for (int i = 1; i < nm; i++)
		if (M[i] < mx)
		{
			mx = M[i]; imx = i;
		}
	return imx;
}

void triangle(int n, char ch)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (j == n - i - 1)
				cout << ch;
			else if (j == 0)
				cout << ch;
			else if (i == 0)
				cout << ch;
			else
				cout << " ";
		cout << endl;
	}
}

double myroot(int x, int n, double e)
{
	if (x == 0) return 0;
	double y = x, ynext;
	while (x)
	{
		ynext = y + (x / pow(y, n - 1) - y) / n;
		if (abs(ynext - y) < e) break;
		y = ynext;
	}
	return ynext;
}

void arrrRShift(int X[], int nx)
{
	int t = X[nx-1];
	for (int i = nx - 1; i >= 0; i--)
		X[i] = X[i - 1];
	X[0] = t;
}