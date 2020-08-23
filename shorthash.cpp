#include <cstdlib>
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
	int hash=0;
	int color=0;
	std::string colorstr="";
	std::stringstream ss;

	//Add up the ASCII values of all characters in the argv[1]
	for(int i=0; i<std::string(argv[1]).length(); i++)
	{
		hash+=(int)std::string(argv[1]).at(i);
	}

	//std::cout<<hash<<std::endl;
	//Divide down to ensure number is within 8-bit bounds
	while(hash>255)
	{
		hash/=std::to_string(hash).length();
	}

	std::cout<<hash<<std::endl;

	return 0;
}
