#include "main.h"

using namespace cv;
using namespace std;
int main(int argc,char **argv)
{
    Mat ref,test;
    Metricas metrica;
    string arg1,arg2;
    arg1 = argv[1];
    arg2 = argv[2];
    VideoCapture cap1(argv[1]),cap2(argv[2]);
    if(!cap1.isOpened() || !cap2.isOpened())
    {
        puts("Error opening video\nQuitting");
        return 0;
    }
    while(cap1.read(ref))
    {
        cap2.read(test);
        cvtColor(ref,ref,CV_BGR2YCrCb);
        cvtColor(test,test,CV_BGR2YCrCb);
        metrica.getPsnr(ref,test);
    }
    cout << metrica.getavg()<<endl;


    return 0;
}
