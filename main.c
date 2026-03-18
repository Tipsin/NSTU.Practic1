#include "practic1.h"

int main(void){
    e_book book1, book2;
    e_book_error err;
    err = init_e_book(&book1, "Samsung", 10, true);
    if (err != ERROR_SUCCESS){
        printf("Ошибка инициализации первой электронной книги, код ошибки: %d\n", err);
        return err;
    }
    err = init_e_book(&book2, "Lenovo", 6, false);
        if (err != ERROR_SUCCESS){
        printf("Ошибка инициализации второй электронной книги, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&book1);
    printf("\n");
    print_e_book(&book2);
    printf("\n");
    copy_e_book(&book2, &book1);
    err = change_e_book(&book1, "PocetBook");
    if (err != ERROR_SUCCESS){
        printf("Ошибка изменения названия, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&book1);
    printf("\n");
    print_e_book(&book2);
    printf("\n");
    e_book *dynamic_book1 = new_dynamic_e_book();
    e_book *dynamic_book2 = new_dynamic_e_book();
    e_book d_e_book1, d_e_book2;
    err = init_e_book(&d_e_book1, "ONYX", 12, true);
    if (err != ERROR_SUCCESS){
        printf("Ошибка инициализации первой электронной книги в динамической памяти, код ошибки: %d\n", err);
        return err;
    }
    err = init_e_book(&d_e_book2, "Amazon", 9, false);
        if (err != ERROR_SUCCESS){
        printf("Ошибка инициализации второй электронной книги в динамической памяти, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&d_e_book1);
    printf("\n");
    print_e_book(&d_e_book2);
    printf("\n");
    copy_e_book(&d_e_book2, &d_e_book1);
    err = change_e_book(&d_e_book1, "Digma");
    if (err != ERROR_SUCCESS){
        printf("Ошибка изменения названия, код ошибки: %d\n", err);
        return err;
    }
    print_e_book(&d_e_book1);
    printf("\n");
    print_e_book(&d_e_book2);
    delete_dynamic_e_book(dynamic_book1);
    delete_dynamic_e_book(dynamic_book2);

    return 0;
}