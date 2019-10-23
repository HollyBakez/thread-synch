// sychronization.cpp 
// Copyright(c) Holland Ho 10/22/19
//libraries for thread and file input/output
#include <iostream>
#include <pthread.h>
#include <fstream>

using namespace std;

/* thread function to write */
void* WriteThreadA(void* file_arg){

    for(int i = 0; i < 26; i++){
        
    }
}

int main(){
    /* thread id */
    pthread_t tid;

    /* create attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    fstream file;
    file.open("synch.txt");
    file << "hello world";

    //pthread_create(&tid, &attr, WriteThreadA, file);

    return 0 ;
}