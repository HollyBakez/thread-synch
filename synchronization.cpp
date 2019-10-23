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



/* thread function to write 1-26 */
void* WriteThreadA(void* arg){
    fstream *file_input = (fstream*) arg;
    int counter = 0;
    /* writes numbers 1 - 26 20x to the file*/
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            *file_input << j+1 << " " ;
        }
        *file_input << endl;
    }
    pthread_exit(0);
}

/* thread function to write A-Z */
void* WriteThreadB(void* arg){
    //vector<char> letter; 

    fstream *file_input = (fstream*) arg;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            *file_input << j+1 << " " ;
        }
        *file_input << endl;
    }
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
    output_file.open("synch.txt");
    /* pass txt file by creating a thread and waits until the thread has done its work */
    pthread_create(&tid1, &attr, WriteThreadA, &output_file);
    pthread_join(tid1, NULL);

    pthread_create(&tid2, &attr, WriteThreadB, &output_file);
    pthread_join(tid2, NULL);


    return 0 ;
}