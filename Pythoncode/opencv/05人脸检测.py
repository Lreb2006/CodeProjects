#导入cv模块
import cv2 as cv
from numpy.ma.core import resize
#检测函数
def face_detect_demo():
    gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)  ###转换灰度
    ###分类器
    face_detect = cv.CascadeClassifier('C:/Users/Lreb2006/Desktop/Pythoncode/opencv/.venv/Lib/site-packages/cv2/data/haarcascade_frontalface_alt2.xml')
    face = face_detect.detectMultiScale(gray,1.1,4,0,(10,10),(100,100))
    for x,y,w,h in face :
        cv.rectangle(img,(x,y),(x+w,y+h),color=(0,0,255),thickness=2)
    cv.imshow('result',img)
#读取图片
img = cv.imread('face2.jpg')
#检测函数
face_detect_demo()
#等待
while True:
    if ord('q') == cv.waitKey(0):
        break
#释放内存
cv.destroyAllWindows()