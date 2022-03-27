#include "global.h"

int main()
{
phonebook *head=NULL;

settings set_obj;

int input_for_phonebook_menu,settings_choice;

bool BREAK_WHILE=0;

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
	while(1)
	{
	
	print_phonebook_menu();
	
	cin>>input_for_phonebook_menu;
	fflush(stdin);
	switch(input_for_phonebook_menu)
	{
		case ADD_CONTACT		: 
									
									head->add_contact(head,set_obj); break;
		
		case DELETE_CONTACT		: head->delete_contact(head,set_obj);break;
		case EDIT_CONTACT		:	head->edit_contact(head,set_obj);break;
		case SHOW_CONTACT		: head->show_contact(head,set_obj); break;
		
		case DISPLAY_CONTACTS	: 	
									head->display_contacts(head,set_obj);
									break;
								
		case SETTINGS			: 	
									
								while(1)
								{
									if(BREAK_WHILE)
									break;
									
									print_settings_menu();
						
									cin>>settings_choice;
									fflush(stdin);
									switch(settings_choice)
									{
										case 1: set_obj.add_to_favourites(head) ;break;
										case 2: set_obj.contacts_to_display()   ;break;
										case 3: set_obj.sort_by(); break;
										case 4: set_obj.name_order(); break;
										case 5: BREAK_WHILE=1; break;
									}
									
								}
		case EXIT_MAIN				:	exit(0);
		
		default					:	cout<<"Wrong Choice"<<endl; break;
	}
	
}
	
   	
}
