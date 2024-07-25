#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
   // read image
   cv::Mat image = cv::imread("Lenna.png");
   cv::imshow("Original Image", image);
   
   // let's downscale the image using new  width and height
   int down_width = 300;
   int down_height = 200;
   
   cv::Mat resized_down;
   //resize down
   cv::resize(image, resized_down, cv::Size(down_width, down_height), cv::INTER_LINEAR);
   
   // let's upscale the image using new  width and height
   int up_width = 600;
   int up_height = 400;
   
   cv::Mat resized_up;
   
   //resize up
   cv::resize(image, resized_up, cv::Size(up_width, up_height), cv::INTER_LINEAR);
   
   // Display Images and press any key to continue
   cv::imshow("Resized Down", resized_down);
   cv::imshow("Resized Up", resized_up);
   cv::waitKey();


   cv::destroyAllWindows();
   return 0;
}
