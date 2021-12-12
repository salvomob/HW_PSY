#ifndef BUFFER_H
#define BUFFER_H
#define BUFFER_ERROR (msg_t*) NULL
#include<pthread.h>
typedef struct buffer
{
	int n;
	int index_acc;
	int index_ext;
	int cont;
	pthread_mutex_t lock;// mutex per la gestione dei messaggi nel buffer
	pthread_cond_t notfull,notempty;//variabile di condizione per la gestione del buffer (relative ai thread)
	msg_t* message_arr;
	struct buffer * buffer_init(unsigned int);
	void buffer_destroy(buffer*);
	msg_t* put_bloccante(buffer*,msg*);
	msg_t* put_non_bloccante(buffer*,msg*);
	msg_t* get_bloccante(buffer*);
	msg_t* get_non_bloccante(buffer*);
}buffer_t;

std::ostream& operator<<(std::ostream& os,const buffer& b)
{
	os << "Sono presenti "<< b.cont << " elementi:" << std::endl;
	/*for(int i = 0; i < b.cont;i++)
	{
		os <<  b.message_arr[b.index_ext+i].content << std::endl;
	}*/
	for(int i = 0; i < b.n; i++)
	{
		if(&b.message_arr[i].content != NULL)
			os <<  b.message_arr[i].content << std::endl;
		else
			os << "X" << std::endl;	
	}
	return os;
}

#endif
