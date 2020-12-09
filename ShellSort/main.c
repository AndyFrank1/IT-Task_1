#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct timeval timeval;

void shellSort(int * numbers, unsigned int length); // Функция соортировки
void findDValue(int * d, int length); // Функция нахождения D из одной из вариация последовательностей Седжвика

int main(int argc, char ** argv) {
	// Создание переменных для хранения времени
	clock_t start, end;
	double time;
	// Создание массива, решил просто передавать элементы массива как аргументы командной строки, на времени это не кка не отразится, т.к. замерятся время будет только до и после соортировки
	int length = atoi(argv[1]);
	int arr[length];
	for (int i = 2; i < length + 2; i++) {
		arr[i - 2] = atoi(argv[i]);
	}

	start = clock();
	shellSort(arr, length);
	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;

	// Выводим время работы в консоль, а python-скриптом будем забирать это значение
	printf("%.15lf", time);
  return 0;
}

void shellSort(int * numbers, unsigned int length) {
	int d, j = 0;
	findDValue(&d, length); // Находим D из последовательности Седжвика
	for (d = d; d > 0; d /= 2) {
		for (int i = d; i < length; i++) {
			j = i - d;
			while (j >= 0 && numbers[j] > numbers[j + d]) {
				// Классическая смена значений двух числовых переменных
				int tmp = numbers[j];
				numbers[j] = numbers[j + d];
				numbers[j + d] = tmp;
				j -= d;
			}
		}		
	}
}

void findDValue(int * d, int length) {
	int sequence[10] = {9539, 3821, 1529, 613, 247, 101, 41, 16, 7, 3};
	// Последовательность Седжвика (только перевёрнутая), взята с сайта oeis.org Идентификатор последовательности - A036567 Сама последовательность была также описана Дональдом Кнутом в "искусстве программирования", том 3, страница 91
	// Как я понял из статьи на вики, сложность агоритма в худшем случае, используя эту последовательность будет составлять N^(4/3) что всё равно лучше чем если взять просто D = N / 2

	// Я же буду брать максимально возможное D, которые подходит под длину из этой последовательности
	// Поэтому массив и перевёрнутый
	for (int i = 0; i < 10; i++) {
		if (sequence[i] < length) * d = sequence[i];
	}
}