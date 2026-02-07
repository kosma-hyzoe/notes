// Dla listy liczb całkowitych zapisanej jako lista jednokierunkowa napisać
// definicję struktury, jedną funkcję która:
// * znajduje pierwszy węzeł o wartości większej niż podana liczba k
// * wstawia przed nim nowy węzeł o wartości x
// * jeśli taki węzeł nie istnieje — dopisuje nowy element na koniec listy
// * przez parametr przekazuje:
//   * liczbę elementów większych od x po wykonaniu operacji
// * zwraca przez return:
//   * sumę wszystkich elementów listy

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int l;
    Node* next;
};

int fun(Node*& head, int k, int x, int& cGeX)
{
    int done = 0;
    Node* iter = head;
    if (!iter) {
        head = new Node{x, nullptr};
    } else if (head->l > k) {
        head = new Node{x, head};
    } else {
        Node* last = iter;
        iter = iter->next;
        while (iter) {
            if (iter->l > k) {
                last->next = new Node{x, iter};
                done = 1;
                break;
            }
            last = iter;
            iter = iter->next;
        }
        if (!done)
            last->next = new Node{x, nullptr};
    }
    int ret = 0;
    cGeX = 0;
    iter = head;
    while (iter) {
        if (iter->l > x)
            cGeX++;
        ret += iter->l;
        iter = iter->next;
    }
    return ret;
}
