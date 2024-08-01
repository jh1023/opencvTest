#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}


	cv::Mat shearConv(image.rows, image.cols * 3 / 2, image.type(), cv::Scalar(0));
	double m(0.5);

	for (int y = 0; y < image.rows; y++) {
		for(int x = 0; x < image.cols; x++) {
			int nx = int(x + m * y);
			int ny = y;
			shearConv.at<uchar>(ny, nx) = image.at<uchar>(y, x);
		}
	}

	cv::imshow("image", image);
	cv::imshow("shearConv", shearConv);
	cv::imwrite("shear_conversion.jpg", shearConv);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
