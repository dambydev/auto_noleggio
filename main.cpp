#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct macchina{
    string categoria, marca, modello, colore;
    char lun, mar, mer, gio, ven, sab, dom;
};

string found_car[100];
int c = 0;

int seleziona_auto(){
    int id = 0;
    for(int i=0; i<c; i++)
        cout<<"ID ["<<i<<"] "<<found_car[i]<<endl;

    do{
    cout<<endl<<"Inserisci l'id della macchina: ";
    cin>>id;
    }while(id<=0 || id>=c);

    char con;
    do{
    cout<<"Hai selezionato "<<found_car[id]<<endl;
    cout<<"Conferma [C]"<<endl<<"Torna indietro [e]"<<endl<<">>";
    }while(con !='C' || con != 'e');

    if(con == 'e')
        seleziona_auto();

}

void cerca_auto(macchina car){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
    cout<<"Errore di apertura del file";

    c = 0;
    string cat, app, res;
    char v = ',';

    cout<<"Inserisci la categoria dell'auto: ";
    cin>>car.categoria;

    while(!fin.eof()){
        fin>>cat;
        cat.erase(remove(cat.begin(),cat.end(),v),cat.end());   // Formula che serve per eliminare la virgola
        if(cat == car.categoria){
            getline(fin, app);
            res = cat + "," + app;
            found_car[c] = res;
            c++;
        }
    }

    //seleziona_auto();

    for(int i=0; i<c; i++){
        int x = 0;
        int cv = 0;
        do{
           if(found_car[i][x] == ",")
            cv++;
            x++;
        }while(cv != 4);

    }
    fin.close();
}

void stampa_file(){
}

void menu(macchina car)
{
    int sc;
    do {
    cout << endl;
		cout << "------------------- MENU' -------------------" << endl;
		cout << "1 - Cerca auto" << endl
             << "2 - Stampa file" << endl
		     << "3 - Uscita" << endl << endl
		     << "Inserire scelta >> ";
		cin >> sc;
		switch (sc)
		{
			case 1:
                cerca_auto(car);
				break;
			case 2:
                stampa_file();
			    break;
            case 3:
                cout<<endl<<"Uscita..."<<endl;
                break;
			default:
				cout << endl << "Scelta sbagliata" << endl << endl;
		}
       } while (sc != 3);
}

int main()
{
    macchina car;
    menu(car);
    return 0;
}
