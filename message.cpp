#include"message.h"
#include<cstdlib>

void msg_destroy(msg_t* msg)
{
	free(msg->content);
	free(msg);
}

msg_t* msg_copy(msg_t* msg)
{
	return msg->msg_init(msg->content);
}

msg_t *msg_init(char *content)
{
	msg_t* newMsg = (msg_t*)malloc(sizeof(msg_t));
	newMsg->content = content;
	newMsg->msg_init = msg_init;
	newMsg->msg_destroy = msg_destroy;
	newMsg->msg_copy = msg_copy;
	return newMsg;
}




