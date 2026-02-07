// Dla listy zawodników o polach (imie, wiek, wzrost), zaczynającej się
// pod jakimś adresem, napisać definicję struktury oraz jedną funkcję (bez definiowania i
// wykorzystywania innych funkcji), która:
// - drukuje wzrost zawodników o imionach zaczynających się jakimś znakiem i w wieku
//   zawartym między dwiema jakimiś wartościami
// - usuwa pierwszego napotkanego zawodnika o wzroście większym od jakiejś wartości
//   i przekazuje przez parametr jego imię
// - zwraca (przez return) adres najmłodszego zawodnika (lub pierwszego z kilku
//   najmłodszych).

#include <string>
#include <iostream>


using namespace std;

struct Zawodnik {
    string imie;
    int wiek;
    int wzrost;
    Zawodnik* next;
};
void print(Zawodnik* head) {
    Zawodnik* p = head;
    while (p) {
        cout << p->imie << " | "
             << p->wiek << " | "
             << p->wzrost << '\n';
        p = p->next;
    }
}
Zawodnik* fun(Zawodnik*& head, char jZnak,
        int wiekL, int wiekR,
        int jWzrost, string& imieJWzrost) {
    Zawodnik* i = head;
    while (i) {
        if (i->imie[0] == jZnak && i->wiek >= wiekL && i->wiek <= wiekR)
            cout << i->wzrost << '\n';
        i = i->next;
    }

    Zawodnik* prev = nullptr;
    i = head;
    while (i) {
        if (i->wzrost > jWzrost) {
            imieJWzrost = i->imie;
            // TODO: note
            if (!prev)
                head = head->next;
            else
                prev->next = i->next;
            delete i;
            // end TODO
            break;
        }
        prev = i;
        i = i->next;
    }

    i = head; if (!i) return nullptr;
    Zawodnik* najmlodszy = head;
    int naj = najmlodszy->wiek;
    while (i) {
        if (i->wiek < naj) {
            naj = i->wiek;
            najmlodszy = i;
        }
        i = i->next;
    }
    return najmlodszy;
}

void clear(Zawodnik*& head) {
    while (head) {
        Zawodnik* tmp = head;
        head = head->next;
        delete tmp;
    }
}
int main()
{
    Zawodnik* a = new Zawodnik{"Adam", 21, 180, nullptr};
    Zawodnik* b = new Zawodnik{"Bartek", 19, 175, nullptr};
    Zawodnik* c = new Zawodnik{"Antek", 23, 190, nullptr};
    Zawodnik* d = new Zawodnik{"Daniel", 18, 168, nullptr};
    Zawodnik* e = new Zawodnik{"Ala", 20, 172, nullptr};
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    string imieJWzrost;
    Zawodnik* najmlodszy = nullptr;
    najmlodszy =fun(a, 'A', 20, 23, 170, imieJWzrost);
    cout << "Imie jWzrost: " << imieJWzrost << '\n';
    if (najmlodszy)
        cout << "Najmlodszy: " << najmlodszy->imie << '\n';
    clear(a);
}
