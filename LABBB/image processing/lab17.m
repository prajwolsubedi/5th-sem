ori_img = imread('img\redrose.jpg');
resized_img1 = imresize(ori_img,[512,312],'nearest');
resized_img2 = imresize(ori_img,[512,253],'bilinear');
subplot(1,3,1); imshow(ori_img); title('Original Image');
subplot(1,3,2); imshow(resized_img1); title('Nearest Interpolation');
subplot(1,3,3); imshow(resized_img2); title('Bilinear Interpolation');