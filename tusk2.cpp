#include <iostream>
#include <cpr/cpr.h>
#include <vector>

using namespace std;

int main()
{
	cpr::Session wewuz;
	wewuz.SetUrl("http://httpbin.org/html");
	wewuz.SetHeader(cpr::Header{{"accept", "text/html"}});
	cpr::Response r = wewuz.Get();	
	if (r.status_code == 200)
	{
		std::string html = r.text;

		int start = html.find("<h1>");
		int end = html.find("</h1>");
		if (start != std::string::npos && end != std::string::npos) {
			std::string header = html.substr(start + 4, end - start - 4);
			std::cout << "header: " << header << std::endl;
		}
		else {
			std::cout << "header not find!" << std::endl;
		}
	}
	else
	{
		cout << "Error" << endl;
	}
}
