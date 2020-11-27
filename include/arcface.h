#ifndef __ARCFACE_H
#define __ARCFACE_H

#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>

class ArcFace
{
public:
	int init(char* model_path);
	int extract(cv::Mat &image, cv::Mat &feature);
	float similarity(cv::Mat &feature1, cv::Mat &feature2);
	int destroy();
};


#endif
