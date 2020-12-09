#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void heapSort(int * numbers, int length);
void swap(int * numbers, int i, int j);
void makeHeap(int * numbers, int root, int last);

int main(int argc, char * argv[]) {
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
	heapSort(arr, length);
	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;

	// Выводим время работы в консоль, а python-скриптом будем забирать это значение
	printf("%.15lf", time);
  return 0;
}

// Функция дляя формирования кучи
void makeHeap(int * numbers, int root, int last) {
  bool isDone = false;
  int childMax;
  while (root * 2 <= last && !isDone) {
    childMax = (root * 2 == last || numbers[root * 2] > numbers[root * 2 + 1])? root * 2 : root * 2 + 1;
    if ((numbers[root] < numbers[childMax])) {
      swap(numbers, root, childMax);
      root = childMax;
    }
    else {
      isDone = true;
    }
  }
}

// Сама функция соортировки на конкретной куче
void heapSort(int * numbers, int length) {
  for (int i = length / 2 - 1; i >= 0; i--) {
    makeHeap(numbers, i, length - 1);
  }
  for (int i = length - 1; i >= 1; i--) {
    swap(numbers, 0, i);
    makeHeap(numbers, 0, i - 1);
  }
}

void swap(int * numbers, int i, int j) {
  int tmp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = tmp;
}
