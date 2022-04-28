//
// Created by iotuser on 22. 4. 28.
//

#ifndef FACE_DETECT_PREPROCESS_HPP
#define FACE_DETECT_PREPROCESS_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 검출기 로드 함수 - 여러 검출기를 로드할 수 있도록 함수로 구현
void load_cascade(CascadeClassifier& cascade, string fname)
{
    String path = "/home/iotuser/opencv/opencv-4.4.0/data/haarcascades/";   // 검출기 폴더
    String full_name = path + fname;

    CV_Assert(cascade.load(full_name));     // 분류기 로드 및 예외 처리
}

// 얼굴 영상 전처리 - 얼굴 영상에서 명암도 변화 및 평활화 수행
Mat preprocessing(Mat image)
{
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);   // 명암도(그레이스케일?)로 영상 변환
    equalizeHist(gray, gray);       // 히스토그램 평활화
    return gray;
}

#endif //FACE_DETECT_PREPROCESS_HPP
