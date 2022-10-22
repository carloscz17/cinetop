#include <iostream>

using namespace std;

string client_name(string name){
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
    cout << "▬▬▬▬▬▬▬▬ CINETOP ▬▬▬▬▬▬▬▬▬" << endl;
    cout << "Nome: ";
    cin >> name;
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
    cout << "Welcome, " << name << "!" << endl;
    
    return name;
}

int quantity_ticket (int quantityTicket){
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
    cout << "1º) Definição da quantidade de ingressos;" << endl;
    cout << "▬ Quantos ingressos deseja comprar? R$ 12,50 CADA INGRESSO :)" << endl;
    cin >> quantityTicket;
    cout << "Ficará um total de R$"<< quantityTicket*12.50 << "." << endl;
    
    return quantityTicket;
}

int number_ticket(int sort) {
    srand(time(NULL));
    sort = 70 + rand() % 10000;

    cout << "Número do ingresso: " << sort << endl;
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;

    return sort;
}

void show_array(int array[][10]) {
    for (int i = 0; i < 7; i++) {
        for(int j = 0; j < 10; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int places[7][10] = {0};
    float adc;
    float profit;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 10; j++) {
            while (places[i][j] == 0) {
                string nameSpace;
                string name = client_name(nameSpace);

                int numBilhete, qnt_tkt;
                float price_ticket = 12.50;

                cout << "O valor da entrada é: R$" << price_ticket << ". Certo?" << endl;

                int qnt = quantity_ticket(qnt_tkt);
                int sort = number_ticket(numBilhete);

                cout << "Os lugares disponiveis são os seguintes: " << endl;

                show_array(places);

                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
                int colun, liner;
                cout << "Escolha a coluna (1 a 7): ";
                cin >> colun;
                cout << endl;
                cout << "Agora escolha a fileira (1 ao 10): ";
                cin >> liner;

                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;

                while (places[colun - 1][liner - 1] != 0) {
                    cout << "Este lugar já está ocupado, tente outro!" << endl;
                    cout << "Informe a coluna (1 a 7): ";
                    cin >> colun;
                    cout << endl;
                    cout << "Agora escolha a fileira (1 ao 10): ";
                    cin >> liner;
                }

                places[colun - 1][liner -1] = sort;

                if (qnt != 1) {
                    for (int i = 1; i < qnt; i++) {
                        cout << "Escolha seu outro lugar: " << endl;
                        cout << "Informe a coluna (1 a 7): ";
                        cin >> colun;
                        cout << endl;
                        cout << "Agora escolha a fileira (1 ao 10): ";
                        cin >> liner;

                        while (places[colun - 1][liner - 1] != 0) {
                            cout << "Este lugar já está ocupado, tente outro!" << endl;
                            cout << "Informe a coluna (1 a 7): ";
                            cin >> colun;
                            cout << endl;
                            cout << "Agora escolha a fileira (1 ao 10): ";
                            cin >> liner;
                        }

                        places[colun - 1][liner -1] = sort;
                    }
                }

                show_array(places);

                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;

                char confirm;
                float value_total = price_ticket * qnt;

                cout << "Valor final: R$" << value_total << endl;
                cout << "(Digite 'S' para confirmar ou 'N' para negar) -> ";
                cin >> confirm;

                if (confirm == 'S' || confirm == 's') {
                    cout << "Bom filme! ";
                } else if (confirm == 'N' || confirm == 'n')  {
                    cout << "Até a próxima";
                }

                cout << name << ", sua ficha é a de número: " << sort << "." << endl;
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;

                profit = price_ticket * qnt;
                adc += profit;
                cout << "Valor arrecadado pelo cinema: R$" << adc << " reais." << endl;
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
            }
        }
    }
    return 0;
}