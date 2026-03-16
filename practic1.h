#ifndef PRACTIC_E_BOOK
#define PRACTIC_E_BOOK
#define MAX_TITLE_LINE 20
#define MIN_SCREEN_SIZE 5
#define MAX_SCREEN_SIZE 13

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[MAX_TITLE_LINE]; // Название фирмы-производителя
    int screen_size; // Размер экрана
    bool screen_backlight; // Наличие подсветки экрана
}e_book;

typedef enum{
    ERROR_SUCCESS = 0, // Успешное выполнение
    ERROR_TITLE_EMPTY = 1, // Пустое название
    ERROR_TITLE_LONG = 2, // Слишком длинное название
    ERROR_SCREEN_SIZE = 3, // Некорректный размер экрана
    ERROR_NULL_PTR = 4 // Нулевой указатель
}e_book_error;

e_book_error validate_e_book(const e_book *book); // Функция, проверяющая корректность значений полей структуры(п.5)
e_book_error init_e_book(e_book *book, char *name, int screen_size, bool screen_backlight); // Функция инициализации структуры(п.6)
e_book copy_e_book(e_book *src, e_book *dest); // Функция копирования структуры(п.7)
void print_e_book(const e_book *book); // Функция, выводящая значения полей(п.8)
e_book_error change_e_book(e_book *book, char *name); // Функция, изменяющая значение одного поля(имя)(п.9)
e_book *new_dynamic_e_book(void); // Функция, создающая структуру в динамической памяти(п.10)
void delete_dynamic_e_book(e_book *new_e_book); // Функция, удаляющая экземпляр структуры из динамической памяти(п.11)

#endif