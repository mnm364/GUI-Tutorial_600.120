#include <iostream>
#include <fstream>

int main() {
	
	std::ofstream myfile;
	myfile.open("templates/out.html");

	myfile << "<span> input number greater than 3 to show output </span>\n";
	std::cout << "input number greater than 3 to show output" << std::endl;

	// close file to update to out.html
	myfile.close();

	int check_num;
	std::cin >> check_num;
	if (check_num > 3) {
		myfile.open("templates/out.html");
		myfile << "<span> your input:" << check_num << "</span><span> Hello, World! </span>" << std::endl;
		std::cout << "Hello, World!" << std::endl;
		myfile.close();
	}

	// copyfile

	return 0;
}