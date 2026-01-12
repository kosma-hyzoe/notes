Procedura Dijkstra (graf G, węzeł źródłowy r)

// S – zbiór pusty
// Q – zbiór pusty
for (każdy węzeł i grafu G(V, E) ) {
    //tablica D przechowująca wartości aktualnie najkrótszej
    D[i] = nieskończoność
    //ścieżki od źródła do węzła vi

    P[i] = 0	//tablica P przechowująca indeks węzła, który jest
            //poprzednikiem węzła i na najkrótszej ścieżce od źródła
            //do i
}
// dodaj źródło (węzeł) r do zbioru Q
// D[r] = 0

while (zbiór Q nie jest pusty) {
    wybierz ze zbioru Q wierzchołek o indeksie i, dla którego wartość D[i] będzie najmniejsza
    dodaj wierzchołek i do zbioru S

    for (każdy wierzchołek j sąsiadujący z wierzchołkiem i, który nie należy do S)
        if  (D[i] +w[i,j] < D[j]) {	//oznacza to, że znaleziono krótszą ścieżkę
                        //do i przez węzeł j niż znaleziona do tej
                        //pory, należy
                        //ją zaktualizować i określić
                        //nowego poprzednika
            D[j] = D[i] +w[i,j]
            P[j] = i
            dodaj węzeł j do zbioru Q
        }
}
