#include "main.h"

void createListDeveloper(Developer *&first) {
    first = NULL;
}

void insertFirstDeveloper(Developer *&first, Developer *newDeveloper) {
    if (first == NULL) {
        newDeveloper->next = NULL;
        newDeveloper->prev = NULL;
        first = newDeveloper;
    } else {
        newDeveloper->next = first;
        
        first->prev = newDeveloper;
        
        newDeveloper->prev = NULL;
        
        first = newDeveloper;
    }
}

void createNewDeveloper(string nama, Developer *&newDeveloper) {
    newDeveloper = new Developer;
    
    newDeveloper->nama = nama;
    
    newDeveloper->next = NULL;
    newDeveloper->prev = NULL;
}
