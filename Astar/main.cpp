#include <bits/stdc++.h>
using namespace std;

typedef pair<int,float> Parint;
typedef vector<pair<Parint, string>> pstr;
typedef pair<Parint, string> pstrfront;

// Cria o grafo do mapa do metrô
vector<pstr> subway() {
    vector<pstr> realStations(15);
    // Conexões Azuis
    realStations[1].push_back({{2, 10.0}, "Azul"});
    realStations[2].push_back({{1, 10.0}, "Azul"});

    realStations[2].push_back({{3, 8.5}, "Azul"});
    realStations[3].push_back({{2, 8.5}, "Azul"});

    realStations[3].push_back({{4, 6.3}, "Azul"});
    realStations[4].push_back({{3, 6.3}, "Azul"});

    realStations[4].push_back({{5, 13.0}, "Azul"});
    realStations[5].push_back({{4, 13.0}, "Azul"});

    realStations[5].push_back({{6, 3.0}, "Azul"});
    realStations[6].push_back({{5, 3.0}, "Azul"});

    // Conexões Amarelas
    realStations[2].push_back({{9, 10.0}, "Amarela"});
    realStations[9].push_back({{2, 10.0}, "Amarela"});

    realStations[2].push_back({{10, 3.5}, "Amarela"});
    realStations[10].push_back({{2, 3.5}, "Amarela"});

    realStations[5].push_back({{7, 2.4}, "Amarela"});
    realStations[7].push_back({{5, 2.4}, "Amarela"});

    realStations[5].push_back({{8, 30.0}, "Amarela"});
    realStations[8].push_back({{5, 30.0}, "Amarela"});

    realStations[8].push_back({{9, 9.6}, "Amarela"});
    realStations[9].push_back({{8, 9.6}, "Amarela"});

    // Conexões Verdes
    realStations[4].push_back({{8, 15.4}, "Verde"});
    realStations[8].push_back({{4, 15.4}, "Verde"});

    realStations[4].push_back({{13, 12.8}, "Verde"});
    realStations[13].push_back({{4, 12.8}, "Verde"});

    realStations[8].push_back({{12, 6.4}, "Verde"});
    realStations[12].push_back({{8, 6.4}, "Verde"});

    realStations[13].push_back({{14, 5.1}, "Verde"});
    realStations[14].push_back({{13, 5.1}, "Verde"});

    // Conexões Vermelhas
    realStations[3].push_back({{9, 9.4}, "Vermelha"});
    realStations[9].push_back({{3, 9.4}, "Vermelha"});

    realStations[9].push_back({{11, 12.2}, "Vermelha"});
    realStations[11].push_back({{9, 12.2}, "Vermelha"});

    realStations[3].push_back({{13, 18.7}, "Vermelha"});
    realStations[13].push_back({{3, 18.7}, "Vermelha"});

    return realStations;
}



// Criar lista de adj com distâncias diretas entre as estações -> só vai pra frente
vector<vector<Parint>> strDist()
{
    vector<vector<Parint>> stations(15); // Definido um tamanho maior para ficar com número das estações

    stations[1].push_back({2, 10.0}); stations[2].push_back({1, 10.0});
    stations[1].push_back({3, 18.5}); stations[3].push_back({1, 18.5});
    stations[1].push_back({4, 24.8}); stations[4].push_back({1, 24.8});
    stations[1].push_back({5, 36.4}); stations[5].push_back({1, 36.4});
    stations[1].push_back({6, 38.8}); stations[6].push_back({1, 38.8});
    stations[1].push_back({7, 35.8}); stations[7].push_back({1, 35.8});
    stations[1].push_back({8, 25.4}); stations[8].push_back({1, 25.4});
    stations[1].push_back({9, 17.6}); stations[9].push_back({1, 17.6});
    stations[1].push_back({10, 9.1}); stations[10].push_back({1, 9.1});
    stations[1].push_back({11, 16.7}); stations[11].push_back({1, 16.7});
    stations[1].push_back({12, 27.3}); stations[12].push_back({1, 27.3});
    stations[1].push_back({13, 27.6}); stations[13].push_back({1, 27.6});
    stations[1].push_back({14, 29.8}); stations[14].push_back({1, 29.8});

    // Adicionando as distâncias para as estações E2
    stations[2].push_back({3, 8.5}); stations[3].push_back({2, 8.5});
    stations[2].push_back({4, 14.8}); stations[4].push_back({2, 14.8});
    stations[2].push_back({5, 26.6}); stations[5].push_back({2, 26.6});
    stations[2].push_back({6, 29.1}); stations[6].push_back({2, 29.1});
    stations[2].push_back({7, 26.1}); stations[7].push_back({2, 26.1});
    stations[2].push_back({8, 17.3}); stations[8].push_back({2, 17.3});
    stations[2].push_back({9, 10.0}); stations[9].push_back({2, 10.0});
    stations[2].push_back({10, 3.5}); stations[10].push_back({2, 3.5});
    stations[2].push_back({11, 15.5}); stations[11].push_back({2, 15.5});
    stations[2].push_back({12, 20.9}); stations[12].push_back({2, 20.9});
    stations[2].push_back({13, 19.1}); stations[13].push_back({2, 19.1});
    stations[2].push_back({14, 21.8}); stations[14].push_back({2, 21.8});

    // Adicionando as distâncias para as estações E3
    stations[3].push_back({4, 6.3}); stations[4].push_back({3, 6.3});
    stations[3].push_back({5, 18.2}); stations[5].push_back({3, 18.2});
    stations[3].push_back({6, 20.6}); stations[6].push_back({3, 20.6});
    stations[3].push_back({7, 17.6}); stations[7].push_back({3, 17.6});
    stations[3].push_back({8, 13.6}); stations[8].push_back({3, 13.6});
    stations[3].push_back({9, 9.4}); stations[9].push_back({3, 9.4});
    stations[3].push_back({10, 10.3}); stations[10].push_back({3, 10.3});
    stations[3].push_back({11, 19.5}); stations[11].push_back({3, 19.5});
    stations[3].push_back({12, 19.1}); stations[12].push_back({3, 19.1});
    stations[3].push_back({13, 12.1}); stations[13].push_back({3, 12.1});
    stations[3].push_back({14, 16.6}); stations[14].push_back({3, 16.6});

    // Adicionando as distâncias para as estações E4
    stations[4].push_back({5, 12.0}); stations[5].push_back({4, 12.0});
    stations[4].push_back({6, 14.4}); stations[6].push_back({4, 14.4});
    stations[4].push_back({7, 11.5}); stations[7].push_back({4, 11.5});
    stations[4].push_back({8, 12.4}); stations[8].push_back({4, 12.4});
    stations[4].push_back({9, 12.6}); stations[9].push_back({4, 12.6});
    stations[4].push_back({10, 16.7}); stations[10].push_back({4, 16.7});
    stations[4].push_back({11, 23.6}); stations[11].push_back({4, 23.6});
    stations[4].push_back({12, 18.6}); stations[12].push_back({4, 18.6});
    stations[4].push_back({13, 10.6}); stations[13].push_back({4, 10.6});
    stations[4].push_back({14, 15.4}); stations[14].push_back({4, 15.4});

    // Adicionando as distâncias para as estações E5
    stations[5].push_back({6, 3.0}); stations[6].push_back({5, 3.0});
    stations[5].push_back({7, 2.4}); stations[7].push_back({5, 2.4});
    stations[5].push_back({8, 19.4}); stations[8].push_back({5, 19.4});
    stations[5].push_back({9, 23.3}); stations[9].push_back({5, 23.3});
    stations[5].push_back({10, 28.2}); stations[10].push_back({5, 28.2});
    stations[5].push_back({11, 34.2}); stations[11].push_back({5, 34.2});
    stations[5].push_back({12, 24.8}); stations[12].push_back({5, 24.8});
    stations[5].push_back({13, 14.5}); stations[13].push_back({5, 14.5});
    stations[5].push_back({14, 17.9}); stations[14].push_back({5, 17.9});

    // Adicionando as distâncias para as estações E6
    stations[6].push_back({7, 3.3}); stations[7].push_back({6, 3.3});
    stations[6].push_back({8, 22.3}); stations[8].push_back({6, 22.3});
    stations[6].push_back({9, 25.7}); stations[9].push_back({6, 25.7});
    stations[6].push_back({10, 30.3}); stations[10].push_back({6, 30.3});
    stations[6].push_back({11, 36.7}); stations[11].push_back({6, 36.7});
    stations[6].push_back({12, 27.6}); stations[12].push_back({6, 27.6});
    stations[6].push_back({13, 15.2}); stations[13].push_back({6, 15.2});
    stations[6].push_back({14, 18.2}); stations[14].push_back({6, 18.2});

    // Adicionando as distâncias para as estações E7
    stations[7].push_back({8, 20.0}); stations[8].push_back({7, 20.0});
    stations[7].push_back({9, 23.0}); stations[9].push_back({7, 23.0});
    stations[7].push_back({10, 27.3}); stations[10].push_back({7, 27.3});
    stations[7].push_back({11, 34.2}); stations[11].push_back({7, 34.2});
    stations[7].push_back({12, 25.7}); stations[12].push_back({7, 25.7});
    stations[7].push_back({13, 12.4}); stations[13].push_back({7, 12.4});
    stations[7].push_back({14, 15.6}); stations[14].push_back({7, 15.6});

    // Adicionando as distâncias para as estações E8
    stations[8].push_back({9, 8.2}); stations[9].push_back({8, 8.2});
    stations[8].push_back({10, 20.3}); stations[10].push_back({8, 20.3});
    stations[8].push_back({11, 16.1}); stations[11].push_back({8, 16.1});
    stations[8].push_back({12, 6.4}); stations[12].push_back({8, 6.4});
    stations[8].push_back({13, 22.7}); stations[13].push_back({8, 22.7});
    stations[8].push_back({14, 27.6}); stations[14].push_back({8, 27.6});

    // Adicionando as distâncias para as estações E9
    stations[9].push_back({10, 13.5}); stations[10].push_back({9, 13.5});
    stations[9].push_back({11, 11.2}); stations[11].push_back({9, 11.2});
    stations[9].push_back({12, 10.9}); stations[12].push_back({9, 10.9});
    stations[9].push_back({13, 21.2}); stations[13].push_back({9, 21.2});
    stations[9].push_back({14, 26.6}); stations[14].push_back({9, 26.6});

    // Adicionando as distâncias para as estações E10
    stations[10].push_back({11, 17.6}); stations[11].push_back({10, 17.6});
    stations[10].push_back({12, 24.2}); stations[12].push_back({10, 24.2});
    stations[10].push_back({13, 18.7}); stations[13].push_back({10, 18.7});
    stations[10].push_back({14, 21.2}); stations[14].push_back({10, 21.2});

    // Adicionando as distâncias para as estações E11
    stations[11].push_back({12, 14.2}); stations[12].push_back({11, 14.2});
    stations[11].push_back({13, 31.5}); stations[13].push_back({11, 31.5});
    stations[11].push_back({14, 35.5}); stations[14].push_back({11, 35.5});

    // Adicionando as distâncias para as estações E12
    stations[12].push_back({13, 28.8}); stations[13].push_back({12, 28.8});
    stations[12].push_back({14, 33.6}); stations[14].push_back({12, 33.6});

    // Adicionando as distâncias para as estações E13
    stations[13].push_back({14, 5.1}); stations[14].push_back({13, 5.1});

    // g[1][0].second; //g[1] acessa o segundo elemento (estação 1) do vector grande. g[1][0] acessa o primeiro vizinho da estação 1.
    // g[1][0].second acessa a distancia entre a estação 1 e seu primeiro vizinho

    // priority queue: escolher qual o próximo vertice a ser visitado?
    return stations;
}


float calc_dist_metro(vector<pstr> realStations, int start, int nextDest) {
    float distancia = 0.0;
    for (auto it = realStations[start].begin(); it != realStations[start].end(); it++) {
        if (it->first.first == nextDest) {
            distancia = it->first.second;
            break;
        }
    }
    return distancia;
}

float calc_dist_ret(vector<vector<Parint>> stations, int origin, int dest) {
    float distancia = 0.0;
    for (long unsigned int i = 0; i < stations[origin].size(); i++) {
        if (stations[origin][i].first == dest) {
            distancia = stations[origin][i].second;
            break;
        }
    }
    return distancia;
}

float heuristic(vector<pstr> subway, vector<vector<Parint>> stations, int origin,int nextDest, int dest){
    float g_dist = calc_dist_metro(subway,origin,nextDest);
    float g_tempo = g_dist * 2;
    float h_dist = calc_dist_ret(stations, nextDest, dest);
    float h_tempo = h_dist * 2;
    return g_tempo + h_tempo;
}

float realTime(vector<pstr> subway,int origin,int nextDest){
    float g_dist = calc_dist_metro(subway,origin,nextDest);
    float g_tempo = g_dist * 2;
    return g_tempo;
}

void astar(vector<pstrfront> frontier, vector<pstr> realStations, vector<vector<Parint>> stations, int startPoint, int origin, int dest, vector<int> path, float realtime){
    // imprime a fronteira
    int lastPoint = origin;
    cout << "Fronteira: ";
    for (auto it = frontier.begin(); it != frontier.end(); it++) {
        cout << "[" << it->first.first << "," << it->first.second << "]";
        if (it != frontier.end() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    if (frontier[0].first.first == dest) {
        cout << endl << "Chegou no destino!" << endl;
        path.push_back(dest);
        //Imprime o caminho
        cout << "Melhor caminho até a estação: ";
        for (auto it = path.begin(); it != path.end(); it++) {
            cout << *it;
            if (it != path.end() - 1) {
                cout << " -> ";
            }
        }
        cout << endl << "Tempo total: " << realtime << " minutos" << endl;
        return;
    }

    // Pega o primeiro da fronteira
    int nextDest = 0;
    int stationStart = frontier[0].first.first;
    long unsigned int sizeFrontier = frontier.size();

    for (auto it = realStations[stationStart].begin(); it != realStations[stationStart].end(); it++) {
        nextDest = it->first.first;
        float newHeuristic = heuristic(realStations, stations, stationStart, nextDest, dest);
        // Adiciona tempo de baldeação se houver
        if (it->second != frontier[0].second) {
            newHeuristic += 4;
        }
        // Verifica se já não está na fronteira, se estiver não adiciona
        int achou = 0;
        for (auto it2 = frontier.begin(); it2 != frontier.end(); it2++) {
            if (it2->first.first == nextDest) {
                ++achou;
                if (it2->first.second > newHeuristic) {
                    it2->first.second = newHeuristic;
                }
                break;
            }
        }
        if (!achou && nextDest != lastPoint && nextDest != startPoint) {
            frontier.push_back({{nextDest, newHeuristic}, it->second});
        }
    }
    lastPoint = frontier[0].first.first;
    string tempColor = frontier[0].second;
    // Remove o nó visitado
    frontier.erase(frontier.begin());

    // Adiciona o nó no caminho
    if (frontier.size()>=sizeFrontier){
        path.push_back(lastPoint);
    }
    // ordena a fronteira de acordo com a heurística
    sort(frontier.begin(), frontier.end(), [](const pstrfront& a, const pstrfront& b) {
        return a.first.second < b.first.second;
    });

    realtime += realTime(realStations, lastPoint, frontier[0].first.first);
    if (tempColor != frontier[0].second) {
        realtime += 4;
    }
    // Chama recursão para próximo elemento da fronteira
    astar(frontier, realStations, stations, startPoint, lastPoint, dest, path, realtime);
    return;
}

int main() {
    vector<int> path;
    vector<pstrfront> frontier;
    vector<pstr> realStations = subway();
    vector<vector<Parint>> stations = strDist();
    //cout << heuristic(realStations, stations, 4, 5, 7) << endl;

    // Recebe de input os valors de entrada origin dest e color
    int origin, dest;
    float realtime = 0.0;
    string color;

    cout << "Digite o número da estação de origem (1 a 14): ";
    cin >> origin;
    cout << "Digite a cor da linha de origem (Azul, Amarela, Verde ou Vermelha): ";
    cin >> color;
    // Pede a cor até receber uma válida
    while (color != "Azul" && color != "Amarela" && color != "Verde" && color != "Vermelha") {
        cout << "Cor inválida! Digite a cor da linha de origem (Azul, Amarela, Verde ou Vermelha): ";
        cin >> color;
    }
    cout << "Digite o número da estação de destino (1 a 14): ";
    cin >> dest;

    // origin = 1;
    // dest = 13;
    // color = "Azul";

    // Calcula primeira fronteira
    frontier.push_back({{ origin, 0 }, color});
    astar(frontier, realStations, stations, origin, origin, dest, path, realtime);
    return 0;
}