#ifndef MSG_H
#define MSH_H
typedef struct msg
{
	char* content;
	struct msg * (*msg_init)(char*); 
	void (*msg_destroy)(struct msg *);
	struct msg * (*msg_copy)(struct msg *);
	bool operator==(const msg& m);
	friend std::ostream& operator<<(std::ostream& os,const msg& m)
	{
		os << m.content << std::endl;
		return os;
	}

}msg_t;

bool msg_t::operator==(const  msg_t& m)
{
	return (content==m.content);
}

#endif
