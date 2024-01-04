
img=imread('img/albatros.jpg');
l=256;
negimg=(l-1)-img;
figure;
subplot(1,2,1);imshow(img);title('Original image');
subplot(1,2,2);imshow(negimg);title('negative image');
imwrite(negimg,"img/negative.jpeg");
