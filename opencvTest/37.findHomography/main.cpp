#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

int main() {
	// 이미지 불러오기
	cv::Mat img1 = cv::imread("../../useImage/candies.png", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("../../useImage/candies2.png", cv::IMREAD_COLOR);

	if (img1.empty() || img2.empty()) {
		std::cerr << "Could not open or find the images!" << std::endl;
		return -1;
	}

	// 특징점 검출기 생성 (SIFT, KAZE, AKAZE, ORB 중 하나 선택)
	cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
	// cv::Ptr<cv::Feature2D> detector = cv::KAZE::create();
	// cv::Ptr<cv::Feature2D> detector = cv::AKAZE::create();
	// cv::Ptr<cv::Feature2D> detector = cv::ORB::create();

	// 특징점 및 기술자 계산
	std::vector<cv::KeyPoint> keypoints1, keypoints2;
	cv::Mat descriptors1, descriptors2;

	detector->detectAndCompute(img1, cv::noArray(), keypoints1, descriptors1);
	detector->detectAndCompute(img2, cv::noArray(), keypoints2, descriptors2);

	// 매칭기 생성 및 특징점 매칭
	cv::BFMatcher matcher(cv::NORM_L2);
	std::vector<cv::DMatch> matches;
	matcher.match(descriptors1, descriptors2, matches);

	// 매칭 결과를 거리 기준으로 정렬
	std::sort(matches.begin(), matches.end());

	// 상위 매칭 결과만 사용 (예: 50개)
	const int numGoodMatches = 50;
	std::vector<cv::DMatch> good_matches(matches.begin(), matches.begin() + std::min<int>(numGoodMatches, matches.size()));

	// 매칭된 점들 추출
	std::vector<cv::Point2f> pts1, pts2;
	for (const auto& match : good_matches) {
		pts1.push_back(keypoints1[match.queryIdx].pt);
		pts2.push_back(keypoints2[match.trainIdx].pt);
	}

	// 호모그래피 계산
	cv::Mat H = cv::findHomography(pts2, pts1, cv::RANSAC);

	if (H.empty()) {
		std::cerr << "Could not compute homography!" << std::endl;
		return -1;
	}

	// 이미지 2의 코너 포인트를 변환
	std::vector<cv::Point2f> img2_corners(4);
	img2_corners[0] = cv::Point2f(0, 0);
	img2_corners[1] = cv::Point2f(static_cast<float>(img2.cols), 0);
	img2_corners[2] = cv::Point2f(static_cast<float>(img2.cols), static_cast<float>(img2.rows));
	img2_corners[3] = cv::Point2f(0, static_cast<float>(img2.rows));

	std::vector<cv::Point2f> img2_corners_transformed;
	cv::perspectiveTransform(img2_corners, img2_corners_transformed, H);

	// 이미지 1 위에 이미지 2의 위치를 사각형으로 표시
	cv::Mat img1_with_box;
	img1.copyTo(img1_with_box);
	for (size_t i = 0; i < 4; ++i) {
		cv::line(img1_with_box, img2_corners_transformed[i], img2_corners_transformed[(i + 1) % 4], cv::Scalar(0, 255, 0), 4);
	}

	// 결과 출력
	cv::imshow("Image 1", img1);
	cv::imshow("Image 2", img2);
	cv::imshow("Image 1 with Image 2 Box", img1_with_box);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
