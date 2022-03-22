
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;


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

//phone book page

class settings;

class phonebook
{
//details of contact:

	//mandatory details to store a contact
	char *first_name;
	char *last_name;
	char **num;
	
	//additional details for a contact
	char *company_name;
	char *job_title;
	char *email;
	char *address;
	char *dob;
	
	bool favorite_flag;
	bool friend_flag;
	bool family_flag;
	bool office_flag;
	
//flags of details whether present or not:
	bool company_name_present;
	bool job_title_present;
	bool email_present;
	bool address_present;
	bool dob_present;
	bool relation_present; 
	
//number of contact numbers present for each contact
	int num_count;
	
//kind of number either work or home or mobile or telephone_home or telephone_office
	int num_kind;

//link for linked list
	phonebook* link;
		bool allocate_mem_to(phonebook* &);
		void input_name(char* &);
		void input_number(char** &);
		bool check_number_valid(char* &);
		void memory_full();
		void add_in_sorted_dictionary_order(phonebook* &);
		
	public:
	   	phonebook();
		~phonebook();
		
		void add_contact();
		void delete_contact();
		void edit_contact();
		void show_contact() const;
		void search_contact() const;
		void display_contacts();
		void settings();
		
		friend class settings;
};


class settings
{
	bool sort_flag;
	bool name_order_flag;
	bool friends_display;
	bool family_display;
	bool office_display;
	bool all_contacts_display;
	bool only_favourites;
	
	public:
		
		friend class phonebook;
		
		settings()
		{
				
		}
		
		~settings()
		{
			
		}
		void add_to_favourites(phonebook* &);
		void my_groups();
	//	void merge_duplicates();
		void contacts_to_display();
		void sort_by();
		void name_order();
		
		void restore_settings();
		
};

void settings::add_to_favourites(phonebook* &obj)
{
	obj->favourite_flag=1;
	cout<<"contact added to favourites."<<endl;
}

void settings::sort_by()
{
	ifstream in;
	in.open(settings.txt);
	if(in)
	{
		
	}
	else
	{
		ofstream out;
		out.open(settings.txt);
		
	}
}

void settings::name_order()
{
	
}
//login page

char *root_password="root_pswd";
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
	delete this->username;
	delete this->password;
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
   	
   		delete this->username;
   		delete this->password;

   }

};
bool user_login_credentials::verify_credentials()
{
    //user_login_credentials*ptr;
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
            {
				
					for(traverse_pointer=head;traverse_pointer->link;traverse_pointer=traverse_pointer->link)
					delete traverse_pointer;
					
					delete u_name;
					delete pswd; 
					
            return true;
        	
			}
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
            {
				delete u_name;
				delete pswd;
				
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
    
    delete u_name;
    delete pswd;
    
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
    
    delete u_name;
    delete pswd;
    delete root_pswd;
    
    return true;
	}
	
	else
	{
		delete root_pswd;
		
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
                               {
							   	delete login_ptr;
							   	verify_credential_flag=1;
                               return true;
                           		}
                               else
                                {
							   		verify_credential_flag=0;
                               		return false;
                           	    }
                            }  
                           
        case SIGN_IN_AS_USER:  
                            {
                               login_ptr=new user_login_credentials;
                               
                               if(login_ptr->verify_credentials())
                               {
							   		delete login_ptr;
							   		verify_credential_flag=1;
                              	 return true;
                           		}
                               else
                               {
							   verify_credential_flag=0;
                               return false;
                           	   }
                            }
        case SIGN_UP_AS_USER:  
                            {
                               login_ptr=new user_login_credentials;
                               if(login_ptr->set_credentials())
                               {
                               	
								   delete login_ptr;
								   set_credential_flag=1;
                               	   return true;
                           	   }
                               else
                               {
							   set_credential_flag=0;
                               return false;
                           	   }
                            }
                               
        case CHANGE_ADMIN:    
                            {
                               login_ptr=admin_login_credentials::get_instance();
                               if(login_ptr->set_credentials())
                               {
                               	
								   delete login_ptr;
								   set_credential_flag=1;
                               	   return true;
                           	   }
                               else
                               {
							   set_credential_flag=0;
                               return false;
                           	   }
                            }
                           
        case EXIT: exit(0);
       
        default:
                    cout<<"wrong_choice"<<endl;
                    goto ENTER_LOGIN_CHOICE_AGAIN;
    }
}
void print_main_menu()
{
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    system("cls");
    system("Color 3F");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  *WELCOME TO PHONEBOOK APPLICATION*";
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t ======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t|PHONE BOOK APPLICATION|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t ======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                        "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tMAIN MENU"<<endl;
    cout<<" \t\t\t\t\t\t\t\t\t======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t[1] Add a new Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[2] Delete Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[3] Search Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[4] Display Contacts\n";
    cout<<"\t\t\t\t\t\t\t\t\t[5] Update a Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[6] Show a Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[7] Settings\n";
    cout<<"\t\t\t\t\t\t\t\t\t[8] Exit\n";
    cout<<"\t\t\t\t\t\t\t\t\t ======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tEnter your choice:";
}
int main()
{

    PRINTING_LOGIN_CREDENTIALS_MENU:
   
    print_login_credentials_menu();  
   
    if(login_operations()==false)
    goto PRINTING_LOGIN_CREDENTIALS_MENU;
    else
    {
    	if(verify_credential_flag==1)
    	{
		
    	cout<<"Login Successful"<<endl;
    	system("pause");
    	}
    	else if (set_credential_flag==1)
    	{
    		cout<<"account created successfully"<<endl;
    		system("pause");
    		goto PRINTING_LOGIN_CREDENTIALS_MENU;
		}
    	
	}
	
	print_main_menu();
	
   	
     
}
