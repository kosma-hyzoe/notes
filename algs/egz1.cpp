// Dla listy studentów o polach (nazwisko, ocena, wiek), zaczynającej się
// pod jakimś adresem, napisać definicję struktury oraz jedną funkcję (bez definiowania i
// wykorzystywania innych funkcji), która:
// - dopisuje dodatkowego studenta o jakichś danych (nazwisko, ocena, wiek) na
//   pierwszym miejscu, jeśli lista ma nieparzystą liczbę studentów, a w przeciwnym razie
//   dopisuje go na drugim miejscu listy
// - przekazuje przez parametr nazwisko ostatniego studenta z listy, jeśli ma on ocenę
//   mniejszą od jakiejś wartości, po czym usuwa z listy tego studenta.
// - zwraca (przez return) liczbę najstarszych studentów na tej liście
//
#include <iostream>
#include <string>

using namespace std;

struct S {
    string nazwisko;
    int ocena;
    int wiek;
    S* next;
};

void cleanList(S*& head) {
    while (head) {
        S* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int fun(S*& head, string nazwisko, int ocena, int wiek,
        int jOcena, string& jS) {
    int ret = -1;

    int c = 0;
    S* prelast = nullptr;
    S* last = nullptr;
    S* iter = head;
    while (iter) {
        c++;
        prelast = last;
        last = iter;
        iter=iter->next;
    }

    if (c == 0) {
        head = new S{nazwisko, ocena, wiek, nullptr};
    }else if (c % 2 == 1) {
        head = new S{nazwisko, ocena, wiek, head};
    } else {
        S* tmp = head->next->next;
        head->next = new S{nazwisko, ocena, wiek, tmp};
    }

    if (prelast && last->ocena < jOcena) {
        jS = last->nazwisko;
        prelast->next = nullptr;
        delete last;
    } else if (last->ocena < jOcena) {
        head = nullptr;
        delete last;
    }

    if (!head)
        return 0;

    int naj = head->wiek;
    c = 1;
    iter = head->next;
    while (iter) {
        if (iter->wiek > naj) {
            c = 1;
            naj = iter->wiek;
        } else if (iter->wiek == naj) {
            c++;
        }
        iter = iter->next;
    }

    return c;
}

void printList(S* head) {
    while (head) {
        cout << head->nazwisko << " "
             << head->ocena << " "
             << head->wiek << endl;
        head = head->next;
    }
    cout << "----" << endl;
}

int main() {
    S* head = nullptr;

    // ręczne tworzenie listy
    head = new S{"Kowalski", 4, 21, nullptr};
    head->next = new S{"Nowak", 3, 19, nullptr};
    head->next->next = new S{"Wisniewski", 5, 23, nullptr};
    head->next->next->next = new S{"Wojcik", 2, 20, nullptr};

    cout << "Lista przed fun():\n";
    printList(head);

    string usunieteNazwisko;
    int ileNajstarszych = fun(head,
                              "Zielinski", 5, 22,
                              3, usunieteNazwisko);

    cout << "Lista po fun():\n";
    printList(head);

    cout << "Usuniete nazwisko: " << usunieteNazwisko << endl;
    cout << "Liczba najstarszych: " << ileNajstarszych << endl;

    cleanList(head);
    return 0;
}
