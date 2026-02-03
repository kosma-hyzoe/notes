#include <string>

using namespace std;


struct Student {
    string nazwisko;
    int ocena;
    int wiek;
    Student* next;
};

int fun(Student*& head, string nazwisko, int ocena, int wiek,
        int prog, string& mozeStudent) {
    int count = 1;
    if (!head) {
        head = new Student{nazwisko, ocena, wiek, nullptr};
    } else {
        Student* iter = head;
        while (iter->next) {
            count++;
            iter = iter->next;
        }
        if (count % 2 != 0) {
            Student* tmp = head;
            head = new Student{nazwisko, ocena, wiek, tmp};
        } else {
            Student* tmp = head->next;
            head->next = new Student{nazwisko, ocena, wiek, tmp};
        }
    }

    if (!head->next && head->ocena < prog) {
        mozeStudent = head->nazwisko;
        delete head;
        head = nullptr;
        return 0;
    } else {
        Student* last = head->next;
        Student* prelast = head;
        while (last->next) {
            prelast = last;
            last = last->next;
        }
        if (last->ocena < prog) {
            mozeStudent = last->nazwisko;
            prelast->next = nullptr;
            delete last;
        }
    }

    int oldest = head->wiek;
    if (!head->next)
        return 1;
    Student* iter = head;
    do {
        iter = iter->next;
        if (iter->wiek > oldest) {
            oldest = iter->wiek;
            count = 1;
        } else if (iter->wiek == oldest) {
            count++;
        }
    } while (iter->next);

    return count;
}

int main()
{

}
