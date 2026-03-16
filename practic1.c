#include "practic1.h"

e_book_error validate_e_book(const e_book *book){
    if (book == NULL){
        return ERROR_NULL_PTR;
    }
    if (book->name[0]=='\0'){
        return ERROR_TITLE_EMPTY;
    }
    if (strlen(book->name) >= MAX_TITLE_LINE){
        return ERROR_TITLE_LONG;
    }
    if (book->screen_size < MIN_SCREEN_SIZE || book->screen_size > MAX_SCREEN_SIZE){
        return ERROR_SCREEN_SIZE;
    }
    return ERROR_SUCCESS;
}

e_book_error init_e_book(e_book *book, char *name, int screen_size, bool screen_backlight){
    if (book == NULL || name == NULL){
        return ERROR_NULL_PTR;
    }
    strncpy(book->name, name, MAX_TITLE_LINE - 1);
    book->screen_size = screen_size;
    book->screen_backlight = screen_backlight;
    e_book_error err = validate_e_book(book);
    if (err != ERROR_SUCCESS){
        return err;
    }
    return ERROR_SUCCESS;
}

e_book copy_e_book(e_book *src, e_book *dest){
    strcpy(dest->name, src->name);
    dest->screen_size = src->screen_size;
    dest->screen_backlight = src->screen_backlight;
    return *dest;
}

void print_e_book(const e_book *book){
    printf("Назание электронной книги: %s\n", book->name);
    printf("Размер экрана: %d дюймов\n", book->screen_size);
    printf("Подсветка экрана: %s\n", book->screen_backlight ? "есть" : "нет");
}

e_book_error change_e_book(e_book *book, char *name){
    if (book == NULL || name == NULL){
        return ERROR_NULL_PTR;
    }
    strncpy(book->name, name, MAX_SCREEN_SIZE - 1);
    int err = validate_e_book(book);
    if (err != 0){
        return err;
    }
    return ERROR_SUCCESS;
}

e_book *new_dynamic_e_book(void){
    e_book *new_e_book = malloc(sizeof(e_book));
    if (new_e_book == NULL){
        return NULL;
    }
    e_book_error book_dynamic = init_e_book(new_e_book, "e_book", 6, false);
    if (book_dynamic != ERROR_SUCCESS){
        free(new_e_book);
        return NULL;
    }
    return new_e_book;
}

void delete_dynamic_e_book(e_book *new_e_book){
    if (new_e_book != NULL){
        free(new_e_book);
    }
}