#include "practic1.h"

int main(void){
    e_book book1, book2; //  Объявление структур с именами book1 и book2
    e_book_error err; // Объявление перечисляемого типа данных с именем err
    err = init_e_book(&book1, "Samsung", 10, true); // Инициализация структуры с именем book1
    if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка инициализации первой электронной книги, код ошибки: %d\n", err);
        return err;
    }
    err = init_e_book(&book2, "Lenovo", 6, false); // Инициализация структуры с именем book2
        if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка инициализации второй электронной книги, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&book1); // Вывод сведений полей структуры book1
    printf("\n");
    print_e_book(&book2); // Вывод сведений полей структуры book2
    printf("\n");
    copy_e_book(&book1, &book2); // Копирование данных из структуры book1 в book2
    err = change_e_book(&book1, "PocetBook"); // Изменение поля структуры 
    if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка изменения названия, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&book1); // Вывод сведений полей структуры book1
    printf("\n");
    print_e_book(&book2); // Вывод сведений полей структуры book2
    printf("\n");
    e_book *dynamic_book1 = new_dynamic_e_book(); // Создание экзепляра структуры в динамической памяти 
    e_book *dynamic_book2 = new_dynamic_e_book(); // Создание экзепляра структуры в динамической памяти
    err = init_e_book(dynamic_book1, "ONYX", 12, true); // Инициализация структуры в динамической памяти с именем dynamic_book1
    if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка инициализации первой электронной книги в динамической памяти, код ошибки: %d\n", err);
        return err;
    }
    err = init_e_book(dynamic_book2, "Amazon", 9, false); // Инициализация структуры в динамической памяти с именем dynamic_book2
        if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка инициализации второй электронной книги в динамической памяти, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(dynamic_book1); //Вывод сведений полей структуры dynamic_book1
    printf("\n");
    print_e_book(dynamic_book2); //Вывод сведений полей структуры dynamic_book2
    printf("\n");
    copy_e_book(dynamic_book1, dynamic_book2); // Копирование данных из структуры dynamic_book1 в dynamic_book2
    err = change_e_book(dynamic_book1, "Digma"); // Изменение поля структуры 
    if (err != ERROR_SUCCESS){ // Проверка корректности значении полей структуры, если err не равна 0, то выход из программы с кодом ошибки
        printf("Ошибка изменения названия, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(dynamic_book1); //Вывод сведений полей структуры dynamic_book1
    printf("\n");
    print_e_book(dynamic_book2); //Вывод сведений полей структуры dynamic_book2
    delete_dynamic_e_book(dynamic_book1); // Удаление структуры dynamic_book1 из динамической памяти
    delete_dynamic_e_book(dynamic_book2); // Удаление структуры dynamic_book2 из динамической памяти

    return 0;
}