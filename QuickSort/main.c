#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *s_arr, int first, int last);

int main(int argc, char * argv[]) {
  // Создание переменных для хранения времени
	clock_t start, end;
	double time = 0.0;
	// Создание массива, решил просто передавать элементы массива как аргументы командной строки, на времени это не кка не отразится, т.к. замерятся время будет только до и после соортировки
	int length = atoi(argv[1]);
	int arr[length];
	for (int i = 2; i < length + 2; i++) {
		arr[i - 2] = atoi(argv[i]);
	}

	start = clock();
	quicksort(arr, 0, length - 1);
	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;

	// Выводим время работы в консоль, а python-скриптом будем забирать это значение
	printf("%.15lf", time);
  return 0;
}

void quicksort(int * numbers, int indexLow, int indexHigh)
{
  	if (indexLow < indexHigh)
    {
        int i = indexLow, j = indexHigh;
				int pivot = numbers[(i + j) / 2];
        do
        {
            while (numbers[i] < pivot) i++;
            while (numbers[j] > pivot) j--;
            if (i <= j)
            {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
                i++;
                j--;
            }
        } while (i <= j);
        quicksort(numbers, indexLow, j);
        quicksort(numbers, i, indexHigh);
    }
}
