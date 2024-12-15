#导入cv模块
import cv2 as cv
from numpy.ma.core import resize

#读取图片
img = cv.imread('face1.jpg')
#坐标
x,y,w,h = 100,100,100,100
#绘制矩形
cv.rectangle(img,(x,y,x+w,y+h),color=(0,255,0),thickness=1)   ###图片，起始点和长宽，颜色，宽度
#绘制圆形
cv.circle(img,center=(x+w,y+h),radius=100,color=(0,0,255),thickness=2)  ###图片，圆心，半径，颜色，宽度
#显示
cv.imshow('re_img',img)
#等待
while True:
    if ord('q') == cv.waitKey(0):
        break
#释放内存
cv.destroyAllWindows()