#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct macchina{
    string categoria, marca, modello, colore;
    char week[7];
};

int seleziona_auto(string found_car[100], int c){
    int id = 0;
    for(int i=0; i<c; i++)
        cout<<"ID ["<<i<<"] "<<found_car[i]<<endl;

    do{
    cout<<endl<<"Inserisci l'id della macchina: ";
    cin>>id;
    }while(id<0 || id>c);

    char con;
    bool q = false;
    do{
    cout<<endl<<"Hai selezionato: "<<found_car[id]<<endl;
    cout<<endl<<"Conferma [C]"<<endl<<"Torna indietro [e]"<<endl<<">>";
    cin>>con;
    if(con != 'C'){
        if(con != 'e')
            q = true;
        else
            q = false;
    }
    else
        q = false;
    }while(q==true);

    if(con == 'e')
        seleziona_auto(found_car, c);
    else{
        return id;
    }
    return 0;
}

void affitta(macchina *car, int id, int x, string found_car[100]){
    bool pv = false, cg = false;
    int ris = 0, conta_gd = 0, cpv = 0, cdd = 0;
    int gd[7];

    for(int i=0; i<7; i++){
        if(car->week[i] == 'A')
            cpv++;
    }

    if(cpv != 7){
        cout<<endl<<"Questi sono i giorni disponibili: "<<endl;
            do{
                cdd = 0;
                for(int i=0; i<7; i++){
                    if(car->week[i] == 'A')
                    cdd++;
                }
                if(cdd != 7){
                    cout<<endl;
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
                        cout<<endl<<"Quale/i giorno/i vuoi affittare?";
                        pv = true;
                    }
                    cout<<endl<<"Inserire 9 per uscire";
                    cout<<endl<<">> ";
                    cin>>ris;
                    if(ris == 9){
                        cg = true;
                    }
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
                }
                else{
                    cout<<endl<<"Questa macchina e' stata affittata per tutta la settimana!"<<endl;
                    cg = true;
                }
            }while(cg == false);

                for(int i=0; i<7; i++){
                found_car[id][x] = car->week[i];
                x+=3;
                }

        }
    else
        cout<<endl<<"Questa macchina e' stata affittata per tutta la settimana!"<<endl;
}

void aggiorna_file(string *fo){
    ofstream fout("auto.csv");

    fout<<"";

    int i = 0;
    while(fo[i] != ""){
        fout<<fo[i];
        i++;
    }
    fout.close();
}

void copia_file(string fo[]){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
        cout<<"Errore di apertura del file";

    int i = 0;

    while(!fin.eof()){
        getline(fin, fo[i]);
        if(fin.eof())
            break;
        else{
        fo[i] = fo[i] + '\n';
        i++;
        }
    }
    fin.close();
}

void stampa_file(){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
        cout<<"Errore di apertura del file";
    string l;
    cout<<endl;
    while(!fin.eof()){
        getline(fin, l);
        cout<<l<<endl;
    }
}

void cerca_auto(macchina car, string found_car[100], int c){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
        cout<<"Errore di apertura del file";
    c = 0;
    string cat, app, res;
    char v = ',';

    stampa_file();
    cout<<endl<<"Queste e' la lista della auto"<<endl;

    cout<<endl<<"Inserisci la categoria dell'auto: ";
    cin>>car.categoria;
    cout<<endl;

    while(!fin.eof()){
        fin>>cat;
        if(fin.eof())
            break;
        else{
            cat.erase(remove(cat.begin(),cat.end(),v),cat.end());   // Formula che serve per eliminare la virgola
            if(cat == car.categoria){
                getline(fin, app);
                res = cat + "," + app;
                found_car[c] = res;
                c++;
            }
            else
            getline(fin, app);
        }
    }

    if(c != 0){
        int id = seleziona_auto(found_car, c);
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


        for(int i=0; i<7; i++){
            car.week[i] = found_car[id][x];
            x+=3;
        }
        x = x-21;

        string original = found_car[id]+'\n';

        affitta(&car, id, x, found_car);

        string fo[200];
        copia_file(fo);

        bool b = false;
        int i = 0;
        while(b != true){
            if(fo[i] == original){
                b = true;
                fo[i] = found_car[id] + '\n';
            }
            i++;
        }
        aggiorna_file(fo);
    }
    else
        cout<<"Auto non disponibile"<<endl;
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

void menu(macchina car)
{
    string found_car[100];
    int c = 0;
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
                cerca_auto(car, found_car, c);
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
