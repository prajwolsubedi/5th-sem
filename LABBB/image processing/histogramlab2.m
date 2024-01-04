img = imread('img/redrose.jpg');
grayimg = rgb2gray(img);
his = histeq(grayimg);
figure;
subplot(3,3,1);imshow(img);title('Original image');
subplot(3,3,2);imhist(img);title('Original image Histogram');
subplot(3,3,3);imshow(grayimg);title('Original Gray Image');
subplot(3,3,4);imhist(grayimg);title('Original gray image Histogram');
subplot(3,3,5);imshow(his);title('Equalized Image');
subplot(3,3,6);imhist(his);title('Equalized Histogram');
imwrite(his,"img/newimag.jpg")%yo chai his wala variable ma vako image save garna
