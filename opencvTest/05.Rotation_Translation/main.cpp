#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png");

	// rotated /////////////////////////////////////////////////////////////////
	double angle = 45;

	// get the center coordinates of the image to create the 2D rotation matrix
	cv::Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
	// using getRotationMatrix2D() to get the rotation matrix
	cv::Mat rotation_matix = cv::getRotationMatrix2D(center, angle, 1.0);

	// we will save the resulting image in rotated_image matrix
	cv::Mat rotated_image;
	// rotate the image using warpAffine
	cv::warpAffine(image, rotated_image, rotation_matix, image.size());
	// rotated /////////////////////////////////////////////////////////////////

	// translation //////////////////////////////////////////////////////////////
	// get the height and width of the image
	int height = image.cols;
	int width = image.rows;
	// get tx and ty values for translation
	float tx = float(width) / 4;
	float ty = float(height) / 4;
	// create the translation matrix using tx and ty
	float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
	cv::Mat translation_matrix = cv::Mat(2, 3, CV_32F, warp_values);
	// save the resulting image in translated_image matrix
	cv::Mat translated_image;
	// apply affine transformation to the original image using the translation matrix
	cv::warpAffine(image, translated_image, translation_matrix, image.size());
	// translation //////////////////////////////////////////////////////////////

	// Display Image
	cv::imshow("Original Image", image);
	cv::imshow("Rotated image", rotated_image);
	cv::imshow("Translated image", translated_image);
	
	// wait indefinitely, press any key on keyboard to exit
	cv::waitKey(0);
	cv::destroyAllWindows();

	// save the image to disk
	cv::imwrite("rotated.jpg", rotated_image);
	cv::imwrite("translated_image.jpg", translated_image);
	
	return 0;
}
