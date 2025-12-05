#include "main.h" 

void createListDeveloper(Developer *&first) {
    first = NULL;
}

void createNewDeveloper(string nama, Developer *&newDeveloper) {
    newDeveloper = new Developer;
    newDeveloper->nama = nama;
    newDeveloper->next = NULL;
    newDeveloper->prev = NULL;
    newDeveloper->firstRelation = NULL;
}

void insertFirstDeveloper(Developer *&first, Developer *newDeveloper) {
    if (first == NULL) {
        newDeveloper->next = NULL;
        newDeveloper->prev = NULL;
        first = newDeveloper;
    } 
    else {
        newDeveloper->next = first;
        first->prev = newDeveloper;
        newDeveloper->prev = NULL;
        first = newDeveloper;
    }
}

void insertAfterDeveloper(Developer *prec, Developer *newDeveloper) {
    if (prec == NULL) {
        cout << "Predecessor (node acuan) tidak boleh NULL." << endl;
        return;
    }
    if (prec->next != NULL) {
        newDeveloper->next = prec->next; 
        prec->next->prev = newDeveloper; 
    } 
    else {
        newDeveloper->next = NULL; 
    }
    prec->next = newDeveloper;
    newDeveloper->prev = prec;
}

void insertLastDeveloper(Developer *&first, Developer *newDeveloper) {
    if (first == NULL) {
        insertFirstDeveloper(first, newDeveloper);
        return;
    }
    Developer *last = first;
    while (last->next != NULL) {
        last = last->next;
    }

}

void deleteFirstDeveloper(Developer *&first) {
    if (first == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    Developer *deletedNode = first;
    if (first->next == NULL) {
        first = NULL;
    } 
    else {
        first = first->next; 
        first->prev = NULL; 
    }
    delete deletedNode;
    cout << "Developer pertama berhasil dihapus." << endl;
}

void deleteAfterDeveloper(Developer *prec) {
    if (prec == NULL || prec->next == NULL) {
        cout << "Tidak ada node setelah predecessor untuk dihapus." << endl;
        return;
    }
    Developer *deletedNode = prec->next;
    if (deletedNode->next == NULL) {
        prec->next = NULL;
    } 
    else {
        deletedNode->next->prev = prec;
        prec->next = deletedNode->next;
    }
    deletedNode->prev = NULL;
    deletedNode->next = NULL;
    delete deletedNode;
    cout << "Node setelah predecessor berhasil dihapus." << endl;
}

void deleteLastDeveloper(Developer *&first) {
    if (first == NULL) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }
    if (first->next == NULL) {
        deleteFirstDeveloper(first);
        return;
    }
    Developer *last = first;
    while (last->next != NULL) {
        last = last->next;
    }    
    Developer *beforeLast = last->prev;
    beforeLast->next = NULL;
    delete last;
    cout << "Developer terakhir berhasil dihapus." << endl;
}

void printListDeveloper(Developer *first) {
    if (first == NULL) {
        cout << "List Developer kosong." << endl;
        return;
    }
    Developer *current = first;
    cout << "--- LIST DEVELOPER (Doubly Linked List) ---" << endl;
    int count = 1;
    while (current != NULL) {
        cout << count << ". Nama: " << current->nama;
        if (current->firstRelation != NULL) {
            cout << " (Punya " << current->nama << " Project)";
        }
        cout << endl;
        current = current->next;
        count++;
    }
    cout << "------------------------------------------" << endl;
}
