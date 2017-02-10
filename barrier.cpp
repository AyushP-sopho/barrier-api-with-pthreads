/*------------------------------------------
 * Name - Ayush Prakash
 * Roll no - CS15BTECH11008
 * Date - 10/02/2017
 * Program to implement the Barrier API using 
   semaphores. 
--------------------------------------------
*/

#include "barrier.h"

using namespace std;

//Class constructor to initialise size,count, mutex and barrier. 
Barrier::Barrier(void)
{
  this->size=0;
  this->count=0;
  
  this->mutex = (sem_t*)malloc(sizeof(sem_t)); 
  this->barrier = (sem_t*)malloc(sizeof(sem_t));

}

//Class Deconstructor to destroy the semaphores. 
Barrier::~Barrier(void)
{
  sem_destroy(this->mutex); 
  sem_destroy(this->barrier);
}

/*The init function to initialise size from user input and semaphores
  returns 0 on success and -1 on failure*/
int Barrier::init(int n)
{
  this->size = n;    //Set size

  if(sem_init(this->mutex, 0, 1))   //Initialise semaphore mutex to 0.
    return -1;

  if(sem_init(this->barrier, 0, 0)) //Initialise semaphore barrier to 1.
    return -1;

  return 0;
}

/*Threads wait at the point this is called and pass when all reach here. 
  returns 0 on success and -1 on failure*/
int Barrier::barrier_point()
{
  //Increment count while avoiding race conditions
  if(sem_wait(mutex))    
    return -1;

  this->count++;

  if(sem_post(mutex))
    return -1;
  
  //If barrier has reached its limit
  if(this->count == this->size)
    {
      if(sem_post(barrier))  //Release a thread
	return -1;
    }
  
  if(sem_wait(barrier))  //Wait if limit is not reached 
    return -1;

  if(sem_post(barrier))  //Release the next thread
    return -1;

  return 0;
}
