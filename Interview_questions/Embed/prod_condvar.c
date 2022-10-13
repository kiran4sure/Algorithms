#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// [FRS 1.0]
#define BUFF_LEN 64
#define DATA_LIMIT 50

typedef enum { FALSE = 0, TRUE = 1 } Boolean;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t Buffer_empty = PTHREAD_COND_INITIALIZER;

// [FRS 1.0]
static char SHARED_BUFF[BUFF_LEN] = {'0'};
static int Data_start = 0;
static int Data_end = 0;

// Some buffer content for random characters
static const char Data_base[] = "Increasingly, embedded systems developers and system-on-chip designers select specific microprocessor cores and a family of tools, libraries, and off-the-shelf components to quickly develop new microprocessor-based products. A major player in this industry is ARM. Over the last 10 years, the ARM architecture has become the most pervasive 32-bit architecture in the world, with more than 2 billion ARM-based processors shipped at the time of this writing. ARM processors are embedded in products ranging from cell/mobile phones to automotive braking systems. A worldwide community of ARM partners and third-party vendors has developed among semiconductor and product design companies, including hardware engineers, system designers, and software developers. To date, no book has directly addressed their need to develop the system and software for an ARM-based embedded design. This text fills that gap.";
static int Data_base_index = 0;

static Boolean Done = FALSE;
static int Reader_count = 0;

/**
 * @brief 
 * 
 *
 * Reader_thread - [FRS 3.0] 
 * Reads random number of bytes from the avaliable data in 
 * shared buffer and prints it to the console.
 * 
 * @param  void* arg - Thread arguments
 * @return void*     - Exit Status
 */
static void* Reader_thread(void* arg)
{
    while(!Done)
    {
        pthread_mutex_lock(&mtx);
        // random length to be read
        int random_len = rand() % DATA_LIMIT;

        // calculate the avaliable space in the circular buffer
        int available_data_length = (Data_end >= Data_start)? Data_end - Data_start : BUFF_LEN - abs(Data_end - Data_start);

        // random length cannot be more than the avaliable data length
        random_len = (random_len > available_data_length)? available_data_length : random_len;        

        while(random_len)
        {
            printf("%c",SHARED_BUFF[Data_start]);
            // adjust index for circular shared buffer
            Data_start  = (Data_start + 1) % BUFF_LEN;
            random_len--;

            // un-comment for testing, limiting data to 2 full chucks
            // Reader_count++; 
            // if(Reader_count == 2*sizeof(Data_base))
            // {
            //     Done = TRUE;
            //     break;
            // }
        }

        pthread_mutex_unlock(&mtx);
        // Wake sleeping consumer
        pthread_cond_signal(&Buffer_empty);
    }

    return NULL;
}

/**
 * @brief 
 * 
 * Writer_Thread - [FRS 2.0]
 * Generates random bytes of data and writes it to shared buffer.
 * If avaliable buffer space is less, it waits until enough space is avaliable
 * and appends the remaning data without dropping.
 * 
 * @param  void* arg - Thread arguments
 * @return void*     - Exit Status
 */
static void* Writer_Thread(void* arg)
{
    while(!Done)
    {
        pthread_mutex_lock(&mtx);
        int data_len = rand() % DATA_LIMIT;

        while(data_len > 0)
        {
            // pend until empty space is avaliable/
            pthread_cond_wait(&Buffer_empty, &mtx);

            while(((Data_end+1) % BUFF_LEN != Data_start) && data_len--) 
            {
                SHARED_BUFF[Data_end] = Data_base[Data_base_index];
                // adjust index for circular shared buffer
                Data_end = (Data_end + 1) % BUFF_LEN;
                Data_base_index = (Data_base_index + 1) % sizeof(Data_base);
            }
        }
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

/**
 * @brief 
 * main - [FRS  1.0]
 * Creates and launches Reader and Writer threads,
 * which share 64 byte data buffer
 * 
 * @param void
 * @return int - Exit Status
 */
int main(void)
{
    pthread_t w_tid;
    pthread_t r_tid;
    int ret, j;
  
    // launch Writer thread thread
    ret = pthread_create(&w_tid, NULL, Writer_Thread, NULL);
	if (ret != 0)
    {
        perror("pthread_create:      ");
    }

   // launch Reader thread 
    ret = pthread_create(&r_tid, NULL, Reader_thread, NULL);
	if (ret != 0)
    {
        perror("pthread_create:      ");
    }

    pthread_join(r_tid, NULL);
    pthread_join(w_tid, NULL);
	
    pthread_exit(NULL);
    exit(EXIT_SUCCESS);
}
