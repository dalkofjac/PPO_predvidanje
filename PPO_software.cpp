#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;

void pom_arit_sredina(int n,int N,float potr[])
{
     float pomarit[n+1];
     float suma_prosjek;
     for(int i=0;i<n-N+1;i++){
             suma_prosjek = 0;
             for(int j=i;j<N+i;j++){
                     suma_prosjek = suma_prosjek + potr[j];
                     }
             pomarit[i+N]=(suma_prosjek / N);
             }
     for(int i=0;i<N;i++){
             pomarit[i]=0;
             }
             
     cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
     cout << "||" << "Mjesec" << "||" << "Potraznja" << "||" << "Pom.arit.sredina" << "||" << endl;
     cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
     
     for(int i=0;i<n+1;i++){
             if(i<9){
                 if(potr[i]==0){
                                cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(10) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                                }
                 else if(potr[i]>=100){
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(8) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                      }
                 else{
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(9) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                      }
                      }
             else{
                  if(potr[i]==0){
                            cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(10) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                            }
                  else if(potr[i]>=100){
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(8) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                  }
                  else{
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(9) << "||" << roundf(pomarit[i]) << setw(16) << "||" << endl;
                  }
                  }
            }
     //tocnost
     float suma_mad = 0;
     float suma_d = 0;
     float suma_bias = 0;
     float suma_mse = 0;
     for(int i=N;i<n;i++){
             suma_mad = suma_mad + abs((potr[i]-pomarit[i]));
             suma_d = suma_d + (potr[i]);
             }
     for(int i=N;i<n;i++){
             suma_bias = suma_bias + (potr[i]-pomarit[i]);
             }
     for(int i=N;i<n;i++){
             suma_mse = suma_mse + pow((potr[i]-pomarit[i]),2);
             }
     
     float MAD = suma_mad / (n-N);
     float MAPD = suma_mad / suma_d;
     float BIAS = suma_bias / (n-N);
     float MSE = suma_mse / (n-N-1);
       
     cout << endl;
     cout << "Podaci tocnosti izracuna predvidanja: " << endl;
     cout << "MAD = " << MAD << endl;
     cout << "MAPD = " << MAPD << endl;
     cout << "BIAS = " << BIAS << endl;
     cout << "E = " << suma_bias << endl;
     cout << "TS = " << (suma_bias / MAD) << endl;
     cout << "MSE = " << MSE << endl;
               
}

void pon_arit_sredina(int n,int b,float faktori[], float potr[])
{
    float ponarit[n+1];
    float suma_ponarit;
    int brojj;
    
    for(int i=0;i<b;i++){
            ponarit[i]=0;
            }
    
    for(int i=0;i<n-b+1;i++){
            suma_ponarit = 0;
            brojj = 0;
            for(int j=i;j<b+i;j++){
                    suma_ponarit= suma_ponarit + (faktori[brojj]*potr[j]);
                    brojj++;
                    }
            ponarit[i+b]=suma_ponarit;
            }
    cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
    cout << "||" << "Mjesec" << "||" << "Potraznja" << "||" << "Pon.arit.sredina" << "||" << endl;
    cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
    
    for(int i=0;i<n+1;i++){
             if(i<9){
                 if(potr[i]==0){
                                cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(10) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                                }
                 else if(potr[i]>=100){
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(8) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                      }
                 else{
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(9) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                      }
                      }
             else{
                  if(potr[i]==0){
                            cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(10) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                            }
                  else if(potr[i]>=100){
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(8) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                  }
                  else{
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(9) << "||" << roundf(ponarit[i]) << setw(16) << "||" << endl;
                  }
                  }
            }
    //tocnost
     float suma_mad = 0;
     float suma_d = 0;
     float suma_bias = 0;
     float suma_mse = 0;
     for(int i=b;i<n;i++){
             suma_mad = suma_mad + abs((potr[i]-ponarit[i]));
             suma_d = suma_d + (potr[i]);
             }
     for(int i=b;i<n;i++){
             suma_bias = suma_bias + (potr[i]-ponarit[i]);
             }
     for(int i=b;i<n;i++){
             suma_mse = suma_mse + pow((potr[i]-ponarit[i]),2);
             }
     
     float MAD = suma_mad / (n-b);
     float MAPD = suma_mad / suma_d;
     float BIAS = suma_bias / (n-b);
     float MSE = suma_mse / (n-b-1);
       
     cout << endl;
     cout << "Podaci tocnosti izracuna predvidanja: " << endl;
     cout << "MAD = " << MAD << endl;
     cout << "MAPD = " << MAPD << endl;
     cout << "BIAS = " << BIAS << endl;
     cout << "E = " << suma_bias << endl;
     cout << "TS = " << (suma_bias / MAD) << endl;
     cout << "MSE = " << MSE << endl;
}

void eks_izgladivanje(int n,float alfa, float potr[])
{
     float izglad[n+1];
     izglad[0]=potr[0];
     
     for(int i=0;i<n+1;i++){
             izglad[i+1]=(alfa*potr[i])+((1-alfa)*izglad[i]);
             }
             
    cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
    cout << "||" << "Mjesec" << "||" << "Potraznja" << "||" << "Eks.izgladivanje" << "||" << endl;
    cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
    
    for(int i=0;i<n+1;i++){
             if(i<9){
                 if(potr[i]==0){
                                cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(10) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                                }
                 else if(potr[i]>=100){
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(8) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                      }
                 else{
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(9) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                      }
                      }
             else{
                  if(potr[i]==0){
                            cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(10) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                            }
                  else if(potr[i]>=100){
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(8) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                  }
                  else{
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(9) << "||" << roundf(izglad[i]) << setw(16) << "||" << endl;
                  }
                  }
            }
    //tocnost
     float suma_mad = 0;
     float suma_d = 0;
     float suma_bias = 0;
     float suma_mse = 0;
     for(int i=0;i<n;i++){
             suma_mad = suma_mad + abs((potr[i]-izglad[i]));
             suma_d = suma_d + (potr[i]);
             }
     for(int i=0;i<n;i++){
             suma_bias = suma_bias + (potr[i]-izglad[i]);
             }
     for(int i=0;i<n;i++){
             suma_mse = suma_mse + pow((potr[i]-izglad[i]),2);
             }
     
     float MAD = suma_mad / (n);
     float MAPD = suma_mad / suma_d;
     float BIAS = suma_bias / (n);
     float MSE = suma_mse / (n-1);
       
     cout << endl;
     cout << "Podaci tocnosti izracuna predvidanja: " << endl;
     cout << "MAD = " << MAD << endl;
     cout << "MAPD = " << MAPD << endl;
     cout << "BIAS = " << BIAS << endl;
     cout << "E = " << suma_bias << endl;
     cout << "TS = " << (suma_bias / MAD) << endl;
     cout << "MSE = " << MSE << endl;
}

void lin_trend(int n,float potr[])
{
     float suma_perioda = 0;
     for(int i=1;i<=n;i++){
             suma_perioda = suma_perioda + i;
             }
     float x = suma_perioda / n;
     float suma_potraznje = 0;
     for(int i=0;i<n;i++){
             suma_potraznje = suma_potraznje + potr[i];
             }
     float y = suma_potraznje / n;
     float suma_xx=0;
     
     for(int i=1;i<=n;i++){
             suma_xx= suma_xx + (i*i);
             }
     float suma_xy=0;
     for(int i=0;i<n;i++){
             suma_xy=suma_xy + (potr[i]*(i+1));
             }
     float b;
     
     b = (suma_xy - (n * x * y)) / (suma_xx - (n * pow(x,2)));
     
     float a;
     
     a= (y - (b * x));
     
     cout << "Jednadzba linearnog trenda za unesene vrijednosti glasi: " << "y = " << a << " + " << b << "x" << endl;
     
     float linearni[n+1];
     for(int i=0;i<n+1;i++){
             linearni[i]=a+(b*(i+1));
             }
     cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
     cout << "||" << "Mjesec" << "||" << "Potraznja" << "||" << "Linearni trend  " << "||" << endl;
     cout << "||" << "------" << "||" << "---------" << "||" << "----------------" << "||" << endl;
    
     for(int i=0;i<n+1;i++){
             if(i<9){
                 if(potr[i]==0){
                                cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(10) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                                }
                 else if(potr[i]>=100){
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(8) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                      }
                 else{
                      cout << "||" << i+1 << setw(7) << "||" << potr[i] << setw(9) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                      }
                      }
             else{
                  if(potr[i]==0){
                            cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(10) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                            }
                  else if(potr[i]>=100){
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(8) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                  }
                  else{
                       cout << "||" << i+1 << setw(6) << "||" << potr[i] << setw(9) << "||" << roundf(linearni[i]) << setw(16) << "||" << endl;
                  }
                  }
            }
     //tocnost
     float suma_mad = 0;
     float suma_d = 0;
     float suma_bias = 0;
     float suma_mse = 0;
     for(int i=0;i<n;i++){
             suma_mad = suma_mad + abs((potr[i]-linearni[i]));
             suma_d = suma_d + (potr[i]);
             }
     for(int i=0;i<n;i++){
             suma_bias = suma_bias + (potr[i]-linearni[i]);
             }
     for(int i=0;i<n;i++){
             suma_mse = suma_mse + pow((potr[i]-linearni[i]),2);
             }
     
     
     float MAD = suma_mad / n;
     float MAPD = suma_mad / suma_d;
     float BIAS = suma_bias / n;
     float MSE = suma_mse / (n-1);
       
     cout << endl;
     cout << "Podaci tocnosti izracuna predvidanja: " << endl;
     cout << "MAD = " << MAD << endl;
     cout << "MAPD = " << MAPD << endl;
     cout << "BIAS = " << BIAS << endl;
     cout << "E = " << suma_bias << endl;
     cout << "TS = " << (suma_bias / MAD) << endl;
     cout << "MSE = " << MSE << endl;
}
     
int main() {
    cout << "Dobrodosli! Ovo je program iz kolegija PPO!"<< "|" << endl;
    cout << "Koristi se za izracun predvidanja! " << setw(9) << "|" << endl;
    cout << "--------------------------------------------";
    cout << endl;
    string jos = "ne";

    int n;
    cout << "Upisite zeljeni broj perioda: ";
    cin >> n;
    cout << endl;
    
    float potr[n+1];
    for(int i=0;i<n;i++){
            cout << "Upisite potraznju za " << i+1 << ". mjesec: ";
            cin >> potr[i];
            }
    potr[n]=0;
        
    do{
        int v;
        
        do{
            cout << endl;
            cout << "Molimo odaberite vrstu predvidanja koju zelite koristiti(1-4): " << endl;
            cout << "1 - pomicna aritmeticka sredina" << endl;
            cout << "2 - ponderirana aritmeticka sredina" << endl;
            cout << "3 - eksponencijalno izgladivanje" << endl;
            cout << "4 - linearni trend" << endl;
            cout << "Odabir? ";
            cin >> v;
            cout << endl;
            if(v<=0 || v>=5){
                    cout << "Pogresan unos..." << endl;
                    }
            }while(v<=0 || v>=5);
        
        cout << endl;
        
        int N;
        int b;
        float alfa;
        float faktori[n];
        float sumafaktora;
        
        if(v==1){
                 cout << "Odabrali ste Pomicnu aritmeticku sredinu" << endl;
                 cout << "Upisite broj prethodnih intervala(n): ";
                 cin >> N;
                 pom_arit_sredina(n,N,potr);
                 }
        
        else if(v==2){
             cout << "Odabrali ste Ponderiranu aritmeticku sredinu" << endl;

             cout << "Upisite broj mjeseci za koji unosite faktore: ";
             cin >> b;
             int pomoc = b;
             do {
                 sumafaktora = 0;
                 for(int i=0;i<b;i++){
                         cout << "Upisite faktor za n - " << pomoc  << " (0.00 - 1.00): ";
                         cin >> faktori[i];
                         sumafaktora = sumafaktora + faktori[i];
                         pomoc--;
                         }
                 if(sumafaktora != 1){
                                cout << "Pogresan unos..." << endl;
                                }
                 pomoc = b;
                 }while(sumafaktora != 1);
                     
             pon_arit_sredina(n,b,faktori,potr);
             }
             
        else if(v==3){
             cout << "Odabrali ste Eksponencijalno izgladivanje" << endl;
             do{
                 cout << "Upisite tezinski faktor alfa(od 0.00 do 1.00): ";
                 cin >> alfa;
                 if(alfa<0 || alfa>1){
                           cout << "Pogresan unos..." << endl;
                           }
                 }while(alfa<0 || alfa>1);
             eks_izgladivanje(n,alfa, potr);
             }
        
        else if(v==4){
             cout << "Odabrali ste Linearni trend" << endl;
             lin_trend(n,potr);
             }
        cout << "Zelite li zapoceti novi izracun sa istim potraznjama? (da/ne): ";
        cin >> jos;
        cout << endl;
        }while(jos == "da");


    system("pause");
    return 0;
}
