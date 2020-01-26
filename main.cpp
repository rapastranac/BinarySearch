#include <iostream>
#include <vector>

/*This functions assumes that the value to be found belongs to 
	the interval between the first and the last element in the vector*/

template <typename T>
std::pair<std::string,T> binarySearch(std::vector<T> const& container, T& toBeFind, size_t left, size_t right) {
	static std::pair< std::string, size_t> p;
	size_t mid = floor(left + ((right - left) / 2));

	if (mid == left) {
		/*If the input vector contains real numbers, the function will reach an infinite 
			loop where middle position will always be equal to the left. Then, when it reaches 
			this point, the function will return the left where it means that the actual value
			is located between this position and the next one.*/
		/*If the input vector contains integers but the value is not found, the function will 
			return the left where it means that the actual value is located between this 
			position and the next one.*/
		return std::make_pair("not found", left);
	}

	if (toBeFind < container[mid]) {
		p = binarySearch<T>(container, toBeFind, left, mid);
	}
	else if (toBeFind > container[mid]) {
		p = binarySearch<T>(container, toBeFind, mid, right);
	}
	else {
		return std::make_pair("found", mid);
	}
	
	return p;
}

int main() {
	/*vector <int> vec = { 3,9,17,18,21,28,32,36,41,44,51,59,\
		60,62,65,66,67,78,84,86,87,88,89,90,97};*/

	std::vector <float> vec = { 4.662, 11.964, 13.913, 16.357, 16.714,
		19.888, 21.699, 27.251, 28.290, 29.107, 29.223, 31.346, 
		33.036, 38.637, 39.210, 55.793, 60.560, 60.839, 63.303, 
		64.790, 65.934, 72.656, 79.567, 83.412, 83.787, 91.612, 
		92.140, 93.685, 96.029 };


	//int a = 28;
	float a = 29.75;

	//pair<string, int> result = binarySearch<int>(vec, a, 0, vec.size());	//For integers
	std::pair<std::string, int> result = binarySearch<float>(vec, a, 0, vec.size());	//For reals

	if (result.first == "not found") {
		std::cout << "Element " << result.first << ", element is located between " 
			<< result.second << " and " << result.second + 1 << std::endl;
	}
	else {
		std::cout << "Element " << result.first << ", element is located at " << result.second << std::endl;
	}
	
	return 0;
}