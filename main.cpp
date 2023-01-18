#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct macchina{
    string categoria, marca, modello, colore;
    char week[7];
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
    }while(id<0 || id>=c);

    char con;
    bool c = false;
    do{
    cout<<"Hai selezionato "<<found_car[id]<<endl;
    cout<<"Conferma [C]"<<endl<<"Torna indietro [e]"<<endl<<">>";
    cin>>con;
    if(con != 'C'){
        if(con != 'e')
            c = true;
        else
            c = false;
    }
    else
        c = false;
    }while(c==true);

    if(con == 'e')
        seleziona_auto();
    else{
        return id;
    }
}

void affitta(macchina *car, int id, int x){
    bool pv = false, cg = false;
    int ris = 0, conta_gd = 0;
    int gd[7];
    cout<<"Questi sono i giorni disponibili: "<<endl;
    do{
        for(int i=1; i<8; i++){
            switch(i){
                case 1:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Lunedi'"<<endl;
                    }
                break;
                case 2:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Martedi'"<<endl;
                    }
                break;
                case 3:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Mercoledi'"<<endl;
                    }
                break;
                case 4:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Giovedi'"<<endl;
                    }
                break;
                case 5:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Venerdi'"<<endl;
                    }
                break;
                case 6:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Sabato"<<endl;
                    }
                break;
                case 7:
                    if(car->week[i-1]=='L'){
                        cout<<"["<<i<<"]"<<"Domenica"<<endl;
                    }
                break;
                default:
                    cout<<"Errore"<<endl;
            }
        }

            if(pv == false){
                cout<<"Quali giorno/i vuoi affittare?";
                pv = true;
            }
            else
                cout<<endl;

            cout<<endl<<"Inserire 9 per uscire";
            cout<<endl<<">> ";
            cin>>ris;
            if(ris == 9)
                cg = true;

                if(cg == false){

                bool cgd = false;
                for(int i=0; i<conta_gd; i++){
                    if(ris == car->week[i])
                        cgd = true;
                    else
                        cgd = false;
                }

                if(cgd == false){
                    switch(ris){
                        case 1:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 2:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 3:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 4:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 5:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 6:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;

                        case 7:
                            car->week[ris-1] = 'A';
                            gd[conta_gd] = ris;
                            conta_gd++;
                        break;
                    }
                }
                else
                    cout<<"Hai inserito un giorno gia' prenotato"<<endl;
            }
        }while(cg == false);

        for(int i=0; i<7; i++)
        {
        found_car[id][x] = car->week[i];
        x+=3;
        }
}

void aggiorna_file(macchina *car, int id, int x){
    ofstream fout("auto.csv", ios::out);
    ifstream fin("auto.csv");
    string line;
    int c = 0;
    if(fout.good()){
            for(int i=0; i<id; i++){
                getline(fin, line);
                    if(i == id-1)
                        fout<<found_car[id][x];
            }
    }
    else
        cout<<"Errore del file in lettura";
    fin.close();

}

/*
utilitaria, FIAT, Panda, rosso, L, L, L, A, A, A, A
utilitaria, KIA, Pikanto, bronzo, A, A, L, L, L, A, A
lusso, Mercedes, Classe 5, nero, L, L, L, L, L, A, A
sportiva, Lamborghini, Huracan, giallo, L, L, L, L, L, L, L
furgone, Ford, Transit, bianco, A, A, A, A, A, L, L
lusso, BMW, Serie 5, grigio metallizzato, L, L, L, L, L, A, A
utilitaria, Peugeot, 108, verde, L, A, L, L, L, A, L
*/
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

    int id = seleziona_auto();
    int cv = 0;
    int x = 0;
    do{

       if(found_car[id][x] == ','){
         cv++;
         }
       if(cv == 4){
            x++;
        }
         x++;
    }while(cv != 4);

    for(int i=0; i<7; i++)
    {
        car.week[i] = found_car[id][x];
        x+=3;
    }
    x = x-21;
    affitta(&car, id, x);
    aggiorna_file(&car, id, x);
    fin.close();
}

void menu(macchina car)
{
    int sc;
    do {
    cout << endl;
		cout << "------------------- MENU' -------------------" << endl;
		cout << "1 - Cerca autoe" << endl
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
