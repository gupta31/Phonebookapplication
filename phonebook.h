#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include<iostream>
using namespace std;
//#include<regex>
//phone book page


#define ADD_CONTACT 		1
#define DELETE_CONTACT 		2
#define EDIT_CONTACT		3
#define SHOW_CONTACT		4
#define DISPLAY_CONTACTS	5
#define SETTINGS			6
#define EXIT_MAIN           7

class settings;

class phonebook
{
//details of contact:

	//mandatory details to store a contact
	string first_name;
	string last_name;
	
	//one is mandatory
	string mobile_num;
	string work_num;
	string home_num;
	
	//additional details for a contact
	string company_name;
	string job_title;
	string email;
	string location;
	string dob;
	
	bool favorite_flag;
	bool friend_flag;
	bool family_flag;
	bool office_flag;
	
	bool name_order;
//flags of details whether present or not:
	bool company_name_present;
	bool job_title_present;
	bool email_present;
	bool location_present;
	bool dob_present;
	bool relation_present; 
	bool mobile_num_flag;
	bool work_num_flag;
	bool home_num_flag;

//link for linked list
	phonebook* link;
	
	    bool check_number_valid(string&);
	//	bool check_email_valid(string&);
		
		void reverse_linked_list(phonebook* &);
		void add_in_sorted_order(phonebook* &,phonebook* &,bool,bool);
		void print_all_the_details(phonebook* &);
		friend void operator>>(istream&,phonebook*&);
		friend void operator<<(ostream&,phonebook*&);
		
		
	public:
	   		phonebook();
			~phonebook();
		
		void add_contact(phonebook* &,settings &);
		void delete_contact(phonebook* &,settings&);
		void edit_contact(phonebook* &,settings&);
		void show_contact(phonebook* &,settings&);
		void display_contacts(phonebook* &,settings &);
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
		
		settings();
		
		~settings()
		{
			
		}
		void add_to_favourites(phonebook* &);
		void contacts_to_display();
		void sort_by();
		void name_order();
		
		
};
void print_phonebook_menu();
void print_settings_menu();
#endif
