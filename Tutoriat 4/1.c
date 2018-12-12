int numarPerechi(int n, int* v) {
    int sosete[101] = {0};
    int rezultat = 0;
    for (int i = 0; i < n; i++) {
        sosete[v[i]]++;
        if (sosete[v[i]] == 2) {
            rezultat++;
            sosete[v[i]] = 0;
        }
    }
    return rezultat;
}