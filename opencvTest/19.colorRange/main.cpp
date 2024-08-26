#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int h_1(50), h_2(80), s_1(150), s_2(255);
cv::Mat image, hsv_, mask_, colorRange_;

void callback(int, void*) {
	// mask 생성
	cv::Scalar lowerb(h_1, s_1, 0);
	cv::Scalar upperb(h_2, s_2, 255);
	cv::inRange(hsv_, lowerb, upperb, mask_);

	cv::cvtColor(image, colorRange_, cv::COLOR_BGR2GRAY);
	cv::cvtColor(colorRange_, colorRange_, cv::COLOR_GRAY2BGR);
	image.copyTo(colorRange_, mask_);

	cv::imshow("mask", mask_);
	cv::imshow("colorRange", colorRange_);
}

int main() {
	image = cv::imread("candies.png");

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}    

	cv::cvtColor(image, hsv_, cv::COLOR_BGR2HSV);

	cv::namedWindow("image");
	cv::namedWindow("mask");
	cv::namedWindow("colorRange");

	cv::imshow("src", image);

	// 트랙바 생성 및 초기 값 설정 후 콜백 호출
	cv::createTrackbar("Lower Hue", "colorRange", &h_1, 179, callback);
	cv::createTrackbar("Upper Hue", "colorRange", &h_2, 179, callback);
	cv::createTrackbar("Lower Sat", "colorRange", &s_1, 255, callback);
	cv::createTrackbar("Upper Sat", "colorRange", &s_2, 255, callback);

	// 트랙바 초기 값을 반영하기 위해 callback 함수를 한 번 호출
	callback(0, nullptr);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
