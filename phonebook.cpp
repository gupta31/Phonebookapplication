#include"global.h"

phonebook::phonebook()
{
	 favorite_flag=0;
	 friend_flag=0;
	 family_flag=0;
	 office_flag=0;
	 mobile_num_flag=0;
	 work_num_flag=0;
	 home_num_flag=0;
	
	company_name_present=0;
	job_title_present=0;
	email_present=0;
	location_present=0;
	dob_present=0;
	relation_present=0; 
	
	name_order=0;
	
	link=NULL;
}

void phonebook::add_in_sorted_order(phonebook* &head,phonebook* &ptr,bool sort,bool name_order)
{
	phonebook *temp,*prev;
	
		if(head==NULL)
        head=ptr;
        else
        {
        	if(sort==0)
        	{
			
            for(temp=head,prev=head;temp;temp=temp->link)
            {
            	if(name_order==0)
            	{
	
                if(temp->first_name < ptr->first_name)
                {
                    if(temp==head)
                    {
                        ptr->link=head;
                        head=ptr;
                    }
                    else
                    {
                    prev->link=ptr;
                    ptr->link=temp;
                    }
                    return;
                }
                
                prev=temp;
                
            	}
            	else
            	{
            		if(temp->last_name < ptr->last_name)
                {
                    if(temp==head)
                    {
                        ptr->link=head;
                        head=ptr;
                    }
                    else
                    {
                    prev->link=ptr;
                    ptr->link=temp;
                    }
                    return;
                }
                
                prev=temp;
				}
            }
            
            prev->link=ptr;
        	}
        	
        	else
        	{
        		for(temp=head,prev=head;temp;temp=temp->link)
            {
            	if(name_order==0)
            	{
	
                if(temp->first_name > ptr->first_name)
                {
                    if(temp==head)
                    {
                        ptr->link=head;
                        head=ptr;
                    }
                    else
                    {
                    prev->link=ptr;
                    ptr->link=temp;
                    }
                    return;
                }
                
                prev=temp;
                
            	}
            	else
            	{
            		if(temp->last_name > ptr->last_name)
                {
                    if(temp==head)
                    {
                        ptr->link=head;
                        head=ptr;
                    }
                    else
                    {
                    prev->link=ptr;
                    ptr->link=temp;
                    }
                    return;
                }
                
                prev=temp;
				}
            }
            
            prev->link=ptr;
			}
        }
        
        return;
}
void phonebook::print_all_the_details(phonebook* &ptr)
{
	if(company_name_present)
	cout<<"Company: "<<ptr->company_name<<endl;
	
	if(job_title_present)
	cout<<"Job Title: "<<ptr->job_title<<endl;
	
	if(email_present)
	cout<<"Email: "<<ptr->email<<endl;
	
	if(location_present)
	cout<<"Home Location: "<<ptr->location<<endl;
	
	if(dob_present)
	cout<<"DOB: "<<ptr->dob<<endl;
	
	if(relation_present)
	{
		cout<<"Relation: ";
		if(friend_flag)
		cout<<"Friend"<<endl;
		
		if(family_flag)
		cout<<"Family"<<endl;
		
		if(office_flag)
		cout<<"Office"<<endl;
	}
	
}
void operator<<(ostream& out,phonebook* &obj)
{
		if(obj->name_order)
		{
		out<<obj->last_name;
		out<<" "<<obj->first_name;
		}
		else
		{
		out<<obj->first_name;
		out<<" "<<obj->last_name;
		}
		
		if(obj->mobile_num_flag)
		cout<<" Mobile: "<<obj->mobile_num;
		
		if(obj->work_num_flag)
		cout<<" Work: "<<obj->work_num;
		
		if(obj->home_num_flag)
		cout<<" Home: "<<obj->home_num<<endl;;
		
		
}

void operator>>(istream& in,phonebook* &obj)
{
	int num_in;
	
	char ch;
	
	cout<<"Enter First Name:"<<endl;
	in>>obj->first_name;
	fflush(stdin);
	
	cout<<"Enter Last Name:"<<endl;
	in>>obj->last_name;
	fflush(stdin);
	
	ENTER_NUMBER_CHOICE_AGAIN:
		
	cout<<"Type of number.\n 1.Mobile Number\n2.Work Number\n3.Home Number"<<endl;
	
	in>>num_in;
	fflush(stdin);
	
	switch(num_in)
	{
		case 1: ENTER_MOBILE_NUMBER_AGAIN:
		
				cout<<"Enter Mobile Number."<<endl;
				in>>obj->mobile_num;
				obj->mobile_num_flag=1;
				fflush(stdin);
				if(obj->check_number_valid(obj->mobile_num))
					break;
					else
					{
						cout<<"number invalid"<<endl;
						cout<<"enter again"<<endl;
						
						goto ENTER_MOBILE_NUMBER_AGAIN;
					}
				
		case 2: ENTER_WORK_NUMBER_AGAIN:
		
				cout<<"Enter Work Number."<<endl;
				in>>obj->work_num;
				obj->work_num_flag=1;
				fflush(stdin);
				
				if(obj->check_number_valid(obj->work_num))
					break;
					else
					{
						cout<<"number invalid"<<endl;
						cout<<"enter again"<<endl;
						
						goto ENTER_WORK_NUMBER_AGAIN;
					}
				
				
		case 3: ENTER_HOME_NUMBER_AGAIN:
		
				cout<<"Enter Home Number."<<endl;
				in>>obj->home_num;
				obj->home_num_flag=1;
				fflush(stdin);
				
				if(obj->check_number_valid(obj->home_num))
					break;
					else
					{
						cout<<"number invalid"<<endl;
						cout<<"enter again"<<endl;
						
						goto ENTER_HOME_NUMBER_AGAIN;
					}
				
		default:
				cout<<"wrong choice"<<endl;
				goto ENTER_NUMBER_CHOICE_AGAIN;
	}
	
	
	cout<<"Add some more details? press Y else any key"<<endl;
	in>>ch;
	fflush(stdin);
	if(ch=='Y'||ch=='y')
	{
		bool BREAK_WHILE=0;
		int relation_flag;
		
		while(1)
		{
			
			if(BREAK_WHILE)
			break;
			
		ENTER_CHOICE_AGAIN:
			
		cout<<"1.COMPANY NAME\n2.JOB TITLE\n3.Email\n4.Location\n5.DOB\n6.Relation\n7.Leave"<<endl;
		
		cin>>ch;
		fflush(stdin);
		
		switch(ch)
		{
			case 1: if(!obj->company_name_present)
					{
					cout<<"Enter Company Name:"<<endl;
					in>>obj->company_name;
					obj->company_name_present=1;
					fflush(stdin);
					break;
					}
					else
					{
						cout<<"company name exist. To update use update contact feature."<<endl;
						break;
					}
			case 2: if(!obj->job_title_present)
					{
					cout<<"Enter Job Title:"<<endl;
					in>>obj->job_title;
					obj->job_title_present=1;
					fflush(stdin);
					break;
					}
					else
					{
						cout<<"Job Title exist. To update use update contact feature."<<endl;
						break;
					}
			case 3: if(!obj->email_present)
					{
					
					ENTER_EMAIL_AGAIN:
					cout<<"Enter Email:"<<endl;
					in>>obj->email;
					fflush(stdin);
					/*if(obj->check_email_valid(obj->email))
					{
						obj->email_present=1;
						break;
					}
					else
					{
						cout<<"email invalid"<<endl;
						cout<<"enter again"<<endl;
						
						 goto ENTER_EMAIL_AGAIN;
					}*/
					break;
					}
					else
					{
						cout<<"Email exist. To update use update contact feature."<<endl;
						break;
					}
			case 4: if(!obj->location_present)
					{
					cout<<"Enter Location(only place):"<<endl;
					in>>obj->location;
					obj->location_present=1;
					fflush(stdin);
					break;
					}
					else
					{
						cout<<"Location exist. To update use update contact feature."<<endl;
						break;
					}
			case 5: if(!(obj->dob_present))
					{
					cout<<"Enter DOB(dd/mm/yyyy):"<<endl;
					in>>obj->dob;
					obj->dob_present=1;
					fflush(stdin);
					break;
					}
					else
					{
						cout<<"DOB exist. To update use update contact feature."<<endl;
						break;
					}
					
			case 6: cout<<"1.Friend\n2.Family\n3.Office"<<endl;
					in>>relation_flag;
					if(relation_flag==1)
					obj->friend_flag=1;
					else if(relation_flag==2)
					obj->family_flag=1;
					else if(relation_flag=3)
					obj->office_flag=1;
					else
					cout<<"wrong choice"<<endl;
					
					break;
					
			case 7: BREAK_WHILE=1;break;
			
			default: cout<<"wrong choice"<<endl;
						goto ENTER_CHOICE_AGAIN;
					
		}
		}
		
		cout<<"Want to add this contact to favourites? Press Y or N."<<endl;
		char ch;
		in>>ch;
		if(ch=='Y'||ch=='y')
		obj->favorite_flag=1;
		
		
	}
}
bool phonebook::check_number_valid(string &p)
{
	if((p.length())>10 || (p.length())<10)
	return false;

	for(int i=0;i<10;i++)
		if(p[i]<'0' || p[i]>'9')
			return false;

			return true;
}
/*bool phonebook::check_email_valid(string &email)
{
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email,pattern);
}*/
void phonebook::add_contact(phonebook* &head,settings &obj)
{
    
    phonebook *temp_obj=NULL,*read_obj=NULL,*traverse_pointer=NULL;
    
    temp_obj=new phonebook;
    
    cin>>temp_obj;
    
    bool sort_flag_1=0;
    bool name_order_flag_1=0;
    
    ifstream file_in;
    file_in.open("phonebook_contacts.txt");
    if(file_in)
    {
    	if(head==NULL)
    	{
    		if(obj->sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(obj->name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    	while(file_in)
    	{
    		read_obj=new phonebook;
    		file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    		add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
		}
		}
		
			add_in_sorted_order(head,temp_obj,sort_flag_1,name_order_flag_1);
		
		file_in.close();
		
		ofstream file_in_out;
		
		file_in_out.open("phonebook_contacts.txt");
		
		for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
			file_in_out.write((char*)traverse_pointer,sizeof(*traverse_pointer));
    	
    	file_in_out.close();
	}
	else
	{
		ofstream file_out;
		file_out.open("phonebook_contacts.txt");
		
		file_out.write((char*)temp_obj,sizeof(temp_obj));
		
		file_out.close();
	}

}

void phonebook::delete_contact(phonebook* &head, settings &obj)
{
	string delete_name;
	bool sort_flag_1=0;
    bool name_order_flag_1=0;
	
	phonebook *traverse_pointer=NULL,*prev_pointer=NULL,*read_obj=NULL;
	
	ifstream file_in;
    file_in.open("phonebook_contacts.txt");
    
    if(file_in)
    {
		if(head==NULL)
    	{
    		if(obj->sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(obj->name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    	while(file_in)
    	{
    		read_obj=new phonebook;
    		file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    		add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
		}
		}
		
		file_in.close();
		
			-cout<<"Enter Contact Name to be deleted(first_name or last name):"<<endl;
	cin>>delete_name;
	fflush(stdin);
	
	bool flag=0;
	
	for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
	{
		if(delete_name==(traverse_pointer->first_name) || delete_name==(traverse_pointer->last_name))
		{
				if(traverse_pointer==head)
				{
					traverse_pointer=traverse_pointer->link;
					
					delete head;
					
					head=traverse_pointer;
					flag=1;
					break;
				}
				else if((traverse_pointer->link)==NULL)
				{
					prev_pointer->link=NULL;
					
					delete traverse_pointer;
					flag=1;
					break;
				}
				else
				{
					prev_pointer->link=traverse_pointer->link;
					
					delete traverse_pointer;
					flag=1;
					break;
				}
		}
		
		prev_pointer=traverse_pointer;
	}
	
	if(flag==1)
	{
	ofstream file_out;
	
	file_out.open("phonebook_contacts.txt");
	
		for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
			file_out.write((char*)traverse_pointer,sizeof(*traverse_pointer));
    	
    	file_out.close();
    }
    else
    {
    	cout<<"name not found"<<endl;
	}
	}
	else
	{
		cout<<"no contacts to delete"<<endl;
	}
	
}
void phonebook::edit_contact(phonebook* &head,settings &obj)
{
	
	bool sort_flag_1=0;
    bool name_order_flag_1=0;
		ifstream file_in;
    file_in.open("phonebook_contacts.txt");
    
    phonebook *read_obj=NULL,*traverse_pointer=NULL;
    
    
	if(file)
	{
			if(head==NULL)
    	{
    		if(obj->sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(obj->name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    			while(file_in)
    			{
    				read_obj=new phonebook;
    				file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    				add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
				}
		}
		file_in.close();
		
		
		string name;
		cout<<"Enter Contact Name to edit:(first name or last name)"<<endl;
		cin>>name;
		
				for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
			{
				if(name==(traverse_pointer->first_name)  || name==(traverse_pointer->last_name))
				{
					bool BREAK_WHILE=0;
					
					while(1)
					{
						if(BREAK_WHILE==1)
						break;
									cout<<"1.Update Mobile Number"<<endl;
									cout<<"2.Update work Number"<<endl;
									cout<<"3.Update Home Number"<<endl;
									cout<<"4.Update Company Name"<<endl;
									cout<<"5.Update Job Title"<<endl;
									cout<<"6.Update Email"<<endl;
									cout<<"7.Update Location"<<endl;
									cout<<"8.Exit"<<endl;
									
									char ch;
									
									switch(ch)
									{
										case 1: ENTER_MOBILE_NUMBER_AGAIN1:
		
												cout<<"Enter Mobile Number."<<endl;
												cin>>traverse_pointer->mobile_num;
												traverse_pointer->mobile_num_flag=1;
												fflush(stdin);
												if(traverse_pointer->check_number_valid(traverse_pointer->mobile_num))
												break;
												else
												{
													cout<<"number invalid"<<endl;
													cout<<"enter again"<<endl;
							
													goto ENTER_MOBILE_NUMBER_AGAIN1;
												}
				
										case 2: ENTER_WORK_NUMBER_AGAIN1:
		
												cout<<"Enter Work Number."<<endl;
												cin>>traverse_pointer->work_num;
												traverse_pointer->work_num_flag=1;
												fflush(stdin);
				
												if(traverse_pointer->check_number_valid(traverse_pointer->work_num))
												break;
												else
												{
												cout<<"number invalid"<<endl;
												cout<<"enter again"<<endl;
						
												goto ENTER_WORK_NUMBER_AGAIN1;
												}
				
				
										case 3: ENTER_HOME_NUMBER_AGAIN1:
		
												cout<<"Enter Home Number."<<endl;
												cin>>traverse_pointer->home_num;
												traverse_pointer->home_num_flag=1;
												fflush(stdin);
				
												if(traverse_pointer->check_number_valid(traverse_pointer->home_num))
												break;
												else
												{
													cout<<"number invalid"<<endl;
													cout<<"enter again"<<endl;
						
													goto ENTER_HOME_NUMBER_AGAIN1;
												}
												
										case 4: 
													cout<<"Enter Company Name:"<<endl;
													cin>>traverse_pointer->company_name;
													traverse_pointer->company_name_present=1;
													fflush(stdin);
													break;
										case 5: 
													cout<<"Enter Job Title:"<<endl;
													cin>>traverse_pointer->job_title;
													traverse_pointer->job_title_present=1;
													fflush(stdin);
													break;
										case 6: 
													cout<<"Enter Email:"<<endl;
													cin>>traverse_pointer->email;
													fflush(stdin);
													break;
										case 7: 
													cout<<"Enter Location(only place):"<<endl;
													cin>>traverse_pointer->location;
													traverse_pointer->location_present=1;
													fflush(stdin);
													break;
					
										case 8: BREAK_WHILE=1;break;
			
										default: cout<<"wrong choice"<<endl;
													goto ENTER_CHOICE_AGAIN;
									}
					}
									
				}
			}
	}
		
	else
	{
		cout<<"No contacts found"<<endl;
	}
}
void phonebook::show_contact(phonebook* & head,settings &obj)
{
	
	string name;
	
	bool sort_flag_1=0;
    bool name_order_flag_1=0;
    
		ifstream file_in;
        file_in.open("phonebook_contacts.txt");
        
        phonebook *read_obj=NULL,*traverse_pointer=NULL;
        
        if(file)
        {
        	if(head==NULL)
    	{
    		if(obj->sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(obj->name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    	while(file_in)
    	{
    		read_obj=new phonebook;
    		file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    		add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
		}
		}
		file_in.close();
			cout<<"enter name:(first name or last name)"<<endl;
			cin>>name;
			
			bool flag=0;
	
	for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
	{
		if(name==(traverse_pointer->first_name) || name==(traverse_pointer->last_name))
		{
				cout<<traverse_pointer;
				
				cout<<"Details:"<<endl;
				print_all_the_details(traverse_pointer);
				flag=1;
				
				break;
		}
		
	}
			if(flag==0)
					cout<<"contact not found"<<endl;
						
	}
		else
		{
			cout<<"no contacts to display"<<endl;
		}
}

void print_phonebook_menu()
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
    cout<<"\t\t\t\t\t\t\t\t\t[3] Update a Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[4] Show a Contact\n";
    cout<<"\t\t\t\t\t\t\t\t\t[5] Display Contacts\n";
    cout<<"\t\t\t\t\t\t\t\t\t[6] Settings\n";
    cout<<"\t\t\t\t\t\t\t\t\t[7] Exit\n";
    cout<<"\t\t\t\t\t\t\t\t\t ======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tEnter your choice:";
}


          settings::settings()
		{
				ifstream file_in;
				file_in.open("settings.txt");
				settings temp;
				
				if(file_in)
				{
					file_in.read((char*)&temp,sizeof(temp));
					
					sort_flag			=	temp.sort_flag;
					name_order_flag		=	temp.name_order_flag;
					friends_display		=	temp.friends_display;
					family_display		=	temp.family_display;
					office_display		=	temp.office_display;
					all_contacts_display=	temp.all_contacts_display;
					only_favourites		=	temp.only_favourites;
					
					file_in.close();
					
				}
				else
				{
					sort_flag=0;
					name_order_flag=0;
					friends_display=0;
					family_display=0;
					office_display=0;
					all_contacts_display=1;
					only_favourites=0;
					
				}
		}
		
		
		
		
		
		
		void phonebook::display_contacts(phonebook* &head,settings &obj)
		{
			ifstream file_in;
        	file_in.open("phonebook_contacts.txt");
        	
        	bool sort_flag_1=0;
    		bool name_order_flag_1=0;
    
        	if(file)
        	{
        		if(head==NULL)
    	{
    		if(obj->sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(obj->name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    	while(file_in)
    	{
    		read_obj=new phonebook;
    		file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    		add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
		}
		}
				
				
						file_in.close();
						
						if(obj->sort_flag == true)
							reverse_linked_list(head);
						
						
						
						if(obj->only_favourites)
						{
							cout<<"FAVOURITES:"<<endl;
							
							for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
										if(traverse_pointer->favorite_flag)
										{
										
										if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
										
										}
							}
						}
						else if(obj->friends_display)
						{
						
						cout<<"FRIENDS:"<<endl;
								for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
										if(traverse_pointer->friend_flag)
										{
										
										if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
										
										}
							}
						}
						else if(obj->family_display)
						{
							cout<<"FAMILY:"<<endl;
								for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
										if(traverse_pointer->family_flag)
										{
										
										if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
										
										}
							}
						}
						else if(obj->office_display)
						{
							cout<<"OFFICE:"<<endl;
						
								for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
										if(traverse_pointer->office_flag)
										{
										
										if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
										
										}
							}
						}
						else
						{
							cout<<"FAVOURITES:"<<endl;
							
							for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
										if(traverse_pointer->favorite_flag)
										{
										
										if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
										
										}
							}
							
							cout<<"CONTACTS:"<<endl;
							
							for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
							{
								if(obj->name_order_flag)
										traverse_pointer->name_order =1;
										
										cout<<traverse_pointer;
							}
						}
						
						
			}
			else
			{
				cout<<"No Contacts To Display"<<endl;
			}
		}
		
		
		
void phonebook::reverse_linked_list(phonebook* &head)
{
    phonebook *prev=NULL;
    phonebook *current=head;
    phonebook *next=NULL;
    
	if(head!=NULL)
	{

    while(current != NULL){
        next=current->link;//store the next
        current->link=prev;//reverse the direction of linked list
        //aheading the pointers
        prev=current;
        current=next;
    }
    	head=prev;
	}
}
void print_settings_menu()
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
    cout<<"\t\t\t\t\t\t\t\t\tSETTINGS MENU"<<endl;
    cout<<" \t\t\t\t\t\t\t\t\t======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t[1] Add To Favorites\n";
    cout<<"\t\t\t\t\t\t\t\t\t[2] Contacts To Display\n";
    cout<<"\t\t\t\t\t\t\t\t\t[3] Sort_by\n";
    cout<<"\t\t\t\t\t\t\t\t\t[4] Name Order\n";
    cout<<"\t\t\t\t\t\t\t\t\t[5] Exit\n";
    cout<<"\t\t\t\t\t\t\t\t\t ======================="<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tEnter your choice:";
}
void settings::add_to_favourites(phonebook* &head)
{
	string name;
	
	phonebook *read_obj=NULL, *traverse_pointer=NULL;
	bool sort_flag_1=0;
    bool name_order_flag_1=0;
    
	ifstream file_in;
        file_in.open("phonebook_contacts.txt");
        
        if(file_in)
        {
        			if(head==NULL)
    		{
    		if(sort_flag == false)
    		sort_flag_1=0;
    		else
    		sort_flag_1=1;
    		
    		if(name_order_flag == false)
    		name_order_flag_1=0;
    		else
    		name_order_flag_1=1;
		
    			while(file_in)
    			{
    				read_obj=new phonebook;
    				file_in.read((char*)read_obj,sizeof(*read_obj));
    		
    		
    				head->add_in_sorted_order(head,read_obj,sort_flag_1,name_order_flag_1);
    		
				}
			}
				
				
						file_in.close();
						
						cout<<"Enter Name To be added to favourites:(first name or last name)"<<endl;
						cin>>name;
						
						bool flag=0;
	
	for(traverse_pointer=head;traverse_pointer;traverse_pointer=traverse_pointer->link)
	{
		if(name==(traverse_pointer->first_name) || name==(traverse_pointer->last_name))
		{
				traverse_pointer->favorite_flag=1;
				flag=1;
		}
		
	}
			if(flag==0)
					cout<<"contact not found"<<endl;
						
						
		}
		else
		{
			cout<<"No Contacts In Phonebook"<<endl;
		}
}

void settings::contacts_to_display()
{
	cout<<"1.SET FRIENDS ONLY TO DISPLAY"<<endl;
	cout<<"2.SET FAMILY ONLY TO DISPLAY"<<endl;
	cout<<"3.SET OFFICE ONLY TO DISPLAY"<<endl;
	cout<<"4.SET ALL CONTACTS TO DISPLAY"<<endl;
	cout<<"5.EXIT"<<endl;
	
	char ch;
	cout<<"Enter Choice: "<<endl;
	
	cin>>ch;
	fflush(stdin);
	
	switch(ch)
	{
		case 1: friends_display=1;break;
		case 2: family_display=1;break;
		case 3: office_display=1;break;
		case 4: all_contacts_display=1;break;
		case 5: break;
		
	}
	
	ofstream file_out;
	
				file_out.open("settings.txt");
				
				file_out.write((char*)this,sizeof(this));
				
				file_out.close();
}

void settings::sort_by()
{
	cout<<"1.Sort By Add in Alphabetical Order"<<endl;
	cout<<"2.Sort By Add in Reverse Alphabetical Order"<<endl;
	cout<<"3.EXIT"<<endl;
	
	char ch;
	cout<<"Enter Choice: "<<endl;
	
	cin>>ch;
	fflush(stdin);
	
	switch(ch)
	{
		case 1: sort_flag=0;break;
		case 2: sort_flag=1;break;
		case 3: break;	
	}
	
	ofstream file_out;
	
				file_out.open("settings.txt");
				
				file_out.write((char*)this,sizeof(this));
				
				file_out.close();
}

void settings::name_order()
{
	cout<<"1.FIRST_NAME LAST_NAME"<<endl;
	cout<<"2.LAST_NAME FIRST_NAME"<<endl;
	cout<<"3.EXIT"<<endl;
	
	char ch;
	cout<<"Enter Choice: "<<endl;
	
	cin>>ch;
	fflush(stdin);
	
	switch(ch)
	{
		case 1: name_order_flag=0;break;
		case 2: name_order_flag=1;break;
		case 3: break;	
	}
	
	ofstream file_out;
	
				file_out.open("settings.txt");
				
				file_out.write((char*)this,sizeof(this));
				
				file_out.close();
}
