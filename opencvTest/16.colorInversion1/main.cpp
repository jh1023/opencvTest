#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("dog.jpg");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	cv::Mat colorInversion = cv::Scalar(255, 255, 255) - image;
	//cv::Mat dst = ~src;
	cv::imshow("image", image);
	cv::imshow("colorInversion", colorInversion);

	cv::imwrite("colorInversion.jpg", colorInversion);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
