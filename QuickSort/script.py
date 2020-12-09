import os
from random import choice, randrange
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from time import sleep

'''
	Скрипт состоит из двух частей:
		1 - генерация массива для теста и собственно выполнение тестов, а также запись данных в нужный файл
		2 - визуализация данных и сохранение этого в картинку
'''

# Функции первой части скрипта
def generateLists(length):
	return list(np.random.randint(9000, size=length) + 1000)
def makeCommandLine(listLen):
	arr = generateLists(listLen)
	stroke = f"{listLen} "
	for i in range(listLen):
		stroke += str(arr[i]) + " "
	return f"./main {stroke}"
def mainProcess(start, end, step):
	for i in range(start, end, step):
		mean = []
		for j in range(25):
			result = os.popen(makeCommandLine(i))
			mean.append(float(result.read()) * 1000000.0)
		mean = sorted(mean)
		# Записываем результат в CSV файл
		with open('time.csv', 'a') as time:
			print(f"{i},{round(mean[12])}", file=time)
		# Выводим плюсики для отчётности того, что итерация завершилась
		print(f"+++ {i}")

# Функции второй части скрипта
def drawAndSave():
	dataFrame = pd.read_csv('time.csv')
	lensArray = list(dataFrame.len)
	timesArray = list(dataFrame.time)

	plt.scatter(lensArray, timesArray, s=5)
	plt.title('Зависимость времени от количества элементов')
	plt.xlabel('Длина массива')
	plt.ylabel('Время (microseconds)')

	plt.show()


# Создаём процесс который создаст массивы длиной от 10 до 12 тысяч с шагом 10, так как числа большие, то шаг вполне оптимальный
mainProcess(10, 12000, 10)
drawAndSave()
