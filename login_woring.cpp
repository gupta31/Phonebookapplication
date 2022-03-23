
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<windows.h>

#define SIGN_IN_AS_ADMIN 	1
#define SIGN_IN_AS_USER 	2
#define SIGN_UP_AS_USER 	3
#define CHANGE_ADMIN 		4
#define EXIT 				5


char *root_password="root_pswd";
char space[]=" ";
char new_line[]="\n";

char* get_string()
{
	char *ptr=NULL;
	int i=0;
	
	do
	{
		ptr=(char*)realloc(ptr,i+1);
		
		if(ptr==NULL)
			return ptr;
			
		ptr[i]=getchar();
		
	} while(ptr[i++]!='\n');
	
	ptr[i-1]='\0';
	
	return ptr;
}
//login

class login
{

protected:
	
char *username;
char *password;
     
public:
virtual bool set_credentials()=0;
virtual bool verify_credentials()=0;
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

~admin_login_credentials(){};

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

};

bool user_login_credentials::verify_credentials(void)
{
    
	ifstream file;
   
    char ch;
   
    int i;
   
    user_login_credentials *temp,*head=NULL,*traverse_pointer;
   
    char *u_name,*pswd;
    
    file.open("user_login_credentials.txt");
    if(file)
    {
   
    //creating a linked list of users
   
   	
   	
        while((ch=file.get())!=EOF)
        {
        	temp=new user_login_credentials;
        	
            i=0;
            do
            {
            	 
                temp->username=(char*)realloc(temp->username,i+1);
                temp->username[i++]=ch;
              
            }while((ch=file.get())!=' ');
           
            temp->username=(char*)realloc(temp->username,i+1);
            temp->username[i]='\0';
           
            i=0;
            ch=file.get();
            do
            {
                temp->password=(char*)realloc(temp->password,i+1);
                temp->password[i++]=ch;
               
            }while(((ch=file.get())!='\n')&&(ch!=EOF));
           
            temp->password=(char*)realloc(temp->password,i+1);
            temp->password[i]='\0';
           
            if(head==NULL)
            head=temp;
            else
            {
                for(traverse_pointer=head;traverse_pointer->link;traverse_pointer=traverse_pointer->link);
               
                traverse_pointer->link=temp;
            }
       		
       		if(ch==EOF)
       		break;
        }
        
        file.close();
       	fflush(stdin);
        cout<<"Enter Username:"<<endl;
        u_name=get_string();
       	fflush(stdin);
        cout<<"Enter Password:"<<endl;
        pswd=get_string();
       	fflush(stdin);
        for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
        {
            if(strcmp(traverse_pointer->username,u_name)==0 && strcmp(traverse_pointer->password,pswd)==0)
            return true;
        }
       
        cout<<"Wrong Credentials.Enter credentials again."<<endl;
        
                
        //system pause
        system("pause");
        
        return false;
       
       
    }
    else
    {
        
        file.close();
        cout<<"users doesn't exist.SignUp to create an user account."<<endl;
        
        
        //system pause
        system("pause");
        return false;
    }
}

bool admin_login_credentials::verify_credentials()
{
    
    ifstream file;
   
    char ch;
   
    int i;
   
   
    char *u_name,*pswd;
    file.open("admin_login_credentials.txt");
    if(file)
    {
   
    //creating a linked list of users
   
        ch=file.get();
        
            i=0;
            
            do
            {
                this->username=(char*)realloc(this->username,i+1);
                this->username[i++]=ch;
               
            }while((ch=file.get())!=' ');
           
            this->username=(char*)realloc(this->username,i+1);
            this->username[i]='\0';
           
            i=0;
            ch=file.get();
            do
            {
                this->password=(char*)realloc(this->password,i+1);
                this->password[i++]=ch;
               
            }while(((ch=file.get())!='\n')&&(ch!=EOF));
           
            this->password=(char*)realloc(this->password,i+1);
            this->password[i]='\0';
       
        file.close();
       	fflush(stdin);
        cout<<"Enter Username:"<<endl;
        u_name=get_string();
       	fflush(stdin);
        cout<<"Enter Password:"<<endl;
        pswd=get_string();
       	fflush(stdin);
            if(strcmp(this->username,u_name)==0 && strcmp(this->password,pswd)==0)
            return true;
       
        cout<<"Wrong Credentials.Enter credentials again."<<endl;
        
        
        //system pause
        system("pause");
        
        return false;
       
       
}
    else
    {
        
        file.close();
        
        cout<<"admin doesn't exist.SignUp to create an admin account."<<endl;
        
        //system pause
        system("pause");
        
        return false;
    }
}
void print_login_credentials_menu()
{
    ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    system("cls");
    system("Color 3F");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  *WELCOME TO PHONEBOOK APPLICATION*";
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tPlease sign-in or sign-up to continue"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t[1] Sign-in as Admin\n";
    cout<<"\t\t\t\t\t\t\t\t\t[2] Sign-in as user\n";
    cout<<"\t\t\t\t\t\t\t\t\t[3] Sign-up to create a User Account\n";
    cout<<"\t\t\t\t\t\t\t\t\t[4] Change Admin\n";
    cout<<"\t\t\t\t\t\t\t\t\t[5] Exit\n";
}

bool user_login_credentials::set_credentials()
{
    fstream file;
    
    file.open("user_login_credentials.txt",ios::out|ios::app);
    
    char *u_name,*pswd;
    	fflush(stdin);
        cout<<"Enter Username:"<<endl;
        u_name=get_string();
       	fflush(stdin);
        cout<<"Enter Password:"<<endl;
        pswd=get_string();
        fflush(stdin);
    file.write(u_name,strlen(u_name));
    file.write(space,1);
    file.write(pswd,strlen(pswd));
    file.write(new_line,1);
    
    file.close();
    
    return true;
    
}

bool admin_login_credentials::set_credentials()
{
    fstream file;
    char *root_pswd;
    
    cout<<"Enter Root Password:"<<endl;
    root_pswd=get_string();
    
    if(strcmp(root_password,root_pswd)==0)
    {

    file.open("admin_login_credentials.txt",ios::out);
    
    char *u_name,*pswd;
    	fflush(stdin);
        cout<<"Enter Username:"<<endl;
        u_name=get_string();
       	fflush(stdin);
        cout<<"Enter Password:"<<endl;
        pswd=get_string();
        fflush(stdin);
        
    file.write(u_name,strlen(u_name));
    file.write(space,1);
    file.write(pswd,strlen(pswd));
    file.close();
    return true;
	}
	
	else
	{
		cout<<"You cannot change the existing admin."<<endl;
		cout<<"Error: Root password wrong."<<endl;
		
		system("pause");
		return false;
	}
}

bool login_operations()
{
    int login_choice;
    login *login_ptr;
   
    ENTER_LOGIN_CHOICE_AGAIN:
   
    cin>>login_choice;
   	fflush(stdin);
    switch(login_choice)
    {
        case SIGN_IN_AS_ADMIN:
                            {
                               login_ptr=admin_login_credentials::get_instance();
                               
                               if(login_ptr->verify_credentials())
                               return true;
                               else
                               return false;
                            }  
                           
        case SIGN_IN_AS_USER:  
                            {
                               login_ptr=new user_login_credentials;
                               
                               if(login_ptr->verify_credentials())
                               return true;
                               else
                               return false;
                            }
        case SIGN_UP_AS_USER:  
                            {
                               login_ptr=new user_login_credentials;
                               if(login_ptr->set_credentials())
                               return true;
                               else
                               return false;
                            }
                               
        case CHANGE_ADMIN:    
                            {
                               login_ptr=admin_login_credentials::get_instance();
                               if(login_ptr->set_credentials())
                               return true;
                               else
                               return false;
                            }
                           
        case EXIT: exit(0);
       
        default:
                    cout<<"wrong_choice"<<endl;
                    goto ENTER_LOGIN_CHOICE_AGAIN;
    }
}

int main()
{

    PRINTING_LOGIN_CREDENTIALS_MENU:
   
   									 print_login_credentials_menu();  
   
    									if(login_operations()==false)
    										goto PRINTING_LOGIN_CREDENTIALS_MENU;
    
    									cout<<"end"<<endl;
     
}

