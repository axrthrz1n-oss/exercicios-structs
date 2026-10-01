// exercicios-structs
// EX 5)
#include <iostream>
using namespace std;

struct TData {
    int Dia;
    int Mes;
    int Ano;
};

bool bissexto(int ano) {
    if (ano % 400 == 0)
        return true;
    if (ano % 100 == 0)
        return false;
    if (ano % 4 == 0)
        return true;
    return false;
}

bool dataValida(TData d) {
    int dias;

    if (d.Mes < 1 || d.Mes > 12)
        return false;

    if (d.Mes == 2) {
        if (bissexto(d.Ano))
            dias = 29;
        else
            dias = 28;
    }
    else if (d.Mes == 4 || d.Mes == 6 || d.Mes == 9 || d.Mes == 11)
        dias = 30;
    else
        dias = 31;

    if (d.Dia < 1 || d.Dia > dias)
        return false;

    return true;
}

int main() {
    TData data;

    cout << "Dia: ";
    cin >> data.Dia;
    cout << "Mes: ";
    cin >> data.Mes;
    cout << "Ano: ";
    cin >> data.Ano;

    if (dataValida(data))
        cout << "Data valida" << endl;
    else
        cout << "Data invalida" << endl;

    return 0;
}
=========================================================================
// EX 6)
#include <iostream>
using namespace std;

struct Ponto {
    float x;
    float y;
};

template <typename T>
void trocar(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}

int main() {
    int a, b;
    Ponto p1, p2;

    cout << "Digite dois numeros: ";
    cin >> a >> b;
    trocar(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    cout << "Digite x e y do ponto 1: ";
    cin >> p1.x >> p1.y;
    cout << "Digite x e y do ponto 2: ";
    cin >> p2.x >> p2.y;
    trocar(p1, p2);
    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    return 0;
}
=========================================================================
// EX 7)
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TData {
    int Dia;
    int Mes;
    int Ano;
};

struct TPessoa {
    string nome;
    TData nasc;
};

void CriaData(TData &D) {
    D.Mes = 1 + (rand() % 12);
    D.Ano = 1940 + (rand() % 74);
    D.Dia = 1 + (rand() % 30);
}

bool bissexto(int ano) {
    if (ano % 400 == 0)
        return true;
    if (ano % 100 == 0)
        return false;
    if (ano % 4 == 0)
        return true;
    return false;
}

bool dataValida(TData d) {
    int dias;

    if (d.Mes < 1 || d.Mes > 12)
        return false;

    if (d.Mes == 2) {
        if (bissexto(d.Ano))
            dias = 29;
        else
            dias = 28;
    }
    else if (d.Mes == 4 || d.Mes == 6 || d.Mes == 9 || d.Mes == 11)
        dias = 30;
    else
        dias = 31;

    if (d.Dia < 1 || d.Dia > dias)
        return false;

    return true;
}

void listarIdades(TPessoa p[], int n, int ano) {
    for (int i = 0; i < n; i++)
        cout << p[i].nome << " - " << ano - p[i].nasc.Ano << " anos" << endl;
}

void listarMaisVelhos(TPessoa p[], int n, int ano, int idade) {
    for (int i = 0; i < n; i++)
        if (ano - p[i].nasc.Ano > idade)
            cout << p[i].nome << endl;
}

int main() {
    TPessoa p[10];
    int n, ano, idade;

    srand(time(NULL));

    cout << "Quantas pessoas (ate 10)? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, p[i].nome);
        do {
            CriaData(p[i].nasc);
        } while (!dataValida(p[i].nasc));
    }

    cout << "Ano de referencia: ";
    cin >> ano;
    listarIdades(p, n, ano);

    cout << "Idade: ";
    cin >> idade;
    listarMaisVelhos(p, n, ano, idade);

    return 0;
}
=========================================================================
// EX 8)
#include <iostream>
using namespace std;

template <typename T>
T maior(T v[], int n) {
    T m = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > m)
            m = v[i];
    return m;
}

int main() {
    float notas[30];

    for (int i = 0; i < 30; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    cout << "Maior nota: " << maior(notas, 30) << endl;

    return 0;
}
=========================================================================
// EX 9)
#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int paginas;
};

int contarLivros(Livro v[], int pag) {
    int cont = 0;
    for (int i = 0; i < 15; i++)
        if (v[i].paginas > pag)
            cont++;
    return cont;
}

int main() {
    Livro v[15];
    int pag;

    for (int i = 0; i < 15; i++) {
        cout << "Titulo: ";
        getline(cin, v[i].titulo);
        cout << "Autor: ";
        getline(cin, v[i].autor);
        cout << "Paginas: ";
        cin >> v[i].paginas;
        cin.ignore();
    }

    cout << "Numero de paginas: ";
    cin >> pag;
    cout << "Livros com mais paginas: " << contarLivros(v, pag) << endl;

    return 0;
}
