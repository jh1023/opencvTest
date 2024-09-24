#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>
#include <vector>

int main() {
    // 이미지 불러오기
    cv::Mat img1 = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);

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

    std::cout << "keypoints1 size: " << keypoints1.size() << std::endl;
    std::cout << "descriptors1 size: " << descriptors1.size() << std::endl;
    std::cout << "keypoints2 size: " << keypoints2.size() << std::endl;
    std::cout << "descriptors2 size: " << descriptors2.size() << std::endl;

    // 매칭기 생성 및 특징점 매칭 (기본적으로 BFMatcher 사용)
    cv::BFMatcher matcher(cv::NORM_L2);
    std::vector<cv::DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    // 매칭 결과를 거리 기준으로 정렬
    std::sort(matches.begin(), matches.end());

    // 상위 매칭 결과만 사용 (예: 50개)
    const int numGoodMatches = 50;
    std::vector<cv::DMatch> good_matches(matches.begin(), matches.begin() + std::min<int>(numGoodMatches, matches.size()));

    // 매칭 결과를 그려서 시각화
    cv::Mat img_matches;
    cv::drawMatches(img1, keypoints1, img2, keypoints2, good_matches, img_matches, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    // 매칭 결과 출력
    cv::imshow("Good Matches", img_matches);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
