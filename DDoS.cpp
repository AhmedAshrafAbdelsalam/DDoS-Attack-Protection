#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <unordered_map>

using std::cout;
using std::endl;
using std::cin;

void blockIP(std::string in, std::string password)	{
	system(("bash block.sh \"" + in + "\" \"" + password + "\"").c_str());
}

int main(int argc, char** argv) {

	int pingLimit;
	std::string password;

	cout << "Please enter the Ping request limit in 5 seconds for block" << endl;
	cin >> pingLimit;
	cout << "Please enter your password" << endl;
	cin >> password;

	std::unordered_map <std::string, int> IPs;
	std::string log{""};
	system(("bash scan.sh " + password).c_str());
	std::ifstream t("outputDDOS.txt");

	std::regex IP(R"([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)");
	std::smatch Match;

	while(std::getline(t,log))	{
		std::regex_search(log,Match,IP);
		IPs[Match[0]]++;
	}
		
	for(auto x : IPs)	{
		if(x.second >= pingLimit)
			blockIP(x.first,password);
	}	
	return 0;
}