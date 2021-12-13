#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include<iostream>
#include<fstream>
#include<unistd.h>
#include<pthread.h>
#include<string>
#include<semaphore.h>
#include<time.h>
#include<cstdlib>
#include<sys/wait.h>
#include<sys/types.h>
#include "message.cpp"
#include"buffer.cpp"
#include"prod_cons.cpp"
#define MAXSIZE 1
#define BUFFER_ERROR (msg_t*) NULL
#define EXPECTED_MSG (char*) "EXPECTED MSG"

using namespace std;

ofstream outfile("log.txt");
buffer_t *buffer;
msg_t *ret;
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);
void test13(void);
void test14(void);
void test15(void);
void test16(void);
void test17(void);
void test18(void);
void test19(void);
void test20(void);
void test21(void);
void test22(void);
void test23(void);
void test24(void);
void test25(void);
int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void log_it(std::ostream& out,int i,int j)
{
	out <<"\n\n\n\n";
	out << "TEST #" << i << " LOG #"<< j <<  "\nBUFFER COSI' COMPOSTO : \n";
	out << "CONT : " << buffer->cont << endl;
	out << "N : " << buffer->n << endl;
	out << "IDX ACC : " << buffer->index_acc << endl;
	out << "IDX EXT : " << buffer->index_ext << endl;
	out << "BUFFER :\n";
	for(int i = 0; i < buffer->cont; i++)
	{
		out << buffer->message_arr[buffer->index_ext+i].content << endl;
	}
	out << "\n\n\n\n";
}

void * producer(void* arg)
{
	msg_t* nm = msg_init(produceItem(10));
	return put_non_bloccante(buffer,nm);
	pthread_exit(NULL);
	//return NULL;
}

void *consumer(void* arg)
{	
	return get_non_bloccante(buffer);
	pthread_exit(NULL);
	//return NULL;
}


void *producerb(void* arg)
{
	msg_t* nm = msg_init(produceItem(10));
	return put_bloccante(buffer,nm);
	//return NULL;
}

void *consumerb(void* arg)
{	
	return get_bloccante(buffer);
	//return NULL;
}



int main(int argc , char** argv)
{
	

	ofstream outfile("log.txt");
	outfile << "EXPECTED_MSG : " << EXPECTED_MSG  << endl;
	
	//initializzazione registro CUnit
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	//add suite
	pSuite = CU_add_suite("SUITE1",init_suite,clean_suite);
	if(!pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 1",test1))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 2",test2))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 3",test3))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 4",test4))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 5",test5))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 6",test6))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 7",test7))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 8",test8))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 9",test9))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 10",test10))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 11",test11))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 12",test12))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 13",test13))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 14",test14))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 15",test15))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 16",test16))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 17",test17))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 18",test18))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 19",test19))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 20",test20))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 21",test21))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 22",test22))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 23",test23))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 24",test24))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(!CU_add_test(pSuite,"test 25",test25))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	//cout << "ERROR CODE:" << CU_get_error() << endl;

	
	/*pthread_t a;
	pthread_create(&a,NULL,produttore,NULL);
	pthread_join(a,NULL);*/
	//return 0;

	outfile.close();	
		return CU_get_error();
}

void test1(void)
{
	
	//PRODUZIONE NON BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER VUOTO

	//setup

	buffer = buffer_init(10);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[0].content);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	log_it(outfile,1,1);
	buffer_destroy(buffer);
}


void test2(void)
{

		//PRODUZIONE BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER VUOTO

	//setup

	buffer = buffer_init(10);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[0].content);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	
	log_it(outfile,2,1);
	buffer_destroy(buffer);
}


void test3(void)
{

	//PRODUZIONE NON BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER PIENO

	//setup

	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	put_non_bloccante(buffer,expected);
	/*pthread_t a ;
	pthread_create(&a,NULL,producer,NULL);
	pthread_join(a,NULL);*/
	
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	CU_ASSERT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	
	log_it(outfile,3,1);
	buffer_destroy(buffer);
}



void test4(void)
{

	//PRODUZIONE BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER PIENO

	//setup

	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	put_non_bloccante(buffer,expected);
	log_it(outfile,4,1);
	
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	pthread_t a ;
	pthread_create(&a,NULL,producerb,NULL);
	log_it(outfile,4,2);
	//CU_ASSERT_EQUAL(1,(int)buffer->lock));
	CU_ASSERT_EQUAL(EXPECTED_MSG,get_bloccante(buffer)->content);
	pthread_join(a,NULL);
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[0].content);
	CU_ASSERT_NOT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);

	log_it(outfile,4,3);
	buffer_destroy(buffer);
}

void test5(void)
{

	//CONSUMAZIONE NON BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER PIENO
	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	put_non_bloccante(buffer,expected);
	log_it(outfile,5,1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_EQUAL(EXPECTED_MSG,get_non_bloccante(buffer)->content);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,5,2);
	buffer_destroy(buffer);
}

void test6(void)
{

	//CONSUMAZIONE NON BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER PIENO
	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	put_bloccante(buffer,expected);
	log_it(outfile,6,1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	CU_ASSERT_EQUAL(EXPECTED_MSG,get_bloccante(buffer)->content);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,6,2);
	buffer_destroy(buffer);
}

void test7(void)
{

	//CONSUMAZIONE NON BLOCCANTE DI UN SOLO MESSAGGIO IN UN BUFFER PIENO
	buffer = buffer_init(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	CU_ASSERT_EQUAL(BUFFER_ERROR,get_non_bloccante(buffer));
	log_it(outfile,7,1);
	buffer_destroy(buffer);
}

void test8(void)
{

	buffer = buffer_init(1);
	pthread_t a;
	pthread_create(&a,NULL,consumerb,NULL);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,8,1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	put_bloccante(buffer,expected);
	sleep(1);
	log_it(outfile,8,2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	pthread_join(a,NULL);
	log_it(outfile,8,3);
	buffer_destroy(buffer);
}

void test9(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,producerb,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,9,1);
	pthread_create(&a,NULL,consumerb,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,9,2);
	buffer_destroy(buffer);
}

void test10(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,producer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,10,1);
	pthread_create(&a,NULL,consumerb,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,10,2);
	buffer_destroy(buffer);
}

void test11(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,producerb,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,11,1);
	pthread_create(&a,NULL,consumer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,11,2);
	buffer_destroy(buffer);
}

void test12(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,producer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,12,1);
	pthread_create(&a,NULL,consumer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,12,2);
	buffer_destroy(buffer);
}

void test13(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,consumerb,NULL);
	sleep(2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,13,1);
	pthread_create(&a,NULL,producerb,NULL);
	log_it(outfile,13,2);
	sleep(2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,13,3);
	buffer_destroy(buffer);

}


void test14(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,consumer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,14,1);
	pthread_create(&a,NULL,producerb,NULL);
	log_it(outfile,14,2);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,14,3);
	buffer_destroy(buffer);
}

void test15(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,consumerb,NULL);
	sleep(2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,15,1);
	pthread_create(&a,NULL,producer,NULL);
	log_it(outfile,15,2);
	sleep(2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,15,3);
	buffer_destroy(buffer);
}

void test16(void)
{
	buffer = buffer_init(1);
	pthread_t a,b;
	pthread_create(&a,NULL,consumer,NULL);
	sleep(1);
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,16,1);
	pthread_create(&a,NULL,producer,NULL);
	log_it(outfile,16,2);
	sleep(1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,16,3);
	buffer_destroy(buffer);
}

void test17(void)
{
	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	pthread_t a;
	pthread_create(&a,NULL,producer,NULL);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	log_it(outfile,17,1);
	pthread_t b;
	pthread_create(&b,NULL,producerb,NULL);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);	
	log_it(outfile,17,2);
	buffer_destroy(buffer);
}

void test18(void)
{
	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,18,1);
	pthread_t a;
	pthread_create(&a,NULL,consumerb,NULL);
	sleep(1);
	log_it(outfile,18,2);
	CU_ASSERT_EQUAL(0,buffer->cont);
	pthread_t b;
	pthread_create(&b,NULL,consumer,NULL);
	log_it(outfile,18,3);	
	CU_ASSERT_EQUAL(0,buffer->cont);
	pthread_t c;
	pthread_create(&c,NULL,consumerb,NULL);
	log_it(outfile,18,4);
	CU_ASSERT_EQUAL(0,buffer->cont);
	buffer_destroy(buffer);
}

void test19(void)
{
	buffer = buffer_init(10);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	sleep(1);
	log_it(outfile,19,1);
	int num = 6;
	sleep(1);
	for(int i = 0; i < num ; i++)
	{
		if(i%2==0)
		{
			pthread_t a;
			pthread_create(&a,NULL,producer,NULL);
			pthread_join(a,NULL);
		}
		else
		{
			pthread_t a;
			pthread_create(&a,NULL,producer,NULL);
			pthread_join(a,NULL);	
		}
		sleep(1);
		log_it(outfile,19,i+2);	
		
	}
	sleep(2);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	CU_ASSERT_EQUAL(7,buffer->cont);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[num].content);
	CU_ASSERT_EQUAL(NULL,buffer->message_arr[num+1].content);
	log_it(outfile,19,num+2);	
	buffer_destroy(buffer);
}

void test20(void)
{
	buffer = buffer_init(3);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[1].content);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[2].content);
	pthread_t a;
	pthread_create(&a,NULL,producer,NULL);
	pthread_t b;
	pthread_create(&a,NULL,producerb,NULL);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[0].content);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[1].content);
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[2].content);
	log_it(outfile,20,1);
	buffer_destroy(buffer);
}

void test21(void)
{
	int num = 4;
	buffer = buffer_init(num);
	log_it(outfile,21,1);
	for(int i = 0; i < num ; i++)
	{
		if(i%2==0)
		{
			pthread_t a;
			pthread_create(&a,NULL,producer,NULL);
		}
		else
		{
			pthread_t a;
			pthread_create(&a,NULL,producerb,NULL);
		}	
	}
	sleep(2);
	CU_ASSERT_EQUAL(4,buffer->cont);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[0].content);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[1].content);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[2].content);
	CU_ASSERT_NOT_EQUAL(NULL,buffer->message_arr[3].content);
	log_it(outfile,21,2);
	buffer_destroy(buffer);
}

void test22(void)
{
	int num = 5;
	buffer = buffer_init(num);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(EXPECTED_MSG,buffer->message_arr[num-1].content);
	log_it(outfile,22,1);
	CU_ASSERT_EQUAL(num,buffer->cont);
	for(int i = 0; i < num ; i++)
	{
		if(i%2==0)
		{
			pthread_t a;
			pthread_create(&a,NULL,consumer,NULL);
		}
		else
		{
			pthread_t a;
			pthread_create(&a,NULL,consumerb,NULL);
		}
		sleep(2);
		log_it(outfile,22,i+2);
		CU_ASSERT_EQUAL(num-i-1,buffer->cont);	
	}
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,22,num+2);
	buffer_destroy(buffer);
}

void test23(void)
{
	buffer = buffer_init(1);
	pthread_t a,b,c,d;
	pthread_create(&a,NULL,producerb,NULL);
	sleep(1);
	log_it(outfile,23,1);
	CU_ASSERT_EQUAL(1,buffer->cont);
	pthread_create(&b,NULL,consumerb,NULL);
	sleep(1);
	log_it(outfile,23,2);
	CU_ASSERT_EQUAL(0,buffer->cont);	
	sleep(1);
	log_it(outfile,23,4);
	pthread_create(&c,NULL,producer,NULL);
	sleep(1);
	log_it(outfile,23,5);
	CU_ASSERT_EQUAL(1,buffer->cont);
	pthread_create(&d,NULL,consumer,NULL);
	sleep(1);
	log_it(outfile,23,6);
	CU_ASSERT_EQUAL(0,buffer->cont);
	buffer_destroy(buffer);
}

void test24(void)
{
	buffer = buffer_init(1);
	msg_t* expected = msg_init(EXPECTED_MSG);
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,put_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,24,1);	
	CU_ASSERT_EQUAL(BUFFER_ERROR,put_non_bloccante(buffer,expected));
	CU_ASSERT_EQUAL(1,buffer->cont);
	log_it(outfile,24,2);	
	CU_ASSERT_NOT_EQUAL(BUFFER_ERROR,get_bloccante(buffer));
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,24,3);
	CU_ASSERT_EQUAL(BUFFER_ERROR,get_non_bloccante(buffer));
	CU_ASSERT_EQUAL(0,buffer->cont);
	log_it(outfile,24,4);
	buffer_destroy(buffer);
}

void test25(void)
{
	buffer = buffer_init(5);
	for(int i = 0; i < 3 ; i++)
	{
		pthread_t a;
		pthread_create(&a,NULL,producerb,NULL);	
		sleep(1);	
		log_it(outfile,25,i+1);
	}
	CU_ASSERT_EQUAL(3,buffer->cont);
	for(int i = 0; i < 2 ; i++)
	{
		pthread_t a;
		pthread_create(&a,NULL,consumerb,NULL);	
		sleep(1);	
		log_it(outfile,25,i+4);
	}
	CU_ASSERT_EQUAL(1,buffer->cont);	
	for(int i = 0; i < 5 ; i++)
	{
		pthread_t a;
		pthread_create(&a,NULL,producer,NULL);	
		sleep(1);	
		log_it(outfile,25,i+6);
	}	
	CU_ASSERT_EQUAL(5,buffer->cont);		
	for(int i = 0; i < 5 ; i++)
	{
		pthread_t a;
		pthread_create(&a,NULL,consumer,NULL);	
		sleep(1);	
		log_it(outfile,25,i+11);
	}	
	CU_ASSERT_EQUAL(0,buffer->cont);
	CU_ASSERT_EQUAL(BUFFER_ERROR,get_non_bloccante(buffer));
	buffer_destroy(buffer);
}
