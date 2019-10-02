#include <iostream>
#include <vector>
#include <string>

using namespace std;

int letraAPos(char caracter){
    return  int(caracter) - 65;
}


int main() {

    unsigned int spreadsheets;
    cin >> spreadsheets;

    for (unsigned int i = 0; i < spreadsheets; ++i) {
        unsigned int columnas, filas;
        vector<vector<pair<int, int>>> calculo;
        vector<pair<unsigned int, unsigned int>> celda;

        cin >> columnas >> filas;

        int** array = new int*[filas];
        for(unsigned int j = 0; j < filas; ++j)
            array[j] = new int[columnas];

        for (unsigned int filaActual = 0; filaActual < filas; ++filaActual) { //Llenarlo con Números ya Defidos
            for (unsigned int columnaActual = 0; columnaActual < columnas; ++columnaActual) {
                string temp;
                cin >> temp;
                if(temp[0] != '='){
                    array[filaActual][columnaActual] = stoi(temp);
                } else {
                    vector<pair<int,int>> celdasASumar;
                    for (unsigned long j = 1; j < temp.size()-1; j+=3){
                        celdasASumar.emplace_back(make_pair(temp[j + 1] - 49, letraAPos(temp[j])));
                    }
                    calculo.emplace_back(celdasASumar);
                    celda.emplace_back(make_pair(filaActual,columnaActual));
                    array[filaActual][columnaActual] = 0;
                }
            }
        }

        for (unsigned long k = 0 ; k < calculo.size() ; ++k) {
            int resultado = 0;
            for (auto & j : calculo[k]) {
                resultado += array[j.first][j.second];
                //cout << "Resultado de Celda F: " << j.first << " C: " << j.second << " es  -> " << resultado << endl;
            }
            //cout << "Fila -> " << celda[k].first << " Columna -> " << celda[k].second << endl;
            array[celda[k].first][celda[k].second] = resultado;
        }

        //PRINT
        for (unsigned int k = 0; k < filas; ++k) {
            for (unsigned int j = 0; j < columnas; ++j) {
                cout << array[k][j] << (j != columnas-1 ? " " : "");
            }
            cout << endl;
        }
        //cout << endl;

        for(unsigned int d = 0; d < filas; ++d) {
            delete[] array[d];
        }
        delete[] array;
        *array = nullptr;

    }

    return 0;
}