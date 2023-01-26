#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct macchina{
    string categoria, marca, modello, colore;
    string week[7];
    bool d = false;
};

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

void cerca_auto(){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
        cout<<"Errore di apertura del file";
    string cat, app, res, prova;

    stampa_file();
    cout<<endl<<"Questa e' la lista della auto"<<endl;
    cout<<endl<<"Inserire la categoria dell'auto e i/il giorni/o della settimana che si vuole prenotare"<<endl
    <<"1 = lunedi', 2 = martedi', 3 = mercoledi', 4 = giovedi', 5 = venerdi'; 6 = sabato; 7 = domenica"<<endl<<endl
    <<"Ricorda se vuoi prenotare piu' di un giorno, bisogna intervallarli con un spazio. Esempio: 'lusso 4 5'";


    string ca, sett;

    cout<<endl<<endl<<" >> ";
    cin.ignore();
    getline(cin, prova);
    stringstream ss(prova);
    string word;
    int i = 0;
    while (ss >> word) {
            if (i == 0) {
            ca = word;
        } else {
            sett += word;
        }
        i++;
    }

    if(sett == ""){
        cout<<endl<<"Bisogna inserire anche il giorno oltre alla categoria!"<<endl;
        return;
    }
    for(int i=0; i<sett.length();i++){
        if(sett[i]=='0' || sett[i]=='8' || sett[i]=='9'){
            cout<<endl<<"Hai inserito un giorno della settimana sbagliato"<<endl;
            return;
        }
    }

     bool setti[]={false,false,false,false,false,false,false};
     for(int i=0; i<sett.length(); i++){
            int n = int(sett[i])-48;
            switch(n){
            case 1:
                if(setti[0]==false)
                    setti[0]=true;
            break;
            case 2:
                if(setti[1]==false)
                    setti[1]=true;
            break;
            case 3:
                if(setti[2]==false)
                    setti[2]=true;
            break;
            case 4:
                if(setti[3]==false)
                    setti[3]=true;
            break;
            case 5:
                if(setti[4]==false)
                    setti[4]=true;
            break;
            case 6:
                if(setti[5]==false)
                    setti[5]=true;
            break;
            case 7:
                if(setti[6]==false)
                    setti[6]=true;
            break;
            }
     }

     string set_g;
     for(int i=0; i<7; i++){
        if(setti[i]==true)
            set_g=set_g+"A";
        else
            set_g=set_g+"L";
     }

     string a;
     macchina mac[100];
     int contato = 0;


     while(!fin.eof()){
        getline(fin, a, ',');
            if(a == ca){
                mac[contato].categoria = a;
                getline(fin, a, ',');
                mac[contato].marca = a;
                getline(fin, a, ',');
                mac[contato].modello = a;
                getline(fin, a, ',');
                mac[contato].colore = a;
                for(int i=0; i<6; i++){
                    getline(fin, a, ',');
                    mac[contato].week[i] = a;
                }
                getline(fin, a);
                mac[contato].week[6] = a;
                contato++;
            }
            else
                getline(fin, a);
     }

    int ok;
    int md = 0;

    for(int i=0; i<contato; i++){
        ok = 0;
        for(int u=0; u<sett.length(); u++){
            int n = int(sett[u])-49;
            string ww = mac[i].week[n];
            ww.erase(remove(ww.begin(),ww.end(),' '),ww.end());
            char w = ww[0];
            if(set_g[n] == w){
                ok++;
            }
        }
        if(ok == 0){
            mac[i].d = true;
            md++;
        }
    }

    if(md>0){
        int ms = 0;
        cout<<endl<<"Queste sono le macchina disponibili"<<endl;
        for(int i=0; i<contato; i++){
            if(mac[i].d==true){
                cout<<"["<<i<<"]"<<"  "<<mac[i].marca<<" "<<mac[i].modello<<" "<<mac[i].colore<<endl;
                ms++;
            }
        }
        char risp;
        bool cris=false;
        int id;
        if(ms != 1){
            do{
            cout<<endl<<"Questa sono le auto disponobili, vuoi continuare con la prenotazione? (s/n)"<<endl;
            cout<<" >> ";
            cin>>risp;
            if(risp == 'n')
                return;
                else if(risp != 's')
                    cris = true;
                else
                    cris = false;
            }while(cris == true);
            cout<<endl<<"Quale vuoi selezionare? >> ";
            cin>>id;
        }
        else{
            do{
            cout<<endl<<"Questa e' l'unica auto disponobile, vuoi confermare la prenotazione? (s/n)"<<endl;
            cout<<" >> ";
            cin>>risp;
            if(risp == 'n')
                return;
                else if(risp != 's')
                    cris = true;
                else
                    cris = false;
            }while(cris == true);
        }

        string riga_og = mac[id].categoria+','+mac[id].marca+','+mac[id].modello+','+mac[id].colore+',';

        for(int i=0; i<7; i++){
            if(i!=6)
                riga_og = riga_og + mac[id].week[i]+',';
            else
                riga_og = riga_og + mac[id].week[i]+'\n';
        }

        for(int i=0; i<sett.length(); i++){
            int n = int(sett[i])-49;
            mac[id].week[n]=" A";
        }

        string riga = mac[id].categoria+','+mac[id].marca+','+mac[id].modello+','+mac[id].colore+',';
        for(int i=0; i<7; i++){
            if(i!=6)
                riga = riga + mac[id].week[i]+',';
            else
                riga = riga + mac[id].week[i]+'\n';
        }

        string fo[100];

        copia_file(fo);

        bool jj = false;
        int ll = 0;

        while(jj == false){
            if(fo[ll] == riga_og){
                fo[ll] = riga;
            jj = true;
            }
            ll++;
        }
    aggiorna_file(fo);
    cout<<endl<<"Prenotazione avvenuta con successo!"<<endl;
    cout<<endl<<"Lista aggiornata"<<endl;
    stampa_file();
    }
    else{
        cout<<endl<<"Non ci sono auto disponibili al momento"<<endl;
    }
    fin.close();
}

void menu()
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
                cerca_auto();
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
    menu();
    return 0;
}
