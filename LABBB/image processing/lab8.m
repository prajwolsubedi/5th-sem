ori_img = imread('img/redrose.jpg');
img = ori_img;
L = 256;
r1 = 10;
r2 = 50;
[row,col] = size(ori_img);
subplot(4,2,1); imshow(ori_img); title('Original Image');
subplot(4,2,3); imshow(ori_img); title('Original Image');
% Slicing Without Background
for i=1:row
 for j=1:col
 if ori_img(i,j) >= r1 && ori_img(i,j)<=r2
 ori_img(i,j) = (L-1);
 else
 ori_img(i,j) = 0;
 endif
 endfor
endfor
subplot(4,2,2); imshow(ori_img); title('Enhanced Image without Background');
% Slicing With Background
for i=1:row
 for j=1:col
 if img(i,j) >= r1 && img(i,j)<=r2
 img(i,j) = (L-1);
 else
 img(i,j) = img(i,j);
 endif
 endfor
endfor
subplot(4,2,4); imshow(img); title('Enhanced Image With Background');