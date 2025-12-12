#include <iostream>

struct SomeChars {
    char a;
    char b;
};

static const int n = 5;
static const int L = 30;

using namespace std;

int main()
{
    char a, b;
    SomeChars P[n] = {};
    int awayLFromACount = 0, awayMoreThanLFromACount = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        P[i] = {a, b};
        if ((P[i].a - 'a') * (P[i].b - 'a') <= L)
            awayLFromACount++;
        else
            awayMoreThanLFromACount++;
    }

    int idx1 = 0, idx2 = 0;
    SomeChars *awayLFromA = new SomeChars[awayLFromACount];
    SomeChars *awayMoreThanLFromA = new SomeChars[awayMoreThanLFromACount];
    cout << "> P:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\t" <<  P[i].a << " " << P[i].b << endl;
        if ((P[i].a - 'a') * (P[i].b - 'a') <= L) {
            awayLFromA[idx1++] = P[i];
        } else {
            awayMoreThanLFromA[idx2++] = P[i];
        }
    }
    cout << "> Rekordy, w których iloczyn odległości nie przekracza L:" << endl;
    for (int i = 0; i < awayLFromACount ; i++)
        cout << "\t" << awayLFromA[i].a << " " << awayLFromA[i].b << endl;

    cout << "> Rekordy, w których iloczyn odległości przekracza L:" << endl;
    for (int i = 0; i < awayMoreThanLFromACount; i++)
        cout << "\t" << awayMoreThanLFromA[i].a << " " << awayMoreThanLFromA[i].b << endl;

    delete [] awayLFromA;
    delete [] awayMoreThanLFromA;
}
