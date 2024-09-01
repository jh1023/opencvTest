#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat cannyImg;
	cv::Canny(image, cannyImg, 50, 150);    

	cv::imshow("image", image);
	cv::imshow("cannyImg", cannyImg);

	cv::imwrite("cannyImg.jpg", cannyImg);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

