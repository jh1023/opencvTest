#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png");
	
	// image w,h,channel
	std::cout << "Width : " << image.size().width << std::endl;
	std::cout << "Height: " << image.size().height << std::endl;
	std::cout<< "Channels: :"<< image.channels() << std::endl;

	// Crop image
	cv::Mat croppedImage = image(cv::Range(80,280), cv::Range(150,330));
	
	// Display Image
	cv::imshow("Original Image", image);
	cv::imshow("Cropped Image", croppedImage);
	// save Image
	cv::imwrite("CroppedImage.png", croppedImage);
	
    cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
