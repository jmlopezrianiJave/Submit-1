#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Data
{
    int tosses;        // Número de lanzamientos por hilo
    unsigned int seed; // Semilla para rand_r (evita condiciones de carrera)
    int *cont;         // Puntero al contador local de puntos dentro del círculo
};

void *monteCarlo(void *arg)
{
    Data *data = (Data *)arg;
    int cont = 0;

    for (int i = 0; i < data->tosses; ++i)
    {
        double x = (double)rand_r(&data->seed) / RAND_MAX * 2 - 1; // [-1, 1]
        double y = (double)rand_r(&data->seed) / RAND_MAX * 2 - 1;
        if (x * x + y * y <= 1)
            cont++;
    }

    *(data->cont) = cont;
    return NULL;
}

int main(int argc, char *argv[])
{
    clock_t start_cpu = clock(); 
    time_t start_wall = time(NULL);

    int N, tosses;

    N = atoi(argv[1]);
    tosses = atoi(argv[2]);

    int Ntosses = tosses / N;
    int tot = 0;

    Data thread_data[N];
    int conts[N];

    pthread_t threads[N];
    for (int i = 0; i < N; ++i)
    {
        thread_data[i].tosses = Ntosses;
        thread_data[i].seed = time(NULL) + i; // Semilla única por hilo
        thread_data[i].cont = &conts[i];

        pthread_create(&threads[i], NULL, monteCarlo, &thread_data[i]);
    }

    for (int i = 0; i < N; ++i)
    {
        pthread_join(threads[i], NULL);
        tot += conts[i];
    }

    double ans = 4.0 * tot / tosses;
    cout << "Estimación de π: " << ans << endl
         << "Error: " << abs(M_PI - ans) << endl;

    clock_t end_cpu = clock();
    time_t end_wall = time(NULL);

    double cpu_time_used = double(end_cpu - start_cpu) / CLOCKS_PER_SEC;
    double wall_time_used = difftime(end_wall, start_wall);

    cout << "CPU time:  " << cpu_time_used << " seconds\n";
    cout << "Wall time: " << wall_time_used << " seconds\n";

    return 0;
}