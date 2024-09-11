#include <opencv2/opencv.hpp>
#include <iostream>
int blockSize = 51;
cv::Mat image, dst_;

void on_trackbar_threshold(int, void*) {
	int bsize = blockSize;
	std::cout << bsize << std::endl;

	if((bsize & 1) == 0)
		bsize--;

	if(bsize < 3)
		bsize = 3;

	std::cout << "->" << bsize << std::endl;

	cv::adaptiveThreshold(image, dst_, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, 
			cv::THRESH_BINARY, bsize, 5);
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
	cv::createTrackbar("Block size", "dst", &blockSize, 201, on_trackbar_threshold);
	on_trackbar_threshold(0, 0);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

