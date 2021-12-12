#include"buffer.h"
#include <pthread.h>
//inizializzazione del buffer

buffer_t* buffer_init(unsigned int maxsize)
{
	buffer_t* newBuf = (buffer_t*) malloc(sizeof(buffer_t));
	pthread_mutex_init(&newBuf->lock,NULL);//inizializzazione mutex
	//inizializzazione condizione relative ai thread
	pthread_cond_init(&newBuf->notfull,NULL);
	pthread_cond_init(&newBuf->notempty,NULL);
	newBuf->index_acc = 0;
	newBuf->cont = 0;
	newBuf->n = maxsize;
	newBuf->index_ext = 0;
	newBuf->message_arr = new msg_t[maxsize];
	return newBuf;
}

//distruzione (deallocazione) buffer

void buffer_destroy(buffer_t* buffer)
{
	/*
	for(int i = 0; i < buffer->n ; i++)
		delete[] &buffer->message_arr[i];
	*/
	free(buffer->message_arr);
	free(buffer);
}

msg_t* put_bloccante(buffer_t* buffer,msg_t* msg)
{
	if(!msg) return BUFFER_ERROR;
	pthread_mutex_lock(&buffer->lock); //mutex bloccato
	while(buffer->cont == buffer->n)
	//blocca i produttori
		pthread_cond_wait(&buffer->notfull,&buffer->lock);
	//aspetto finchè il buffer non si libera
	//una volta libero, inserisco il messaggio e aggiorno l'indice
	if(buffer->n == 1)
	{
		buffer->index_acc = buffer->index_ext = 0;
		buffer->message_arr[buffer->index_acc] = *msg;
		pthread_cond_signal(&buffer->notempty); 
		pthread_mutex_unlock(&buffer->lock);
		buffer->cont = 1;
//	std::cout << pthread_mutex_trylock(&buffer->lock) << std::endl;
		return msg;
	}
	buffer->message_arr[buffer->index_acc] = *msg;
	buffer->index_acc = buffer->index_acc + 1;
	
		
	if(buffer->index_acc > buffer->n) 
		buffer->index_acc = 0;	
	buffer->cont++;
	
	// risveglia eventuali consumatori sospesi
	
	pthread_cond_signal(&buffer->notempty); 
	pthread_mutex_unlock(&buffer->lock);
//	std::cout << pthread_mutex_trylock(&buffer->lock) << std::endl;
	return msg;		
}

msg_t* put_non_bloccante(buffer_t* buffer,msg_t* msg)
{
	if(!msg) return BUFFER_ERROR;
	pthread_mutex_lock(&buffer->lock); //mutex bloccato
	if(buffer->cont == buffer->n)
	{
		pthread_mutex_unlock(&buffer->lock);
		return BUFFER_ERROR;

	}
	if(buffer->n == 1)
	{
		buffer->index_acc = buffer->index_ext = 0;
		buffer->message_arr[buffer->index_acc] = *msg;
		pthread_cond_signal(&buffer->notempty); 
		pthread_mutex_unlock(&buffer->lock);
		buffer->cont = 1;
//	std::cout << pthread_mutex_trylock(&buffer->lock) << std::endl;
		return msg;
	}
	buffer->message_arr[buffer->index_acc] = *msg;
	buffer->index_acc = buffer->index_acc + 1;
	if(buffer->index_acc > buffer->n)
		buffer->index_acc = 0;	
	buffer->cont++;
	pthread_cond_signal(&buffer->notempty);
	pthread_mutex_unlock(&buffer->lock);
	return msg;	
 		
}

msg_t* get_bloccante(buffer_t* buffer)
{
	
	pthread_mutex_lock(&buffer->lock); //mutex bloccato	
	while(buffer->cont == 0)
		pthread_cond_wait(&buffer->notempty,&buffer->lock);
	//msg_t*newMsg = msg_copy(&buffer->message_arr[buffer->index_ext]);
	if(buffer->n == 1)
	{
		msg_t * msgr = &buffer->message_arr[buffer->index_ext];
		buffer->cont = buffer->cont - 1;
		pthread_cond_signal(&buffer->notfull);
		pthread_mutex_unlock(&buffer->lock);
		buffer->index_ext = buffer->index_acc = 0;
		return msgr;
	}
	else
	{
		msg_t * msgr = &buffer->message_arr[buffer->index_ext];
		buffer->index_ext = buffer->index_ext + 1;
		if(buffer->index_ext > buffer->n) buffer->index_ext = 0;
		buffer->cont = buffer->cont - 1;
		//msg_destroy(&buffer->message_arr[buffer->index_ext]);
		pthread_cond_signal(&buffer->notfull);
		pthread_mutex_unlock(&buffer->lock);
		//return newMsg;
		return msgr;
	}
}

msg_t* get_non_bloccante(buffer_t* buffer)
{
	pthread_mutex_lock(&buffer->lock); //mutex bloccato	
	if(buffer->cont == 0)
	{
		pthread_mutex_unlock(&buffer->lock);
		return BUFFER_ERROR;

	}	
	if(buffer->n == 1)
	{
		msg_t * msgr = &buffer->message_arr[buffer->index_ext];
		buffer->cont = buffer->cont - 1;
		pthread_cond_signal(&buffer->notfull);
		pthread_mutex_unlock(&buffer->lock);
		buffer->index_ext = buffer->index_acc = 0;
		return msgr;
	}
	else
	{
		//msg_t* newMsg = &buffer->message_arr[buffer->index_ext];
		msg_t * msgr = &buffer->message_arr[buffer->index_ext];
		buffer->index_ext = buffer->index_ext + 1;
		if(buffer->index_ext > buffer->n) buffer->index_ext = 0;
		buffer->cont = buffer->cont - 1;
		//msg_destroy(&buffer->message_arr[buffer->index_ext]);
		pthread_cond_signal(&buffer->notfull);
		pthread_mutex_unlock(&buffer->lock);
		return msgr;
	}	
}
