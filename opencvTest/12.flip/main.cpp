#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}
	cv::Mat vImg;
	cv::Mat hImg;
	cv::Mat bImg;
	// 0:수평으로 반전 (수직 반전) 
	cv::flip(image, vImg, 0); // 수평으로 반전 (수직 반전)
	// 1:수직으로 반전 (수평 반전)
	cv::flip(image, hImg, 1);
	// -1:두 축으로 반전 (수직 반전 + 수평 반전)
	cv::flip(image, bImg, -1);

	cv::imshow("image", image);
	cv::imshow("vImg", vImg);
	cv::imshow("hImg", hImg);
	cv::imshow("bImg", bImg);
	
	cv::imwrite("vImg.jpg", vImg);
	cv::imwrite("hImg.jpg", hImg);
	cv::imwrite("bImg.jpg", bImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
