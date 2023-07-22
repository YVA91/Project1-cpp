#include <iostream>
#include <fstream>

int main() {
	setlocale(LC_ALL, "Russian");
	int sizeOne;
	int sizeTwo;
	int item;
	std::ifstream file_in("in.txt");

	if (file_in) {
		
		file_in >> sizeOne;

		int* arr = new int[sizeOne];

		for (int i = 0; i < sizeOne; i++) {
			file_in >> item;
			arr[i] = item;
		}

		file_in >> sizeTwo;

		int* arrTwo = new int[sizeTwo];
		for (int i = 0; i < sizeTwo; i++) {
			file_in >> item;
			arrTwo[i] = item;
		}

		std::ofstream file_out("out.txt");

		file_out << sizeTwo << std::endl;
		file_out << arrTwo[sizeTwo-1] << " ";

		for (int i = 0; i < sizeTwo-1; i++) {
			file_out << arrTwo[i] << " ";
		}
		file_out << std::endl;

		file_out << sizeOne << std::endl;

		for (int i = 1; i < sizeOne; i++) {
			file_out << arr[i] << " ";
		}
		file_out << arr[0] << " ";
		file_out << std::endl;

		delete[] arr;
		delete[] arrTwo;
		file_in.close();
		file_out.close();
	}
	else {
		std::cout << "Файл не найдет" << std::endl;
	}
	return 0;
}
