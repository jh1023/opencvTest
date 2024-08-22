#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("dog.jpg");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	cv::Mat color2gray;
	cv::cvtColor(image, color2gray, cv::COLOR_BGR2GRAY);

	cv::imshow("imgae", image);
	cv::imshow("color2gray", color2gray);

	cv::imwrite("color2gray.jpg", color2gray);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
