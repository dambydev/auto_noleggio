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

/*void affitta(macchina *car, int id, int x, string found_car[100]){
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
}*/

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
/*bool setti[]={false,false,false,false,false,false,false};

     for(int i=0; i<sett.length()-1; i++){
            switch(sett[i]){
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
     cout<<set_g<<endl;*/

void cerca_auto(macchina car, string found_car[100], int c){
    ifstream fin("auto.csv", ios::in);
    if(!fin)
        cout<<"Errore di apertura del file";
    c = 0;
    string cat, app, res, prova;
    char v = ',';

    stampa_file();
    cout<<endl<<"Queste e' la lista della auto"<<endl;


    string ca, sett;
    int k = 0;

    cout<<" >> ";
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
     cout<<set_g<<endl;

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

     cout<<mac[0].categoria<<endl;
     cout<<mac[0].marca<<endl;
     cout<<mac[0].modello<<endl;
     cout<<mac[0].colore<<endl;
     for(int i=0; i<7; i++){
        cout<<mac[0].week[i]<<endl;
     }
     cout<<mac[1].categoria<<endl;
     cout<<mac[1].marca<<endl;
     cout<<mac[1].modello<<endl;
     cout<<mac[1].colore<<endl;
     for(int i=0; i<7; i++){
        cout<<mac[1].week[i]<<endl;
     }

    int ok;
    int md = 0;

    for(int i=0; i<contato; i++){
        ok = 0;
        for(int u=0; u<sett.length()-1; u++){
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

    cout<<"Queste sono le macchina disponibili"<<endl;

    if(md>0){
        for(int i=0; i<contato; i++){
            if(mac[i].d==true)
                cout<<"["<<i<<"]"<<"  "<<mac[i].marca<<" "<<mac[i].modello<<" "<<mac[i].colore<<endl;
        }
    }

    int id;
    cout<<"Quale vuoi selezionare? >> ";
    cin>>id;

    for(int i=0; i<7; i++)
        cout<<"Posizione I : "<<i<<" "<<mac[id].week[i]<<endl;

    cout<<endl<<endl;

    for(int i=0; i<7; i++)
        cout<<mac[id].week[i];

       cout<<endl<<endl;

    for(int i=0; i<sett.length(); i++){
        int n = int(sett[i])-49;
        cout<<"Posizione n : "<<n<<" "<<mac[id].week[n]<<endl;
        mac[id].week[n]=" A";
    }

    string riga = mac[id].categoria+','+mac[id].marca+','+mac[id].modello+','+mac[id].colore+',';
    for(int i=0; i<7; i++){
        if(i!=6)
            riga = riga + mac[id].week[i]+',';
        else
            riga = riga + mac[id].week[i];
    }

    cout<<riga<<endl;

    string fo[100];

    copia_file(fo);

    int conta_r = 0;
    int r = 0;

    while(!fin.eof()){
        getline(fin, a, ',');
        if(a == mac[id].categoria){
            getline(fin, a, ',');
            if(a == mac[id].marca)
                getline(fin, a, ',');
                    if(a == mac[id].modello)
                        getline(fin, a, ',');
                            if(a == mac[id].colore){
                                r = conta_r;
                            }
        }
        else{
            getline(fin, a);
            conta_r++;
        }
    }

    fo[r] = riga;
    aggiorna_file(fo);

    /*cin>>car.categoria;
    cout<<endl;
    int g;
    do{
        cout<<"Inserisci i giorni da prenotare (8 per uscire): ";
        cin>>g;
        if(g!=8){
            switch(g){
                case 1:
                    car.week[g-1] = "A";
                break;

                case 2:
                    car.week[g-1] = "A";
                break;

                case 3:
                    car.week[g-1] = "A";
                break;

                case 4:
                    car.week[g-1] = "A";
                break;

                case 5:
                    car.week[g-1] = "A";
                break;

                case 6:
                    car.week[g-1] = "A";
                break;

                case 7:
                    car.week[g-1] = "A";
                break;

                default:
                break;
            }
        }
    }while(g!=8);


    string settimana;

    for(int i=0; i<7; i++){
        if(car.week[i]!="A")
            car.week[i]="L";
        settimana = settimana+car.week[i];
    }*/
/*
    string found_sett[100];
    string ap;

    while(!fin.eof()){
        getline(fin, ap, ',');
        if(ap == car.categoria){
                cout<<ap<<endl;
                for(int i=0; i<10; i++){
                    if(i!=9)
                        getline(fin, ap, ',');
                    else
                        getline(fin, ap, '\n');
                    ap.erase(remove(ap.begin(),ap.end(),' '),ap.end());
                    switch(i){
                    case 0:
                        cout<<"marca"<<ap;
                        car.marca = ap;
                        break;
                    case 1:
                        cout<<"marca"<<ap<<endl;
                        car.modello = ap;
                        break;
                    case 2:
                        cout<<"marca"<<ap<<endl;
                        car.colore = ap;
                        break;
                    case 3:
                        cout<<"msca"<<ap<<endl;
                        car.week[0] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 4:
                        cout<<"marca"<<ap<<endl;
                        car.week[1] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 5:
                        cout<<"marca"<<ap<<endl;
                        car.week[2] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 6:
                        cout<<"marca"<<ap<<endl;
                        car.week[3] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 7:
                        cout<<"marca"<<ap<<endl;
                        car.week[4] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 8:
                        cout<<"marca"<<ap<<endl;
                        car.week[5] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                    case 9:
                        cout<<"marca"<<ap<<endl;
                        car.week[6] = ap;
                        found_sett[c] = found_sett[c]+app;
                        break;
                }
            }
            c++;
        }
        else
            getline(fin, ap);
    }

    int id[100];
    int contid = 0;

    for(int i=0; i<c; i++){
        if(settimana == found_sett[i]){
            id[contid] = i;
            contid++;
        }
    }

    if(contid != 0){
        cout<<"Queste sono le macchine disponibili; "<<endl;
        for(int i=0; i<contid; i++){
            int d = id[i];
            cout<<"["<<i<<"]"<<" "<<car.marca[d]<<" "<<car.modello[d]<<" "<<car.colore[d]<<endl;
        }
    }

    int as;
    cout<<"Quale vuoi inserire? >> ";
    cin>>as;
    if(as>=contid){
        cout<<"errore";
    }
    cout<<"["<<as<<"]"<<" "<<car.marca[as]<<" "<<car.modello[as]<<" "<<car.colore[as]<<endl;



/*



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

        //affitta(&car, id, x, found_car);

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
        */
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
