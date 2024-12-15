#导入cv模块
import cv2 as cv
from numpy.ma.core import resize

#读取图片
img = cv.imread('face1.jpg')
#修改尺寸
resize_img = cv.resize(img,dsize=(200,200))
#显示原图
cv.imshow('img',img)
#显示修改后的
cv.imshow('resize_img',resize_img)
#打印原图大小
print('未修改',img.shape)
#打印修改后的大小
print('修改后',resize_img.shape)
#灰度转换
gray_img = cv.cvtColor(img,cv.COLOR_BGR2GRAY)   ###BGR2GRAY就是灰色
#显示灰度
cv.imshow('gray',gray_img)  ###窗口名为gray
#保存灰度图片
cv.imwrite('gray_face1.jpg',gray_img)
#显示图片
cv.imshow('read_img',img)
#等待
cv.waitKey(0)
#释放内存
cv.destroyAllWindows()