#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/contour_test.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat thresholdImg;
	cv::threshold(image, thresholdImg, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU); // binarization

	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(thresholdImg, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

	cv::Mat contourImg = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
	for(int i = 0; i < contours.size(); i++) {
		cv::Scalar color(rand() & 255, rand() & 255, rand() & 255);
		cv::drawContours(contourImg, contours, i, color, 2, cv::LINE_8);
	}

	cv::imshow("image", image);
	cv::imshow("threshold Img", thresholdImg);
	cv::imshow("contourImg", contourImg);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

