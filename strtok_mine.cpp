#include <stdio.h>
#include <iostream>


char* strtok_mine( char* str, char* delim ){  

	static char* savedPtr = NULL;

	char* itr = str; 

	if( str == NULL )
	{
		itr = savedPtr;	
	}else{
		itr = str;	
	}
	
	while( *itr !=0){
		
		bool bIsDelim = false;
		char* delimItr = delim;
		while(*delimItr != 0)
		{
			if(*delimItr == *itr){
				bIsDelim = true;
				break;	
			}	
			delimItr++;
		} 
		if(bIsDelim){
			itr++;
		}
		else{
			break;	
		}
	}
	
	char* retPointer = itr;
	if(*retPointer=='\0'){
		return NULL;
	}
	
	while( *itr !=0){
		
		bool bIsDelim = false;
		char* delimItr = delim;
		while(*delimItr != 0)
		{
			if(*delimItr == *itr){
				bIsDelim = true;
				break;	
			}
			delimItr++;
		}
		if(bIsDelim){
			*itr = 0;
			itr++;
			break;
		}
		else{
			itr++	;
		}
	}
	savedPtr = itr;

	if(*retPointer=='\0'){
		return NULL;
	}

	return retPointer;
		
}

char* strtok_r_mine( char* str, char* delim, char** savePtr ){  

	char* itr = str; 

	if( str == NULL )
	{
		itr =  *savePtr;	
	}else{
		itr = str;	
	}
	
	while( *itr !=0){
		
		bool bIsDelim = false;
		char* delimItr = delim;
		while(*delimItr != 0)
		{
			if(*delimItr == *itr){
				bIsDelim = true;
				break;	
			}	
			delimItr++;
		} 
		if(bIsDelim){
			itr++;
		}
		else{
			break;	
		}
	}
	
	char* retPointer = itr;
	if(*retPointer=='\0'){
		return NULL;
	}
	
	while( *itr !=0){
		
		bool bIsDelim = false;
		char* delimItr = delim;
		while(*delimItr != 0)
		{
			if(*delimItr == *itr){
				bIsDelim = true;
				break;	
			}
			delimItr++;
		}
		if(bIsDelim){
			*itr = 0;
			itr++;
			break;
		}
		else{
			itr++	;
		}
	}
	*savePtr = itr;

	if(*retPointer=='\0'){
		return NULL;
	}

	return retPointer;
		
}

int main()
{ 
	{
		std::cout << "----------------------\n";
		char str[1024] = " ,,,,,    arreeeee             and Hello,and how 'aha' are you";
		char* delim = ",' ";
		std::cout << "str : " << str << "\n";
		std::cout << "delim : " << delim << "\n-----\n";
		char* token = strtok_mine(str, delim);
		while(token)
		{
			std::cout << token << "\n";
			token = strtok_mine(NULL,delim);
		}
	}
	{
		std::cout << "----------------------\n";
		char str[1024] = "'' ,,,,,    LOL'            and' lo' kallo baat";
		char* delim = ",' ";
		std::cout << "str : " << str << "\n";
		std::cout << "delim : " << delim << "\n-----\n";
		char* token = strtok_mine(str,delim);
		while(token)
		{
			std::cout << token << "\n";
			token = strtok_mine(NULL,delim);
		}
	}
	{
		std::cout << "----------------------\n";
		char str[1024] = " ,,,,,    arreeeee             and Hello,and how 'aha' are you";
		char* delim = ",' ";
		std::cout << "str : " << str << "\n";
		std::cout << "delim : " << delim << "\n-----\n";
		char* savePtr;	
		char* token = strtok_r_mine(str, delim, &savePtr);
		while(token)
		{
			std::cout << token << "\n";
			token = strtok_r_mine(NULL,delim,&savePtr);
		}
	}
	{
		std::cout << "----------------------\n";
		char str[1024] = "'' ,,,,,    LOL'            and' lo' kallo baat";
		char* delim = ",' ";
		std::cout << "str : " << str << "\n";
		std::cout << "delim : " << delim << "\n-----\n";
		char* savePtr;	
		char* token = strtok_r_mine(str,delim, &savePtr);
		while(token)
		{
			std::cout << token << "\n";
			token = strtok_r_mine(NULL,delim,&savePtr);
		}
	}
	std::cout << "----------------------\n";

	return 0;	
}
