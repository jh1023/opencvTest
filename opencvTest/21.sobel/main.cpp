#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat dx, dy;
	cv::Sobel(image, dx, CV_32FC1, 1, 0); // x방향 gradient
	cv::Sobel(image, dy, CV_32FC1, 0, 1); // y방향 gradient

	cv::Mat mag; // magnitude
	cv::magnitude(dx, dy, mag);
	mag.convertTo(mag, CV_8UC1);

	cv::Mat thresholdImg = mag > 110; // threshold

	cv::imshow("image", image);
	cv::imshow("mag", mag);
	cv::imshow("thresholdImg", thresholdImg);    
	cv::imwrite("magnitude.jpg", mag);
	cv::imwrite("threshold.jpg", thresholdImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

