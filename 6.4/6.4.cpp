// lab 6.4 - recursion
// варіант 10

#include <iostream>
#include <iomanip>
using namespace std;

void Print(int* a, const int size, int i);
void Create(int* a, const int size, const int Low, const int High, int i);
int sum(int* a, const int size, int i, int s);
int find_zero(int* a, const int size, int i);
int min(int* a, const int size, int m, int i);
void format_mas(int* a, int* b, const int size, int j, int i);

int main()
{
	srand((unsigned)time(0));

	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];

	Create(a, n, -10, 10, 0);
	cout << "array = ";
	Print(a, n, 0);

	cout << "min element =" << setw(6) << min(a, n, find_zero(a, n, 0) , 0) << endl;
	cout << "sum after zero  = " << sum(a, n, find_zero(a, n, 0), 0) << endl;
	format_mas(a, b, n, 0, 0);
	cout << "array = ";
	Print(b, n, 0);

	getchar();
}

void format_mas1(int* a, int* b, const int size, int i, int k)
{
	if (i < size)
	{
		b[k++] = a[i];
		format_mas1(a, b, size, i += 2, k);
	}
}

void format_mas(int* a, int* b, const int size, int i, int k)
{
	if (i < size)
	{
		b[k++] = a[i];
		format_mas(a, b, size, i += 2, k);
	}
	else
		format_mas1(a, b, size, 1, k);
}

void Print(int* a, const int size, int i)
{
	if (i < size)
	{
		cout << setw(4) << a[i];
		Print(a, size, i + 1);
	}
	else
		cout << '\n';
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

int sum(int* a, const int size, int i, int s)
{
	if (i < size)
	{
		s += abs(a[i]);
		sum(a, size, i + 1, s);
	}
	else
		return s;
}

int find_zero(int* a, const int size, int i)
{
	if (i < size)
	{
		if (a[i] == 0)
			return i;
		find_zero(a, size, i + 1);
	}
}

int min(int* a, const int size, int m, int i)
{
	if (i < size)
	{
		if (abs(a[i]) < abs(m))
		{
			m = a[i];
		}
		min(a, size, m, i + 1);
	}
	else
		return m; // повертаємо найменший за модулем елемент
}