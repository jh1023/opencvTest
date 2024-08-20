#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("dog.jpg");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}
	
	cv::Mat mapX = cv::Mat::zeros(image.rows, image.cols, CV_32FC1);
	cv::Mat mapY = cv::Mat::zeros(image.rows, image.cols, CV_32FC1);
	
	for (int y = 0; y < image.rows; y++) {
		for(int x = 0; x < image.cols; x++) {
			mapX.at<float>(y, x) = (float)x;
			mapY.at<float>(y, x) = (float)image.rows -1 - y; // 상하대칭
		}
	}

	cv::Mat remapImg;
	cv::remap(image, remapImg, mapX, mapY, cv::INTER_LINEAR);

	cv::imshow("image", image);
	cv::imshow("remap", remapImg);

	cv::imwrite("remap.jpg", remapImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
