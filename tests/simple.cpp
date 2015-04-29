#include <iostream>
#include <fstream>
#include <cctype>

int main() {
	
	std::ofstream myfile;
	myfile.open("templates/out.html", std::ios::trunc);

	myfile << "<p> input number </p>\n";
	myfile << "	<!-- Button example -->\n	<form action=\"/\" method=\"POST\">\n		<input type=\"text\">\n		<input type=\"submit\" id=\"SUBMIT\" />\n	</form>" << std::endl;
	std::cout << "input number greater than 3 to show output" << std::endl;
	// close file to update to out.html
	myfile.close();

	int check_num;
	std::cin >> check_num;
	
	myfile.open("templates/out.html");
	myfile << "<span> your input:" << check_num << "</span>" << std::endl;
	std::cout << "your input" << check_num << std::endl;
	myfile.close();

	// copyfile

	return 0;
}