#include <iostream>
#include <ctime>
#define MAXSTACK 2048 
using namespace std;

template<class T>

void qSortI(T a[], long size) {

	long i, j; 
	long lb, ub; 

	long lbstack[MAXSTACK], ubstack[MAXSTACK];
	long stackpos = 1; 
	long ppos; 
	T pivot; 
	T temp;

	lbstack[1] = 0;
	ubstack[1] = size - 1;

	do {
		
		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do {
			
			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = a[ppos];
			do {
				while (a[i] < pivot) i++;
				while (pivot < a[j]) j--;
				if (i <= j) {
					temp = a[i]; a[i] = a[j]; a[j] = temp;
					i++; j--;
				}
			} while (i <= j);

			if (i < ppos) {
				if (i < ub) { 
					stackpos++;
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j; 
				
			}
			else { 
				if (j > lb) {
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}
		} while (lb < ub); 
	} while (stackpos != 0); 
}

void pSort(int* dig, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (dig[j] > dig[j + 1])
			{
				int b = dig[j];
				dig[j] = dig[j + 1];
				dig[j + 1] = b;
			}
		}
	}
}

void ppSort(int dig[8], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (dig[j] > dig[j + 1])
			{
				int b = dig[j];
				dig[j] = dig[j + 1];
				dig[j + 1] = b;
			}
		}
	}
}

void pppSort(int dig[4], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (dig[j] > dig[j + 1])
			{
				int b = dig[j];
				dig[j] = dig[j + 1];
				dig[j + 1] = b;
			}
		}
	}
}

void iSort(int* arr, int l) // сортировка вставками
{
	int t, // временная переменная для хранения значения элемента сортируемого массива
		it; // индекс предыдущего элемента
	for (int i = 1; i < l; i++)
	{
		t = arr[i]; // инициализируем временную переменную текущим значением элемента массива
		it = i - 1; // запоминаем индекс предыдущего элемента массива
		while (it >= 0 && arr[it] > t) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[it + 1] = arr[it]; // перестановка элементов массива
			arr[it] = t;
			it--;
		}
	}
}

void a1()
{
	srand(time(NULL));
	const int s = 10;
	int a[s];
	cout << "Массив >>> { ";
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 5;
		cout <<a[i]<< " ";
	}
	cout << " }\n";

	for (int i = 0; i < 10; ++i)if (a[i] == 0)
	{
		for (int j = i; j < 10 - 1; ++j)
		{
			a[j] = a[j + 1];
		}
		a[10 - 1] = -1;
		--i;
	}
	
	cout << "Сжатый массив >>> { ";
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << " }\n";
}

void a2()
{
	int a[5], b[5], c[10];
	int in = 0;
	cout << "Массив 1 >>> { ";
	for (int i = 0; i < 5; i++)
	{
		a[i] = rand() % 11 - 5;
		cout << a[i] << " ";
	}
	cout << "}\n";
	cout << "Массив 2 >>> { ";
	for (int i = 0; i < 5; i++)
	{
		b[i] = rand() % 11 - 5;
		cout << b[i] << " ";
	}
	cout << "}\n";

	for (int i = 0; i < 5; i++)
	{
		if (a[i] > 0)
		{
			c[in] = a[i];
			in++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (b[i] > 0)
		{
			c[in] = b[i];
			in++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == 0)
		{
			c[in] = a[i];
			in++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (b[i] == 0)
		{
			c[in] = b[i];
			in++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (a[i] < 0)
		{
			c[in] = a[i];
			in++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (b[i] < 0)
		{
			c[in] = b[i];
			in++;
		}
	}

	cout << "Готовый массив: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	


}

void a3()
{
	setlocale(LC_ALL, "rus");

	int n; 
	cout << "Введите размер массива: ";
	cin >> n;
	int* dig = new int[n];
	cout << "Введите "<<n<<" чисел для заполнения массива: " << endl;

	for (int i = 0; i < n; i++) {
		cin >> dig[i]; 
	}

	pSort(dig, n);

	cout << "Массив в отсортированном виде >>> { ";
	
	for (int i = 0; i < n; i++) 
	{
		cout << dig[i] << ", "; 
		
	}
	cout << "}\n";
}

void a4()
{
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* dig = new int[n];
	
	cout << "Массив в не сортированном виде >>> { ";
	for (int i = 0; i < n; i++) {
		dig[i] = rand() % 101 - 50;
		cout << dig[i]<<", ";
	}
	cout << "}";
	iSort(dig, n);

	cout << "Массив в отсортированном виде >>> { ";

	for (int i = 0; i < n; i++)
	{
		cout << dig[i] << ", ";

	}
	cout << "}\n";
}

void a5()
{
	cout << "Программа успеваемость, по 12 балльной системе\n\n";
	
	setlocale(LC_ALL, "rus");

	int dig[10],l,k,j;  double sum = 0;

	cout << "Введите 10 чисел для заполнения массива: " << endl;

	for (int i = 0; i < 10; i++) {
		cin >> dig[i]; 
	}
	cout << "Массив оценок >>> { ";
	for (int i = 0; i < 10; i++)
	{
		cout << dig[i]<<", ";
	}
	cout << "}\n";

	cout << "Хотите исправить 1 оценку, 0 - net, 1 - da; "; cin >> l;
	if (l == 1)
	{
		cout << "Введите номер элемента в миссиве: "; cin >> k;
		if (k > 10 || k < 0)
		{
			do
			{
				cout << "Вы ввели неправильный номер, повторите попытку "; cin >> k;
			} while (k > 10 || k < 0);
		}
		cout << "На какую оценку хотите исправить; "; cin >> j;
		if (j > 12 || j < 0)
		{
			do
			{
				cout << "Вы ввели неправильную оценку, повторите попытку "; cin >> j;
			} while (j > 10 || j < 0);
		}
			dig[k] = j;
		;
		for (int i = 0; i < 10; i++)
		{
			sum = sum + dig[i];
		}
		sum = sum / 10;
		if (sum < 10.7)
		{
			cout << "Вы не получите стипендию, так как ваш средний бал " << sum;
		}
		if (sum >= 10.7)
		{
			cout << "Вы получите стипендию, так как ваш средний бал " << sum;
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			sum = sum + dig[i];
		}
		sum = sum / 10;
		if (sum < 10.7)
		{
			cout << "Вы не получите стипендию, так как ваш средний бал " << sum;
		}
		if (sum >= 10.7)
		{
			cout << "Вы получите стипендию, так как ваш средний бал " << sum;
		}
	}
}

void a6()
{
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* dig = new int[n];

	cout << "Массив в не сортированном виде >>> { ";
	for (int i = 0; i < n; i++) {
		dig[i] = rand() % 101 - 50;
		cout << dig[i] << ", ";
	}
	cout << "}\n";
	qSortI(dig, n);

	cout << "Массив в отсортированном виде >>> { ";

	for (int i = 0; i < n; i++)
	{
		cout << dig[i] << ", ";

	}
	cout << "}\n";
	
}

void a7()
{
	int n = 12; double sum8 = 0; int dig[12], a[4], b[8], c[8], g[4];
	int in = 0;
	cout << "Массив в не сортированном виде >>> { ";
	for (int i = 0; i < n; i++) {
		dig[i] = rand() % 101 - 50;
		cout << dig[i] << ", ";
	}
	cout << "}\n";

	for (int i = 0; i < 4; i++)
	{
		a[i] = dig[i];
	}
	for (int i = 0; i < 8; i++)
	{
		b[i] = dig[i + 4];
	}
	for (int i = 0; i < 8; i++)
	{
		c[i] = dig[i];
	}
	for (int i = 0; i < 5; i++)
	{
		g[i] = dig[i + 8];
	}
	cout << ">>> { ";
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "}\n\n";
	cout << ">>> { ";
	for (int i = 0; i < 8; i++)
	{
		cout << b[i] << ", ";
	}
	cout << "}\n\n";
	cout << ">>> { ";
	for (int i = 0; i < 8; i++)
	{
		cout << c[i] << ", ";
	}
	cout << "}\n\n";
	cout << ">>> { ";
	for (int i = 0; i < 4; i++)
	{
		cout << g[i] << ", ";
	}
	cout << "}\n\n";

	for (int i = 0; i < 6; i++)
	{
		sum8 = sum8 + dig[i];
	}
	sum8 = sum8 / 6;

	if (sum8 > 0)
	{
		ppSort(c, 8);
		cout << "Массив 2/3 >>> { ";

		for (int i = 0; i < 8; i++)
		{
			cout << c[i] << ", ";
		}
		for (int i = 4 - 1; i >= 0; i--)
		{
			cout << g[i] << ", ";
		}
		cout << "}\n";
		
	}
	else
	{
		pppSort(a, 4);
		cout << "Массив 1/3 >>> { ";

		for (int i = 0; i < 4; i++)
		{
			cout << a[i] << ", ";
		}
		for (int i = 8 - 1; i >= 0; i--)
		{
			cout << b[i] << ", ";
		}
		cout << "}\n";
	}
}

void main()
{
	int a;
	setlocale(LC_ALL, "rus");
	cout << "1 - 8 > > > ";
	cin >> a;
	switch (a)
	{
	case 1:
		a1();
		break;
	case 2:
		a2();
		break;
	case 3:
		a3();
		break;
	case 4:
		a4();
		break;
	case 5:
		a5();
		break;
	case 6:
		a6();
		break;
	case 7:
		a7();
		break;
	}
}
