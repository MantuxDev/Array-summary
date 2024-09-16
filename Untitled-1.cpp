#include<iostream>
#include<cctype>

using namespace std;

//Prototipi
int menu();
bool caricamento(int numeri[],int &dim);
void copy(int numeri[],int copy_numeri[],int dim);
bool ordina(int copy_numeri[],int dim);
void ordinamento_crescente(int vettore[],int dim);
void stampa(int vettore[],int dim);
void max_min(int numeri[],int dim);
float media(int vettore[],int dim);
int ricerca_parziale(int vettore[],int dim,int x,bool &c);
int ricerca_totale(int vettore[],int dim,int x,bool &c);

//Dichiarazione costanti
const int e=100;

//Caratteri ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"       
#define GREEN   "\033[32m"       
#define YELLOW  "\033[33m"       

int main(){

    int numeri[e],copy_numeri[e],dim,s;
    bool c,c1,c2,c3;

    c=c1=c2=c3=false;

    do{
        system("cls");
        s=menu();
        switch(s){
            case 1:{
                c=caricamento(numeri,dim);
                copy(numeri,copy_numeri,dim);
                cout<<GREEN<<"Caricamento completato!"<<RESET<<endl;
                break;
            }

            case 2:{
                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }

                c1=ordina(copy_numeri,dim);
                break;
            }

            case 3:{
                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }
                max_min(numeri,dim);
                break;
            }

            case 4:{
                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }
                cout<<GREEN<<"La media e': "<<media(numeri,dim)<<RESET<<endl;
                break;
            }

            case 5:{
                int i=0,x=0;
                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }
                cout<<"Inserisci numero da cercare: ";
                cin>>x;
                ricerca_parziale(numeri,dim,x,c2);

                if(c2==false){
                    cout<<RED<<"ERRORE: numero non trovato!"<<RESET<<endl;
                }
                else{
                    cout<<GREEN<<"Numero trovato!"<<RESET<<endl;
                    cout<<"Posizione: "<<x+1<<endl;
                }
                break;
            }

            case 6:{
                int i=0,x=0;

                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }
                cout<<"Inserisci numero da cercare: ";
                cin>>x;
                i=ricerca_totale(numeri,dim,x,c3);

                if(c3==false){
                    cout<<RED<<"ERRORE: numero non trovato!"<<RESET<<endl;
                }
                else{
                    cout<<GREEN<<"Numero trovato!"<<RESET<<endl;
                    cout<<"Posizione: "<<x+1<<endl;
                    cout<<"Numero comparso "<<i<<" volte"<<endl;
                }
                break;
            }

            case 7:{
                if(c==false){
                    cout<<RED<<"ERRORE: caricare prima il vettore!"<<RESET<<endl;
                    break;
                }
                stampa(numeri,dim);
                break;
            }

            case 0:{
                cout<<GREEN<<"Arrivederci!"<<RESET<<endl;
                break;
            }

            default:{
                cout<<RED<<"ERRORE: scelta non valida!"<<RESET<<endl;
                break;
            }

        }

    }while(s!=0);
    system("pause");
    return 0;
}

//Prototipi
int menu(){
    int s;

    cout<<"\t-----MENU-----"<<endl;
    cout<<"1. Caricamento"<<endl;
    cout<<"2. Ordina vettore"<<endl;
    cout<<"3. Trova Max e Min"<<endl;
    cout<<"4. Media"<<endl;
    cout<<"5. Ricerca Parziale"<<endl;
    cout<<"6. Ricerca Totale"<<endl;
    cout<<"7. Stampa vettore"<<endl;
    cout<<"0. Esci"<<endl;

    cout<<"\nInserisci scelta: ";
    cin>>s;
    return s;
}

bool caricamento(int numeri[],int &dim){
    int i=0;
    char ris;

    do{
        cout<<"\nInserisci numero: ";
        cin>>numeri[i];

        i++;

        cout<<"Vuoi continuare? [s/n] ";
        cin>>ris;

        ris=tolower(ris);
    }while(ris!='n');

    dim=i++;
    return true;
}

void copy(int numeri[],int copy_numeri[],int dim){
    for(int i=0;i<dim;i++){
        copy_numeri[i]=numeri[i];
    }
}

bool ordina(int copy_numeri[],int dim){

    ordinamento_crescente(copy_numeri,dim);

    cout<<GREEN<<"Vettore ordinato in ordine crescente:"<<RESET<<endl;
    stampa(copy_numeri,dim);

    for(int i=0;i<dim-1;i++){
        for(int j=i+1;j<dim;j++){
            if(copy_numeri[i]<copy_numeri[j]){
                swap(copy_numeri[i],copy_numeri[j]);
            }
        }    
    }

    cout<<GREEN<<"Vettore ordinato in ordine descrescente:"<<RESET<<endl;
    stampa(copy_numeri,dim);

    return true;
}

void ordinamento_crescente(int vettore[],int dim){
    for(int i=0;i<dim-1;i++){
        for(int j=i+1;j<dim;j++){
            if(vettore[i]>vettore[j]){
                swap(vettore[i],vettore[j]);
            }
        }    
    }
}

void stampa(int vettore[],int dim){
    for(int i=0;i<dim;i++){
        cout<<vettore[i]<<" ";
    }
    cout<<endl;
}

void max_min(int numeri[],int dim){
    int max,min;
    max=min=numeri[0];
    for(int i=1;i<dim;i++){
        if(numeri[i]>max){
            max=numeri[i];
        }
        if(numeri[i]<min){
            min=numeri[i];
        }
    }
    cout<<"Il valore massimo e': "<<max<<endl;
    cout<<"Il valore minimo e': "<<min<<endl;
}

float media(int vettore[],int dim){
    int somma=0;
    for(int i=0;i<dim;i++){
        somma+=vettore[i];
    }
    return (float)somma/dim;
}

int ricerca_parziale(int vettore[],int dim,int x,bool &c){
    for(int i=0;i<dim;i++){
        if(vettore[i]==x){
            x=i;
            c=true;
            break;
        }
    }

    return 0;
}

int ricerca_totale(int vettore[],int dim,int x,bool &c){
    int y=0;

    for(int i=0;i<dim;i++){
        if(vettore[i]==x){
            x=i;
            y++;
            c=true;
        }
    }
    return y;
}