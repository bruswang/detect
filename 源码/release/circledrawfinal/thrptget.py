#Writen By XSkylerXie 2022-04-26 
#获取圆弧上的点
#输入图片地址
# 1.读取图片，
# 2.灰度化、二值化，优化器
# 5.返回圆心半径
import cv2
import numpy as np
import os

from scipy      import optimize

def get_t_allp(img_bit,minbit=172):
    h,w =img_bit.shape
    img_bit_new = np.zeros((h,w,3) , np.uint8)
    posi_m=[]
    k=0
    for i in range(0,w):
        for j in range(0,h):
            if (img_bit[j,i]<minbit):
                axx = i
                ayy = j
                
                xx = [axx,ayy]
                posi_m.append(xx)
    #posi_m中选若干组计算出R
    return posi_m

#多次拟合降低噪声
def prget(points_in):
    x=[]
    y=[]
    for i in range(0,len(points_in)):
        x_tmp,y_tmp = points_in[i]
        x.append(x_tmp)
        y.append(y_tmp)


    def calc_R(xc, yc):
        """ calculate the distance of each 2D points from the center (xc, yc) """
        return np.sqrt((x-xc)**2 + (y-yc)**2)

    def f_2(c):
        """ calculate the algebraic distance between the data points and the mean circle centered at c=(xc, yc) """
        Ri = calc_R(*c)
        return Ri - np.mean(Ri)

    x_m = np.mean(x)
    y_m = np.mean(y)

    center_estimate = x_m, y_m
    center_2, ier = optimize.leastsq(f_2, center_estimate)

    xc_2, yc_2 = center_2
    Ri_2       = calc_R(*center_2)
    R_2        = Ri_2.mean()
    residu_2   = sum((Ri_2 - R_2)**2)

    
    return xc_2 , yc_2 , R_2

def main():
    cdpwd = os.getcwd()
    filename = cdpwd+r"\tmpcircap.png"
    #print(filename)
    img = cv2.imread(filename)

    img_bit = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    posi_m_out = get_t_allp(img_bit,minbit=172)
    xc , yc , Rout = prget(posi_m_out)

    wstr = str(xc)+","+str(yc)+","+str(Rout)
    txtname = cdpwd+r"\tmpcircap.txt"
    f = open(txtname,'w') 
    f.write(wstr) #将字符串写入文件中
    f.write("\n")   #换行
    f.close()
    
if __name__ == "__main__":
    main()
