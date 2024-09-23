#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

// 템플릿 매칭을 이용하여 숫자를 인식하는 함수
void recognizeDigits(cv::Mat& inputImage, const std::vector<cv::Mat>& templates) {
    cv::Mat gray;
    cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);
    
    for (int digit = 0; digit <= 9; ++digit) {
        cv::Mat result;
        cv::Mat templ = templates[digit];
        
        // 템플릿 매칭 수행
        cv::matchTemplate(gray, templ, result, cv::TM_CCOEFF_NORMED);
        
        // 일치하는 위치 찾기
        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        
        // 특정 임계값 이상 일치하면 인식된 숫자로 간주
        if (maxVal > 0.7) {  // 임계값 조정 가능
            cv::rectangle(inputImage, maxLoc, cv::Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2);
            cv::putText(inputImage, std::to_string(digit), cv::Point(maxLoc.x, maxLoc.y - 10),
                        cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
        }
    }
}

int main() {
    // 입력 이미지 로드
    cv::Mat inputImage = cv::imread("../../useImage/templatesNum/entireImg.png");
    if (inputImage.empty()) {
        std::cerr << "Image load failed" << std::endl;
        return -1;
    }

    // 숫자 템플릿 로드 (각 숫자에 대해 개별적으로 로드해야 함)
    std::vector<cv::Mat> templates;
    for (int i = 0; i <= 9; ++i) {
        std::string templateFilename = "../../useImage/templatesNum/" + std::to_string(i) + ".png";  // 각 숫자 템플릿 파일
        cv::Mat templ = cv::imread(templateFilename, cv::IMREAD_GRAYSCALE);
        if (templ.empty()) {
            std::cerr << "Template " << i << " load failed" << std::endl;
            return -1;
        }
        templates.push_back(templ);
    }

    // 숫자 인식 수행
    recognizeDigits(inputImage, templates);

    // 결과 출력
    cv::imshow("Recognized Digits", inputImage);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

