#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}


	cv::Mat bdMapping(image.rows * 2, image.cols * 2, image.type());

	// backward mapping
	for (int y = 0; y < bdMapping.rows; y++) {
		for(int x = 0; x < bdMapping.cols; x++) {
			int mx = x / 2;
			int my = y / 2;

			bdMapping.at<uchar>(y, x) = image.at<uchar>(my, mx);
		}
	}

	cv::imshow("image", image);
	cv::imshow("bdMapping", bdMapping);
	cv::imwrite("backwardMapping.jpg", bdMapping);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
