ori=imread('img/redrose.jpg');
double_img=im2double(ori);
new_img=double_img;
new_img2=double_img;
[row,col]=size(ori);
gamma1=5;
gamma2=10;
c=1;
for i=1:row
    for j=1:col
        new_img(i,j)=c*double_img(i,j)^gamma1;
        new_img2(i,j)=c*double_img(i,j)^gamma2;
     end
end


figure;
subplot(2,2,1);imshow(ori);title('Original Image');
subplot(2,2,2);imshow(new_img);title('gamma image transformation(gamma 1=5)');
subplot(2,2,3);imshow(new_img2);title('gamma image transformation(gamma2=10)');

