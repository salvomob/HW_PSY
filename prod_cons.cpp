#include"prod_cons.h"

char* produceItem(int len)
{
	//chiamata bloccante
	char* ret = new char[len];
	const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!£$%&/()=?^PL_:;:-.,";
	int n = sizeof(alphabet)/sizeof(char);
	srand(time(NULL));
	for(int i = 0; i< len; i++)
	{
		int x = rand()%n;
		ret[i] = alphabet[x];
	}
	return ret;
}

void printToScreen(msg_t* nmsg)
{
	std::cout << nmsg->content << std::endl;
}

char * produceEItem()
{
	std::string a = "EXPECTED";
	int s = a.length();
	char *ret = new char[s];
	for(int i = 0; i < s; i++)
	{
		ret[i] = a[i];
	}
	return ret; 
}
