// sychronization.cpp 
// Copyright(c) Holland Ho 10/22/19
//libraries for thread and file input/output
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fstream>
#include <mutex>

using namespace std;



/* thread function to write */
void* WriteThreadA(void* arg){
    string *file_input = (string*) arg;
    cout << "Hello World \n";
    pthread_exit(0);
}

void* WriteThreadB(void* arg){
    string *file_input = (string*) arg;
    cout << "I love OS! \n";
    pthread_exit(0);
}
int main(){
    /* thread id */
    pthread_t tid;

    /* create attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    /* create synch.txt file */
    ofstream output_file;
    output_file.open("synch.txt");

    /* pass txt file by creating a thread and waits until the thread has done its work */
    pthread_create(&tid, &attr, WriteThreadA, &output_file);
    pthread_create(&tid, &attr, WriteThreadB, &output_file);
    pthread_join(tid, NULL);
    //pthread_create(&tid, &attr, WriteThreadB, &output_file);

    return 0 ;
}