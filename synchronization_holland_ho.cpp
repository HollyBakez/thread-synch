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
/* create mutex lock */
mutex thread_lock;

/* thread function to write 1-26 */
void* WriteThreadA(void* arg){
    fstream *file_input = (fstream*) arg;
    thread_lock.lock();

    /* writes numbers 1 - 26 20x to the file*/
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            *file_input << j+1 << " " ;
        }
        *file_input << endl;
    }
    thread_lock.unlock();
    pthread_exit(0);
}

/* thread function to write A-Z */
void* WriteThreadB(void* arg){
    /* writes the alphabets to the file */
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fstream *file_input = (fstream*) arg;
    thread_lock.lock();
    
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            *file_input << alphabet[j] << " " ;
        }
        *file_input << endl;
    }
    thread_lock.unlock();
    pthread_exit(0);
}

int main(){
    /* thread id */
    pthread_t tid1, tid2;

    /* create attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    /* create synch.txt file */
    fstream output_file;
    output_file.open("synch.txt", fstream::out | fstream::app);

    /* pass txt file by creating a thread and waits until the thread has done its work */
    /* create threadA */
    //thread_lock.lock();
    pthread_create(&tid1, &attr, WriteThreadA, &output_file);
    pthread_join(tid1, NULL);
    //thread_lock.unlock();

    /* create threadB */
    //thread_lock.lock();
    pthread_create(&tid2, &attr, WriteThreadB, &output_file);
    pthread_join(tid2, NULL);
    //thread_lock.unlock();

    output_file.close();
    return 0 ;
}