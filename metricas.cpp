#include "main.h"



Metricas::Metricas()
{
    avg = 0;
    count = 0;
}
double Metricas::getavg()
{
    return avg/count;
}
double Metricas::getPsnr(const Mat& img1, const Mat& img2,int id)
{
    Mat sub,im1,im2,temp[3];
    double mse,psnr;
    Scalar s;
    split(img1,temp);
    im1 = temp[1].clone();
    split(img2,temp);
    im2 = temp[1].clone();
    //Subtração |img1 - img2|
    absdiff(im1,im2,sub);
    //Conversão para 32 float para fazer a multiplicaçao
    sub.convertTo(sub,CV_32F);
    //|img1 - img2|^2
    sub = sub.mul(sub);
    s = sum(sub);

    mse = s[0]/sub.total();

    psnr = 10*log10(255*255/mse);
    if(id)
    {
        avg+=psnr;
        count++;
    }

    return psnr;

}

double Metricas::getSSIM(const Mat &igm1, const Mat &img2,int id)
{

    double ssim;
    return ssim;
}



