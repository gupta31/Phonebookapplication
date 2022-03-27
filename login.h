#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include<iostream>
using namespace std;
//login page

char root_password[]="root_pswd";
bool set_credential_flag;
bool verify_credential_flag;

#define SIGN_IN_AS_ADMIN 	1
#define SIGN_IN_AS_USER 	2
#define SIGN_UP_AS_USER 	3
#define CHANGE_ADMIN 		4
#define EXIT 				5

class login
{

protected:
	
char *username;
char *password;
     
public:
virtual bool set_credentials()=0;
virtual bool verify_credentials()=0;

virtual ~login()
{
	//cout<<"login destructor"<<endl;
	
}

};

//singleton class for admin as admin could be only one

class admin_login_credentials: public login
{

static admin_login_credentials *instance;

admin_login_credentials()
{
	username=NULL;
	password=NULL;
} //constructor must be private for a singleton class

public:
    bool set_credentials();
	bool verify_credentials();

static admin_login_credentials* get_instance()
{
if(instance==NULL)
instance=new admin_login_credentials;

return instance;
}

~admin_login_credentials()
{
	//cout<<"admin destructor"<<endl;
	delete username;
	delete password;
}

};

admin_login_credentials* admin_login_credentials::instance=NULL;

//class for user login credentials

class user_login_credentials : public login
{
//users can be more than one hence we will be creating a linked list
user_login_credentials *link;

public:
   bool verify_credentials();
   bool set_credentials();
   
   user_login_credentials()
   {
   		username=NULL;
   		password=NULL;
   		link=NULL;
   }
   
   ~user_login_credentials()
   {
   	
   	//cout<<"user destructor"<<endl;
   	
   		delete username;
   		delete password;

   }

};
void print_login_credentials_menu(void);
bool login_operations(void);
#endif
