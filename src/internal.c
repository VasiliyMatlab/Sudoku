#include "internal.h"

// Считывание массива из файла
uint8_t** readArray(char *filename, uint8_t *rows, uint8_t *columns) {

	// Инициализация файла
	FILE *input = fopen(filename,"r");
	if (!input) {
		fprintf(stderr, "Error: unable to open file \"%s\"\n", filename);
		exit(EIO);
	}

	// Подсчет количества строк и столбцов
	_Bool isprevdigit = false;  // является ли предыдущий символ цифрой
	*rows = 0;                  // кол-во строк
	*columns = 0;               // кол-во столбцов
	char c;                     // текущий символ
	char buffer[BUFFER_SIZE];   // буфер входных данных
	// В перовой строке подсчитываем кол-во столбцов
	while ((c = fgetc(input)) != '\n') {
		if (isdigit(c)) {
			if (!isprevdigit) {
				isprevdigit = true;
				(*columns)++;
			}
		}
		else
			isprevdigit = false;
	}
	(*rows)++;
	// Подсчитываем кол-во строк
	while (!feof(input)) {
		fgets(buffer, 128, input);
		(*rows)++;
	}
	fseek(input, 0,SEEK_SET);   // переместить указатель на начало файла

	// Считывание массива
	uint8_t** array = (uint8_t**) malloc(*rows*sizeof(uint8_t*));
	for (uint8_t i = 0; i < *rows; i++) {
		array[i] = (uint8_t*) malloc(*columns*sizeof(uint8_t));
		fgets(buffer, 128, input);
		char num[8];        // массив символов для запоминания числа
		uint8_t j = 0;      // текущий столбец массива
		uint8_t curr = 0;   // номер текущего символа массива 'num'
		for (uint8_t k = 0; buffer[k] != '\n'; k++) {
			if (isdigit(buffer[k])) {
				num[curr++] = buffer[k];
				if ((buffer[k+1] == '\n')) {
					// Конвертировать num в число и присвоить массиву
					array[i][j++] = atoi(num);
                    if (j == *columns)
                        break;
					// Очистить num
					memset(num, 0, 8);
					curr = 0;
				}
			}
			else {
				if (!curr)
					continue;
				// Конвертировать num в число и присвоить массиву
				array[i][j++] = atoi(num);
                if (j == 9)
                    break;
				// Очистить num
				memset(num, 0, 8);
				curr = 0;
			}
		}
	}

	fclose(input); // закрытие файла
	return array;
}