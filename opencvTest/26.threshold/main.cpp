#include <opencv2/opencv.hpp>
#include <iostream>
int t_val = 128;
cv::Mat image, dst_;

void on_trackbar_threshold(int, void*) {
	cv::threshold(image, dst_, t_val, 255, cv::THRESH_BINARY_INV);
	cv::imshow("dst", dst_);
}

int main() {
	// 이미지 읽기
	image = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::namedWindow("image");
	cv::imshow("image", image);

	cv::namedWindow("dst");
	cv::createTrackbar("Threshold", "dst", &t_val, 255, on_trackbar_threshold);
	on_trackbar_threshold(0, 0);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

