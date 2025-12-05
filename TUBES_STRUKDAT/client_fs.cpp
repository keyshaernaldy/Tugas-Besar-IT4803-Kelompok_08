#include "main.h"

void createListClient(Client *&first) {
    first = NULL;
}

void createNewClient(string nama, Client *&newClient) {
    newClient = new Client;
    newClient->nama = nama;
    newClient->next = NULL;
    newClient->prev = NULL;
}

void insertFirstClient(Client *&first, Client *newClient) {
    if (first == NULL) {
        newClient->next = NULL;
        newClient->prev = NULL;
        first = newClient;
    } 
    else {
        newClient->next = first;
        first->prev = newClient;
        newClient->prev = NULL;
        first = newClient;
    }
}

void insertAfterClient(Client *prec, Client *newClient) {
    if (prec == NULL) {
        cout << "Predecessor (node acuan) tidak boleh NULL." << endl;
        return;
    }
    
    if (prec->next != NULL) {
        newClient->next = prec->next; 
        prec->next->prev = newClient; 
    } 
    prec->next = newClient;
    newClient->prev = prec;
}

void insertLastClient(Client *&first, Client *newClient) {
    if (first == NULL) {
        insertFirstClient(first, newClient);
        return;
    }
    Client *last = first;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newClient;
    newClient->prev = last;
}

void deleteFirstClient(Client *&first) {
    if (first == NULL) {
        cout << "List kosong, tidak ada Client yang bisa dihapus." << endl;
        return;
    }
    Client *deletedNode = first;
    if (first->next == NULL) {
        first = NULL;
    } 
    else {
        first = first->next; 
        first->prev = NULL; 
    }
    
    delete deletedNode;
    cout << "Client pertama berhasil dihapus." << endl;
}

void deleteAfterClient(Client *prec) {
    if (prec == NULL || prec->next == NULL) {
        cout << "Tidak ada node setelah predecessor untuk dihapus." << endl;
        return;
    }
    Client *deletedNode = prec->next;
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
    cout << "Node Client setelah predecessor berhasil dihapus." << endl;
}

void deleteLastClient(Client *&first) {
    if (first == NULL) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }
    if (first->next == NULL) {
        deleteFirstClient(first);
        return;
    }
    Client *last = first;
    while (last->next != NULL) {
        last = last->next;
    }
    Client *beforeLast = last->prev;
    beforeLast->next = NULL;
    delete last;
    cout << "Client terakhir berhasil dihapus." << endl;
}

void printListClient(Client *first) {
    if (first == NULL) {
        cout << "List Client kosong." << endl;
        return;
    }

    Client *current = first;
    cout << "--- LIST CLIENT (Doubly Linked List) ---" << endl;
    int count = 1;
    while (current != NULL) {
        cout << count << ". Nama: " << current->nama << endl;
        current = current->next;
        count++;
    }
    cout << "------------------------------------------" << endl;
}

