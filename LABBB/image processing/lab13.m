ori_img = imread('img/redrose.jpg');
mask1 = (1/9)*[1,1,1;1,1,1;1,1,1];
mask2 = (1/25)*[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1];
filtered_img1 = imfilter(ori_img,mask1);
filtered_img2 = imfilter(ori_img,mask2);
subplot(1,3,1); imshow(ori_img); title('Original Image');
subplot(1,3,2); imshow(filtered_img1);title('3x3 filtered Image');
subplot(1,3,3); imshow(filtered_img2);title('5x5 filtered Image');