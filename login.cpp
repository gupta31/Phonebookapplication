#include"global.h"

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
    
     free (u_name);
     free (pswd);
    
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
