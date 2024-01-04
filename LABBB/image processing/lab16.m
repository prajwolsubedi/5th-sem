ori_img = imread('img\redrose.jpg');
a = 2;
mask = [-1,-1,-1; -1,a+8,-1; -1,-1,-1];
filtered_img = imfilter(ori_img,mask);
subplot(1,2,1); imshow(ori_img); title('Original Image');
subplot(1,2,2); imshow(filtered_img); title('Filtered Image');