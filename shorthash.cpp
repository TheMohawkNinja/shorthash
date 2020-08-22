#include <cstdlib>
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>

std::string getCmdOut(std::string cmd)
{
        std::string data;
        FILE* stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        cmd.append(" 2>&1");
        stream=popen(cmd.c_str(), "r");

        if(stream)
        {
                while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
                pclose(stream);
        }

        return data;
}
int main(int argc, char *argv[])
{
	int hash=0;
	int color=0;
	std::string tty=getCmdOut("tty");
	std::string pwd=argv[1];
	std::string colorstr="";
	std::stringstream ss;

	tty=tty.substr(tty.length()-2,1);

	//Add up the ASCII values of all characters in the argv[1]
	for(int i=0; i<pwd.length(); i++)
	{
		hash+=(int)pwd.at(i);
	}

	//std::cout<<hash<<std::endl;
	//std::cout<<(int)(hash/255)<<std::endl;
	//Divide down to ensure number is within 8-bit bounds
	while(hash>255)
	{
		hash/=std::to_string(hash).length();
	}

	std::cout<<hash<<std::endl;

	return 0;
}
