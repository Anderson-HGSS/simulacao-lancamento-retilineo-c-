#include <iostream>

using namespace std;

double posicao_inicial = 100; //Em metros
double velocidade_inicial = 30; //Em metros por segundo
double G = 9.81; 
double tempo; //Em segundos
double posicao_atual;
double velocidade_atual;
double pico_altura;
double pico_tempo;
bool pico_encontrado = false;
double posicao_anterior = 0;
double tempo_anterior = 0;

int main(){
    cout << "Digite o tempo da simulacao: ";
    cin >> tempo;

    cout << "\n---------------------------------------" << "\n";

    for(double t = 0; t <= tempo; t = t + 0.01){
        posicao_atual = posicao_inicial + velocidade_inicial * t - ( ( G* ( t * t ) ) / 2);
        velocidade_atual = velocidade_inicial - (G * t);

        if(posicao_atual < posicao_anterior){
            pico_altura = posicao_anterior;
            pico_tempo = tempo_anterior;
            pico_encontrado = true;
        }

        if(!pico_encontrado){
            posicao_anterior = posicao_atual;
            tempo_anterior = t;
        }

        if(posicao_atual > 0){
            cout << "Tempo: " << t << "\n";
            cout << "A posicao atual do objeto eh: " << posicao_atual << "\n";
            cout << "A velocidade atual do objeto eh: " << velocidade_atual << "\n";

        }else{

            cout << "Chegou ou passou o chao!" << "\n\n";
            break;
        }
        
        cout << "---------------------------------------" << "\n";

    }

    cout << "A altura do pico do lancamento pela simulacao foi em " << pico_altura << " metros!\n";
    cout << "O tempo do pico do lancamento pela simulacao foi em " << pico_tempo << " segundos!\n\n";

    return 0;
}