%rgb to binary transformation using thresholding
img=imread('img/redrose.jpg');
thval=graythresh(img);
thimg=im2bw(img,thval);
figure;
subplot(1,2,1);imshow(img);title('original image');
subplot(1,2,2);imshow(thimg);title('binary image transformation');