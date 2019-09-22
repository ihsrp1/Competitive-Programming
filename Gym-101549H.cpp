#include <bits/stdc++.h>

using namespace std;

typedef struct pessoa{
	char nome[1000];
	int dias;
}Pessoa;


int bissexto(int ano){
    if(ano%4 == 0){
        if(ano%100 == 0){
            if(ano%400 == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mesesBi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dias_entre_datas(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2){
	int aux, i, qtdDias = 0;
	for(i = ano1+1; i < ano2; i++){
        if(bissexto(i) == 1){
            qtdDias += 366;
        }else{
            qtdDias += 365;
        }
    }
    
    if(ano1 == ano2){
        if(mes1 == mes2){
            qtdDias += dia2 - dia1;
            printf("%d\n", qtdDias);
            return 0;
        }
        for(i = mes1; i < mes2-1; i++){
            if(bissexto(ano1) == 1){
                qtdDias += mesesBi[i];
            }else{
                qtdDias += meses[i];
            }
        }
    }else{
        for(i = mes1; i < 12; i++){
            if(bissexto(ano1) == 1){
                qtdDias += mesesBi[i];
            }else{
                qtdDias += meses[i];
            }
        }

        for(i = 0; i < mes2-1; i++){
            if(bissexto(ano2) == 1){
                qtdDias += mesesBi[i];
            }else{
                qtdDias += meses[i];
            }
        }
    }


    qtdDias += dia2;
    if(bissexto(ano1) == 1) qtdDias += (mesesBi[mes1 - 1] - dia1);
    else qtdDias += (meses[mes1 - 1] - dia1);

    return qtdDias;
}

int main()
{
    vector<Pessoa> pessoas;
	char nome[1000];
    int dia, mes, ano;
    int n;
	int min = 99999999;
	int indice_min = 0;
	int indice_max = 0;
	int max = 0;

	cin >> n;

	for(int i = 0; i < n; i++){
		Pessoa temp;
		cin >> nome >> dia >> mes >> ano;
		strcpy(temp.nome, nome);
		temp.dias = dias_entre_datas(1, dia, 1, mes, 1, ano);
		//cout << temp.nome << " - " << temp.dias << endl;
		pessoas.push_back(temp);
	}

	for(int i = 0; i < n; i++){
		if(pessoas[i].dias > max) {
			max = pessoas[i].dias;
			indice_min = i;
		}
		if(pessoas[i].dias < min){
			min = pessoas[i].dias;
			indice_max = i;
		}
	}

	cout << pessoas[indice_min].nome << endl << pessoas[indice_max].nome << endl;
	


    

    return 0;
}