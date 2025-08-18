#include <iostream>
#include <cstdlib>   //rand() y srand()
#include <ctime>     //time()
#include <cmath>     //sqrt y fab
using namespace std;

int main(int argc, char* argv[]) {
    clock_t start_cpu = clock(); 
    time_t start_wall = time(NULL);

    int N = atoi(argv[1]);

    srand(time(NULL));

    int dentro = 0; // puntos dentro del círculo

    for (int i = 0; i < N; i++) {
        // Generar coordenadas x, y entre -1 y 1 [-1, 1]
        double x = -1 + 2 * (double)rand() / RAND_MAX;
        double y = -1 + 2 * (double)rand() / RAND_MAX;

        // Verificar si está dentro del círculo de radio 1
        if (x * x + y * y <= 1.0) {
            dentro++;
        }
    }

    // Fórmula para aproximar pi
    double pi = 4.0 * dentro / N;

    cout << "Pi aproximation: " << pi << "\n";
    cout << "Error: " << abs(M_PI - pi) << endl;

    clock_t end_cpu = clock();
    time_t end_wall = time(NULL);

    double cpu_time_used = double(end_cpu - start_cpu) / CLOCKS_PER_SEC;
    double wall_time_used = difftime(end_wall, start_wall);

    cout << "CPU time:  " << cpu_time_used << " seconds\n";
    cout << "Wall time: " << wall_time_used << " seconds\n";

    return 0;
}