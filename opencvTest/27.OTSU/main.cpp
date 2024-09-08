#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/dog.jpg", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat dst;
	double threshold = cv::threshold(image, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU); // 0, 255는 사용되지 않는다. BINARY_INV를 대신 넣어주면 반전됨.

	cv::imshow("image", image);
	cv::imshow("dst", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

