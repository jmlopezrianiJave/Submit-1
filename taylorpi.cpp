#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

typedef struct{
    int start;
    int end;
    double partial_result;
} Task;

void* taylor_pi(void* arg){
    Task* t = (Task*)arg;
    double local = 0.0;

    for(int i = t->start; i < t->end; ++i){
        double term = (i % 2 ==0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
        local += term;
    }
    t->partial_result = local;
    return nullptr;
}

int main(){
    int N;
    cin >> N;

    int nthreads = 4;

    pthread_t threads[nthreads];
    Task tasks[nthreads];

    int seccion = N / nthreads;

    for(int i = 0; i < nthreads; i++){
        tasks[i].start = i * seccion;
        tasks[i].end = (i == nthreads - 1) ? N : (i + 1) * seccion;
        pthread_create(&threads[i], nullptr, taylor_pi, &tasks[i]);
    }

    double result = 0.0;
    for(int i = 0; i < nthreads; i++){
        pthread_join(threads[i], nullptr);
        result += tasks[i].partial_result;
    }

    double estimate = 4.0 * result;
    cout << "Pi = " << estimate << endl;

    return 0;
}