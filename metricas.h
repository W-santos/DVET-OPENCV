
#ifndef METRICAS_H
#define METRICAS_H
using namespace cv;
enum id
{img ,video};
enum metricas{
    psnr,
    ssim,
    pwssim
};

class Metricas
{
protected:
    double avg=0;
    long long count=0;
public:
    Metricas();
    double getPsnr(const Mat& igm1, const Mat& img2,int id = video);
    double getSSIM(const Mat& igm1, const Mat& img2,int id = video);
    double getPWSSIM(const Mat& igm1, const Mat& img2,int id = video);
    double getavg();

};

#endif // METRICAS_H
