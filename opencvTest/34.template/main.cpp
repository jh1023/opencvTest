#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    // 입력 이미지와 템플릿 이미지 경로
    std::string imagePath = "../../useImage/polygon.png";   // 큰 이미지 경로
    std::string templatePath = "../../useImage/templateImage.png";  // 템플릿 이미지 경로

    // 이미지 읽기
    cv::Mat img = cv::imread(imagePath, cv::IMREAD_COLOR);
    cv::Mat templ = cv::imread(templatePath, cv::IMREAD_COLOR);

    // 이미지 읽기 실패 시 종료
    if (img.empty() || templ.empty()) {
        std::cerr << "이미지 로드 실패!" << std::endl;
        return -1;
    }

    // 템플릿 매칭을 위한 결과 행렬 크기 계산
    int result_cols = img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    // 결과를 저장할 행렬 생성
    cv::Mat result(result_rows, result_cols, CV_32FC1);

    // 매칭 방법 선택 (예: TM_CCOEFF_NORMED)
    int match_method = cv::TM_CCOEFF_NORMED;

    // 템플릿 매칭 수행
    cv::matchTemplate(img, templ, result, match_method);

    // 최적의 매칭 위치 찾기
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::Point matchLoc;

    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    // TM_SQDIFF와 TM_SQDIFF_NORMED는 최소값이 최적의 매칭 위치
    if (match_method == cv::TM_SQDIFF || match_method == cv::TM_SQDIFF_NORMED) {
        matchLoc = minLoc;
    } else {
        matchLoc = maxLoc;
    }

    // 매칭된 위치에 사각형 그리기
    cv::rectangle(img, matchLoc, cv::Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2);

    // 결과 출력
    cv::imshow("Matched Image", img);
    cv::waitKey(0);

    return 0;
}

